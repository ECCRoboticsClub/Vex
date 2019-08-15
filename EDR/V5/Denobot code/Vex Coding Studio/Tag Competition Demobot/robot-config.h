vex::brain Brain;
vex::controller Controller1 = vex::controller();
vex::motor BackRightMotor = vex::motor(vex::PORT16,vex::gearSetting::ratio6_1,false);
vex::motor BackLeftMotor = vex::motor(vex::PORT15,vex::gearSetting::ratio6_1,false);
vex::motor FrontRightMotor = vex::motor(vex::PORT6,vex::gearSetting::ratio6_1,true);
vex::motor FrontLeftMotor = vex::motor(vex::PORT5,vex::gearSetting::ratio6_1,false);
vex::bumper FrontBumper = vex::bumper(Brain.ThreeWirePort.A);
vex::bumper BackBumper = vex::bumper(Brain.ThreeWirePort.B);