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
vex::motor motor1(vex::PORT20, vex::gearSetting::ratio18_1, true);
vex::controller con(vex::controllerType::primary);
// define your global instances of motors and other devices here

#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iostream> // std::cout
#include <fstream>  // std::ifstream, std::ofstream
#include <sstream>  // std::sstream
#include <string>   // std::string
#include <ctime>    // std::strftime, std::localtime, std::time
#include <array>    // std::array<T>

using std::stringstream;
using std::ifstream;
using std::ofstream;
using std::cout;

using std::localtime;
using std::strftime;
using std::time;

using std::string;
using std::array;


bool fexists(const char *filename) {
  std::ifstream ifile(filename);
  return (bool)ifile;
}
std::ofstream ofs;

int main() {
  int i = 1;
  bool nameTest = true;
  if (Brain.SDcard.isInserted()) {

    stringstream s;
        s << "run (" << i << ").csv";
        const string filename = s.str();
        ofstream ofs(filename);

    while (nameTest == true) {

      if (fexists(s.str())) {
        i++;
      }

      else {
        nameTest = false;
      }
    }
    // create a file with long filename
    ofs.open("Run3.csv", std::ofstream::out);
    ofs << "time,battery,,motor1,,,,,,,,\r\n";
    ofs << "senors,capacity,temperature,Position,Velocity "
           "(calculated),Current,Voltage,Power,Torque (calculated),Efficiency "
           "(calculated)\r\n";
    for (int i = 1; i <= 6; i++) {
      ofs << Brain.timer(msec) << "," << Brain.Battery.capacity() << ","
          << Brain.Battery.temperature() << "," << i + 8 << "," << i * 3 << ","
          << i * i << "," << i + 1 << "," << i * i * i << "," << i << ","
          << i - 5 << "\n";
      vex::task::sleep(1);
    }
    ofs.close();
    Brain.Screen.printAt(10, 40, "done");
  }

  else {
    Brain.Screen.printAt(10, 40, "No SD Card");
  }
}