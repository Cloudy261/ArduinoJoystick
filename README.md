# ArduinoJoystick
Easy to use Library for Arduino Joysticks.
Get floating point Numbers between -1.0 and 1.0 (or whatever you like) instead of analogReadings. 

# Wiring
 
 
 |Arduino|         Joystick|
 |----------|--------------|
 |5V        |      5V |
 |GND       |      GND |
 | A2        |      VRx |
 | A3        |      VRy |
 | D2        |      SW |
  
 Depending on your Joystick, you might need a pulldown Resistor on your Arduino D2 Pin.
 
 # Example
 In your Arduino IDE, paste the following code (alternatively you can open the included example):
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

# Useful functions

[obligatory] The setup. Sets the 3 default (or your Pins) as INPUT. Autocalibration happens afterwards.
```cpp
JoyStick joystick;
joystick.setup();
```

[obligatory] Update. Reads, converts and stores values. Has to be called before the getters.
```cpp
joystick.update();
```



This sets the minimal and maximal output. Note that a must be negative and b must be positive. I'll probably extend this function in the futute so you can set the Output to whatever you want, i.e. (+2, +0.5).
Default : -1.0 , 1.0.

```cpp
joystick.setOutput(float a, float b);
```


Getters..

```c
float x = joystick.getX(); // returns the floating point x value
float y = joystick.getY(); // returns the floating point y value
int raw_x = joystick.getRawX(); // returns the integer analogRead x value
int raw_y = joystick.getRawY(); // returns the integer analogRead y value
bool pressed = joystick.isPressd(); // returns true or false. 
```

Autocalibration. This gets called in joystick.setup(), but i kept it public so it is callable from the Arduino scope. Maybe this is useful for you. 

```cpp
joystick.autoCalibrate();
```

Offset setter. If your analogReadings wiggle a bit you can increase the offset. 
Default : 1.

```cpp
joystick.setOffset(int someInt);

