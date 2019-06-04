#include "robot-config.h"
void arrowUp();
void arrowDown();
void moveArrow();
void printMenu();
int arrowPos = 1;
bool dirty = false;
int main() {
    
    while(true){

        if (dirty) {
            printMenu();
        }           
        moveArrow();
    }
}

void printMenu() {
    for (int i = 1; i <= 3; ++i) {
        Controller.Screen.setCursor(i, 1);    
        if (i == arrowPos) {            
            Controller.Screen.print(">");
        } else {
            Controller.Screen.print(" ");
        }
        Controller.Screen.setCursor(i, 3);    
        Controller.Screen.print("menu");
        Controller.Screen.setCursor(i, 8);    
        Controller.Screen.print(i);
    }
    dirty = false;
}

void arrowUp() {
    arrowPos -= 1;
    if (arrowPos < 1) {
        arrowPos = 3;
    }
    vex::task::sleep(10);
    dirty = true;
}

void arrowDown() {
    arrowPos += 1;
    if (arrowPos > 3) {
        arrowPos = 1;        
    }
    vex::task::sleep(10);
    dirty = true;    
}

void moveArrow() {    
        Controller.ButtonDown.pressed(arrowDown);
        Controller.ButtonUp.pressed(arrowUp);
}
