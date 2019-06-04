#include "robot-config.h"

void rumbleFeedBack();
void AxisValueChanged();
void GyroValueChanged();
void tankDrive(int threshold, int speed, bool centerFlag);
void motorVelocity(int velocity);
void mecanumDrive(int threshold, int speed, bool centerFlag);
void arcadeDrive(int threshold, int speed, bool centerFlag);
int speedControl();
void centerMotorControl(int threshold,bool flag);
int main() {
   // int X2 = 0, Y1 = 0, X1 = 0, threshold = 15;
    
    Gyro.isCalibrating();
    Controller.Screen.clearScreen();
    //motorVelocity(100);
    
   while(true){
       rumbleFeedBack();
        GyroValueChanged();   
        AxisValueChanged(); 
        tankDrive(15,speedControl(), false);
       
       
       
       vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources.
    }
}
void rumbleFeedBack(){
   
        if (abs(Controller.Axis1.position(vex::percentUnits::pct))>5)
            Controller.rumble("."); 
        
       if (abs(Controller.Axis4.position(vex::percentUnits::pct))>5)
            Controller.rumble("-"); 
}
void AxisValueChanged() {
    
    //Right Stick Axes
    Brain.Screen.clearLine(1,vex::color::black);
    Brain.Screen.setCursor(1, 0);
    Brain.Screen.print("Axis1 value: %d", Controller.Axis1.position(vex::percentUnits::pct));
   
    Brain.Screen.setCursor(1, 20);
    Brain.Screen.print("Axis2 value: %d", Controller.Axis2.position(vex::percentUnits::pct));
    
    //Left Stick Axes
    Brain.Screen.clearLine(2,vex::color::black);
    Brain.Screen.setCursor(2, 0);
    Brain.Screen.print("Axis3 value: %d", Controller.Axis3.position(vex::percentUnits::pct));
    
     Brain.Screen.setCursor(2, 20);
    Brain.Screen.print("Axis4 value: %d", Controller.Axis4.position(vex::percentUnits::pct));
    
    
}

void GyroValueChanged() {
    Brain.Screen.clearLine(3,vex::color::black);
    Brain.Screen.setCursor(3, 0);
    Brain.Screen.print("Gyro value: %d",Gyro.value(vex::analogUnits::range8bit) );
    Brain.Screen.setCursor(3, 20);
    Brain.Screen.print("Gyro value: %d",Gyro.value(vex::rotationUnits::deg));
    vex::task::sleep(30);
    
    Controller.Screen.clearLine(1);
    Controller.Screen.setCursor(1, 0);
    Controller.Screen.print("Gyro value: %d",Gyro.value(vex::analogUnits::range8bit) );
    vex::task::sleep(300);
}

void tankDrive(int threshold, int speed, bool centerFlag){
        //Set the left and right motor to spin forward using the controller Axis values as the velocity value.
        backRightMotor.spin(vex::directionType::fwd, Controller.Axis2.value(), vex::velocityUnits::pct);
        

    if(abs(Controller.Axis3.value()) > threshold)         // If the left joystick is greater than or less than the threshold:
    {
      frontLeftMotor.spin(vex::directionType::fwd, Controller.Axis3.value()/speed, vex::velocityUnits::pct);
      backLeftMotor.spin(vex::directionType::fwd, Controller.Axis3.value()/speed, vex::velocityUnits::pct);
             // Left Joystick Y value / speed.
    }
    else                                    // If the left joystick is within the threshold:
    {
      frontLeftMotor.stop(vex::brakeType::brake);
      backLeftMotor.stop(vex::brakeType::brake);
                       // Stop the left motor (cancel noise)
    }

    if(abs(Controller.Axis2.value()) > threshold)         // If the right joystick is greater than or less than the threshold:
    {
      frontRightMotor.spin(vex::directionType::fwd, Controller.Axis2.value()/speed, vex::velocityUnits::pct);
      backRightMotor.spin(vex::directionType::fwd, Controller.Axis2.value()/speed, vex::velocityUnits::pct);
        // Right Joystick Y value / 2.
    }
    else                                    // If the right joystick is within the threshold:
    {
      frontRightMotor.stop(vex::brakeType::brake);
      backRightMotor.stop(vex::brakeType::brake);               // Stop the right motor (cancel noise)
    }
  centerMotorControl(threshold, centerFlag);
}

void motorVelocity(int velocity){
    frontLeftMotor.setVelocity(velocity,vex::percentUnits::pct);
    backRightMotor.setVelocity(velocity,vex::percentUnits::pct);
    backLeftMotor.setVelocity(velocity,vex::percentUnits::pct);
    backCenterMotor.setVelocity(velocity,vex::percentUnits::pct);
    frontRightMotor.setVelocity(velocity,vex::percentUnits::pct);
}

void mecanumDrive(int threshold, int speed, bool centerFlag){
    int X2, Y1, X1 ;
  //Create "deadzone" for Y1/Ch3
    if(abs(Controller.Axis3.value()) > threshold)
      Y1 = Controller.Axis3.value();
    else
      Y1 = 0;
    //Create "deadzone" for X1/Ch4
    if(abs(Controller.Axis4.value()) > threshold)
      X1 = Controller.Axis4.value();
    else
      X1 = 0;
    //Create "deadzone" for X2/Ch1
    if(abs(Controller.Axis1.value()) > threshold)
      X2 = Controller.Axis1.value();
    else
      X2 = 0;

    //Remote Control Commands
   frontLeftMotor.spin(vex::directionType::fwd, (Y1 + X2 + X1)/speed, vex::velocityUnits::pct);
   frontRightMotor.spin(vex::directionType::fwd,(Y1 - X2 - X1)/speed, vex::velocityUnits::pct);
   backLeftMotor.spin(vex::directionType::fwd, (Y1 + X2 - X1)/speed, vex::velocityUnits::pct);  
   backRightMotor.spin(vex::directionType::fwd, (Y1 - X2 + X1)/speed, vex::velocityUnits::pct);
    
    centerMotorControl(threshold, centerFlag);
}

void arcadeDrive(int threshold, int speed, bool centerFlag){
    int joy_x, joy_y;
    
    joy_x = Controller.Axis1.value();   // This is the RIGHT analog stick.  For LEFT, change 'Ch1' to 'Ch4'.
    joy_y = Controller.Axis3.value();   // This is the RIGHT analog stick.  For LEFT, change 'Ch2' to 'Ch3'.

    // Forward, and swing turns: (both abs(X) and abs(Y) are above the threshold, and Y is POSITIVE)
    if((abs(joy_x) > threshold) && (abs(joy_y) > threshold) && (joy_y > 0))
    {
      
    frontLeftMotor.spin(vex::directionType::fwd, (joy_y + joy_x)/speed, vex::velocityUnits::pct);
   frontRightMotor.spin(vex::directionType::fwd,(joy_y - joy_x)/speed, vex::velocityUnits::pct);
   backLeftMotor.spin(vex::directionType::fwd, (joy_y + joy_x)/speed, vex::velocityUnits::pct);  
   backRightMotor.spin(vex::directionType::fwd, (joy_y - joy_x)/speed, vex::velocityUnits::pct);
    }
    // Backwards and swing turns: (both abs(X) and abs(Y) are above the threshold, and Y is NEGATIVE)
    else if((abs(joy_x) > threshold) && (abs(joy_y) > threshold) && (joy_y < 0))
    {
        frontLeftMotor.spin(vex::directionType::fwd, (joy_y - joy_x)/speed, vex::velocityUnits::pct);
   frontRightMotor.spin(vex::directionType::fwd,(joy_y + joy_x)/speed, vex::velocityUnits::pct);
   backLeftMotor.spin(vex::directionType::fwd, (joy_y - joy_x)/speed, vex::velocityUnits::pct);  
   backRightMotor.spin(vex::directionType::fwd, (joy_y + joy_x)/speed, vex::velocityUnits::pct);
    }
    // Turning in place: (abs(X) is above the threshold, abs(Y) is below the threshold)
    else if((abs(joy_x) > threshold) && (abs(joy_y) < threshold))
    {
        
   frontLeftMotor.spin(vex::directionType::fwd, (joy_x)/speed, vex::velocityUnits::pct);
   frontRightMotor.spin(vex::directionType::fwd,(-1 * joy_x)/speed, vex::velocityUnits::pct);
   backLeftMotor.spin(vex::directionType::fwd, (joy_x)/speed, vex::velocityUnits::pct);  
   backRightMotor.spin(vex::directionType::fwd, (-1 * joy_x)/speed, vex::velocityUnits::pct);
        
    }
    // Standing still: (both abs(X) and abs(Y) are below the threshold)
    else
    {
   frontLeftMotor.stop(vex::brakeType::brake);
   frontRightMotor.stop(vex::brakeType::brake);
   backLeftMotor.stop(vex::brakeType::brake); 
   backRightMotor.stop(vex::brakeType::brake);
        
     centerMotorControl(threshold,centerFlag);
    }
}
int speedControl(){
    if (Controller.ButtonR1.pressing())
        return 1;
    else if (Controller.ButtonL1.pressing())
        return 4;
    else
        return 2;
}

void centerMotorControl(int threshold, bool flag){
    if (flag == true){
      if(abs(Controller.Axis4.value()) > threshold)         // If the right joystick is greater than or less than the threshold:
    {
      backCenterMotor.spin(vex::directionType::fwd, Controller.Axis4.value()/speedControl(), vex::velocityUnits::pct);
      
    }
    else                                    // If the right joystick is within the threshold:
    {
      backCenterMotor.stop(vex::brakeType::brake);
    }  
    }
    else{
         backCenterMotor.stop(vex::brakeType::coast);
    }
}
//Controller.Screen.print("Hello");

//Motor1.setVelocity(100,vex::percentUnits::pct);
  // frontLeftMotor.spin(vex::directionType::fwd,100,vex::velocityUnits::rpm);
   // vex::task::sleep(3000);
    //Motor1.stop();

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
	