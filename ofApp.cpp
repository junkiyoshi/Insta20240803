#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(0);
	ofSetLineWidth(1.5);
}
//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(270);
	ofRotateZ(ofGetFrameNum() * 0.1);

	auto radius = 250;
	int deg_span = 2;

	auto target_deg = ofGetFrameNum() % 360;
	for (int deg = 0; deg < 360; deg += deg_span) {

		auto location = glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), 0);
		auto len = ofMap(ofNoise(glm::vec4(location * 0.05, ofGetFrameNum() * 0.01)), 0, 1, -200, 200);

		auto location_1 = glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), 0);
		auto location_2 = glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), len);

		ofDrawLine(location_1, location_2);
		ofDrawBox(location_1, 4);
		ofDrawSphere(location_2, 3);
	}

	this->cam.end();

	/*
	int start = 150;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}