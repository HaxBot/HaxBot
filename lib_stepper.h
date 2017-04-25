#include <AccelStepper.h>
#define HALFSTEP 8

// motor pins for left motor
#define defaultMotorPin1  4     // IN1 on the ULN2003 driver 1
#define defaultMotorPin2  5     // IN2 on the ULN2003 driver 1
#define defaultMotorPin3  6     // IN3 on the ULN2003 driver 1
#define defaultMotorPin4  7     // IN4 on the ULN2003 driver 1

// motor pins for right motor
#define defaultMotorPin5  8     // IN1 on the ULN2003 driver 2
#define defaultMotorPin6  9     // IN2 on the ULN2003 driver 2
#define defaultMotorPin7  10    // IN3 on the ULN2003 driver 2
#define defaultMotorPin8  11    // IN4 on the ULN2003 driver 2


// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
//AccelStepper STEPPER1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
AccelStepper STEPPER1;
AccelStepper STEPPER2;


// variables
int stepperSpeed = 1000; //speed of the stepper (steps per second)
int stepperMaxSpeed = 2000; //speed of the stepper (steps per second)
int STEPS1 = 0; // keep track of the step count for motor 1
int STEPS2 = 0; // keep track of the step count for motor 2


/*
 * methods
 */

 void setupStepper(int motorPins[]) {
  short motorPin1 = motorPins[0];
  short motorPin2 = motorPins[1];
  short motorPin3 = motorPins[2];
  short motorPin4 = motorPins[3];
  short motorPin5 = motorPins[4];
  short motorPin6 = motorPins[5];
  short motorPin7 = motorPins[6];
  short motorPin8 = motorPins[7];
  
  STEPPER1 = AccelStepper(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
  STEPPER2 = AccelStepper(HALFSTEP, motorPin5, motorPin7, motorPin6, motorPin8);

  delay(1000);
  
  STEPPER1.setMaxSpeed(stepperMaxSpeed);
  STEPPER1.move(1);  // I found this necessary
  STEPPER1.setSpeed(stepperSpeed);

  STEPPER2.setMaxSpeed(stepperMaxSpeed);
  STEPPER2.move(-1);  // I found this necessary
  STEPPER2.setSpeed(stepperSpeed);
}

void setupStepperDefault() {
  STEPPER1 = AccelStepper(HALFSTEP, defaultMotorPin1, defaultMotorPin3, defaultMotorPin2, defaultMotorPin4);
  STEPPER2 = AccelStepper(HALFSTEP, defaultMotorPin5, defaultMotorPin7, defaultMotorPin6, defaultMotorPin8);

  delay(1000);
  
  STEPPER1.setMaxSpeed(stepperMaxSpeed);
  STEPPER1.move(1);  // I found this necessary
  STEPPER1.setSpeed(stepperSpeed);

  STEPPER2.setMaxSpeed(stepperMaxSpeed);
  STEPPER2.move(-1);  // I found this necessary
  STEPPER2.setSpeed(stepperSpeed);
}


void isMoveDone() {

}





void executeMove() {
  STEPS1 = STEPPER1.distanceToGo();
  STEPS2 = STEPPER2.distanceToGo();
  
  STEPPER1.runSpeedToPosition();
  STEPPER2.runSpeedToPosition();

  // Serial.print("steps needed: ");
  // Serial.println(STEPS1);
}



void moveStepper1(int distance) {
  if (STEPS1 == 0) {
    int target = distance;
    STEPPER1.move(target);
    STEPPER1.setSpeed(stepperSpeed);
  }
}

void moveStepper2(int distance) {
  if (STEPS2 == 0) {
    int target = distance;
    STEPPER2.move(target);
    STEPPER2.setSpeed(stepperSpeed);
  }
}

void moveForward(int distance) {
  moveStepper1(distance);
  moveStepper2(-distance);
  executeMove();
}


void moveBackward(int distance) {
  moveStepper1(-distance);
  moveStepper2(distance);
  executeMove();
}

void turnLeft(int distance) {
  moveStepper1(distance);
  moveStepper2(distance);
  executeMove();
}

void turnRight(int distance) {
  moveStepper1(-distance);
  moveStepper2(-distance);
  executeMove();
}
