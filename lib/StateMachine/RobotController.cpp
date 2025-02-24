#include "RobotController.h"
#include "BluetoothCommand.h" 
#include <Arduino.h>
#include "PinDef.h"

RobotController::RobotController()
  : currentState(WAIT_FOR_START)
{
}

void RobotController::setup() {
    Serial.begin(115200);
    bluetooth.initialize("MARK-2 BT");
    PinDef::setupPins();

    // Initialize the ready LED pin.
    pinMode(PinDef::readyLED, OUTPUT);
    digitalWrite(PinDef::readyLED, LOW);

    motor.enable();
}

void RobotController::update() {
    // Manage the ready LED:
    // - If Bluetooth is connected, keep the LED on.
    // - Otherwise, blink the LED every 500ms.
    if (bluetooth.isConnected()) {
        digitalWrite(PinDef::readyLED, HIGH);
    } else {
        static unsigned long previousMillis = 0;
        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= 500) {
            previousMillis = currentMillis;
            // Toggle LED state
            digitalWrite(PinDef::readyLED, !digitalRead(PinDef::readyLED));
        }
    }
    
    // Retrieve any new command from Bluetooth
    String appCommand = bluetooth.receiveCommand();
    
    // Process command if available
    if (appCommand.length() > 0) {
        Serial.print("Received command: ");
        Serial.println(appCommand);
        
        if (appCommand == CMD_FORWARD) {
            currentState = MOVE_FORWARD;
        } else if (appCommand == CMD_BACKWARD) {
            currentState = MOVE_BACKWARD;
        } else if (appCommand == CMD_LEFT) {
            currentState = MOVE_LEFT;
        } else if (appCommand == CMD_RIGHT) {
            currentState = MOVE_RIGHT;
        } else if (appCommand == CMD_STOP) {
            currentState = STOP;
        }
    }
    
    // Execute motor actions based on the current state
    switch (currentState) {
        case WAIT_FOR_START:
            bluetooth.getSerial().println("Waiting for start command...");
            // Remain idle until a command is received.
            break;
            
        case MOVE_FORWARD:
            // Both motors run forward (adjust the speed value as needed)
            motor.left(200);
            motor.right(200);
            break;
            
        case MOVE_BACKWARD:
            // Both motors run in reverse
            motor.left(-200);
            motor.right(-200);
            break;
            
        case MOVE_LEFT:
            // To turn left, reduce the left motor speed relative to the right
            motor.left(100);
            motor.right(200);
            break;
            
        case MOVE_RIGHT:
            // To turn right, reduce the right motor speed relative to the left
            motor.left(200);
            motor.right(100);
            break;
            
        case STOP:
            // Stop the motors using braking
            motor.brake();
            break;
            
        default:
            // For any unknown state, disable the motors
            motor.disable();
            break;
    }
}
