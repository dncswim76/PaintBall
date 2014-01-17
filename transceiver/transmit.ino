/*
 * Code for the transmitter.
 * Receives data through usb connection.
 * Transmits to other arduino.
 * Packets of size 18 bytes.
 *
 */

#include "Nrf2401.h"

Nrf2401 Radio;

void setup(void){
    Serial.begin(9600);

    Radio.remoteAddress = 1;
    Radio.txMode(18);
}

void loop(){
    if (Serial.available() > 0) {
        Serial.readBytes(Radio.data, 18);
        Radio.write();
    }
}
