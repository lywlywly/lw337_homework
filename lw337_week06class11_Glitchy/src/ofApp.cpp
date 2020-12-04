#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	camW = 640;
	camH = 480;
	webcam.setup(camW, camH);
	vidShift.allocate(camW, camH, OF_IMAGE_COLOR);
	// setup gui
	gui.setup();

	gui.add(distortionScale.set("distortionScale", 30, 0, 100));
	gui.add(contrast.set("contrast", 0.5, 0, 1));
	gui.add(bInvert.set("invert color", false));
}

//--------------------------------------------------------------
void ofApp::update() {

	float time = ofGetElapsedTimef();

	webcam.update();
	if (webcam.isFrameNew())
	{
		for (int y = 0; y < webcam.getHeight(); y++) {
			for (int x = 0; x < webcam.getWidth(); x++) {
				int xOffset = ofNoise(y * .005, time) * distortionScale;
				int yOffset = ofNoise(x * .005, time) * distortionScale;

				int newX = (x + xOffset) % int(webcam.getWidth());
				int newY = (y + yOffset) % int(webcam.getHeight());

				ofColor color = webcam.getPixels().getColor(x, y);
				color.setBrightness(contrast*(color.getBrightness()-127.5)+127.5);
				if (bInvert) {
					color.r = 255 - color.r;
					color.g = 255 - color.g;
					color.b = 255 - color.b;
				}
				vidShift.setColor(newX, newY, color);
			}
		}
		vidShift.update();
	}


}

//--------------------------------------------------------------
void ofApp::draw() {
	vidShift.draw(0, 0, ofGetWidth(), ofGetHeight());
	gui.draw();
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
