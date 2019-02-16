#include <Stepper.h> 

class ControlStepper{
  public:
    ControlStepper(Stepper stepperMotor, int stepNumber, int maxSpeed, int delayLenght);
  private: 
    int delayLenght;
    int stepNumber;
    int maxSpeed;
}; 
ControlStepper::ControlStepper(Stepper stepperMotor, int stepNumber, int maxSpeed, int delayLenght){
        stepperMotor.setSpeed(maxSpeed);
        stepperMotor.step(stepNumber);
        delay(delayLenght);
    }
