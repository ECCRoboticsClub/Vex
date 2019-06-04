#include "robot-config.h"


int main() 
{
	while (true) 
        
        /*First, the while (true) line of code tells the robot to run this code 
          repeatedly as long as the condition is true like a forever loop.*/
	{
        
		VisionSensor.takeSnapshot(1); 
        Controller.Screen.setCursor(3,1);
        Controller.Screen.print("%f in", Sonar.distance(vex::distanceUnits::in));
        /*Then, the Vision Sensor takes its first  snapshot
          of Signature 1 (1 = ORANGE_CUBE).*/
        
        if (VisionSensor.largestObject.exists && VisionSensor.largestObject.width>5 && Sonar.distance(vex::distanceUnits::in)>3 )
            
            /*Then, the program decides (Boolean: 1-true / 0-false)   if the Vision Sensor
            detects that the largest green object exists and that the largest object's 
            width is greater than 5. */
            
		{   /*If both of those conditionals are true (1), then the program:*/
            
			Brain.Screen.setPenColor(vex::color::white);  //sets the brain's screen's pen color to white 
			Brain.Screen.setFillColor(vex::color::orange); //sets the brain's screen's fill color to green
			Brain.Screen.drawRectangle(0,0, 480, 240);    /*then the brain's screen draws a rectangle 
                                                            starting at (0,0) that is 480 pixels wide and
                                                            240 pixels tall*/
			Brain.Screen.setCursor(2,6);                  //then sets the brain's screen's cursor at (2,6)
			Brain.Screen.setFont(vex::fontType::mono40);  //sets the brain's screen's font to mono40
			Brain.Screen.print("I love this");                //then the brain's screen prints "Forward"
            Controller.Screen.setCursor(1,1);
            Controller.Screen.print("ORANGE_CUBE");
            Controller.Screen.newLine();
            Controller.Screen.print("I love this");
			LeftMotor.spin(vex::directionType::fwd);      //and then the LeftMotor spins forward
			RightMotor.spin(vex::directionType::fwd);     //and the RightMotor spins forward
		}
		else 
            
            /*If those two conditionals are not both true (0-false ---> else), the Vision Sensor takes a 
              snapshot of Signature 2 (2 = PURPLE_CUBE). */
		{
			VisionSensor.takeSnapshot(2);
			if (VisionSensor.largestObject.exists && VisionSensor.largestObject.width>5)
                
                /*Then, the program decides (Boolean: 1-true / 0-false) if the Vision Sensor detects that 
                the largest yellow object exists, and that the largest object's width is greater than 5. */
                
			{   //If both of those conditionals are true (1), then the program:
                
				Brain.Screen.setPenColor(vex::color::white);   //sets the brain's screen's pen color to black 
				Brain.Screen.setFillColor(vex::color::purple); //sets the brain's screen's fill color to yellow
				Brain.Screen.drawRectangle(0,0, 480, 240);     /*then the brain's screen draws a rectangle 
                                                                 starting at (0,0) that is 480 pixels wide and 
                                                                 240 pixels tall*/
				Brain.Screen.setCursor(2,6);                   //then sets the brain's screen's cursor at (2,6)
				Brain.Screen.setFont(vex::fontType::mono40);   //sets the brain's screen's font to mono40
				Brain.Screen.print("Right");                   //then the brain's screen prints "Right"
                Controller.Screen.setCursor(1,1);
                    Controller.Screen.print("PURPLE_CUBE");
                    Controller.Screen.newLine();
                    Controller.Screen.print("Yuckie");
				LeftMotor.spin(vex::directionType::fwd);       //and then the LeftMotor spins forward
				RightMotor.spin(vex::directionType::rev);      //and the RightMotor spins reverse
			}
			else 
                
                /*if those two conditionals are not both true (0-false ---> else), the Vision Sensor takes a 
                  snapshot of Signature 3 (3 = GREEN_CUBE). */
			{
				VisionSensor.takeSnapshot(3);
				if (VisionSensor.largestObject.exists && VisionSensor.largestObject.width>5)
                    
                    /*Then, the program decides (Boolean: 1-true / 0-false) if the Vision Sensor detects that 
                      the largest red object exists and that the largest object's width is greater than 5.*/
                    
				{   //If both of those conditionals are true (1), then the program:
                    
					Brain.Screen.setPenColor(vex::color::white);   //sets the brain's screen's pen color to white 
					Brain.Screen.setFillColor(vex::color::green);    //sets the brain's screen's fill color to red
					Brain.Screen.drawRectangle(0,0, 480, 240);     /*then the brain's screen draws a rectangle 
                                                                     starting at (0,0) that is 480 pixels wide and 
                                                                     240 pixels tall*/
					Brain.Screen.setCursor(2,6);                   //then sets the brain's screen's cursor at (2,6)
					Brain.Screen.setFont(vex::fontType::mono40);   //sets the brain's screen's font to mono40
					Brain.Screen.print("Left");                    //then the brain's screen prints "Left"
                    Controller.Screen.setCursor(1,1);
                    Controller.Screen.print("GREEN_CUBE");
                    Controller.Screen.newLine();
                    Controller.Screen.print("Eww Gross");
                    LeftMotor.spin(vex::directionType::rev);       //and then the LeftMotor spins reverse
					RightMotor.spin(vex::directionType::fwd);      //and the RightMotor spins forward
				}
				else 
                    
                    //If those two conditionals are  not both true (0-false --->else), the program:
				{
					LeftMotor.stop();                  //stops the LeftMotor
					RightMotor.stop();                 //stops the RightMotor
                    Brain.Screen.clearScreen();        //and clears the brain's screen
                    Controller.Screen.clearScreen();   //and clears the Controller's screen
				}
			}
		}
        
		task::sleep(100); 
        
        /*Then the program  waits 100 milliseconds and starts the loop again by taking a Snapshot of 
        Signature 1 and continuing.*/
	}
}