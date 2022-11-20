//
//  Sensor.h
//  Quad
//
//  Created by Preston Raab on 10/9/22.
//

#ifndef Sensor_h
#define Sensor_h
#include "constants.h"


class Sensor {
private:
  int trigPin; 
  int echoPin;
  float distanceAvg = 0;
  long duration; // variable for the duration of sound wave travel
  float distance;  // variable for the distance measurement
public:
  Sensor(int trig, int echo);
  void setup();

  void update();

  float getDistance();
};

#endif /* Sensor_h */
