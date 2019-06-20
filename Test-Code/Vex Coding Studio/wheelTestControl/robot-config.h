/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++++
Mecanum Drive - Basic
- This program allows you to remotely control a robot with mecanum wheels.
- The left joystick Y-axis controls the robot's forward and backward movement.
- The left joystick X-axis controls the robot's left and right movement.
- The right joystick X-axis controls the robot's rotation.

[I/O Port]      [Name]                [Description]
Port 11        FrontRightMotor           Front Right motor
Port 1         BackRightMotor            Back Right motor
Port 20        FrontLeftMotor            Front Left motor
Port 10        BackLeftMotor             Back Left motor
----------------------------------------------------------------------------------------------------*/

vex::brain Brain;
vex::controller Controller1 = vex::controller();
vex::motor FrontRightMotor  = vex::motor(vex::PORT11,false);
vex::motor BackRightMotor = vex::motor(vex::PORT1,false);
vex::motor FrontLeftMotor = vex::motor(vex::PORT20,true);
vex::motor BackLeftMotor = vex::motor(vex::PORT10,true);