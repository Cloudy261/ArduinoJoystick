#include "JoyStick.h"

/* 
*  Creating the default Joystick Object: 
*  This sets the X input to A2, the Y input to A3 
*  and the Joystick Button Input to the digital Pin 2.
*  Alternatively, you get use the commented Constructor 
*  to define your own Input Pins as shown:
*  JoyStick js(A2,A3,4);
*/


JoyStick js; 

void setup() {
  Serial.begin(115200);
  js.setup();              // setup the Joystick Object. This includes an autocalibration of the mean values. 
  
  //js.setOutput(-2, 2);   // set the Range of the x and y output.
  //js.setOffset(5);       // set the offset to another Value. 
                           //This eliminates analogRead error if it wiggles between two values. Default: 1
}

void loop() {
  
  js.update();             // Update the Joystick Object. You have to call this in the Loop Function.
  
  Serial.println(js.getX());
  Serial.println(js.getY());
  //Serial.println(js.getRawX());
  //Serial.println(js.getRawY());
  if(js.isPressed())
  {
    Serial.println("JoyStick is Pressed");
  }
  Serial.println("___________________________");
  delay(200);
}
