//============================================================================
// Name        : Super8Scan2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// |||||||||||||||||||||||||||||||||||||||
// |||||||||||||||||||||||||||||||||||||||

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <errno.h>
#include <dirent.h>
using namespace std;

#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

/********* Shoot Settings ************/


int isPosYFromTag = 1; //1 : perf position in the filename of image
int isNegative = false; // negative for B&W
int verticalCorrection = 0; // >0  : UP, <0 = DOWN // zm2 = 20, eumig nautica = 20


/** photo count **/
int imageCount;

/** set super datas **/
int super8_PerfWidth = 240; //emperical, should be measured on the image itself, with gimp
int super8_FilmWidth = 2050; //emperical, should be measured on the image itself, with gimp
int super8_FilmLeftBorder = 236; //emperical, should be measured on the image itself, with gimp
int super8_LeftBorderToPerf = 1676; //emperical, should be measured on the image itself, with gimp
int super8_RightBorderToPerf = 370; //emperical, should be measured on the image itself, with gimp
int super8_PerfHeight = 296; //emperical, should be measured on the image itself, with gimp
int super8_ImageHeight = 1088; //ie: distance between two startPerfs

int extraBorder = 160; // extra border outside of film

int numberOfStepsPerFrame = 160; // ie: 200 steps * 16 microStep / 20 teeth
float numberOfPixel_per_stepMotorMicroStep = (float)super8_ImageHeight / (float)numberOfStepsPerFrame;

/** save datas **/
string baseDir = "/mnt/hgfs/TEMP"; // Shared Dir with Temp Dir on the host
string savedImagesDir = baseDir + "/_ScanImages/";
string extractedImagesDir = baseDir + "/_ExtractedImages/";


/** Debug mode **/
int isDebug = false;


string intToString(int number){
	ostringstream oss;
	oss << number;

	string str = "";

	int tempNum = 1;
	for(int i=0; i<7; i++){
		tempNum = tempNum * 10;
		if(number < tempNum){
			str += "0";
		}
	}
	
	str += oss.str();

	return str;
}



/** return the first position of the perf **/
int getStartPerfCoordY(Mat image){

	int startPerfCoordY = -1; /* returned Value */
	int localStartPerfCoordY = -1;
	//int meanStartPerfCoordY = 0;
	//int count = 0;

	//=======================================================
	//=======================================================

	/** center perf is between 0.77 & 0.79 **/
	/** center perf is between 1980 & 2120 **/
	int xmin= 1950;
	int xmax = 2100;
	/** perf width is > 250 **/
	int ymin = 250;
	int ymax = image.rows-250;

	int perfMinHeight = 230; //taille minimale considerée comme perf, empirique selon le reglage du zoom

	int startPerfCoordYValues[xmax-xmin];
	for (int n=0 ; n<xmax-xmin ; n++ ) startPerfCoordYValues[n] = -1;

	//for each column
	/** 1 get average color **/
	/** 2 keep only color far from average (to be defined) **/

	for(int x=xmin; x<xmax; x=x+2){

		/** 1 get average color **/
		/*
		int averageRedValue = 0;
		int averageGreenValue = 0;
		int averageBlueValue = 0;

		for(int y=0;y<image.rows;y++){

			Vec3b color = image.at<Vec3b>(Point(x,y));

			averageRedValue = averageRedValue +color[0];
			averageGreenValue = averageGreenValue +color[1];
			averageBlueValue = averageBlueValue +color[2];

		}

		averageRedValue = averageRedValue / image.rows;
		averageGreenValue = averageGreenValue / image.rows;
		averageBlueValue = averageBlueValue / image.rows;

		if(isDebug) cout << "RGB: (" << averageRedValue << ", " << averageGreenValue << ", " << averageBlueValue << ")" << endl;
		 */


		/** 2 keep only color near to white **/

		int isStartPerf = 0; /** flag to know if we already are in a perf **/
		/** lighter pixel still as min pixel **/
		int colorShift = 20; //20
		if(!isNegative) colorShift = 20; //20

		for(int y=ymin;y<ymax;y++)
		{
			Vec3b color = image.at<Vec3b>(Point(x,y));

			if( //Negative ie B&W
					(isNegative &&
							color[0] <= 0 + colorShift && //14
							color[1] <= 0 + colorShift && //14
							color[2] <= 0 + colorShift)   //14
							||
							//Positiv ie Color
							(!isNegative &&
									color[0] >= 255 - colorShift &&
									color[1] >= 255 - colorShift && //color[1] >= 140
									color[2] >= 255 - colorShift
							) )

							//rsberrypY
							//(!isNegative && color[1] >= 140 ) )
			{
				/** we found a pixel possibly inside a Perf **/
				if(isStartPerf == 0){
					isStartPerf = 1;
					localStartPerfCoordY = y;
				}
				/** DEBUG **/
				if(isDebug){
					// set pixel green (pixel inside possible pref)
					color[0] = 0; color[1] = 255; color[2] = 0;
				}
				/** END DEBUG **/

			}else{
				/** Pixel is not (or maybe no more) part of the perf **/
				if(isStartPerf == 1){
					isStartPerf = 0; //reset

					/** check is size of possibly detected perf **/

					/** Yes we found the perf **/
					if(y - localStartPerfCoordY > perfMinHeight){

						/** DEBUG **/
						if(isDebug){
							/*
							//print min perf size in blue
							for(int j=startPerfCoordY; j<startPerfCoordY+perfMinHeight; j++){
								// set pixel blue
								color[0] = 255; color[1] = 0; color[2] = 0;
								image.at<Vec3b>(Point(x+0,j)) = color;
							}
							 */
							//print found perf turquoise
							for(int j=localStartPerfCoordY; j<y; j++){
								// set pixel turquoise
								color[0] = 255; color[1] = 128; color[2] = 0;
								image.at<Vec3b>(Point(x+0,j)) = color;
							}
						}
						/** END DEBUG **/

						//if Found, we break

						//meanStartPerfCoordY = meanStartPerfCoordY + localStartPerfCoordY;
						//count = count + 1;
						startPerfCoordYValues[x-xmin] = localStartPerfCoordY;

						break;

					}else{
						/** DEBUG **/
						if(isDebug){
							//print not good perf orange
							for(int j=localStartPerfCoordY; j<y; j++){
								// set pixel orange
								color[0] = 0; color[1] = 165; color[2] = 255;
								image.at<Vec3b>(Point(x+0,j)) = color;
							}
						}
						/** END DEBUG **/

						/** not size of Perf, ie we reset value **/
						localStartPerfCoordY = -1;
					}
				}else{

					/** DEBUG **/
					if(isDebug){
						// set pixel red (nothing found)
						color[0] = 0; color[1] = 0; color[2] = 255;
					}
					/** END DEBUG **/

				}
			}

			/** DEBUG **/
			if(isDebug){
				image.at<Vec3b>(Point(x,y)) = color;
			}
			/** END DEBUG **/
		}

	}


	/** DEBUG **/
	if(isDebug){
		string rootFileName = "last_Perf_Detection_Before_Crash.jpeg";
		string savedFilename = extractedImagesDir;
		savedFilename += "_Debug_"+rootFileName;
		imwrite( savedFilename, image );
	}



	//1) keep only the perfY around the mean (to avoid aberration)
	//on mets en paquet les valeurs proches et on prends la moyenne du paquet le plus gros
	int meanValues[xmax-xmin][xmax-xmin]; //les paquets de valeurs proches
	for (int n=0 ; n<xmax-xmin ; n++ ){
		for (int m=0 ; m<xmax-xmin ; m++ ){
			meanValues[n][m]=-9999;
		}
	}

	int ecartMax = 5; // empirique en pixel
	//count = 0;
	for (int n=0 ; n<xmax-xmin ; n++ ){
		if(startPerfCoordYValues[n] >= 0){

			//we check if we found close value
			for (int m=0 ; m<xmax-xmin ; m++ ){
				if(meanValues[m][0]==-9999){ meanValues[m][0]=1; meanValues[m][1]=startPerfCoordYValues[n]; break; } //we didn't find close values, we save new one
				//if close value
				if(meanValues[m][1]<=startPerfCoordYValues[n]+ecartMax && meanValues[m][1]>=startPerfCoordYValues[n]-ecartMax){
					//we save
					int index = meanValues[m][0] +1;
					meanValues[m][index] = startPerfCoordYValues[n];
					meanValues[m][0] = index;
					break;
				}
			}
		}
	}

	//trouve le paquet le plus gros
	int maxSizeIndex = 0;
	for (int n=0 ; n<xmax-xmin ; n++ ){
		if(meanValues[n][0] > meanValues[maxSizeIndex][0]) maxSizeIndex = n;
	}

	//copute the mean of values
	int realMeanStartPerfCoordY=0;
	for (int n=1 ; n<xmax-xmin ; n++ ){
		if(meanValues[maxSizeIndex][n]==-9999) break;
		realMeanStartPerfCoordY = realMeanStartPerfCoordY + meanValues[maxSizeIndex][n];
	}

	startPerfCoordY = (realMeanStartPerfCoordY/meanValues[maxSizeIndex][0]);


	/** DEBUG **/
	if(isDebug){
		cout << "startPerfCoordY: " << startPerfCoordY << endl;

		for(int i=0; i<image.cols; i++){
			// set pixel mediumseagreen
			Vec3b color = image.at<Vec3b>(Point(i,startPerfCoordY));
			color[0] = 113; color[1] = 179; color[2] = 60;
			image.at<Vec3b>(Point(i,startPerfCoordY)) = color;
		}

	}
	/** END DEBUG **/

	return startPerfCoordY;
}






/** get posY tag from filename "NAME_number_shutterSpeed_posY.jpeg" **/
int getPosYfromTag(string imageName){

	string valueString = imageName.substr(imageName.find_last_of("\\") + 1);
	valueString = valueString.substr(valueString.find_last_of("_")+1);
	valueString = valueString.substr(0, valueString.find_last_of("."));

	return atoi(valueString.c_str());

}




void extractImage(string imageName, int fileNumber){

	Mat image;
	image = imread(imageName.c_str(), IMREAD_COLOR); // Read the file
	if( image.empty() )
		cout <<  "Could not open or find the image" << std::endl ;
	else{

		//		/*** a mettre dans la partie RaspPI **/


		//		int startPerfCoordY = getStartPerfCoordY(image);
		//		int startPerfCoordY = getPosYfromTag(imageName);

		int startPerfCoordY = 0;
		if(isPosYFromTag)startPerfCoordY = getPosYfromTag(imageName);
		else startPerfCoordY = getStartPerfCoordY(image);


		int startY = (int)( startPerfCoordY + (float)super8_PerfHeight/2 - (float)super8_ImageHeight/2 );


		//=======================================================
		//=======================================================
		/** DEBUG **/
		if(isDebug){
			string rootFileName = /*intToString(fileNumber) + "_" +*/ imageName.substr(imageName.find_last_of("/") + 1);
			string savedFilename = extractedImagesDir;
			savedFilename += "_Debug_"+rootFileName;
			imwrite( savedFilename, image );
		}

		//crop image inside the original image?
		if(!isDebug){
			if(startY+verticalCorrection >=0 && startY+verticalCorrection + (float)super8_ImageHeight < image.rows ){
				Rect myROI(super8_FilmLeftBorder - extraBorder, startY+verticalCorrection, super8_FilmWidth+2*extraBorder, super8_ImageHeight);
				//Rect myROI(startx, startY, cropWidth, super8_ImageHeight); //if we compute startPerfX
				Mat croppedImage = image(myROI);

				//string rootFileName = /*intToString(fileNumber) + "_" +*/ imageName.substr(imageName.find_last_of("/") + 1);
				string rootFileName = "crop_" + intToString(fileNumber) + ".jpg";
				string savedFilename = extractedImagesDir;
				savedFilename += rootFileName;

				//cout << savedFilename << endl;
				imwrite( savedFilename, croppedImage );
				cout << "  _Cropped Image: " << savedFilename << endl;

			}
			else{
				cout << "####### ERROR Cropped Image: " << imageName << endl;
			}
		}

		/** END DEBUG **/

	}

}


int isFile(const char* name)
{
	DIR* directory = opendir(name);

	if(directory != NULL)
	{
		closedir(directory);
		return 0;
	}

	if(errno == ENOTDIR)
	{
		return 1;
	}

	return -1;
}



int main(int argc, char** argv) {


	for(int i=1; i<argc; i=i+2){
		string arg = argv[i];
		if(arg == "-vc"){ //vertical correction
			cout<< argv[i] << " " << argv[i+1] << endl;
			string value = argv[i+1];
			stringstream(value) >> verticalCorrection;
		}
		else if(arg == "-ng"){ //is negative
			cout<< argv[i] << " " << argv[i+1] << endl;	
			string value = argv[i+1];
			if(value == "1")
				isNegative = true;
			else
				isNegative = false;
		}
		else if(arg == "-h"){
			cout << "-vc value    :vertical Correction ( >O : UP; <0 : DOWN;)\n-ng value    :isNegative (O = FALSE; 1 = TRUE;)" << endl;
			return 0;
		}
	}


	cout << "Starting..." << endl;

	int fileCount = 0;
	DIR* dir;
	dirent* pdir;
	dir = opendir(savedImagesDir.c_str());

	while ((pdir = readdir(dir))){
		string filename = savedImagesDir;
		filename += pdir->d_name;

		//We skip self dir
		string tempName = pdir->d_name;
		if((tempName == ".")||(tempName == "..")) continue;

		if(isFile(filename.c_str())){

			//It is a file
			if(filename.substr(filename.find_last_of(".") + 1) == "jpeg"){
				cout << fileCount << " Current image: " << filename << endl;
				extractImage(filename, fileCount);
				fileCount = fileCount + 1;
			}

		}else{

			//It is a dir
			DIR* dir2;
			dirent* pdir2;
			dir2 = opendir(filename.c_str());

			while ((pdir2 = readdir(dir2))){
				string filename2 = filename;
				filename2 += "/";
				filename2 += pdir2->d_name;

				if(filename2.substr(filename2.find_last_of(".") + 1) == "jpeg"){
					cout << fileCount << " Current image: " << filename2 << endl;
					extractImage(filename2, fileCount);
					fileCount = fileCount + 1;
				}
			}
		}
	}

	cout << "Done!" << endl;

	return 0;
}

