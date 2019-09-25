/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\brandon                                          */
/*    Created:      Sun Aug 11 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain Brain;
vex::controller con = vex::controller();
vex::motor BackRightMotor = vex::motor(vex::PORT10, vex::gearSetting::ratio6_1, true);
vex::motor BackLeftMotor = vex::motor(vex::PORT20, vex::gearSetting::ratio6_1, false);
vex::motor FrontRightMotor = vex::motor(vex::PORT1, vex::gearSetting::ratio6_1, true);
vex::motor FrontLeftMotor = vex::motor(vex::PORT11, vex::gearSetting::ratio6_1, false);
// define your global instances of motors and other devices here

#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>

void drive();
void sensorHeader();
void sensorWriter();
void Batterydata();
void controller1Data();
void BackLeftMotorData();
void FrontRightMotorData();
void BackRightMotorData();
void FrontLeftMotorData();
void BatteryHeader();
void competitionHeader();
void controller1Header();
void BackLeftMotorHeader();
void FrontRightMotorHeader();
void BackRightMotorHeader();
void FrontLeftMotorHeader();
void BatteryHeader2();
void competitionHeader2();
void controllerHeader2();
void motorHeader2();
void stopmotor();

vex::competition Competition;
std::ofstream ofs;

int main() {
  if (Brain.SDcard.isInserted()) {
    // create a file with long filename
    ofs.open("Run.csv", std::ofstream::out);
    sensorHeader();
    while (true) {

      sensorWriter();

      vex::task::sleep(10);

      drive();

      if (con.ButtonL1.pressing() == 1 && con.ButtonL2.pressing() == 1 &&
          con.ButtonR2.pressing() == 1 && con.ButtonR1.pressing() == 1) {
        break;
      }
    }

    ofs.close();
    Brain.Screen.printAt(10, 40, "done");
    stopmotor();
  } else {
    Brain.Screen.printAt(10, 40, "No SD Card");
  }
}

void drive() {
  // Set the left and right motor to spin forward using the controller Axis
  // values as the velocity value.

  FrontLeftMotor.spin(vex::directionType::fwd, con.Axis3.value(),
                      vex::velocityUnits::pct);
  BackLeftMotor.spin(vex::directionType::fwd, con.Axis3.value(),
                     vex::velocityUnits::pct);

  FrontRightMotor.spin(vex::directionType::fwd, con.Axis2.value(),
                       vex::velocityUnits::pct);
  BackRightMotor.spin(vex::directionType::fwd, con.Axis2.value(),
                      vex::velocityUnits::pct);
  // Right Joystick Y value / 2.
}

void sensorHeader() {
  ofs << "time (msec),";
  BatteryHeader();
  controller1Header();
  BackLeftMotorHeader();
  FrontRightMotorHeader();
  BackRightMotorHeader();
  FrontLeftMotorHeader();
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
  controller1Data();
  BackLeftMotorData();
  FrontRightMotorData();
  BackRightMotorData();
  FrontLeftMotorData();
  ofs << "\n";
}

void Batterydata() {
  ofs << Brain.Battery.capacity(vex::percentUnits::pct) << ","
      << Brain.Battery.temperature(vex::temperatureUnits::fahrenheit) << ",";
}

void competitionDate() {
  ofs << Competition.isAutonomous() << "," << Competition.isDriverControl()
      << Competition.isCompetitionSwitch() << ","
      << Competition.isFieldControl() << Competition.isEnabled() << ",";
}

void controller1Data() {
  ofs << con.Axis1.position() << "," << con.Axis1.value() << ","
      << con.Axis2.position() << "," << con.Axis2.value() << ","
      << con.Axis3.position() << "," << con.Axis3.value() << ","
      << con.Axis4.position() << "," << con.Axis4.value() << ","
      << con.ButtonA.pressing() << "," << con.ButtonB.pressing() << ","
      << con.ButtonX.pressing() << "," << con.ButtonY.pressing() << ","
      << con.ButtonUp.pressing() << "," << con.ButtonDown.pressing() << ","
      << con.ButtonLeft.pressing() << "," << con.ButtonRight.pressing() << ","
      << con.ButtonL1.pressing() << "," << con.ButtonL2.pressing() << ","
      << con.ButtonR1.pressing() << "," << con.ButtonR2.pressing();
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

void BatteryHeader2() { ofs << "capacity,temperature,"; }

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
void controller1Header() { ofs << "Controller1,,,,,,,,,,,,,,,,,,,,"; }
void BackLeftMotorHeader() { ofs << "BackLeftMotor,,,,,,,,,,,,,"; }
void FrontRightMotorHeader() { ofs << "FrontRightMotor,,,,,,,,,,,,,"; }
void BackRightMotorHeader() { ofs << "BackRightMotor,,,,,,,,,,,,,"; }
void FrontLeftMotorHeader() { ofs << "FrontLeftMotor,,,,,,,,,,,,,"; }

void stopmotor() {
  BackLeftMotor.stop();
  FrontRightMotor.stop();
  BackRightMotor.stop();
  FrontLeftMotor.stop();
}