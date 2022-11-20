//
//  DistanceSensorController.h
//  Quad
//
//  Created by Preston Raab on 10/9/22.
//


#ifndef DistanceSensorController_h
#define DistanceSensorController_h
#include "constants.h"

#include "Sensor.h"

class DistanceSensorController {
public:
  struct FourDistances{
    float positiveX;
    float positiveY;
    float negativeX;
    float negativeY;
  };
private:
  FourDistances sensorResults;
    char numSamples;

  Sensor sensorRight;
  Sensor sensorUp;
  Sensor sensorLeft;
  Sensor sensorDown;
public:
  DistanceSensorController();

  void init();

  void updateSensors();

  void debugSensors();

  FourDistances getGlobalResults();
};

#endif /* DistanceSensorController_h */
