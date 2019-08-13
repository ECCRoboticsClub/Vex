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
vex::brain       Brain;
vex::motor      motor1(vex::PORT20, vex::gearSetting::ratio18_1, true);
vex::controller con(vex::controllerType::primary);
// define your global instances of motors and other devices here


#include <cstdio>
#include <iostream>
#include <iomanip>
#include <fstream>

std::ofstream ofs;

int main() {
    if( Brain.SDcard.isInserted() ) {
      // create a file with long filename
      ofs.open("Run.csv", std::ofstream::out);
      ofs << "time,battery,,motor1,,,,,,,,\r\n";
      ofs << "senors,capacity,temperature,Position,Velocity (calculated),Current,Voltage,Power,Torque (calculated),Efficiency (calculated)\r\n";
      ofs.close();

      Brain.Screen.printAt(10, 40, "done");
    }
    else {
      Brain.Screen.printAt(10, 40, "No SD Card");        
    }
}