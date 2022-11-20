//
//  Leg.cpp
//  Quad
//
//  Created by Preston Raab on 10/9/22.
//

#include "Leg.h"

/**
Domains for right front leg
A1                                     A2                           A3 
-45º to 135º                      -90º to 90º                   0º to -180º
-45 is pointed back right     -90 is straight down         0 is inline with leg 2 
0 is straight out x           0 is flat horizontal         -90 is normal to leg 2 
135 is pointed front left      90 is straight up            -180 is sharply bent
**/

Leg::Leg(int shoulderPin, int elbowPin, int wristPin, Quadrant orientation)
    : shoulder(shoulderPin), elbow(elbowPin),
      wrist(wristPin) {
    configureDomains(orientation);
}

void Leg::configureDomains(Quadrant orientation) {
    this->orientation = orientation;
  switch (orientation) {
    case FORWARD_RIGHT:
      shoulder.setLimits(-45);
      break;
    case FORWARD_LEFT:
      shoulder.setLimits(45);
      break;
    case BACK_LEFT:
      shoulder.setLimits(135);
      break;
    case BACK_RIGHT:
      shoulder.setLimits(-135);
      break;
    default:
      #if DEBUG_ERROR
      debugln("ERROR configureServoDomains recieved unrecognized orientation");
      #endif
      break;
  }
  elbow.setLimits(-90);
  wrist.setLimits(0);
}

void Leg::home(){

}

// Attach Servo Pins to each joint
void Leg::init(float time) {
  wrist.init();
  shoulder.init();
  elbow.init();
  home();
}
