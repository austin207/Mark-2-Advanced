#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>
#include "PinDef.h"

class Motor {
public:
    Motor();
    // (Re)initialize motor pins and set motors to a known state.
    void enable();
    // Disable motors (stop and set outputs low).
    void disable();
    // Control the left motor: positive pwm for one direction, negative for the opposite.
    void left(int pwm);
    // Control the right motor: positive pwm for one direction, negative for the opposite.
    void right(int pwm);
    // Brake the motors (active braking by shorting the motor terminals).
    void brake();
};

#endif // MOTOR_H
