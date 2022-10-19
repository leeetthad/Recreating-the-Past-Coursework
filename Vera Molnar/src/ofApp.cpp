#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(0, 0, 0);

	for (int i = 0; i < 16; i++) {
		randomSixteen.push_back(i);
	}

}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofHideCursor();
	line.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

	line.clear();

	for (int a = 0; a < s; a++) {

		if (a % 2 == 0) {

			for (int b = (s * a); b < (s * a) + s; b++) {

				ofSeedRandom(mouseX);
				ofRandomize(randomSixteen);

				int yOffset = m + (a * (4*m));
				int xOffset = m + ((b % s) * (4 * m));

				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						int k = (4 * i) + j;
						points[b][k].set(xOffset + (m * j), yOffset + (m * i));
					}
				}

				for (int i = 0; i < 16; i++) {
					line.addVertex(points[b][randomSixteen[i]]);
				}

			}
		}

		else {

			for (int b = (s * a); b < (s * a) + s; b++) {

				ofSeedRandom(mouseX);
				ofRandomize(randomSixteen);

				int yOffset = m + (a * (4 * m));
				int xOffset = (((4*(s-1))+1)*m) - ((b % s) * (4 * m));

				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						int k = (4 * i) + j;
						points[b][k].set(xOffset + (m * j), yOffset + (m * i));
					}
				}

				for (int i = 0; i < 16; i++) {
					line.addVertex(points[b][randomSixteen[i]]);
				}

			}
			
		}
	}


}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
