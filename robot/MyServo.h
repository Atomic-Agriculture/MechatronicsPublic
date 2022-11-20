//
//  Servo.h
//  Quad
//
//  Created by Preston Raab on 10/9/22.
//
#ifndef MyServo_h
#define MyServo_h
#include "constants.h"


class MyServo {
private:
  //Pinout for arduino UNO
  char pin;
  
public:
  int startPosition;
  //Constains the sweeep of the servo. Angle in degrees
  Servo servo;
  MyServo(char pin);
  //Creates a servo object with a pin number, and movement constraints defined by startPos and endPos
  MyServo(char pin, int startPos);
  void setLimits(int startPos);
  void init();
  void writeDegrees(int deg);
  void writeRadians(float rad);
  void writePercent(float percent);

  void setPosition(int angle);
  int getHypotheticalPositionUnit(float percent);
};

#endif /* MyServo_h */
