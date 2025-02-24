#ifndef PINDEF_H
#define PINDEF_H

#include <Arduino.h>

class PinDef {
public:
    static const int ENA = 25; //
    static const int ENB = 26;
    static const int IN1 = 27; //A4
    static const int IN2 = 14; //A3
    static const int IN3 = 12; //A2
    static const int IN4 = 13; //A1
    static const int readyLED = 2;
    
    static void setupPins();
};

#endif // PINDEF_H
