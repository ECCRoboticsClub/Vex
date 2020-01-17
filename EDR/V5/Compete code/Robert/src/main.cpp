/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       El Camino College Robotics                                */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Robert        FORKLIFT                   

// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <algorithm>
#include <cmath>
using namespace vex;


vex::motor LM1 = vex::motor(vex::PORT20,false);
vex::motor LM2 = vex::motor(vex::PORT10,false);
vex::motor RM1 = vex::motor(vex::PORT12,true);
vex::motor RM2 = vex::motor(vex::PORT1,true);
 
vex::controller Controller2 = vex::controller();
 
vex::motor Elevator = vex::motor(vex::PORT2,true);
vex::motor Pivot = vex::motor(vex::PORT3,true);
vex::motor Claw = vex::motor(vex::PORT4,true);

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................





}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

      //drivetrain
 LM2.spin(vex::directionType::fwd, Controller2.Axis2.value() + Controller2.Axis4.value() - Controller2.Axis1.value(), vex::velocityUnits::pct);
     LM1.spin(vex::directionType::fwd, Controller2.Axis2.value() + Controller2.Axis4.value() + Controller2.Axis1.value(), vex::velocityUnits::pct);
     RM2.spin(vex::directionType::fwd, Controller2.Axis2.value() - Controller2.Axis4.value() + Controller2.Axis1.value(), vex::velocityUnits::pct);
     RM1.spin(vex::directionType::fwd, Controller2.Axis2.value() - Controller2.Axis4.value() - Controller2.Axis1.value(), vex::velocityUnits::pct);
 int speed = 100;
 int slow=15;
 //lift
 if(Controller2.ButtonL2.pressing()){
   Elevator.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
 }
 else if(Controller2.ButtonL1.pressing()){
   Elevator.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
 }
 else{
   Elevator.stop(vex::brakeType::hold);
 }
   
 
 //pivot code
  if(Controller2.ButtonR1.pressing()){
   Pivot.spin(vex::directionType::fwd,slow,vex::velocityUnits::pct);
 }
  else if(Controller2.ButtonR2.pressing()){
   Pivot.spin(vex::directionType::rev,slow,vex::velocityUnits::pct);
 }
  else{
   Pivot.stop(vex::brakeType::hold);
 }

 //claw code
if(Controller2.ButtonLeft.pressing()){
     Claw.spin(vex::directionType::fwd,speed,vex::velocityUnits::pct);
 }
 else if(Controller2.ButtonRight.pressing()){
   Claw.spin(vex::directionType::rev,speed,vex::velocityUnits::pct);
 }
 else{
   Claw.stop(vex::brakeType::hold);
 }

 
   vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources.
 }
 vexcodeInit();
 }

//     wait(20, msec); // Sleep the task for a short amount of time to
//                     // prevent wasted resources.
//   }
// }

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
