// Ball.h

/* #pragma once should always be at the top of your header files
 * it prevents other headers like "ofMain.h" from being included more than once in your app
 * (note that ofMain.h is also included in ofApp.h)
 */

#pragma once		
#include "ofMain.h"		// ofMain.h lets our Ball "see" openFrameworks

class bird
{
public:


	void setup(int X,int Y);
	void draw();

		ofVec2f eye;
		int x,y;








};

