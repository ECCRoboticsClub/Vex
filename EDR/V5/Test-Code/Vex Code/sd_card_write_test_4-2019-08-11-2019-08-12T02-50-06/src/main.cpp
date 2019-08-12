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
int main() {
    if (Brain.SDcard.isInserted()) {
        // Use a new filename for each run (unless two runs are done in the
        // same second.)
        stringstream s;
        s << "run " << getCurrentTime() << ".csv";
        const string filename = s.str();
        ofstream ofs(filename);
        if (ofs) {
            // Write the header row.
            ofs << "time,battery,,motor1,,,,,,,,\r\n";
            ofs << "sensors,capacity,temperature,Position,Velocity (calculated),Current,Voltage,Power,Torque (calculated),Efficiency (calculated)\r\n";
            // TODO: Loop through the gathered data and write the other rows here.
            
            Brain.Screen.printAt(10, 40, "done");
        } else {
            s.str("");
            s << "Error: Could not open " << filename << "' for writing";
            Brain.Screen.printAt(10, 40, s.str().c_str());
            
        }
    }
    else {
        Brain.Screen.printAt(10, 40, "No SD Card");
    }
}