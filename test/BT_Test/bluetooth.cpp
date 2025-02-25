#include "BluetoothHandler.h"
#include <Arduino.h>

BluetoothHandler Bluetooth;
void setup(){
    Serial.begin(115200);
    Bluetooth.initialize("MARK-2 BT debug");
}

void loop(){
    String appCommand = Bluetooth.receiveCommand();

    if (Bluetooth.isConnected()) {
        Serial.println("Connected!");
    } 

    if(appCommand.length() > 0){
        Serial.println("Recieved Command: ");
        Serial.println(appCommand);
    }
}