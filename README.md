<p align="center">
<img src=https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/scanner/IMG_20170502_134240.jpg | width=400> <img src=https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/scanner/IMG_20170502_135535.jpg | width=400>
</p>

# Super-8-Raspberry-Scan
*A Super 8 Scanner based on Raspberry Pi*

This article present how to build a super 8 scanner based on Raspberry Pi.

This scanner is inspired from :

 - the <a href="https://github.com/Alexamder/rpitelecine">Rpitelecine project</a> [(local)](href=%22https://github.com/etiennecollomb/rpitelecine), itself inspired from the <a href="http://kinograph.cc/">Kinograph project</a>.<br>
- this project : http://www.chrisgavin.com/2013/10/another-diy-film-scanner.html
<br><br>

## Construction details

 - Raspberry Pi 3 (1x) <br><img src=https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/rpi.jpg | width=100>
 - Camera Module Board 5MP Webcam Video 1080p 720p  (1x)<br>**Note :** The 8MP Camera version does not work well with the lens , and has some distorsion. <br><img src=https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/camera.jpg | width=100>
 - (1x) Camera cable 30cm <br><img src=https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/camera_cable.jpg | width=100>
 - (1x) Raspberry Pi 7" Touchscreen Display <br><img src=https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/touchscreen.jpg | width=100>
 - (2x) Big Easy Driver for Stepper Motor<br>How to connect Raspbery & Big Easy Driver & Stepper Motor : [link](https://developer.microsoft.com/en-us/windows/iot/samples/arduino-wiring/steppermotor) <br><img src=https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/big_easy_driver.jpg | width=100>
 - (2x) NEMA 17 Stepper Motor (2 Phase Moteur, 4-Wire, 1.5A, 42 * 42 * 34mm) <br><img src=https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/step_motor.jpg | width=100>
 - (1x) External Power Supply (12V 10A) 120W <br><img src=https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/dc_power.jpg | width=100>
 - (1x) FemtoBuck LED Driver<br>[How to use](https://learn.sparkfun.com/tutorials/femtobuck-constant-current-led-driver-hookup-guide-v12) <br><img src=https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/femtobuck.jpg | width=100>
 - (1x) LM2596 DC-DC Buck Converter<br>(used to provide 5V to the Raspberry Pi) <br><img src=https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/lm2596.jpg | width=100>
 - (1x) 15mm Dia x 25.4mm EFL Hastings Triplet Achromatic Lens<br>[(Edmundoptics) Hastings Triplet](https://www.edmundoptics.com/optics/optical-lenses/achromatic-lenses/hastings-triplet-achromatic-lenses/) <br><img src=https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/hastings_triplet.jpg | width=100>
 - (1x) 2.1mm Breadboard Male DC Power Jack <br><img src=https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/dc_power_jack.png | width=100>
 - (1x) Stripboad <br><img src=https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/stripboard.jpg | width=100>
 - (3x) LED - 3W Aluminum PCB (Warm White) <br><img src=https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/led.jpg | width=100>
 - (1x) Pin 2.54 mm <br><img src=https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/pin.jpg | width=100>
 - (1x) Angle Pin 2.54 mm <br><img src=https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/angle_pin.jpg | width=100>
 - (1x) 2x20 pin IDC Box Header <br><img src=https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/box_header.jpg | width=100>
 - 2x20 pin Gpio Cable (1x) <br><img src=https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/gpio_cable.jpg | width=100>
 - polystyrene sheet white (1x)
 - Structure component (makerbeam.com)
 

<img src=https://raw.githubusercontent.com/etiennecollomb/Super-8-Raspberry-Scan/master/images/components/ | width=100>


## Heading3D Printed components 
