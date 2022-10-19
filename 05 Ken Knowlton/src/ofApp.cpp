#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetBackgroundColor(0, 0, 0);
	obama.load("ObamaFinalRefBW9.jpg");
	obama.setImageType(OF_IMAGE_GRAYSCALE);
	font.load("CooperHewitt-Thin.otf", 42, true, true, true);
	font.setSpaceSize(0.4);
	font.setGlobalDpi(600);
	float s = 0.8;
	font.setLetterSpacing(s);
	int posX = ofGetWidth();
	int posY = ofGetHeight();
	int z = 1;
	ofSetFrameRate(144);


	text[0] = "If there is anyone out there who still doubts that America is";
	text[1] = "a place where all things are possible; who still wonders if";
	text[2] = "the dream of our founders is alive in our time; who still ques";
	text[3] = "tions the power of our democracy, tonight is your answer. It’s";
	text[4] = "the answer spoken by young and old, rich and poor, Democrat";
	text[5] = "and Republican, black, white, Latino, Asian, Native American,";
	text[6] = "gay, straight, disabled and not disabled – Americans who sent a";
	text[7] = "of Red States and Blue States: we are, and always will be the";
	text[8] = "United States of America.It’s been a long time coming, but";
	text[9] = "tonight, because of what we did on this day, in this elec-";
	text[10] = "tion, at this defining moment, change has come to America.";
	text[11] = "The road ahead will be long. Our climb will be steep. We may";
	text[12] = "not get there in one year or even one term, but America,I";
	text[13] = "have never been more hopeful than I am tonight that we will";
	text[14] = "get there. I promise you – we as a people will get there.I will";
	text[15] = "always be honest with you about the challenges we face. I";
	text[16] = "will listen to you, especially when we disagree. And above";
	text[17] = "all, I will ask you join in the work of remaking this nation the";
	text[18] = "only way it’s been done in America for two hundred years,";
	text[19] = "block by block, brick by brick, calloused hand by calloused";
	text[20] = "hand.Let us summon a new spirit of patriotism, where each";
	text[21] = "of us resolves to look after not only  ourselves, but each";
	text[22] = "other. Let us remember that in this country we rise or fall as";
	text[23] = "one nation; as one people.Let us resist the temptation to fall";
	text[24] = "back on the same partisanship and pettiness and immaturity";
	text[25] = "that has poisoned our politics for so long. Let us remember";
	text[26] = "that it was a man from this state who first carried the banner";
	text[27] = "of the Republican Party to the White House, a party founded";
	text[28] = " on the values of self-reliance, individual liberty, and national";
	text[29] = "unity. Those are values we all share, and while the De-";
	text[30] = "mocratic Party has won a great victory tonight, we do so with";
	text[31] = "a measure of humility and determination to heal the divides";
	text[32] = "that have held back our progress. As Lincoln said to a nation";
	text[33] = "far more divided than ours, “We are not enemies, but friends";
	text[34] = "Though passion may have strained it must not break our bonds";
	text[35] = "of affection.” And to those Americans whose support I have yet";
	text[36] = "to earn – I may not have won your vote, but I hear your voices,";
	text[37] = "I need your help, and I will be your President too.And to all";
	text[38] = "those who have wondered if America’s beacon still burns as";
	text[39] = "bright, tonight we proved once more that the true strength of";
	text[40] = "our nation comes not from our the might of our arms or the scale";
	text[41] = "of our wealth, but from the enduring power of our ideals: de-";
	text[42] = "mocracy, liberty, opportunity, and unyielding hope.This is our";
	text[43] = "moment. This is our time – to put our people back to work and";
	text[44] = "open doors of opportunity for our kids; to restore prosperity";
	text[45] = "and promote the cause of peace; to reclaim the American";
	text[46] = "Dream and reaffirm that fundamental truth – that out of many,";
	text[47] = "we are one; that while we breathe, we hope, and where we";
	text[48] = "are met with cynicism, and doubt, and those who tell us that";
	text[49] = "we can’t, we will respond with that timeless creed that sums";
	text[50] = "up the spirit of a people:'Yes We Can.'Thank you, God";
	text[51] = "bless you, and may God Bless the United States of America.";
	text[52] = "(from Barack Obama's November 4,2008 acceptance speech)";
}

//--------------------------------------------------------------
void ofApp::update(){

	/*z = z + 1;
	posX = ofMap(z, 1, 255, 0, ofGetWidth(), true);
	posY = ofMap(z, 1, 255, 0, ofGetHeight(), true);
	cout << z << endl; */

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofHideCursor(); 

	//obama.draw(0, 0);

	for (int a = 0; a < 53; a++) {

		s = 0.8;

		font.setLetterSpacing(s);

		ofPushMatrix();

		ofTranslate(0, 37*(a+1));

		ofRectangle rect = font.getStringBoundingBox(text[a], 0, 0);

		while (rect.getWidth() < 1423) {
			s = s + 0.01;
			font.setLetterSpacing(s);
			rect = font.getStringBoundingBox(text[a], 0, 0);
		}

		vector <ofPath> paths = font.getStringAsPoints(text[a], true, false);
		vector <ofPath> pathsfill = font.getStringAsPoints(text[a], true, true);
		

		for (int i = 0; i < paths.size(); i++) {

			paths[i].setPolyWindingMode(OF_POLY_WINDING_ODD);

			vector <ofPolyline> lines = paths[i].getOutline();

			if (!lines.size()) {
				continue;
			}

			ofRectangle rect = lines[0].getBoundingBox();

			for (int j = 1; j < lines.size(); j++) {
				rect.growToInclude(lines[j].getBoundingBox());
			}

			ofPoint pt = rect.getCenter();

			ofColor color = obama.getColor((pt.x), pt.y + (37 * (a+1)));
			float brightness = color.getBrightness();
			float l = color.getLightness();

			//pathsfill[i].setStrokeWidth(ofMap(brightness, 0, 255, 0.01, 5));
			//pathsfill[i].setStrokeColor(ofMap(l, 0, 255, 25, 255));
			//pathsfill[i].draw();
			
			for (int j = 0; j < lines.size(); j++) {

				lines[j] = lines[j].getResampledBySpacing(2);

				for (int k = 0; k < lines[j].size(); k++) {

					ofSetColor(ofMap(l, 0, 255, 50, 255));
					ofDrawCircle(lines[j][k], ofMap(l, 0, 255, 0.5, 2));

					//ofSetColor(ofMap(l, 0, 255, 50, ofMap(posX, 0, ofGetWidth(), 50, 255)));
					//ofDrawCircle(lines[j][k], ofMap(l, 0, 255, 2 - (ofMap(posY, 0, ofGetHeight(), 0, 1.5)), 2));
				}
			}
		}

		ofPopMatrix();
	}
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
