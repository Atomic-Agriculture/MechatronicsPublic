//
//  DistanceSensorController.cpp
//  Quad
//
//  Created by Preston Raab on 10/9/22.
//
#include "DistanceSensorController.h"

DistanceSensorController::DistanceSensorController():
  sensorRight(TRIG_PIN, ECHO_1),
  sensorUp(TRIG_PIN, ECHO_2),
  sensorLeft(TRIG_PIN, ECHO_3),
  sensorDown(TRIG_PIN, ECHO_4) {
  numSamples = 0;
}

void DistanceSensorController::init() {
  sensorRight.setup();
  sensorUp.setup();
  sensorLeft.setup();
  sensorDown.setup();
}

void DistanceSensorController::updateSensors() {
  sensorRight.update();
  sensorUp.update();
  sensorLeft.update();
  sensorDown.update();
  if(numSamples < 20)
    numSamples++;
}

void DistanceSensorController::debugSensors(){
  debugfloatln("Right:", sensorRight.getDistance());
  debugfloatln("Up:", sensorUp.getDistance());
  debugfloatln("Left:", sensorLeft.getDistance());
  debugfloatln("Down:", sensorDown.getDistance());
  debugfloatln("Max:", 120);
  debugfloatln("Min:", 0);
}

DistanceSensorController::FourDistances DistanceSensorController::getGlobalResults(){
  float rightStatus = sensorRight.getDistance();
  float upStatus = sensorUp.getDistance();
  float leftStatus = sensorLeft.getDistance();
  float downStatus = sensorDown.getDistance();

  if(sensorRight.getDistance() < 1)
    rightStatus = 0;
  else
    rightStatus += sensorOffset;
  if(sensorUp.getDistance() < 1)
    upStatus = 0;
  else
    upStatus += sensorOffset;
  if(sensorLeft.getDistance() < 1)
    leftStatus = 0;
  else
    leftStatus = -(sensorOffset + leftStatus);
  if(sensorDown.getDistance() < 1)
    downStatus = 0;
  else
    downStatus = -(sensorOffset + downStatus);
  
  FourDistances result = {rightStatus, upStatus, leftStatus, downStatus};
  if(numSamples < 10){
    result.positiveX = 0;
    result.positiveY = 0;
    result.negativeX = 0;
    result.negativeY = 0;
  }
  debugfloatln("posX:", result.positiveX);
  debugfloatln("negX:", result.negativeX);
  debugfloatln("posY:", result.positiveY);
  debugfloatln("negX:", result.negativeY);
  return result;
}
