//
//  Servo.cpp
//  Quad
//
//  Created by Preston Raab on 10/9/22.
//

#include "MyServo.h"

MyServo::MyServo(char pin) : pin(pin), startPosition(0) {

}

MyServo::MyServo(char pin, int startPos)
    : pin(pin), startPosition(startPos) {

}

void MyServo::setLimits(int startPos) {
  startPosition = startPos;
}

void MyServo::setPosition(int angle) {
  if (pin != -1) {
    int endPosition = startPosition == 0? -180 : startPosition + 180;

    int servoPos = (int)map(angle, startPosition, endPosition, 0 , 180);
    #if DEBUG_ERROR
    if(servoPos > 180 || servoPos < 0) {
      debug("ERROR Servo ");
      debugfloat(" Out of Bounds ERROR: Servo Angle: ", angle);
      debugfloat(" {", startPosition);
      debugfloat(", ", endPosition);
      debug(" ");
      debug("}");
    }
    #endif
    writeDegrees(servoPos);
  }
}

void MyServo::init() {
  if (pin != -1)
    servo.attach(pin);
}

void MyServo::writeDegrees(int deg) {
  #if DEBUG_LOW
   debug("Writing ");
   debug(deg);
   debug(" degrees to Servo ");
   debugln(name);
  #endif
  servo.write(deg);
}

void MyServo::writeRadians(float rad) {
  int deg = degrees(rad);
  writeDegrees(deg);
}

void MyServo::writePercent(float percent) {
  int deg = percent * 180.0;
  writeDegrees(deg);
}

int MyServo::getHypotheticalPositionUnit(float percent){
  return (int)(startPosition + percent * (180));
}
