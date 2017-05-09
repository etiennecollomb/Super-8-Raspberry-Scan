# Super-8-Raspberry-Scan
A Super 8 Scanner based on Raspberry Pi


This article present how to build a super 8 scanner based on Raspberry Pi.<br>
This scanner is inspired from the <a href="https://github.com/Alexamder/rpitelecine">Rpitelecine project</a>, itself inspired from the <a href="http://kinograph.cc/">Kinograph project</a>
It is also inspired from this project : http://www.chrisgavin.com/2013/10/another-diy-film-scanner.html
<br><br>


<a href="./Super8Scan/Images/IMAG0025.jpg"><img src="./Super8Scan/Images/IMAG0025.jpg" style="width: 12.5%; "/></a><br><br>

<a href="./Super8Scan/Images/IMAG0030.jpg"><img src="./Super8Scan/Images/IMAG0030.jpg" style="height: 12.5%"/></a><br><br>

<a href="./Super8Scan/Images/IMAG0035.jpg"><img src="./Super8Scan/Images/IMAG0035.jpg" style="width: 12.5%; height: 12.5%"/></a><br><br>

<a href="./Super8Scan/Images/IMAG0036.jpg"><img src="./Super8Scan/Images/IMAG0036.jpg" style="width: 12.5%; height: 12.5%"/></a><br><br>

<a href="./Super8Scan/Images/.jpg"><img src="./Super8Scan/Images/.jpg" style="width: 12.5%; height: 12.5%"/></a><br><br>

<a href="./Super8Scan/Images/.jpg"><img src="./Super8Scan/Images/.jpg" style="width: 12.5%; height: 12.5%"/></a><br><br>

<a href="./Super8Scan/Images/.jpg"><img src="./Super8Scan/Images/.jpg" style="width: 12.5%; height: 12.5%"/></a><br><br>

<a href="./Super8Scan/Images/.jpg"><img src="./Super8Scan/Images/.jpg" style="width: 12.5%; height: 12.5%"/></a><br><br>

What you need :
<a href=""/></a><br><br>


Raspberry Pi 3 (1x) <br>
<a href="https://www.amazon.com/s/ref=nb_sb_noss_2?url=search-alias%3Daps&field-keywords=Raspberry+Pi+3&rh=i%3Aaps%2Ck%3ARaspberry+Pi+3"><img 

src="./Super8Scan/Components/rpi.jpg" style="width: 12.5%; height: 12.5%"/></a><br>
<a href="https://www.amazon.com/s/ref=nb_sb_noss_2?url=search-alias%3Daps&field-keywords=Raspberry+Pi+3&rh=i%3Aaps%2Ck%3ARaspberry+Pi+3"/>(amazon.com) 

Raspberry Pi 3</a><br>
<br>

Camera Module Board 5MP Webcam Video 1080p 720p  (1x) <br>
<a href="https://www.amazon.com/s/ref=nb_sb_noss?url=search-alias%3Daps&field-keywords=Camera+Module+Board+5MP+Webcam+Video+1080p+720p+"><img 

src="./Super8Scan/Components/camera.jpg" style="width: 12.5%; height: 12.5%"/></a><br>
<a href="https://www.amazon.com/s/ref=nb_sb_noss?url=search-alias%3Daps&field-keywords=Camera+Module+Board+5MP+Webcam+Video+1080p+720p+"/>(amazon.com) 

Camera 1080p 720p for Raspberry</a><br>
The new 8MP Camera version does not work well with the lens , and has some distorsion.<br>
<br>


(1x) Camera cable 30cm <br>
<a href="https://shop.pimoroni.com/products/raspberry-pi-camera-cable"><img src="./Super8Scan/Components/Camera_Cable.jpg" style="width: 12.5%; height: 

12.5%"/></a><br>
<a href="https://shop.pimoroni.com/products/raspberry-pi-camera-cable"/>(pimoroni.com) Camera cable 30cm</a><br>
<br>


(1x) Raspberry Pi 7" Touchscreen Display <br>
<a href="https://www.amazon.com/s/ref=nb_sb_noss_2?url=search-alias%3Daps&field-keywords=Raspberry+Pi+7%22+Touchscreen+Display&rh=i%3Aaps%2Ck

%3ARaspberry+Pi+7%22+Touchscreen+Display"><img src="./Super8Scan/Components/touchscreen.jpg" style="width: 12.5%; height: 12.5%"/></a><br>
<a href="https://www.amazon.com/s/ref=nb_sb_noss_2?url=search-alias%3Daps&field-keywords=Raspberry+Pi+7%22+Touchscreen+Display&rh=i%3Aaps%2Ck

%3ARaspberry+Pi+7%22+Touchscreen+Display"/>(amazon.com) Raspberry Pi 7" Touchscreen Display</a><br>
<br>


(2x) Big Easy Driver for Stepper Motor <br>
<a href=""><img src="./Super8Scan/Components/BigEasyDriver.jpg" style="width: 12.5%; height: 12.5%"/></a><br>
<a href="http://www.schmalzhaus.com/BigEasyDriver/index.html"/>http://www.schmalzhaus.com/BigEasyDriver/index.html</a><br>
How to connect Raspbery & Big Easy Driver & Stepper Motor : <a href="https://developer.microsoft.com/en-us/windows/iot/samples/arduino-

wiring/steppermotor"/>https://developer.microsoft.com/en-us/windows/iot/samples/arduino-wiring/steppermotor</a><br>
<a href="https://www.amazon.com/s/ref=nb_sb_noss?url=search-alias%3Daps&field-keywords=big+easy+driver&rh=i%3Aaps%2Ck%3Abig+easy+driver"/>(amazon.com) 

Big Easy Driver</a><br>
<br>


(2x) NEMA 17 Stepper Motor (2 Phase Moteur, 4-Wire, 1.5A, 42 * 42 * 34mm) <br>
<a href="https://www.amazon.com/s/ref=nb_sb_ss_c_1_9?url=search-alias%3Daps&field-keywords=17hd34008-22b&sprefix=17HD34008%2Caps

%2C774&crid=1LN1CFL9L2TKL"><img src="./Super8Scan/Components/step_motor.jpg" style="width: 12.5%; height: 12.5%"/></a><br>
<a href="https://www.amazon.com/s/ref=nb_sb_ss_c_1_9?url=search-alias%3Daps&field-keywords=17hd34008-22b&sprefix=17HD34008%2Caps

%2C774&crid=1LN1CFL9L2TKL>(amazon.com) Nema 17 Step Motor</a><br>
<br>


(1x) External Power Supply (12V 10A) 120W, <br>
<a href="https://www.amazon.com/s/ref=nb_sb_noss?url=search-alias%3Daps&field-keywords=Power+Supply+Adapter+110V%2F120V+to+12V+10A&rh=i%3Aaps%2Ck

%3APower+Supply+Adapter+110V%2F120V+to+12V+10A"><img src="./Super8Scan/Components/.jpg" style="width: 12.5%; height: 12.5%"/></a><br>
<a href="https://www.amazon.com/s/ref=nb_sb_noss?url=search-alias%3Daps&field-keywords=Power+Supply+Adapter+110V%2F120V+to+12V+10A&rh=i%3Aaps%2Ck

%3APower+Supply+Adapter+110V%2F120V+to+12V+10A">(amazon.com) Power Supply Adapter 110V/120V to 12V 10A</a>
<br>


(1x) FemtoBuck LED Driver: <br>
<a href=""><img src="./Super8Scan/Components/.jpg" style="width: 12.5%; height: 12.5%"/></a><br>
<a href="https://learn.sparkfun.com/tutorials/femtobuck-constant-current-led-driver-hookup-guide-v12"/>https://learn.sparkfun.com/tutorials/femtobuck-

constant-current-led-driver-hookup-guide-v12</a><br>
<a href="https://shop.pimoroni.com/products/femtobuck-led-driver"/>https://shop.pimoroni.com/products/femtobuck-led-driver</a><br><br>
<br>


(1x) LM2596 DC-DC Buck Converter: <br>
<a href=""><img src="./Super8Scan/Components/.jpg" style="width: 12.5%; height: 12.5%"/></a><br>
<a href="https://www.amazon.com/s/ref=nb_sb_noss?url=search-alias%3Daps&field-keywords=LM2596+&rh=i%3Aaps%2Ck%3ALM2596+"/>(Amazon.com) 

LM2596</a><br><br>
https://www.amazon.com/s/ref=nb_sb_noss?url=search-alias%3Daps&field-keywords=LM2596+&rh=i%3Aaps%2Ck%3ALM2596+
<br>

(1x) 15mm Dia x 25.4mm EFL Hastings Triplet Achromatic Lens <br>
<a href=""><img src="./Super8Scan/Components/.jpg" style="width: 12.5%; height: 12.5%"/></a><br>
<a href="https://www.edmundoptics.com/optics/optical-lenses/achromatic-lenses/hastings-triplet-achromatic-lenses/"/>(Edmundoptics) Hastings Triplet 

Achromatic Lens</a> <br>
<br>

(1x) 2.1mm Breadboard Male DC Power Jack<br>
<a href=""><img src="./Super8Scan/Components/.jpg" style="width: 12.5%; height: 12.5%"/></a><br>
<br>

(1x) Stripboad <br>
<a href=""><img src="./Super8Scan/Components/.jpg" style="width: 12.5%; height: 12.5%"/></a><br>
https://www.amazon.com/s/ref=nb_sb_noss?url=search-alias%3Daps&field-keywords=stripboard <br>
<br>

(3x) LED - 3W Aluminum PCB (Warm White) <br>
https://www.sparkfun.com/products/13104 <br>
<br>

(1x) Pin 2.54 mm <br>
https://www.amazon.com/s/ref=nb_sb_noss?url=search-alias%3Daps&field-keywords=40x1+Pin+2.54+mm&rh=i%3Aaps%2Ck%3A40x1+Pin+2.54+mm <br>
(1x) Angle Pin 2.54 mm <br>
https://www.amazon.com/s/ref=nb_sb_noss?url=search-alias%3Daps&field-keywords=40x1+angle+Pin+2.54+mm&rh=i%3Aaps%2Ck%3A40x1+angle+Pin+2.54+mm <br>
<br>

(1x) 2x20 pin IDC Box Header <br>
<a href=""><img src="./Super8Scan/Components/box_header.jpg" style="width: 12.5%; height: 12.5%"/></a><br>
<a href="https://www.amazon.com/s/ref=nb_sb_noss_2?url=search-alias%3Daps&field-keywords=+2x20+pin+IDC+Box+Header"/>(amazon.com) 2x20 pin IDC Box 

Header</a> <br>
<br>

2x20 pin Gpio Cable (1x)
https://www.amazon.com/s/ref=nb_sb_noss?url=search-alias%3Daps&field-keywords=40p+to+40p+GPIO+Ribbon+Cable&rh=i%3Aaps%2Ck%3A40p+to+40p+GPIO+Ribbon+Cable

polystyrene sheet white (1x)<br>
<br>

Structure component (makerbeam.com) <br>
<br>
<br>

3D Printed components <br>
How to open <br>



</body>

</html>