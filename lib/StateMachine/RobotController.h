#ifndef ROBOTCONTROLLER_H
#define ROBOTCONTROLLER_H

#include <Arduino.h>
#include "PinDef.h"
#include "Motor.h"
#include "BluetoothHandler.h"
#include "BluetoothCommand.h"

enum SystemState {
    WAIT_FOR_START,
    MOVE_FORWARD,
    MOVE_BACKWARD,
    MOVE_LEFT,
    MOVE_RIGHT,
    STOP,
};

class RobotController {
public:
    RobotController();
    void setup();
    void update();
private:
    Motor motor;
    BluetoothHandler bluetooth;
    SystemState currentState;
};

#endif // ROBOTCONTROLLER_H
