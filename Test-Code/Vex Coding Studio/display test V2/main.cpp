#include "robot-config.h"

void display(int choice);
int screenSelect(int max);
void velocityDispaly();
void clearscreen();    
void rotationDispaly();
void currentDispaly();
void powerDispaly();
void torqueDispaly();
void efficiencyDispaly();
void temperatureDispaly();
void batteryDispaly();    

int displayInfo = 0;

int main() {
	//display(screenSelect(int max));
	screenSelect(10);
}

void display(int choice)
{
	clearscreen();

	switch(choice)
	{
	case 1:
		velocityDispaly();
		break;

	case 2:
		rotationDispaly();
		break;

	case 3:
		currentDispaly();
		break;

	case 4:
		powerDispaly();
		break;

	case 5:
		torqueDispaly();
		break;

	case 6:
		efficiencyDispaly();
		break;

	case 7:
		temperatureDispaly();
		break;

	default:
		batteryDispaly();
	}
}

//Brain.timer(vex::timeUnits::msec);

int screenSelect(int max)
{
	int rPic = 430, lPic = 50;
	if(Brain.Screen.pressing())
	{ //If the Brain is pressed...


		if (Brain.Screen.xPosition()< lPic)
		{
			if (displayInfo < 1)
				displayInfo = max;
			else
				displayInfo--;
		}
		else if (Brain.Screen.xPosition()> rPic)
		{
			if (displayInfo > max)
				displayInfo = 1;
			else
				displayInfo++;
		}
		else
		{

		}

	}
	else if (Controller1.ButtonR1.pressing())
	{
		if (displayInfo > max)
			displayInfo = 1;
		else
			displayInfo++;
	}
	else if (Controller1.ButtonL1.pressing())
	{
		if (displayInfo < 1)
			displayInfo = max;
		else
			displayInfo--;
	}
	else
	{

	}
	return displayInfo;
}

void clearscreen()
{
	Controller1.Screen.clearLine(1);
	Controller1.Screen.clearLine(2);
	Controller1.Screen.clearLine(3);
	Brain.Screen.clearLine(1,"#FF0000");
	Brain.Screen.clearLine(2,"#FF0000");
	Brain.Screen.clearLine(3,"#FF0000");
}

void velocityDispaly()
{
	Controller1.Screen.setCursor(1,1);
	Controller1.Screen.print("velocity");
	Controller1.Screen.setCursor(2,12);
	Controller1.Screen.print("RF %f rpm",FrontRightMotor.velocity(vex::velocityUnits::rpm));
	Controller1.Screen.setCursor(2,1);
	Controller1.Screen.print("LF %f rpm",FrontLeftMotor.velocity(vex::velocityUnits::rpm));
	Controller1.Screen.setCursor(3,12);
	Controller1.Screen.print("RR %f rpm",BackRightMotor.velocity(vex::velocityUnits::rpm));
	Controller1.Screen.setCursor(3,1);
	Controller1.Screen.print("LR %f rpm",BackLeftMotor.velocity(vex::velocityUnits::rpm));

	Brain.Screen.setCursor(1,1);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("velocity");
	Brain.Screen.setCursor(2,12);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("RF %f rpm",FrontRightMotor.velocity(vex::velocityUnits::rpm));
	Brain.Screen.setCursor(2,1);
	Brain.Screen.print("LF %f rpm",FrontLeftMotor.velocity(vex::velocityUnits::rpm));
	Brain.Screen.setCursor(3,12);
	Brain.Screen.print("RR %f rpm",BackRightMotor.velocity(vex::velocityUnits::rpm));
	Brain.Screen.setCursor(3,1);
	Brain.Screen.print("LR %f rpm",BackLeftMotor.velocity(vex::velocityUnits::rpm));
}

void rotationDispaly()
{
	Controller1.Screen.setCursor(1,1);
	Controller1.Screen.print("rotation");
	Controller1.Screen.setCursor(2,12);
	Controller1.Screen.print("RF %f deg",FrontRightMotor.rotation(vex::rotationUnits::deg));
	Controller1.Screen.setCursor(2,1);
	Controller1.Screen.print("LF %f deg",FrontLeftMotor.rotation(vex::rotationUnits::deg));
	Controller1.Screen.setCursor(3,12);
	Controller1.Screen.print("RR %f deg",BackRightMotor.rotation(vex::rotationUnits::deg));
	Controller1.Screen.setCursor(3,1);
	Controller1.Screen.print("LR %f deg",BackLeftMotor.rotation(vex::rotationUnits::deg));

	Brain.Screen.setCursor(1,1);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("rotation");
	Brain.Screen.setCursor(2,12);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("RF %f deg",FrontRightMotor.rotation(vex::rotationUnits::deg));
	Brain.Screen.setCursor(2,1);
	Brain.Screen.print("LF %f deg",FrontLeftMotor.rotation(vex::rotationUnits::deg));
	Brain.Screen.setCursor(3,12);
	Brain.Screen.print("RR %f deg",BackRightMotor.rotation(vex::rotationUnits::deg));
	Brain.Screen.setCursor(3,1);
	Brain.Screen.print("LR %f deg",BackLeftMotor.rotation(vex::rotationUnits::deg));
}

void currentDispaly()
{
	Controller1.Screen.setCursor(1,1);
	Controller1.Screen.print("current");
	Controller1.Screen.setCursor(2,12);
	Controller1.Screen.print("RF %f amp",FrontRightMotor.current(vex::currentUnits::amp));
	Controller1.Screen.setCursor(2,1);
	Controller1.Screen.print("LF %f amp",FrontLeftMotor.current(vex::currentUnits::amp));
	Controller1.Screen.setCursor(3,12);
	Controller1.Screen.print("RR %f amp",BackRightMotor.current(vex::currentUnits::amp));
	Controller1.Screen.setCursor(3,1);
	Controller1.Screen.print("LR %f amp",BackLeftMotor.current(vex::currentUnits::amp));

	Brain.Screen.setCursor(1,1);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("current");
	Brain.Screen.setCursor(2,12);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("RF %f amp",FrontRightMotor.current(vex::currentUnits::amp));
	Brain.Screen.setCursor(2,1);
	Brain.Screen.print("LF %f amp",FrontLeftMotor.current(vex::currentUnits::amp));
	Brain.Screen.setCursor(3,12);
	Brain.Screen.print("RR %f amp",BackRightMotor.current(vex::currentUnits::amp));
	Brain.Screen.setCursor(3,1);
	Brain.Screen.print("LR %f amp",BackLeftMotor.current(vex::currentUnits::amp));
}

void powerDispaly()
{
	Controller1.Screen.setCursor(1,1);
	Controller1.Screen.print("power");
	Controller1.Screen.setCursor(2,12);
	Controller1.Screen.print("RF %f watts",FrontRightMotor.power(vex::powerUnits::watt));
	Controller1.Screen.setCursor(2,1);
	Controller1.Screen.print("LF %f watts",FrontLeftMotor.power(vex::powerUnits::watt));
	Controller1.Screen.setCursor(3,12);
	Controller1.Screen.print("RR %f watts",BackRightMotor.power(vex::powerUnits::watt));
	Controller1.Screen.setCursor(3,1);
	Controller1.Screen.print("LR %f watts",BackLeftMotor.power(vex::powerUnits::watt));

	Brain.Screen.setCursor(1,1);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("power");
	Brain.Screen.setCursor(2,12);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("RF %f watts",FrontRightMotor.power(vex::powerUnits::watt));
	Brain.Screen.setCursor(2,1);
	Brain.Screen.print("LF %f watts",FrontLeftMotor.power(vex::powerUnits::watt));
	Brain.Screen.setCursor(3,12);
	Brain.Screen.print("RR %f watts",BackRightMotor.power(vex::powerUnits::watt));
	Brain.Screen.setCursor(3,1);
	Brain.Screen.print("LR %f watts",BackLeftMotor.power(vex::powerUnits::watt));
}

void torqueDispaly()
{
	Controller1.Screen.setCursor(1,1);
	Controller1.Screen.print("torque");
	Controller1.Screen.setCursor(2,12);
	Controller1.Screen.print("RF %f Nm",FrontRightMotor.torque(vex::torqueUnits::Nm));
	Controller1.Screen.setCursor(2,1);
	Controller1.Screen.print("LF %f Nm",FrontLeftMotor.torque(vex::torqueUnits::Nm));
	Controller1.Screen.setCursor(3,12);
	Controller1.Screen.print("RR %f Nm",BackRightMotor.torque(vex::torqueUnits::Nm));
	Controller1.Screen.setCursor(3,1);
	Controller1.Screen.print("LR %f Nm",BackLeftMotor.torque(vex::torqueUnits::Nm));

	Brain.Screen.setCursor(1,1);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("torque");
	Brain.Screen.setCursor(2,12);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("RF %f Nm",FrontRightMotor.torque(vex::torqueUnits::Nm));
	Brain.Screen.setCursor(2,1);
	Brain.Screen.print("LF %f Nm",FrontLeftMotor.torque(vex::torqueUnits::Nm));
	Brain.Screen.setCursor(3,12);
	Brain.Screen.print("RR %f Nm",BackRightMotor.torque(vex::torqueUnits::Nm));
	Brain.Screen.setCursor(3,1);
	Brain.Screen.print("LR %f Nm",BackLeftMotor.torque(vex::torqueUnits::Nm));
}

void efficiencyDispaly()
{
	Controller1.Screen.setCursor(1,1);
	Controller1.Screen.print("efficiency");
	Controller1.Screen.setCursor(2,12);
	Controller1.Screen.print("RF %f pct",FrontRightMotor.efficiency(vex::percentUnits::pct));
	Controller1.Screen.setCursor(2,1);
	Controller1.Screen.print("LF %f pct",FrontLeftMotor.efficiency(vex::percentUnits::pct));
	Controller1.Screen.setCursor(3,12);
	Controller1.Screen.print("RR %f pct",BackRightMotor.efficiency(vex::percentUnits::pct));
	Controller1.Screen.setCursor(3,1);
	Controller1.Screen.print("LR %f pct",BackLeftMotor.efficiency(vex::percentUnits::pct));

	Brain.Screen.setCursor(1,1);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("efficiency");
	Brain.Screen.setCursor(2,12);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("RF %f pct",FrontRightMotor.efficiency(vex::percentUnits::pct));
	Brain.Screen.setCursor(2,1);
	Brain.Screen.print("LF %f pct",FrontLeftMotor.efficiency(vex::percentUnits::pct));
	Brain.Screen.setCursor(3,12);
	Brain.Screen.print("RR %f pct",BackRightMotor.efficiency(vex::percentUnits::pct));
	Brain.Screen.setCursor(3,1);
	Brain.Screen.print("LR %f pct",BackLeftMotor.efficiency(vex::percentUnits::pct));
}

void temperatureDispaly()
{
	Controller1.Screen.setCursor(1,1);
	Controller1.Screen.print("temperature");
	Controller1.Screen.setCursor(2,12);
	Controller1.Screen.print("RF %f pct",FrontRightMotor.temperature(vex::percentUnits::pct));
	Controller1.Screen.setCursor(2,1);
	Controller1.Screen.print("LF %f pct",FrontLeftMotor.temperature(vex::percentUnits::pct));
	Controller1.Screen.setCursor(3,12);
	Controller1.Screen.print("RR %f pct",BackRightMotor.temperature(vex::percentUnits::pct));
	Controller1.Screen.setCursor(3,1);
	Controller1.Screen.print("LR %f pct",BackLeftMotor.temperature(vex::percentUnits::pct));

	Brain.Screen.setCursor(1,1);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("temperature");
	Brain.Screen.setCursor(2,12);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("RF %f pct",FrontRightMotor.temperature(vex::percentUnits::pct));
	Brain.Screen.setCursor(2,1);
	Brain.Screen.print("LF %f pct",FrontLeftMotor.temperature(vex::percentUnits::pct));
	Brain.Screen.setCursor(3,12);
	Brain.Screen.print("RR %f pct",BackRightMotor.temperature(vex::percentUnits::pct));
	Brain.Screen.setCursor(3,1);
	Brain.Screen.print("LR %f pct",BackLeftMotor.temperature(vex::percentUnits::pct));
}

void batteryDispaly()
{
	Controller1.Screen.setCursor(1,1);
	Controller1.Screen.print("Battery");
	Controller1.Screen.setCursor(2,1);
	Controller1.Screen.print("Temperature %f C",Brain.Battery.temperature());

	Controller1.Screen.setCursor(3,1);
	Controller1.Screen.print("Capacity %f pct",Brain.Battery.capacity());

	Brain.Screen.setCursor(1,1);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("Battery");
	Brain.Screen.setCursor(2,1);
	Brain.Screen.setPenColor("#FF0000");
	Brain.Screen.print("Temp %f C",Brain.Battery.temperature());

	Brain.Screen.setCursor(3,1);
	Brain.Screen.print("Capacity %f pct",Brain.Battery.capacity());
}
