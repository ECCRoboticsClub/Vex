#include "robot-config.h"

// storage for some information to save
uint8_t     myTestData[ 100 ];
uint8_t     myReadBuffer[ 1000 ];

int main() {
	// set the test data to something detectable
	if (Brain.SDcard.isInserted() == 1){
		for(int i=0;i<100;i++) {
			myTestData[i] = i * 2;
		}


		// write test data to SD Card
		int nWritten = Brain.SDcard.savefile( "test.h", myTestData, sizeof(myTestData) );

		// did that work ?
		if( nWritten > 0) {
			// display on screen how many bytes we wrote
			Brain.Screen.setCursor( 2, 2 );
			Brain.Screen.print( "We wrote %d bytes to the SD Card", nWritten );

			// now read it back into a different buffer
			int nRead = Brain.SDcard.loadfile( "test.h", myReadBuffer, sizeof(myReadBuffer) );

			// display on screen how many bytes we read
			Brain.Screen.setCursor( 3, 2 );
			Brain.Screen.print( "We read %d bytes from the SD Card", nRead );

			// and display some of the data
			Brain.Screen.setCursor( 6, 2 );
			for(int i=0;i<8;i++)
				Brain.Screen.print("%02X ", myReadBuffer[i]);
		}
		else {
			Brain.Screen.printAt( 10, 40, "Error writing to the SD Card" );
		}
	}
	else {
		Brain.Screen.printAt( 10, 40, "No SD Card" );
	}
}