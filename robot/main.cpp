
#ifndef MAIN_CPP
#define MAIN_CPP

#include "constants.h"
#include "Leg.h"
#include "MyServo.h"
#include "DistanceSensorController.h"

float timeNow;


#if RUN_ON_SERIAL
  Leg leg1(LEG_A1, LEG_A2, LEG_A3);
  Leg leg2(LEG_B1, LEG_B2, LEG_B3);
  Leg leg3(LEG_C1, LEG_C2, LEG_C3);
  Leg leg4(LEG_D1, LEG_D2, LEG_D3);


  void runOnSerialSetup(float timeNow) {
    leg1.init(timeNow);
    leg1.home();
    leg2.init(timeNow);
    leg2.home();
    leg3.init(timeNow);
    leg3.home();
    leg4.init(timeNow);
    leg4.home();
  }

  float shoulder1Percent = 0.5;
  float shoulder2Percent = 0.5;
  float elbowPercent = 0.5;
  float wristPercent = 0.5;

  //Input commands in these forms:
  //0 --set all servos to 0
  //0.5 --set all servos to halfway
  //s:1 --set the shoulders to all the way
  //e:.7 --set elbows to .7
  //w:0.2 --set wrists to 0.2
  void runOnSerialLoop() {
  #if DEBUG_ALL
    if(Serial.available()){
        String s = Serial.readStringUntil('\n');
        if(s.startsWith("s:")){
          s = s.substring(2);
          shoulder1Percent = s.toFloat();
          shoulder2Percent = s.toFloat();
        }
        else if(s.startsWith("e:")){
          s = s.substring(2);
          elbowPercent = s.toFloat();
        }
        else if(s.startsWith("w:")){
          s = s.substring(2);
          wristPercent = s.toFloat();
        }
        else if(s.startsWith("0") || s.startsWith("1") || s.startsWith(".")){
          shoulder1Percent = s.toFloat();
          shoulder2Percent = s.toFloat();
          elbowPercent = s.toFloat();
          wristPercent = s.toFloat();
        }  
    }
  #endif

    leg1.shoulder.writePercent(shoulder1Percent);
    leg1.elbow.writePercent(elbowPercent);
    leg1.wrist.writePercent(wristPercent); 

    leg2.shoulder.writePercent(shoulder2Percent);
    leg2.elbow.writePercent(elbowPercent);
    leg2.wrist.writePercent(wristPercent); 

    leg3.shoulder.writePercent(shoulder1Percent);
    leg3.elbow.writePercent(elbowPercent);
    leg3.wrist.writePercent(wristPercent); 

    leg4.shoulder.writePercent(shoulder2Percent);
    leg4.elbow.writePercent(elbowPercent);
    leg4.wrist.writePercent(wristPercent); 

    debugfloat("Setting servos to: ", shoulder1Percent);
    debugfloat(", ", elbowPercent);
    debugfloatln(", ", wristPercent);
  }
#endif
#if EYES
  DistanceSensorController dsc;
#endif

void setup() {
  Serial.begin(9600);
  debugln("Serial Communication Online");
  timeNow = millis();
  #if RUN_ON_SERIAL
    runOnSerialSetup(timeNow);
  #else
  #endif

  delay(1000);
}


bool firstTime = true;
void loop() {
  timeNow = long(millis()); 
    #if RUN_ON_SERIAL
      runOnSerialLoop();
    #else 
      #if JUST_EYES
        if(firstTime){
          firstTime = false;
          dsc.init();
        }
        dsc.debugSensors();
      #endif
  #endif
}
 #endif
