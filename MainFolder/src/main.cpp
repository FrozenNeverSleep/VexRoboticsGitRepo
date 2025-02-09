#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define global instances of motors and other devices here
motor frontLeftMotor = motor(PORT20, ratio18_1, true);
motor frontRightMotor = motor(PORT19, ratio18_1, true);
motor backLeftMotor = motor(PORT18, ratio18_1, false);
motor backRightMotor = motor(PORT17, ratio18_1, false);
motor_group leftMotors = motor_group(frontLeftMotor, backLeftMotor);
motor_group rightMotors = motor_group(frontRightMotor, backRightMotor);

controller Controller = controller();

// usercontrol functions
void drive() {
  int rightAxis = Controller.Axis2.position();
  int leftAxis = Controller.Axis4.position();

  leftMotors.spin(forward, leftAxis + rightAxis, pct);
  rightMotors.spin(forward, leftAxis - rightAxis, pct);
}

// competition callbacks
void pre_auton() {

}

void autonomous() {

}

void usercontrol() {
  while (1) {
    drive();
    wait(20, msec);
  }
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();

  while (true) {
    wait(100, msec);
  }
}
