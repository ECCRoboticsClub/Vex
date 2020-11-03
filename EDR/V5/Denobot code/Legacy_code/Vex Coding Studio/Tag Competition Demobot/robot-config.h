vex::brain Brain;
vex::controller Controller1 = vex::controller();
vex::motor RightMotor = vex::motor(vex::PORT16,vex::gearSetting::ratio18_1,false);
vex::motor LeftMotor = vex::motor(vex::PORT17,vex::gearSetting::ratio18_1,true);
vex::bumper FrontBumper = vex::bumper(Brain.ThreeWirePort.A);
vex::bumper BackBumper = vex::bumper(Brain.ThreeWirePort.B);