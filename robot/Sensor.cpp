//
//  Sensor.cpp
//  Quad
//
//  Created by Preston Raab on 10/9/22.
//

#include "Sensor.h"

/* Code for Ultrasonic sensor
 *
 *
 */

// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// ---------------------------------------------------------------- //

Sensor::Sensor(int trig, int echo):trigPin(trig), echoPin(echo){
}

void Sensor::setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  if(echoPin != -1){
    pinMode(echoPin, INPUT);  // Sets the echoPin as an INPUT
  }
  digitalWrite(trigPin, LOW);
}
void Sensor::update() {
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  debugln("hello5");
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds/
  if(echoPin != -1){
    duration = pulseIn(echoPin, HIGH, 30000);
  }
  else{
    duration = 0;
  }
  // Calculating the distance
  distance = duration * 0.034 / 2.0; // Speed of sound wave divided by 2 (go and back)
  distanceAvg = 0.7 * distanceAvg + 0.3 * (float)((distance < 125) ? distance : 125);  //In centimeters
  // Displays the distance on the Serial Monitor
  //debugfloat("Avg Distance: ", distanceAvg);

  delayMicroseconds(30000);
}

float Sensor::getDistance(){
  return distanceAvg;
}

