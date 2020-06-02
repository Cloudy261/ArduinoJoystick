#include "JoyStick.h"

JoyStick js(A2,A3,4);

void setup() {
  Serial.begin(115200);
  js.setup();
  //js.setOutput(-2, 2);
  //js.setOffset(5);
}

void loop() {
  js.update();
  
  Serial.println(js.getX());
  Serial.println(js.getY());
  if(js.isPressed())
  {
    Serial.println("JoyStick is Pressed");
  }
  Serial.println();
  delay(200);
}
