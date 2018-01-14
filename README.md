# Super-8-Raspberry-Scan
*A Super 8 Scanner based on Raspberry Pi*

This article present how to build a super 8 scanner based on Raspberry Pi.

This scanner is inspired from :

 - the <a href="https://github.com/Alexamder/rpitelecine">Rpitelecine project</a> [(local)](href=%22https://github.com/etiennecollomb/rpitelecine), itself inspired from the <a href="http://kinograph.cc/">Kinograph project</a>.<br>
- this project : http://www.chrisgavin.com/2013/10/another-diy-film-scanner.html
<br><br>

## Construction details

 - Raspberry Pi 3 (1x) ![](https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/rpi.jpg)
 - Camera Module Board 5MP Webcam Video 1080p 720p  (1x)<br>**Note :** The 8MP Camera version does not work well with the lens , and has some distorsion.![](https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/camera.jpg) 
 - (1x) Camera cable 30cm![](https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/camera_cable.jpg)
 - (1x) Raspberry Pi 7" Touchscreen Display![](https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/touchscreen.jpg)
 - (2x) Big Easy Driver for Stepper Motor<br>How to connect Raspbery & Big Easy Driver & Stepper Motor : [link](https://developer.microsoft.com/en-us/windows/iot/samples/arduino-wiring/steppermotor)![](https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/big_easy_driver.jpg)
 - (2x) NEMA 17 Stepper Motor (2 Phase Moteur, 4-Wire, 1.5A, 42 * 42 * 34mm)![](https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/step_motor.jpg)
 - (1x) External Power Supply (12V 10A) 120W![](https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/dc_power.jpg)
 - (1x) FemtoBuck LED Driver<br>[How to use](https://learn.sparkfun.com/tutorials/femtobuck-constant-current-led-driver-hookup-guide-v12)![](https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/femtobuck.jpg)
 - (1x) LM2596 DC-DC Buck Converter<br>(used to provide 5V to the Raspberry Pi)![](https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/lm2596.jpg)
 - (1x) 15mm Dia x 25.4mm EFL Hastings Triplet Achromatic Lens<br>[(Edmundoptics) Hastings Triplet](https://www.edmundoptics.com/optics/optical-lenses/achromatic-lenses/hastings-triplet-achromatic-lenses/)![](https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/hastings_triplet.jpg)
 - (1x) 2.1mm Breadboard Male DC Power Jack![](https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/dc_power_jack.png)
 - (1x) Stripboad ![](https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/stripboard.jpg)
 - (3x) LED - 3W Aluminum PCB (Warm White) ![](https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/led.jpg)
 - (1x) Pin 2.54 mm ![](https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/pin.jpg)
 - (1x) Angle Pin 2.54 mm ![](https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/angle_pin.jpg)
 - (1x) 2x20 pin IDC Box Header ![](https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/box_header.jpg)
 - 2x20 pin Gpio Cable (1x)![](https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/gpio_cable.jpg)
 - polystyrene sheet white (1x)![](https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/)
 - Structure component (makerbeam.com)
 

![](https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/)


## Heading3D Printed components 
