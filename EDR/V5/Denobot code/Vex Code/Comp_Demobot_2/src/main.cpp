#include "robot-config.h"
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VCS VEX V5                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// Creates a competition object that allows access to Competition methods.
vex::competition Competition;
std::ofstream ofs;

void tankDrive(int threshold, int speed);
void arcadeDrive(int threshold, int speed);
int speedControl();
void teamColor(int flagRed);
int driveChoose();
void drivecon(int drive);
void sensorHeader();
void sensorWriter();
void Batterydata();
void competitionDate();
void controller1Data();
void FrontLeftMotorData();
void BackLeftMotorData();
void FrontRightMotorData();
void BackRightMotorData();
void BatteryHeader();
void competitionHeader();
void controller1Header();
void FrontLeftMotorHeader();
void BackLeftMotorHeader();
void FrontRightMotorHeader();
void BackRightMotorHeader();
void BatteryHeader2();
void competitionHeader2();
void controllerHeader2();
void motorHeader2();
void stopmotor();
bool SDflag;
/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...

  if (Brain.SDcard.isInserted()) {
    // create a file with long filename
    ofs.open("Run.csv", std::ofstream::out);
    sensorHeader();
    SDflag = 1;
  }
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
    int drive = 1;
    Controller1.Screen.clearLine(1);
    teamColor(1);
    while (true) {
      drive = driveChoose();
      while (Controller1.ButtonRight.pressing() == 0) {

        if (SDflag == 1) {

          sensorWriter();
        }
        drivecon(drive);
        vex::task::sleep(50);
      }
    }
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main()

{

  // Run the pre-autonomous function.
  pre_auton();

  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Prevent main from exiting with an infinite loop.
  while (1) {
    vex::task::sleep(100); // Sleep the task for a short amount of time to
                           // prevent wasted resources.
  }
}

void teamColor(int flagRed) {

  if (flagRed == 1) {
    Brain.Screen.clearScreen(vex::color::red);
    Controller1.Screen.setCursor(2, 1);
    Controller1.Screen.print("Red Bot");
  } else if (flagRed == 2) {
    Brain.Screen.clearScreen(vex::color::blue);
    Controller1.Screen.setCursor(2, 1);
    Controller1.Screen.print("Blue Bot");
  } else if (flagRed == 3) {
    Brain.Screen.clearScreen(vex::color::green);
    Controller1.Screen.setCursor(2, 1);
    Controller1.Screen.print("Green Bot");
  } else {
    Brain.Screen.clearScreen(vex::color::yellow);

    Controller1.Screen.setCursor(2, 1);
    Controller1.Screen.print("Yellow Bot");
  }
  if (SDflag == 0) {
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("No SD Card");
  }
}

void tankDrive(int threshold, int speed) {
  // Set the left and right motor to spin forward using the controller Axis
  // values as the velocity value.

  if (abs(Controller1.Axis3.value()) >
      threshold) // If the left joystick is greater than or less than the
                 // threshold:
  {
    FrontLeftMotor.spin(vex::directionType::fwd,
                        Controller1.Axis3.value() / speed,
                        vex::velocityUnits::pct);
    BackLeftMotor.spin(vex::directionType::fwd,
                       Controller1.Axis3.value() / speed,
                       vex::velocityUnits::pct);
    // Left Joystick Y value / speed.
  } else // If the left joystick is within the threshold:
  {
    FrontLeftMotor.stop(vex::brakeType::brake);
    BackLeftMotor.stop(vex::brakeType::brake);
    // Stop the left motor (cancel noise)
  }

  if (abs(Controller1.Axis2.value()) >
      threshold) // If the right joystick is greater than or less than the
                 // threshold:
  {
    FrontRightMotor.spin(vex::directionType::fwd,
                         Controller1.Axis2.value() / speed,
                         vex::velocityUnits::pct);
    BackRightMotor.spin(vex::directionType::fwd,
                        Controller1.Axis2.value() / speed,
                        vex::velocityUnits::pct);
    // Right Joystick Y value / 2.
  } else // If the right joystick is within the threshold:
  {
    FrontRightMotor.stop(vex::brakeType::brake);
    BackRightMotor.stop(
        vex::brakeType::brake); // Stop the right motor (cancel noise)
  }
}

void arcadeDrive(int threshold, int speed) {
  FrontLeftMotor.spin(vex::directionType::fwd,
                      (Controller1.Axis3.value() + Controller1.Axis4.value()) /
                          speed,
                      vex::velocityUnits::pct); //(Axis3+Axis4)/speed
  FrontRightMotor.spin(vex::directionType::fwd,
                       (Controller1.Axis3.value() - Controller1.Axis4.value()) /
                           speed,
                       vex::velocityUnits::pct); //(Axis3-Axis4)/speed
  BackLeftMotor.spin(vex::directionType::fwd,
                     (Controller1.Axis3.value() + Controller1.Axis4.value()) /
                         speed,
                     vex::velocityUnits::pct); //(Axis3+Axis4)/speed
  BackRightMotor.spin(vex::directionType::fwd,
                      (Controller1.Axis3.value() - Controller1.Axis4.value()) /
                          speed,
                      vex::velocityUnits::pct); //(Axis3-Axis4)/speed
}

int speedControl() {
  if (Controller1.ButtonR1.pressing())
    return 1;
  else if (Controller1.ButtonL1.pressing())
    return 4;
  else
    return 2;
}

int driveChoose() {
  if (Controller1.ButtonX.pressing() == 1)
    return 2;
  else
    return 1;
}

void drivecon(int drive) {
  if (SDflag == 0) {
    Controller1.Screen.setCursor(3, 1);
    Controller1.Screen.print("No SD Card");
  }
  if (drive == 1) {
    tankDrive(0, speedControl());
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print("Tank Drive");
  } else {
    arcadeDrive(0, speedControl());
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print("Arcade Drive");
  }
}

void sensorHeader() {
  ofs << "time (msec),";
  BatteryHeader();
  competitionHeader();
  controller1Header();
  FrontLeftMotorHeader();
  BackLeftMotorHeader();
  FrontRightMotorHeader();
  BackRightMotorHeader();

  ofs << "\n";
  ofs << "senors,";
  BatteryHeader2();
  controllerHeader2();
  for (int n = 4; n > 0; n--) {
    motorHeader2();
  }
  ofs << "\n";
}

void sensorWriter() {

  ofs << Brain.timer(vex::timeUnits::msec) << ",";

  Batterydata();
  competitionDate();
  controller1Data();
  FrontLeftMotorData();
  BackLeftMotorData();
  FrontRightMotorData();
  BackRightMotorData();

  ofs << "\n";
}

void Batterydata() {
  ofs << Brain.Battery.capacity(vex::percentUnits::pct) << ","
      << Brain.Battery.temperature(vex::temperatureUnits::fahrenheit);
}

void competitionDate() {
  ofs << "," << Competition.isAutonomous() << "," << Competition.isDriverControl()
      << Competition.isCompetitionSwitch() << ","
      << Competition.isFieldControl() << Competition.isEnabled();
}

void controller1Data() {
  ofs << "," << Controller1.Axis1.position() << "," << Controller1.Axis1.value() << ","
      << Controller1.Axis2.position() << "," << Controller1.Axis2.value() << ","
      << Controller1.Axis3.position() << "," << Controller1.Axis3.value() << ","
      << Controller1.Axis4.position() << "," << Controller1.Axis4.value() << ","
      << Controller1.ButtonA.pressing() << "," << Controller1.ButtonB.pressing()
      << "," << Controller1.ButtonX.pressing() << ","
      << Controller1.ButtonY.pressing() << ","
      << Controller1.ButtonUp.pressing() << ","
      << Controller1.ButtonDown.pressing() << ","
      << Controller1.ButtonLeft.pressing() << ","
      << Controller1.ButtonRight.pressing() << ","
      << Controller1.ButtonL1.pressing() << ","
      << Controller1.ButtonL2.pressing() << ","
      << Controller1.ButtonR1.pressing() << ","
      << Controller1.ButtonR2.pressing();
}

void FrontLeftMotorData() {
  ofs << "," << FrontLeftMotor.efficiency(vex::percentUnits::pct) << ","
      << FrontLeftMotor.velocity(vex::velocityUnits::rpm) << ","
      << FrontLeftMotor.velocity(vex::velocityUnits::dps) << ","
      << FrontLeftMotor.velocity(vex::velocityUnits::pct) << ","
      << FrontLeftMotor.rotation(vex::rotationUnits::deg) << ","
      << FrontLeftMotor.rotation(vex::rotationUnits::rev) << ","
      << FrontLeftMotor.rotation(vex::rotationUnits::raw) << ","
      << FrontLeftMotor.torque(vex::torqueUnits::Nm) << ","
      << FrontLeftMotor.torque(vex::torqueUnits::InLb) << ","
      << FrontLeftMotor.current(vex::currentUnits::amp) << ","
      << FrontLeftMotor.power(vex::powerUnits::watt) << ","
      << FrontLeftMotor.temperature(vex::temperatureUnits::fahrenheit) << ","
      << FrontLeftMotor.temperature(vex::percentUnits::pct);
}

void BackLeftMotorData() {
  ofs << "," << BackLeftMotor.efficiency(vex::percentUnits::pct) << ","
      << BackLeftMotor.velocity(vex::velocityUnits::rpm) << ","
      << BackLeftMotor.velocity(vex::velocityUnits::dps) << ","
      << BackLeftMotor.velocity(vex::velocityUnits::pct) << ","
      << BackLeftMotor.rotation(vex::rotationUnits::deg) << ","
      << BackLeftMotor.rotation(vex::rotationUnits::rev) << ","
      << BackLeftMotor.rotation(vex::rotationUnits::raw) << ","
      << BackLeftMotor.torque(vex::torqueUnits::Nm) << ","
      << BackLeftMotor.torque(vex::torqueUnits::InLb) << ","
      << BackLeftMotor.current(vex::currentUnits::amp) << ","
      << BackLeftMotor.power(vex::powerUnits::watt) << ","
      << BackLeftMotor.temperature(vex::temperatureUnits::fahrenheit) << ","
      << BackLeftMotor.temperature(vex::percentUnits::pct);
}

void FrontRightMotorData() {
  ofs << "," << FrontRightMotor.efficiency(vex::percentUnits::pct) << ","
      << FrontRightMotor.velocity(vex::velocityUnits::rpm) << ","
      << FrontRightMotor.velocity(vex::velocityUnits::dps) << ","
      << FrontRightMotor.velocity(vex::velocityUnits::pct) << ","
      << FrontRightMotor.rotation(vex::rotationUnits::deg) << ","
      << FrontRightMotor.rotation(vex::rotationUnits::rev) << ","
      << FrontRightMotor.rotation(vex::rotationUnits::raw) << ","
      << FrontRightMotor.torque(vex::torqueUnits::Nm) << ","
      << FrontRightMotor.torque(vex::torqueUnits::InLb) << ","
      << FrontRightMotor.current(vex::currentUnits::amp) << ","
      << FrontRightMotor.power(vex::powerUnits::watt) << ","
      << FrontRightMotor.temperature(vex::temperatureUnits::fahrenheit) << ","
      << FrontRightMotor.temperature(vex::percentUnits::pct);
}

void BackRightMotorData() {
  ofs << "," << BackRightMotor.efficiency(vex::percentUnits::pct) << ","
      << BackRightMotor.velocity(vex::velocityUnits::rpm) << ","
      << BackRightMotor.velocity(vex::velocityUnits::dps) << ","
      << BackRightMotor.velocity(vex::velocityUnits::pct) << ","
      << BackRightMotor.rotation(vex::rotationUnits::deg) << ","
      << BackRightMotor.rotation(vex::rotationUnits::rev) << ","
      << BackRightMotor.rotation(vex::rotationUnits::raw) << ","
      << BackRightMotor.torque(vex::torqueUnits::Nm) << ","
      << BackRightMotor.torque(vex::torqueUnits::InLb) << ","
      << BackRightMotor.current(vex::currentUnits::amp) << ","
      << BackRightMotor.power(vex::powerUnits::watt) << ","
      << BackRightMotor.temperature(vex::temperatureUnits::fahrenheit) << ","
      << BackRightMotor.temperature(vex::percentUnits::pct);
}

void BatteryHeader2() { ofs << "capacity,temperature,"; }

void competitionHeader2() {
  ofs << "isAutonomous,isDriverControl,isCompetitionSwitch,isFieldControl,"
         "isEnabled,";
}

void controllerHeader2() {
  ofs << "Axis1 (position),Axis1 (value),Axis2 "
         "(position),Axis2 (value),Axis3 (position),Axis3 (value),Axis4 "
         "(position),Axis4 "
         "(value),ButtonA,ButtonB,ButtonX,ButtonY,ButtonUp,ButtonDown,"
         "ButtonLeft,ButtonRight,ButtonL1,ButtonL2,ButtonR1,ButtonR2,";
}

void motorHeader2() {
  ofs << "efficiency "
         "(percent),velocity (rpm),velocity (degrees per second),velocity "
         "(percent),rotation (degrees),rotation (rev),rotation (raw),torque "
         "(Nm),torque (InLb),current (amp),power (watt),temperature "
         "(fahrenheit),temperature (percent),";
}

void BatteryHeader() { ofs << "Battery,,"; }
void competitionHeader() { ofs << "Competition,,,,,"; }
void controller1Header() { ofs << "Controller1,,,,,,,,,,,,,,,,,,,,"; }

void FrontLeftMotorHeader() { ofs << "FrontLeftMotor,,,,,,,,,,,,,"; }
void BackLeftMotorHeader() { ofs << "BackLeftMotor,,,,,,,,,,,,,"; }
void FrontRightMotorHeader() { ofs << "FrontRightMotor,,,,,,,,,,,,,"; }
void BackRightMotorHeader() { ofs << "BackRightMotor,,,,,,,,,,,,,"; }

void stopmotor() {
  FrontLeftMotor.stop();
  BackLeftMotor.stop();
  FrontRightMotor.stop();
  BackRightMotor.stop();
}