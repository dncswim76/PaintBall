#include <FrequencyTimer2.h>

#define INTERRUPTINT 0 /*digital pin 2 on arduinoMEGA*/

/*full array for the sphere*/
char fullBallArray[128][360];

/*the deg we are on, 
 * or the index of the full 
 *array*/
int currentDegNumber;

/*to calculate the frequency
 * the ball is spinning*/
unsigned long timeA, timeB;
unsigned long frequency;


void setup(){
  
  attachInterrupt(INTERRUPTINT, updateFrequency, RISING); 
  timeA = 0;
  timeB = 0;
  
  FrequencyTimer2::disable();
  FrequencyTimer2::setPeriod(200);
  FrequencyTimer2::setOnOverflow(displayFunc);

}

/*the function that will constant refresh the array to display the column*/
void displayFunc(){}
  


/*Interupt Service Routine
 * -linked with Hall effect sensor*/
void updateFrequency(){
  
  /*store old time*/
  timeA = timeB;
  /*number of milliseconds since the program started*/
  timeB = millis();
  /*calculate frequence in milliseconds*/
  frequency = (timeB - timeA)/360;
  currentDegNumber = 0;  
  
}

void loop(){

  /* step to the next degree*/  
  currentDegNumber++;
  
  /*delay in milliseconds*/
  delay(frequency);

}

