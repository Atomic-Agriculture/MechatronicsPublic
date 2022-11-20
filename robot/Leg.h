//
//  Leg.h
//  Quad
//
//  Created by Preston Raab on 10/9/22.
//
#ifndef Leg_h
#define Leg_h

#include "constants.h"
#include "MyServo.h"
#include "math.h"


class Leg {
public:

  enum Quadrant {
    FORWARD_RIGHT,
    FORWARD_LEFT,
    BACK_RIGHT,
    BACK_LEFT
  };

  
  
private:
  Quadrant orientation;

  void configureDomains(Quadrant orientation);
  
public:
  MyServo shoulder,   elbow,      wrist;

  Leg(int shoulderPin, int elbowPin, int wristPin, Quadrant orientation= FORWARD_RIGHT);
  Leg(const char* name, int shoulderPin, int elbowPin, int wristPin, Quadrant orientation= FORWARD_RIGHT);


  void home();

  void moveServos(float x, float y, float z);


  void debugAngles(float sAngle, float eAngle, float wAngle);

  void init(float time);

};

#endif /* Leg_h */
