vex::brain Brain;
vex::motor frontLeftMotor = vex::motor(vex::PORT5,vex::gearSetting::ratio18_1,false); 
vex::motor backRightMotor = vex::motor(vex::PORT16,vex::gearSetting::ratio18_1,true);
vex::motor backLeftMotor = vex::motor(vex::PORT15,vex::gearSetting::ratio18_1,false);
vex::motor frontRightMotor = vex::motor(vex::PORT6,vex::gearSetting::ratio18_1,true);
vex::controller Controller1 = vex::controller();
