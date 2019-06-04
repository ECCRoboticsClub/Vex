#include "robot-config.h"
          
void tankDrive(int threshold, int speed);
void arcadeDrive(int threshold, int speed);
int speedControl();
void teamColor(int flagRed);
int driveChoose();
int main() 
{ 
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
        
            task::sleep(50);  
        }
        
    }
}

 void teamColor(int flagRed)
 {
     if( flagRed == 1 )
     {
         Brain.Screen.clearScreen(color::red);
         Controller1.Screen.setCursor(2,1);
         Controller1.Screen.print("Red Bot");
     }
     else if ( flagRed == 2 )
     {
         Brain.Screen.clearScreen(color::blue); 
         Controller1.Screen.setCursor(2,1);
         Controller1.Screen.print("Blue Bot");
     }
     else if ( flagRed == 3 )
     {
         Brain.Screen.clearScreen(color::green); 
         Controller1.Screen.setCursor(2,1);
         Controller1.Screen.print("Green Bot");
     }
     else
     {
         Brain.Screen.clearScreen(color::yellow); 
         Controller1.Screen.setCursor(2,1);
         Controller1.Screen.print("Yellow Bot");
     }
     
 }

void tankDrive(int threshold, int speed){
        //Set the left and right motor to spin forward using the controller Axis values as the velocity value.    

    if(abs(Controller1.Axis3.value()) > threshold)         // If the left joystick is greater than or less than the threshold:
    {
      LeftMotor.spin(vex::directionType::fwd, Controller1.Axis3.value()/speed, vex::velocityUnits::pct);
             // Left Joystick Y value / speed.
    }
    else                                    // If the left joystick is within the threshold:
    {
      LeftMotor.stop(vex::brakeType::brake);
                       // Stop the left motor (cancel noise)
        Brain.Screen.setFillColor(color::red);    }

    if(abs(Controller1.Axis2.value()) > threshold)         // If the right joystick is greater than or less than the threshold:
    {
      RightMotor.spin(vex::directionType::fwd, Controller1.Axis2.value()/speed, vex::velocityUnits::pct);
        // Right Joystick Y value / 2.
    }
    else                                    // If the right joystick is within the threshold:
    {
      RightMotor.stop(vex::brakeType::brake);              // Stop the right motor (cancel noise)
    }
}

void arcadeDrive(int threshold, int speed){
   LeftMotor.spin(vex::directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis4.value())/speed, vex::velocityUnits::pct); //(Axis3+Axis4)/2
        RightMotor.spin(vex::directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis4.value())/speed, vex::velocityUnits::pct);//(Axis3-Axis4)/2
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
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
	