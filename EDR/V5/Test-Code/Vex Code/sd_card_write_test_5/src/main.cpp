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
vex::gyro Gyro1 = vex::gyro(Brain.ThreeWirePort.B);
vex::limit Limit1 = vex::limit(Brain.ThreeWirePort.A);
vex::light Light1 = vex::light(Brain.ThreeWirePort.C);
vex::line Line1 = vex::line(Brain.ThreeWirePort.D);
vex::pot Pot1 = vex::pot(Brain.ThreeWirePort.E);
vex::sonar Sonar1 = vex::sonar(Brain.ThreeWirePort.F);
// define your global instances of motors and other devices here

// A global instance of vex::competition
vex::competition Competition;

// -*- mode: c++; compile-command: "g++ -Wall -std=c++11 -o
// test-write-csv-file-with-dates test-write-csv-file-with-dates.cpp" -*-
#include <fstream>  // std::ifstream, std::ofstream
#include <iostream> // std::cout
#include <sstream>  // std::sstream
#include <string>   // std::string
#include <vector>   // std::vector<T>

//#include <sys/types.h>
#include <dirent.h>
using std::cout;
using std::ifstream;
using std::ios;
using std::ofstream;
using std::string;
using std::stringstream;

// Uncomment to simulate calling isInserted() and printAt() without a
// cortex. struct {
//         struct {
//                 bool isInserted() const { return true; }
//         } SDcard;
//         struct {
//                 void printAt(int, int, string message) {
//                     cout << message;
//                 }
//         } Screen;
// } Brain;
// Returns the index of the next CSV in the file succession
// prefix+"0"+suffix, prefix+"1"+suffix, and so on, which is NOT already in
// use.
int getNextCsvIndex(string prefix, string suffix) {
  int highestIndex = -1;
  DIR *directory = ::opendir(".");
  if (!directory) {
    return 0;
  }
  for (::dirent *entry = ::readdir(directory); entry;
       entry = ::readdir(directory)) {
    const string currentFileName = entry->d_name;
    if (prefix == currentFileName.substr(0, prefix.length()) &&
        suffix == currentFileName.substr(currentFileName.length() -
                                         suffix.length())) {
      // cout << "\"" << currentFileName << "\" matches pattern.\n";
      // The file matches the format prefix + SOMETHING + suffix.
      // Extract the SOMETHING bit.
      string content = currentFileName.substr(
          prefix.length(),
          currentFileName.length() - prefix.length() - suffix.length());
      // Attempt to convert to an integer.
      stringstream s;
      s << content;
      int n;
      s >> n;
      if (s) {
        // Parsed successfully.
        if (n > highestIndex) {
          highestIndex = n;
        }
      } else {
        // cout << "  (\"" << content << "\" is not an integer, skipping)\n";
      }
    }
  }
  closedir(directory);
  return highestIndex + 1;
}
int main() {
  if (Brain.SDcard.isInserted()) {
    // Use a new filename for each run.
    int availableIndex = getNextCsvIndex("run-", ".csv");
    // Use a new filename for each run (unless two runs are done in the
    // same second.)
    stringstream s;
    s.flags(ios::right);
    s.fill('0');
    s.width(6);
    s << availableIndex;
    const string filename = "run" + s.str() + ".csv";
    cout << "Data will be written to " << filename << ".\n";
    ofstream ofs(filename);
    if (ofs) {

      // Write the header row.
      ofs << "time,battery,,motor1,,,,,,,,\r\n";
      ofs << "sensors,capacity,temperature,Position,Velocity "
             "(calculated),Current,Voltage,Power,Torque "
             "(calculated),Efficiency (calculated)\r\n";
      // TODO: Loop through the gathered data and write the other rows here.
      Brain.Screen.printAt(10, 40, "done\n");
    } else {
      s.str("");
      s << "Error: Could not open " << filename << "' for writing";
      Brain.Screen.printAt(10, 40, s.str().c_str());
    }
  } else {
    Brain.Screen.printAt(10, 40, "No SD Card");
  }
}

void statin() {
  bool motorstat;
  int batteryCapacity;
  double timeMark, batteryTemperature, motorRotation, motorVelocity,
      motorCurrent, motorPower;
  double motorTorque, motorEfficiency, motorTemperature;

  motorVelocity = motor1.velocity(vex::velocityUnits::rpm);
  motorRotation = motor1.rotation(vex::rotationUnits::deg);
  motorCurrent = motor1.current(vex::currentUnits::amp);
  motorPower = motor1.power(vex::powerUnits::watt);
  motorTorque = motor1.torque(vex::torqueUnits::Nm);
  motorEfficiency = motor1.efficiency(vex::percentUnits::pct);
  motorTemperature = motor1.temperature(vex::percentUnits::pct);
  motorstat = motor1.isSpinning(); // bool

  batteryTemperature = Brain.Battery.temperature();
  batteryCapacity = Brain.Battery.capacity();
  timeMark = Brain.timer(msec);

  // bool
  Competition.isCompetitionSwitch();
  Competition.isFieldControl();
  Competition.isEnabled();
  Competition.isAutonomous();
  Competition.isDriverControl();

  con.Axis3.position(percentUnits::pct); // int
  con.ButtonY.pressing();                // bool

  // int
  Gyro1.value(rotationUnits::deg);
  Gyro1.value(percentUnits::pct);
  Gyro1.value(analogUnits::mV);

  // int
  Light1.value(percentUnits::pct);
  Light1.value(analogUnits::mV);

  Limit1.pressing(); // bool

  // int
  Line1.value(percentUnits::pct);
  Line1.value(analogUnits::mV);

  // int
  Pot1.value(rotationUnits::deg);
  Pot1.value(percentUnits::pct);
  Pot1.value(analogUnits::mV);

  // double
  Sonar1.distance(distanceUnits::mm);
  Sonar1.distance(distanceUnits::in);
  Sonar1.distance(distanceUnits::cm);
}