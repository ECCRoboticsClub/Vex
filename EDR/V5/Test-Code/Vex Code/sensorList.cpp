

void statin()
{
  bool motorstat;
	int batteryCapacity;
	double timeMark, batteryTemperature, motorRotation, motorVelocity, motorCurrent, motorPower;
	double motorTorque, motorEfficiency, motorTemperature;

	motorVelocity = motor1.velocity(vex::velocityUnits::rpm);
	motorRotation = motor1.rotation(vex::rotationUnits::deg);
	motorCurrent = motor1.current(vex::currentUnits::amp);
	motorPower = motor1.power(vex::powerUnits::watt);
	motorTorque = motor1.torque(vex::torqueUnits::Nm);
	motorEfficiency = motor1.efficiency(vex::percentUnits::pct);
	motorTemperature = motor1.temperature(vex::percentUnits::pct);
	motorstat = motor1.isSpinning(); //bool


	batteryTemperature = Brain.Battery.temperature();
	batteryCapacity = Brain.Battery.capacity();
	timeMark = Brain.timer(msec);

	//bool
	Competition.isCompetitionSwitch();
	Competition.isFieldControl();
	Competition.isEnabled();
	Competition.isAutonomous();
	Competition.isDriverControl();

	con.Axis3.position(percentUnits::pct); //int
	con.ButtonY.pressing();//bool

	//int
	Gyro1.value(rotationUnits::deg);
	Gyro1.value(percentUnits::pct);
	Gyro1.value(analogUnits::mV);

	//int
	Light1.value(percentUnits::pct);
	Light1.value(analogUnits::mV);

	Limit1.pressing(); //bool

	//int
	Line1.value(percentUnits::pct);
	Line1.value(analogUnits::mV);

	//int
	Pot1.value(rotationUnits::deg);
	Pot1.value(percentUnits::pct);
	Pot1.value(analogUnits::mV);

	//double
	Sonar1.distance(distanceUnits::mm);
	Sonar1.distance(distanceUnits::in);
	Sonar1.distance(distanceUnits::cm);


}