/*
 * Code for receiver arduino
 * Listens for data on radio transmission
 * Packets should be of size 18 bytes
 */


#include "Nrf2401.h"

Nrf2401 Radio;

void setup(void){
    Radio.localAddress = 1; /* device of address 1 */
    Radio.rxMode(18); /* packets of size 18 bytes */
}

void loop(void){
    while(!Radio.available());
    Radio.read();
}
