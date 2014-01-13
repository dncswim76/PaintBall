#include <FrequencyTimer2.h>

#define INTERRUPTINT (0) /*digital pin 2 on arduinoMEGA*/
#define PRECISION (360)

/*full array for the sphere*/
char fullBallArray[360][16];

/*the deg we are on, 
 * or the index of the full 
 *array*/
int currentDegNumber;

/*to calculate the frequency
 * the ball is spinning*/
unsigned long timeA, timeB;
unsigned long frequency;

/*temporary pin values (to be changed later*/
char rowPins[8] = {0, 1, 2, 3, 4, 5, 6, 7};
char colPins[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

void setup(){
  
  attachInterrupt(INTERRUPTINT, updateFrequency, RISING); 
  timeA = 0;
  timeB = 0;
  
  FrequencyTimer2::disable();
  FrequencyTimer2::setPeriod(200);
  FrequencyTimer2::setOnOverflow(displayFunc);

}

/*the function that will constant refresh the array to display the column*/
void displayFunc(){

  /*loop through the column*/
  for (int i = 0; i < 8; i ++){
      digitalWrite(rowPins[i], HIGH);
     for (int j = 0; j < 16; j++){
       /*not so sure on these bitwise operators .... but we'll see*/
       digitalWrite(colPins[j], (fullBallArray[currentDegNumber][2*i+j/8]>>(j%8))&1);
     }
     digitalWrite(rowPins[i], LOW);
  }
  
}
  


/*Interupt Service Routine
 * -linked with Hall effect sensor*/
void updateFrequency(){
  
  /*store old time*/
  timeA = timeB;
  /*number of milliseconds since the program started*/
  timeB = millis();
  /*calculate frequence in milliseconds*/
  frequency = (timeB - timeA)/PRECISION;
  /*restart the display to 0*/
  currentDegNumber = 0;  
  
}

void loop(){

  /* step to the next degree*/  
  currentDegNumber++;
  
  /*delay in milliseconds*/
  delay(frequency);

}

