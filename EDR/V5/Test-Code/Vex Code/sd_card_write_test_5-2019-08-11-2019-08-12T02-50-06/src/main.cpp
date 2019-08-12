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

// Uncomment to simulate calling isInserted() and printAt() without a cortex.
// struct {
//         struct {
//                 bool isInserted() const { return true; }
//         } SDcard;
//         struct {
//                 void printAt(int, int, string message) {
//                     cout << message;
//                 }
//         } Screen;
// } Brain;
// Returns the current time in RFC 3339 format (YYYY-MM-DDTHH:MM:SS ZoneAbbrev).
string getCurrentTime() {
    const size_t MAX_LENGTH  = 50;
    array<char, MAX_LENGTH> buffer;
    time_t now               = time(nullptr);
    size_t charactersWritten = strftime(buffer.data(), buffer.size(), "%F %H_%M_%S %Z", localtime(&now));

    return string(buffer.data(), charactersWritten);
}
bool fexists(const char *filename) {
  std::ifstream ifile(filename);
  return (bool)ifile;
}
int getCount(){ 
int count = 1;
while (fexists(s.str().c_str())){
	
	if(fexists(s.str().c_str())){
        count++;
      }
      else {
		  return count;
	  }
 }
}
int main() {
    if (Brain.SDcard.isInserted()) {
		
        // Use a new filename for each run (unless two runs are done in the
        // same second.)
        stringstream s;
        s << "run" << getCount() << ".csv";
        const string filename = s.str();

        ofstream ofs(filename);
        if (ofs) {
            // Write the header row.
            ofs << "time,battery,,motor1,,,,,,,,,\r\n";
            ofs << "sensors,capacity,temperature,Position,Velocity (calculated),Current,Voltage,Power,Torque (calculated),Efficiency (calculated),Temperature\r\n";
            // TODO: Loop through the gathered data and write the other rows here.
            //ofs << timeMark <<"," << batteryCapacity << "," << batteryTemperature <<",," << motorVelocity << "," << motorCurrent <<",," << motorPower <<"," << motorTorque <<"," << motorEfficiency <<"," << motorTemperature;
            s.str("");
            s << "Curret file is  " << filename << "' for writing";
			Brain.Screen.printAt(10, 40, s.str().c_str());
        } 
		else {
            s.str("");
            s << "Error: Could not open " << filename << "' for writing";
            Brain.Screen.printAt(10, 40, s.str().c_str());
            
        }
    }
    else {
        Brain.Screen.printAt(10, 40, "No SD Card");
    }
}
void statin()
{
	int batteryCapacity, ;
double timeMark, batteryTemperature, motorRotation, motorVelocity, motorCurrent, motorPower;
double motorTorque, motorEfficiency, motorTemperature;

Motor.velocity(vex::velocityUnits::rpm)= motorVelocity;
Motor.rotation(vex::rotationUnits::deg)= motorRotation;
Motor.current(vex::currentUnits::amp)= motorCurrent;
Motor.power(vex::powerUnits::watt)= motorPower;
Motor.torque(vex::torqueUnits::Nm)= motorTorque;
Motor.efficiency(vex::percentUnits::pct)= motorEfficiency;
Motor.temperature(vex::percentUnits::pct)= motorTemperature;
Motor.isSpinning()  //bool


Brain.Battery.temperature()= batteryTemperature;
Brain.Battery.capacity()= batteryCapacity;
Brain.timer() = timeMark;

//bool
Competition.isCompetitionSwitch()
Competition.isFieldControl()
Competition.isEnabled()
Competition.isAutonomous()
Competition.isDriverControl()

Controller1.Axis3.position(percent) //int
Controller1.ButtonY.pressing() //bool

//int
Gyro.value(roationUnits::deg)
Gyro.value(percentUnits::pct)
Gyro.value(analogUnits::mV)

//int 
Light.value(percentUnits::pct)
Light.value(analogUnits::mV)

Limit.pressing() //bool

//int 
Line.value(percentUnits::pct)
Line.value(analogUnits::mV)

//int
pot.value(rotationUnits::deg)
pot.value(percentUnits::pct)
pot.value(analogUnits::mV)

//double
Sonar.distance(distanceUnits::mm)
Sonar.distance(distanceUnits::in)
Sonar.distance(distanceUnits::cm)

	
}