#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	//bgfbo.allocate(2720, 2720);
	bgfbo.allocate(4450, 4450);
	bgrotate = 90;

	shadertoy.load("shader/clouds.glsl");
	// https://www.shadertoy.com/view/4tdSWr
	// original shader by "drift", Jeff Simons, used under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
	// edited for this application

	ofSetFrameRate(120);
	shadertoy.setAdvanceTime(true);

	cam.setFov(35);
	cam.setFarClip(500000);

	ofDirectory animals;
	animals.listDir("animals");

	ofDisableArbTex();

	modeldiv = 11;
	helixct = 4;
	helixstep = 0;
	modeldivstep = 0;
	posstep = 0;

	index.push_back(3);
	index.push_back(5);
	index.push_back(7);
	index.push_back(9);

	for (int i = 0; i < 4; i++) {
		rotation.push_back(0.0);
		domain.push_back(12 * PI);
		zheight.push_back(2800);
		rotoffset.push_back(PI / index[i]);
		rotationx.push_back(0);
		rotationy.push_back(0);
	}

	rotstep.push_back(PI / 400);
	rotstep.push_back(PI / 600);
	rotstep.push_back(PI / 500);
	rotstep.push_back(PI / 800);

	rad.push_back(1500);
	rad.push_back(8000);
	rad.push_back(3500);
	rad.push_back(12000);

	scale.push_back(1.2);
	scale.push_back(1.5);
	scale.push_back(1.5);
	scale.push_back(1);

	for (int j = 0; j < 4; j++) {
		
		vector <ofxAssimpModelLoader> modelvectortemp;
		modelAll.push_back(modelvectortemp);

		for (int i = 0; i < animals.size(); i++) {
			ofxAssimpModelLoader modeltemp;
			modelAll.back().push_back(modeltemp);
			modelAll.back().back().loadModel(animals.getPath(i));
			modelAll.back().back().setPosition(0, 0, 0);
			modelAll.back().back().disableMaterials();
			modelAll.back().back().enableTextures();
		}
	}

	for (int k = 0; k < modelAll.size(); k++) {
		//ofSeedRandom(k);
		ofRandomize(modelAll[k]);
	}


	for (int j = 0; j < 4; j++) {

		for (int i = 0; i < (index[j] * 2); i++) {
			Helix helixtemp;
			helixAll.push_back(helixtemp);
			helixAll.back().setup(modelAll[0].size() / modeldiv, rad[j], zheight[j], 100000, domain[j], rotation[j], rotstep[j], i * rotoffset[j]);
			//helixAll.back().setup(modelAll[0].size(), rad[j], zheight[j], 100000, domain[j], rotation[j], rotstep[j], i * rotoffset[j]);
		}

	}

	soundPlayer.load("sounds/everything.mp3");
	soundPlayer.play();
}

//--------------------------------------------------------------
void ofApp::update() {

	helixstep += 0.0005;
	modeldivstep += 0.0005;
	posstep += 0.0001;
	modeldiv = ofMap(cos(modeldivstep), -1, 1, 11, 50);
	cout << modeldiv << endl;

	for (int i = 0; i < helixAll.size(); i++) {
		helixAll[i].update(ofMap(sin(helixstep), -1, 1, 1, 5));
	}

	bgrotate += 0.08;

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofHideCursor();

	//cout << ofGetFrameRate() << endl;

	ofDisableDepthTest();
	
	ofPushMatrix();

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);
	ofRotateDeg(bgrotate);
	ofTranslate(-4450 / 2, -4450 / 2, 0);
	//ofTranslate(-2720 / 2, -2720 / 2, 0);

	bgfbo.begin();
	ofClear(255);
	shadertoy.begin();
	shadertoy.createRGBANoise(100);
	//ofDrawRectangle(0,0, 2720, 2720);
	ofDrawRectangle(0, 0, 4450, 4450);
	shadertoy.end();
	bgfbo.end();
	
	//bgfbo.draw(0, 0, 2720, 2720);
	bgfbo.draw(0, 0, 4450, 4450);

	ofPopMatrix();

	ofEnableDepthTest();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	ofEnableSeparateSpecularLight();

	cam.begin();

	ofSetColor(255, 255, 255, 255);
	ofPushMatrix();

	ofScale(1, -1);

	ofMatrix4x4 cammatrix;
	cammatrix = cam.getModelViewMatrix();
	ofVec3f pos;
	pos = cammatrix.getTranslation();


	for (int j = 0; j < 4; j++) {

		if (j == 0) {
			
			for (int i = 0; i < index[j] * 2; i++) {

				for (int k = 0; k < modelAll[0].size() / modeldiv; k++) {

					modelAll[i % 4][k].setPosition(helixAll[i].x(k, ofMap(sin(posstep), -1, 1, -0.5, 0.5)), helixAll[i].y(k, ofMap(sin(posstep), -1, 1, -0.5, 0.5)), helixAll[i].z(k));
					modelAll[i % 4][k].setScale(scale[j], scale[j], scale[j]);
					modelAll[i % 4][k].setRotation(0, helixAll[i].zrot(k), 0, 0, 1);
					modelAll[i % 4][k].setRotation(1, k + rotation[j], 1, 0, 0);
					modelAll[i % 4][k].setRotation(2, k + rotation[j], 0, 1, 0);
					modelAll[i % 4][k].drawFaces();
				}
			}
		}

		else {

			for (int i = index[j-1]; i < ((index[j-1] * 2) + (index[j] * 2)); i++) {

				for (int k = 0; k < modelAll[0].size() / modeldiv; k++) {

					if (j % 2 == 0) {
						modelAll[i % 4][k].setPosition(helixAll[i].x(k, -ofMap(sin(posstep), -1, 1, -0.5, 0.5)), helixAll[i].y(k, -ofMap(sin(posstep), -1, 1, -0.5, 0.5)), helixAll[i].z(k));
					}
					else {
						modelAll[i % 4][k].setPosition(helixAll[i].x(k, ofMap(sin(posstep), -1, 1, -0.5, 0.5)), helixAll[i].y(k, ofMap(sin(posstep), -1, 1, -0.5, 0.5)), helixAll[i].z(k));
					}
					modelAll[i % 4][k].setScale(scale[j], scale[j], scale[j]);
					modelAll[i % 4][k].setRotation(0, helixAll[i].zrot(k), 0, 0, 1);
					modelAll[i % 4][k].setRotation(1, k + rotation[j], 1, 0, 0);
					modelAll[i % 4][k].setRotation(2, k + rotation[j], 0, 1, 0);
					modelAll[i % 4][k].drawFaces();
				}
			}
		}
	}


	ofPopMatrix();
	
	cam.end();
	
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
