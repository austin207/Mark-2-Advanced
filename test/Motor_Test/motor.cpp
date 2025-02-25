#include <Arduino.h>
#include "PinDef.h"
#include "Motor.h"

Motor motor;
int count = 5000;
void Test(){
    motor.enable();
    motor.forward(100);
    delay(5000);
    motor.disable();
    delay(1000);
    motor.left(100);
    delay(2500);
    motor.right(100);
    delay(2500);
    motor.backward(100);
    delay(1000);
    motor.brake();
    delay(500);
}