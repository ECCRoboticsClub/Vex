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
vex::motor motor1(vex::PORT1, vex::gearSetting::ratio18_1, true);
vex::motor motor2(vex::PORT2, vex::gearSetting::ratio18_1, true);
vex::controller con(vex::controllerType::primary);
// define your global instances of motors and other devices here

#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>

std::ofstream ofs;

int main() {
  if (Brain.SDcard.isInserted()) {
    // create a file with long filename
    ofs.open("Run.csv", std::ofstream::out);
    ofs << ofs
        << "time "
           "(msec),battery,,controller1,,,,,,,,,,,,,,,,,,,,motor1,,,,,,,,,,,,,"
           "motor2,,,,,,,,,,,,\r\n";
    ofs << "senors,capacity,temperature,Axis1 (position),Axis1 (value),Axis2 "
           "(position),Axis2 (value),Axis3 (position),Axis3 (value),Axis4 "
           "(position),Axis4 "
           "(value),ButtonA,ButtonB,ButtonX,ButtonY,ButtonUp,ButtonDown,"
           "ButtonLeft,ButtonRight,ButtonL1,ButtonL2,ButtonR1,ButtonR2,"
           "efficiency (percent),velocity (rpm),velocity (degrees per "
           "second),velocity (percent),rotation (degrees),rotation "
           "(rev),rotation (raw),torque (Nm),torque (InLb),current (amp),power "
           "(watt),temperature (fahrenheit),temperature (percent),efficiency "
           "(percent),velocity (rpm),velocity (degrees per second),velocity "
           "(percent),rotation (degrees),rotation (rev),rotation (raw),torque "
           "(Nm),torque (InLb),current (amp),power (watt),temperature "
           "(fahrenheit),temperature (percent)\r\n";
    while (true) {
      ofs << Brain.timer(vex::timeUnits::msec) << ","
          << Brain.Battery.capacity(vex::percentUnits::pct) << ","
          << Brain.Battery.temperature(vex::temperatureUnits::fahrenheit) << ","
          << con.Axis1.position() << "," << con.Axis1.value() << ","
          << con.Axis2.position() << "," << con.Axis2.value() << ","
          << con.Axis3.position() << "," << con.Axis3.value() << ","
          << con.Axis4.position() << "," << con.Axis4.value() << ","
          << con.ButtonA.pressing() << "," << con.ButtonB.pressing() << ","
          << con.ButtonX.pressing() << "," << con.ButtonY.pressing() << ","
          << con.ButtonUp.pressing() << "," << con.ButtonDown.pressing() << ","
          << con.ButtonLeft.pressing() << "," << con.ButtonRight.pressing()
          << "," << con.ButtonL1.pressing() << "," << con.ButtonL2.pressing()
          << "," << con.ButtonR1.pressing() << "," << con.ButtonR2.pressing()
          << "," << motor1.efficiency(vex::percentUnits::pct) << ","
          << motor1.velocity(vex::velocityUnits::rpm) << ","
          << motor1.velocity(vex::velocityUnits::dps) << ","
          << motor1.velocity(vex::velocityUnits::pct) << ","
          << motor1.rotation(vex::rotationUnits::deg) << ","
          << motor1.rotation(vex::rotationUnits::rev) << ","
          << motor1.rotation(vex::rotationUnits::raw) << ","
          << motor1.torque(vex::torqueUnits::Nm) << ","
          << motor1.torque(vex::torqueUnits::InLb) << ","
          << motor1.current(vex::currentUnits::amp) << ","
          << motor1.power(vex::powerUnits::watt) << ","
          << motor1.temperature(vex::temperatureUnits::fahrenheit) << ","
          << motor1.temperature(vex::percentUnits::pct) << ","
          << motor2.efficiency(vex::percentUnits::pct) << ","
          << motor2.velocity(vex::velocityUnits::rpm) << ","
          << motor2.velocity(vex::velocityUnits::dps) << ","
          << motor2.velocity(vex::velocityUnits::pct) << ","
          << motor2.rotation(vex::rotationUnits::deg) << ","
          << motor2.rotation(vex::rotationUnits::rev) << ","
          << motor2.rotation(vex::rotationUnits::raw) << ","
          << motor2.torque(vex::torqueUnits::Nm) << ","
          << motor2.torque(vex::torqueUnits::InLb) << ","
          << motor2.current(vex::currentUnits::amp) << ","
          << motor2.power(vex::powerUnits::watt) << ","
          << motor2.temperature(vex::temperatureUnits::fahrenheit) << ","
          << motor2.temperature(vex::percentUnits::pct) << "\n";
      vex::task::sleep(10);

      motor1.spin(vex::directionType::fwd, con.Axis3.value(),
                  vex::velocityUnits::pct);
      motor2.spin(vex::directionType::fwd, con.Axis2.value(),
                  vex::velocityUnits::pct);

      if (con.ButtonB.pressing() == 1 && con.ButtonX.pressing() == 1 &&
          con.ButtonUp.pressing() == 1 && con.ButtonDown.pressing() == 1 &&
          con.ButtonL1.pressing() == 1 && con.ButtonL2.pressing() == 1 &&
          con.ButtonR2.pressing() == 1 && con.ButtonR1.pressing() == 1) {
        break;
      }
    }

    ofs.close();
    Brain.Screen.printAt(10, 40, "done");
    motor1.stop();
    motor2.stop();
  } else {
    Brain.Screen.printAt(10, 40, "No SD Card");
  }
}