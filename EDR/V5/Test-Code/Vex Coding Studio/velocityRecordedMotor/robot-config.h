#include <list>
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace vex;

vex::brain      Brain;
vex::motor      motor1(vex::PORT1, vex::gearSetting::ratio18_1, false);
vex::motor      motor10(vex::PORT10, vex::gearSetting::ratio18_1, true);
vex::controller con(vex::controllerType::primary);
