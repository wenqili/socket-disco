
/*
  Stepper Motor Control - speed control

  This program drives a unipolar or bipolar stepper motor.
  The motor is attached to digital pins 8 - 11 of the Arduino.
  A potentiometer is connected to analog input 0.

  The motor will rotate in a clockwise direction. The higher the potentiometer value,
  the faster the motor speed. Because setSpeed() sets the delay between steps,
  you may notice the motor is less responsive to changes in the sensor value at
  low speeds.

  Created 30 Nov. 2009
  Modified 28 Oct 2010
  by Tom Igoe

*/

#include <Stepper.h>
int incomingByte = 0;   // for incoming serial data


const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor


// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

int stepCount = 0;  // number of steps the motor has taken

void setup() {
  // nothing to do inside the setup
  Serial.begin(9600);

}

void loop() {
  // read the sensor value:
//  int sensorValue = analogRead(A0);
  if (Serial.available() > 0) {
    // read the incoming byte:
//    incomingByte = Serial.read();
    incomingByte = Serial.parseInt();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
  }

  // map it to a range from 0 to 100:
  int motorSpeed = map(incomingByte, 0, 20, 0, 50);
  //  int motorSpeed = 60;
  // set the motor speed:
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    myStepper.step(stepsPerRevolution / 100);
  }
  delay(1);        // delay in between reads for stability

}


