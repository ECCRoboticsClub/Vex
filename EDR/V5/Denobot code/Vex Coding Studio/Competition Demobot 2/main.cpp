#include "robot-config.h"
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VCS VEX V5                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/

//Creates a competition object that allows access to Competition methods.
vex::competition   Competition;

void tankDrive(int threshold, int speed);
void arcadeDrive(int threshold, int speed);
int speedControl();
void teamColor(int flagRed);
int driveChoose();

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */ 
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton( void ) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous( void ) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol( void ) 
{
  // User control code here, inside the loop
  while (1) 
  {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo 
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to 
    // update your motors, etc.
    // ........................................................................
 int drive= 1;
 Controller1.Screen.clearLine(1);
    teamColor(1);
    while(true)
    {
     drive = driveChoose();
        while(Controller1.ButtonRight.pressing() ==0)
        {      
            if (drive == 1)
            {       
                tankDrive(0, speedControl()); 
                Controller1.Screen.setCursor(1,1);
                Controller1.Screen.print("Tank Drive");
            }
            else
            {
                arcadeDrive(0, speedControl());
                Controller1.Screen.setCursor(1,1);
                Controller1.Screen.print("Arcade Drive");
            }
        
            vex::task::sleep(50);  
        }     
    }

  }   
}

//
// Main will set up the competition functions and callbacks.
//
int main() 

{
    
    //Run the pre-autonomous function. 
    pre_auton();
    
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );

    //Prevent main from exiting with an infinite loop.                        
    while(1) 
    {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
       
}

void teamColor(int flagRed)
 {
     if( flagRed == 1 )
     {
         Brain.Screen.clearScreen(vex::color::red);
         Controller1.Screen.setCursor(2,1);
         Controller1.Screen.print("Red Bot");
     }
     else if ( flagRed == 2 )
     {
         Brain.Screen.clearScreen(vex::color::blue); 
         Controller1.Screen.setCursor(2,1);
         Controller1.Screen.print("Blue Bot");
     }
     else if ( flagRed == 3 )
     {
         Brain.Screen.clearScreen(vex::color::green); 
         Controller1.Screen.setCursor(2,1);
         Controller1.Screen.print("Green Bot");
     }
     else
     {
         Brain.Screen.clearScreen(vex::color::yellow); 
         Controller1.Screen.setCursor(2,1);
         Controller1.Screen.print("Yellow Bot");
     }
     
 }

void tankDrive(int threshold, int speed){
        //Set the left and right motor to spin forward using the controller Axis values as the velocity value.    

    if(abs(Controller1.Axis3.value()) > threshold)         // If the left joystick is greater than or less than the threshold:
    {
      FrontLeftMotor.spin(vex::directionType::fwd, Controller1.Axis3.value()/speed, vex::velocityUnits::pct);
        BackLeftMotor.spin(vex::directionType::fwd, Controller1.Axis3.value()/speed, vex::velocityUnits::pct);
             // Left Joystick Y value / speed.
    }
    else                                    // If the left joystick is within the threshold:
    {
      FrontLeftMotor.stop(vex::brakeType::brake);
        BackLeftMotor.stop(vex::brakeType::brake);
                       // Stop the left motor (cancel noise)
     }

    if(abs(Controller1.Axis2.value()) > threshold)         // If the right joystick is greater than or less than the threshold:
    {
      FrontRightMotor.spin(vex::directionType::fwd, Controller1.Axis2.value()/speed, vex::velocityUnits::pct);
        BackRightMotor.spin(vex::directionType::fwd, Controller1.Axis2.value()/speed, vex::velocityUnits::pct);
        // Right Joystick Y value / 2.
    }
    else                                    // If the right joystick is within the threshold:
    {
      FrontRightMotor.stop(vex::brakeType::brake); 
        BackRightMotor.stop(vex::brakeType::brake);             // Stop the right motor (cancel noise)
    }
}

void arcadeDrive(int threshold, int speed)
{
   FrontLeftMotor.spin(vex::directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis4.value())/speed, vex::velocityUnits::pct); //(Axis3+Axis4)/speed
        FrontRightMotor.spin(vex::directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis4.value())/speed, vex::velocityUnits::pct);//(Axis3-Axis4)/speed
     BackLeftMotor.spin(vex::directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis4.value())/speed, vex::velocityUnits::pct); //(Axis3+Axis4)/speed
        BackRightMotor.spin(vex::directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis4.value())/speed, vex::velocityUnits::pct);//(Axis3-Axis4)/speed
}

int speedControl()
{
    if (Controller1.ButtonR1.pressing())
        return 1;
    else if (Controller1.ButtonL1.pressing())
        return 4;
    else
        return 2;
}

int driveChoose()
{
    if (Controller1.ButtonX.pressing() == 1)
        return 2;
    else 
        return 1;
    
}