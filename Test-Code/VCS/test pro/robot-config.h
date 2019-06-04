vex::brain Brain;
vex::motor frontLeftMotor = vex::motor(vex::PORT20,vex::gearSetting::ratio18_1,false); // was motor1
vex::motor backRightMotor = vex::motor(vex::PORT1,vex::gearSetting::ratio18_1,true);// was motor2
vex::motor backLeftMotor = vex::motor(vex::PORT10,vex::gearSetting::ratio18_1,false);// was motor3
vex::motor backCenterMotor = vex::motor(vex::PORT9,vex::gearSetting::ratio36_1,true);// was motor4
vex::motor frontRightMotor = vex::motor(vex::PORT11,vex::gearSetting::ratio18_1,true);// was motor5
vex::controller Controller = vex::controller();
vex::gyro Gyro = vex::gyro(Brain.ThreeWirePort.H);
vex::vision::signature SIG_1 (1, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_2 (2, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_3 (3, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_4 (4, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_5 (5, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_6 (6, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_7 (7, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision Vision1 (vex::PORT14, 50, SIG_1, SIG_2, SIG_3, SIG_4, SIG_5, SIG_6, SIG_7);
vex::vision Vision2 (vex::PORT15, 50, SIG_1, SIG_2, SIG_3, SIG_4, SIG_5, SIG_6, SIG_7);