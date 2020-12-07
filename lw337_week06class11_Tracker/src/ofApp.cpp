#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {


	camW = 640;
	camH = 480;
	vid.setup(camW, camH);
	vidShift.allocate(640, 480, OF_IMAGE_COLOR);

}

//--------------------------------------------------------------
void ofApp::update() 
{
	float time = ofGetElapsedTimef();

	vid.update();
	count = 1;
	if (vid.isFrameNew())
	{
		sumX = 0;

		sumY = 0;

		for (int y = 0; y < camH; y++) 
		{

			for (int x = 0; x < camW; x++) 
			{

				ofColor color = vid.getPixels().getColor(x, y);

				if (color.r > 200 && color.g < 100 && color.b < 100)
				{
					sumX += x;
					sumY += y;
					count++;

				}
			}
		}

		for (int y = 0; y < vid.getHeight(); y++) 
		{
			for (int x = 0; x < vid.getWidth(); x++)
			{
				int xOffset = ofNoise(y * .005, time) * distortionScale;
				int yOffset = ofNoise(x * .005, time) * distortionScale;

				int newX = (x + xOffset) % int(vid.getWidth());
				int newY = (y + yOffset) % int(vid.getHeight());

				ofColor color = vid.getPixels().getColor(x, y);

				vidShift.setColor(newX, newY, color);
			}
		}
		vidShift.update();
	}

	if ((ofGetFrameNum() % 2 == 0))
	{
		oldX = X;
		oldY = Y;
		X = sumX / count;
		Y = sumY / count;
	}

	if (time > 1)
	{
		oldDistortionScale = distortionScale;
		distortionScale = sqrt(abs(X - oldX)*abs(Y - oldY)) + 0.5*oldDistortionScale;
	}

	//cout << distortionScale<< endl;


}


//--------------------------------------------------------------
void ofApp::draw() 
{
	vidShift.draw(0, 0, ofGetWidth(), ofGetHeight());
	stringstream info;
	info << "Move a red object around your webcam to disrtort the image." << endl << "Just like bullfighting, your movement before the webcam will irritate the bull, so the image is being distorted." << endl << "The faster you move a red object before the cam, the bigger the scale of distiortion is."<<endl<<"You can use your phone to display an image of red to get started."<< endl;
	ofDrawBitmapStringHighlight(info.str(), 25, 50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
