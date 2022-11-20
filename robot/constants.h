/*
This file contains project wide constants and definitions.
*/
#ifndef CONSTANTS
    #define CONSTANTS

    #include <Arduino.h>
    #include <Servo.h>

    //Pinout numbers
    #define LEG_A1 10
    #define LEG_A2 2
    #define LEG_A3 3

    #define LEG_B1 11
    #define LEG_B2 4
    #define LEG_B3 5

    #define LEG_C1 12
    #define LEG_C2 6
    #define LEG_C3 7

    #define LEG_D1 13
    #define LEG_D2 8
    #define LEG_D3 9

    #define TRIG_PIN A1
    #define ECHO_1 -1//A2
    #define ECHO_2 -1//A3
    #define ECHO_3 -1//A4
    #define ECHO_4 -1//A5

    //Length of each segment(cm)
    #define L1 4.0
    #define L2 6.0
    #define L3 14.5

    #define sensorOffset 6

    #define PERIOD 1.3    //seconds

    //Toggle stuff
    #define EYES 1
    #define RUN_ON_SERIAL 1
    #define JUST_EYES 0

    //Toggle the debug print statements. Turning it off can make the robot run smoothly.
    #define DEBUG_ALL 1

    #if DEBUG_ALL
      #include <stdio.h>
      #define debug(string) Serial.print(string)
      #define debugln(string) Serial.println(string)
      #define debugfloat(string,flt) Serial.print(string);Serial.print(flt)
      #define debugfloatln(string,flt) Serial.print(string);Serial.println(flt)
    #else
        #define debug(x)
        #define debugln(x)
        #define debugfloat(string,flt)
        #define debugfloatln(string,flt)
    #endif

#endif
