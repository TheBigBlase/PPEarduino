#include <Stepper.h>
#include "ControlStepper.h"

int out1 = 8;
int out2 = 9;
int enA  = 3;  // Enable pin 1 on Motor Control Shield  
int enB  = 11;  // Enable pin 2 on Motor Control Shield  
int dirA = 12;  // Direction pin dirA on Motor Control Shield
int dirB = 13;  // Direction pin dirB on Motor Control Shield
 
 
const int stepsPerRevolution = 360;  // change this to fit the number of steps per revolution
                                     // for your motor
 
// Initialize the stepper library on pins 8, 9, 12, 13:
Stepper stepperMotor(stepsPerRevolution, out1, dirA, out2, dirB);            
 
void setup() {
  // Set speed to 60 rpm:
 
  // Enable IC3 outputs.
  pinMode(enA, OUTPUT);
  digitalWrite (enA, HIGH);
  pinMode(enB, OUTPUT);
  digitalWrite (enB, HIGH);
}

void loop() {
  // Step five revolutions into one direction:
  ControlStepper(stepperMotor, -500,20,200);
  ControlStepper(stepperMotor, 500,20,200);
 
  // Step five revolutions in the other direction:

}
