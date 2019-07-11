#include "robot-config.h"
#include <algorithm>
#include <cmath>


int main(void) {
	int n=1;
	int leftright = 0;
	int horizontal = 0;
	int updown = 0;
	int vertical = 0;

	while (n>0){
		//press x for mecanum drive

		while (n==1){

			LM2.spin(vex::directionType::fwd, Controller1.Axis2.value()  - Controller1.Axis1.value(), vex::velocityUnits::pct);
			LM1.spin(vex::directionType::fwd, Controller1.Axis2.value()  + Controller1.Axis1.value(), vex::velocityUnits::pct);
			RM2.spin(vex::directionType::fwd, Controller1.Axis2.value()  + Controller1.Axis1.value(), vex::velocityUnits::pct);
			RM1.spin(vex::directionType::fwd, Controller1.Axis2.value()  - Controller1.Axis1.value(), vex::velocityUnits::pct);

			if(Controller1.ButtonA.pressing()){
				n=2;
			}
			if(Controller1.ButtonX.pressing()){
				n=1;

			}
			if(Controller1.ButtonB.pressing()){
				n=3;

			}
		}
		//press a for normal drive

		while (n==2){

			LM2.spin(vex::directionType::fwd, Controller1.Axis2.value() + Controller1.Axis1.value() , vex::velocityUnits::pct);
			LM1.spin(vex::directionType::fwd, Controller1.Axis2.value() + Controller1.Axis1.value() , vex::velocityUnits::pct);
			RM2.spin(vex::directionType::fwd, Controller1.Axis2.value() - Controller1.Axis1.value() , vex::velocityUnits::pct);
			RM1.spin(vex::directionType::fwd, Controller1.Axis2.value() - Controller1.Axis1.value() , vex::velocityUnits::pct);

			if(Controller1.ButtonA.pressing()){
				n=2;
			}
			if(Controller1.ButtonX.pressing()){
				n=1;

			}
			if(Controller1.ButtonB.pressing()){
				n=3;

			}
		}
		while (n==3){
			leftright = Controller1.Axis1.position( vex::percentUnits::pct);
			horizontal = leftright * leftright * leftright * leftright * leftright /  100000000;
			updown = Controller1.Axis2.position( vex::percentUnits::pct);
			vertical = updown * updown * updown * updown * updown /  100000000;

			LM2.spin(vex::directionType::fwd, updown + leftright , vex::velocityUnits::pct);
			LM1.spin(vex::directionType::fwd, updown + leftright , vex::velocityUnits::pct);
			RM2.spin(vex::directionType::fwd, updown - leftright , vex::velocityUnits::pct);
			RM1.spin(vex::directionType::fwd, updown - leftright , vex::velocityUnits::pct);

			if(Controller1.ButtonA.pressing()){
				n=2;
			}
			if(Controller1.ButtonX.pressing()){
				n=1;

			}
			if(Controller1.ButtonB.pressing()){
				n=3;

			}
		}

	}
	vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources.
}
/*
for autonomous only
left        left 45 FWD
LM1 REV     LM2 FWD
LM2 FWD     RM1 FWD
RM1 FWD
RM2 REV

right       right 45 FWD
lm1 fwd     RM2 FWD
lm2 rev     LM1 FWD
rm1 rev
rm2 fwd
*/
