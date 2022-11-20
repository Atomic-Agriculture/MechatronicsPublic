# MechatronicsPublic
Helpful for getting started

The main code is in main.cpp

Has two modes: Running the servos off of Serial input, and testing the sensors.

The modes can be toggled from constants.h

## Sensors

The pins can be changed in constants.h.
Each sensor a moving average of its measured distance to help smooth the values.

Best way to view the data is in the "Serial Plotter" in Arduino IDE 2.0

## Servos

The pins can be changed in constants.h. Feel free to change the names of the servos, or really any of the code.
Sets the limits for each servo, and maps global angles (domain) onto the servo range. 
Global angles are nifty because then you can interpret global x, y, z positions without too much trouble.

Use the Serial Monitor to send Serial input to the Arduino, and set the servos to positions as a fraction from 0 to 1.
