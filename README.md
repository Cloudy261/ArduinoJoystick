# ArduinoJoystick
Easy to use Library for Arduino Joysticks.
Get floating point Numbers instead of analogReadings. 

# Wiring
 
 
 |Arduino|         Joystick|
 |----------|--------------|
 |5V        |      5V |
 |GND       |      GND |
 | A2        |      VRx |
 | A3        |      VRy |
 | D2        |      SW |
  
 
 # Example
 ```cpp
 
 #include "JoyStick.h"
 
 JoyStick joystick;
 
 void setup()
 {
   joystick.setup();
   Serial.begin(9600);
 }
 
 void loop()
 {
   joystick.update();
   Serial.println(joystick.getX());   // float between -1.0 and 1.0
   Serial.println(joystick.getY());   // float between -1.0 and 1.0
   if(joystick.isPressed())
   {
     Serial.println("Joystick is pressed!");
   }
   Serial.println("");
   delay(100);
 }
 
 ```
