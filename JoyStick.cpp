/**
 * @Author: Claudius Laves <claudi>
 * @Date:   02-06-2020  18:13:35
 * @Email:  claudiuslaves@gmx.de
 * @Filename: JoyStick.cpp
 * @Last modified by:   claudi
 * @Last modified time: 02-06-2020  21:07:53
 */



#include "JoyStick.h"


void JoyStick::setup()
{
  pinMode(x_pin, INPUT);
  pinMode(y_pin, INPUT);
  pinMode(sw_pin, INPUT);
  autoCalibrate();
}

void JoyStick::setOutput(float _min, float _max)
{
  min_out = _min;
  max_out = _max;
}


void JoyStick::update()
{
  x_reading = analogRead(x_pin);
  y_reading = analogRead(y_pin);
  sw_reading = digitalRead(sw_pin);
  x = map_float(x_reading, 0, 1023, min_out, max_out, mean_x);
  y = map_float(y_reading, 0, 1023, min_out, max_out, mean_y);
}

void JoyStick::autoCalibrate()
{
  mean_x = analogRead(x_pin);
  mean_y = analogRead(y_pin);
}

float JoyStick::map_float(int val, int min_in, int max_in, float min_out, float max_out, int mean)
{
  float output;
  if(abs(val-mean) < mean_offset)
  {
    output = 0;
  }
  else if (val < (mean - mean_offset))
  {
    output = 1.0 - ((float)(val - min_in) / (float)((mean - mean_offset) - min_in));
    output *= min_out;
  }
  else
  {
    output = (float)(val - mean + mean_offset) / (float)(max_in - mean + mean_offset);
    output *= max_out;
  }
  return output;
}

float JoyStick::getX()
{
  return x;
}

float JoyStick::getY()
{
  return y;
}

bool JoyStick::isPressed()
{
  return (sw_reading == 1);
}

int JoyStick::getRawX()
{
  return x_reading;
}

int JoyStick::getRawY()
{
  return y_reading;
}

void JoyStick::setOffset(int os)
{
  mean_offset = os;
}
