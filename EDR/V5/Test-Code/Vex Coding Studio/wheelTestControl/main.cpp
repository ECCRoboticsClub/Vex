#include "robot-config.h"
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VCS VEX V5                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/

//Creates a competition object that allows access to Competition methods.
vex::competition   Competition;

void Drive(int speed);
int speedControl();

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

 
    while(true)
    {
     Drive(speedControl());
        
         
           
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




void Drive(int speed)
{
   FrontRightMotor.spin(vex::directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis1.value() - Controller1.Axis4.value())/speed, vex::velocityUnits::pct);//(Axis3-Axis1-Axis4)/speed
    
   BackRightMotor.spin(vex::directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis1.value() + Controller1.Axis4.value())/speed, vex::velocityUnits::pct);//(Axis3-Axis1+Axis4)/speed
    
   FrontLeftMotor.spin(vex::directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis1.value() + Controller1.Axis4.value())/speed, vex::velocityUnits::pct); //(Axis3+Axis1+Axis4)/speed
      
   BackLeftMotor.spin(vex::directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis1.value() - Controller1.Axis4.value())/speed, vex::velocityUnits::pct); //(Axis3+Axis1-Axis4)/speed 
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