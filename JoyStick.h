/**
 * @Author: Claudius Laves <claudi>
 * @Date:   02-06-2020  18:13:44
 * @Email:  claudiuslaves@gmx.de
 * @Filename: JoyStick.h
 * @Last modified by:   claudi
 * @Last modified time: 02-06-2020  19:59:30
 */
#ifndef __JOYSTICK__
#define __JOYSTICK__

#include "Arduino.h"

class JoyStick{
private:
  int x_pin;
  int y_pin;
  int sw_pin;

  float min_out{-1.}, max_out{1.};

  int mean_x;
  int mean_y;
  int mean_offset{2};

  int x_reading;
  int y_reading;
  int sw_reading;

  float x;
  float y;

  float map_float(int val, int min_in, int max_in, float min_out, float max_out, int mean);

public:
  JoyStick(): x_pin(A2), y_pin(A3), sw_pin(4){}
  JoyStick(int x, int y, int s): x_pin(x), y_pin(y), sw_pin(s){}
  void setOutput(float min, float max);
  void update();
  void setup();
  void autoCalibrate();
  float getX();
  float getY();
  int getRawX();
  int getRawY();
  void setOffset(int os);
};


#endif
