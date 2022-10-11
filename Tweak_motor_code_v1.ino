#include <AFMotor.h>

AF_DCMotor motor(4);
AF_DCMotor lotor(3);
char userInput;

void setup() {
  Serial.begin(9600);
  Serial.println("Begin controlling Robot!"); //AF_Motor code

//turns on motor
  motor.setSpeed(200);
  lotor.setSpeed(200);

  motor.run(RELEASE);
  lotor.run(RELEASE);
}

void loop() {
  uint8_t i; //iniatlize the i variable 
 
 if(Serial.available()> 0){

    userInput = Serial.read();     //read user's input

    if(userInput == 'w'){

      Serial.print("Forward");

      motor.run(FORWARD);
      lotor.run(FORWARD);
      for (i=0; i<255; i++) {
      }

      for (i=255; i!=0; i--) {
        motor.setSpeed(i);
        lotor.setSpeed(i);
        delay(10);
        }
      }
     if(userInput == 's'){

      Serial.print("Backward");

      motor.run(BACKWARD);
      lotor.run(BACKWARD);
      for (i=0; i<255; i++) {
        motor.setSpeed(i);
        lotor.setSpeed(i);
        delay(10);
      }

      for (i=255; i!=0; i--) {
        motor.setSpeed(i);
        lotor.setSpeed(i);
        delay(10);
      }
        
      } //user input
      
    } //serial
  } //loop
