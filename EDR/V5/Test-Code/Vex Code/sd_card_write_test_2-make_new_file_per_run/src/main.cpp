/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\brandon                                          */
/*    Created:      Sun Aug 11 2019                                           */
/*    Description:  sd_card_write_test_2-make new file per run                                             */
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
#include <sstream>
#include <iomanip>
#include <fstream>
#include <string>   
using namespace std; 
std::ofstream ofs;
bool fexists(const char *filename);

int main() {
	int counter = 1; 
    if( Brain.SDcard.isInserted() ) {
      // create a file with long filename
	  std::string filemw = "run(";
	  string nm = filemw + to_string(counter) + ").csv";
	  if (fexists(nm)){
	  counter++;
	  }
	  else {
		  Brain.Screen.printAt(10, 40, nm);
      ofs.open(nm, std::ofstream::out);
      ofs << "time,battery,,motor1,,,,,,,,\r\n";
      ofs << "senors,capacity,temperature,Position,Velocity (calculated),Current,Voltage,Power,Torque (calculated),Efficiency (calculated)\r\n";
      ofs.close();

      }
    }
    else {
      Brain.Screen.printAt(10, 40, "No SD Card");        
    }
}

bool fexists(const char *filename) {
  std::ifstream ifile(filename);
  return (bool)ifile;
}