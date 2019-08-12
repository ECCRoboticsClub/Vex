

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


