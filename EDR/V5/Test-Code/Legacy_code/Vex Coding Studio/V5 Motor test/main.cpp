#include "robot-config.h"
          
void motortest1(int speed);
    
int main() {

motortest1(25);
    vex::task::sleep(1000);
    motortest1(50);
    vex::task::sleep(1000);
    motortest1(75);
    vex::task::sleep(1000);
    motortest1(100);
    vex::task::sleep(1000);
}

void motortest1(int speed)
{
    int time1 = 1000, time2 = 2000;
    for (int i=1; i<5; i++)
    {
       Brain.Screen.newLine();
        Brain.Screen.printAt(i,40,speed);
        Brain.Screen.printAt(i,40," test ");
        Brain.Screen.printAt(i,40,i);
        
    vex::task::sleep(time2);
    //Set the velocity of the left and right motor to 50% power. This command will not make the motor spin.
    Motor1.setVelocity(speed, vex::velocityUnits::pct); 
    Motor2.setVelocity(speed, vex::velocityUnits::pct);
    Motor3.setVelocity(speed, vex::velocityUnits::pct);
    Motor4.setVelocity(speed, vex::velocityUnits::pct);    
    Motor5.setVelocity(speed, vex::velocityUnits::pct);
    Motor6.setVelocity(speed, vex::velocityUnits::pct);
    Motor7.setVelocity(speed, vex::velocityUnits::pct);
    Motor8.setVelocity(speed, vex::velocityUnits::pct);
    Motor9.setVelocity(speed, vex::velocityUnits::pct);
    Motor10.setVelocity(speed, vex::velocityUnits::pct);
    Motor11.setVelocity(speed, vex::velocityUnits::pct);
    Motor12.setVelocity(speed, vex::velocityUnits::pct);
    Motor13.setVelocity(speed, vex::velocityUnits::pct);
    Motor14.setVelocity(speed, vex::velocityUnits::pct);    
    Motor15.setVelocity(speed, vex::velocityUnits::pct);
    Motor16.setVelocity(speed, vex::velocityUnits::pct);
    Motor17.setVelocity(speed, vex::velocityUnits::pct);
    Motor18.setVelocity(speed, vex::velocityUnits::pct);
    Motor19.setVelocity(speed, vex::velocityUnits::pct);
    Motor20.setVelocity(speed, vex::velocityUnits::pct);
        
        //Spin the right and left motor in the forward direction. The motors will spin at 50% power because of the previous commands.
    Motor1.spin(vex::directionType::fwd);
    Motor2.spin(vex::directionType::fwd); 
    Motor3.spin(vex::directionType::fwd);
    Motor4.spin(vex::directionType::fwd);
    Motor5.spin(vex::directionType::fwd);
    Motor6.spin(vex::directionType::fwd);
    Motor7.spin(vex::directionType::fwd); 
    Motor8.spin(vex::directionType::fwd);
    Motor9.spin(vex::directionType::fwd);
    Motor10.spin(vex::directionType::fwd);
    Motor11.spin(vex::directionType::fwd);
    Motor12.spin(vex::directionType::fwd);
    Motor13.spin(vex::directionType::fwd);
    Motor14.spin(vex::directionType::fwd);
    Motor15.spin(vex::directionType::fwd);
    Motor16.spin(vex::directionType::fwd);
    Motor17.spin(vex::directionType::fwd);
    Motor18.spin(vex::directionType::fwd);
    Motor19.spin(vex::directionType::fwd);
    Motor20.spin(vex::directionType::fwd);
    vex::task::sleep(time1);
        
    //Spin the right and left motor in the forward direction. The motors will spin at 50% power because of the previous commands.
    Motor1.spin(vex::directionType::rev);
        Motor2.spin(vex::directionType::rev);
        Motor3.spin(vex::directionType::rev);
        Motor4.spin(vex::directionType::rev);
        Motor5.spin(vex::directionType::rev);
        Motor6.spin(vex::directionType::rev);
        Motor7.spin(vex::directionType::rev);
        Motor8.spin(vex::directionType::rev);
        Motor9.spin(vex::directionType::rev);
        Motor10.spin(vex::directionType::rev);
        Motor11.spin(vex::directionType::rev);
        Motor12.spin(vex::directionType::rev);
        Motor13.spin(vex::directionType::rev);
        Motor14.spin(vex::directionType::rev);
        Motor15.spin(vex::directionType::rev);
        Motor16.spin(vex::directionType::rev);
        Motor17.spin(vex::directionType::rev);
        Motor18.spin(vex::directionType::rev);
        Motor19.spin(vex::directionType::rev);
        Motor20.spin(vex::directionType::rev);
    vex::task::sleep(time1);  
    }
}