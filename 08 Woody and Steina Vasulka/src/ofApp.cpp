#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    //grabber.listDevices();

    ofSetFrameRate(12);

    ofBackground(0, 0, 0);
    rad = 3000;
    s = 10;
    div = 10;

    linewidthstep = 0;

    grabber.setDeviceID(0);
    grabber.initGrabber(1200, 800);

    camGray.allocate(grabber.getWidth(), grabber.getHeight(), OF_IMAGE_GRAYSCALE);
    bgGray.allocate(grabber.getWidth(), grabber.getHeight(), OF_IMAGE_GRAYSCALE);
    diffImg.allocate(grabber.getWidth(), grabber.getHeight(), OF_IMAGE_GRAYSCALE);

    ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update(){

    s++;
    grabber.update();

    if (grabber.isFrameNew()) {

        convertColor(grabber, camGray, CV_RGB2GRAY);
        camGray.update();

        if (bRecordBg) {
            bgGray.setFromPixels(camGray.getPixels());
            bgGray.update();
            bRecordBg = false;
        }

        absdiff(camGray, bgGray, diffImg);
        diffImg.update();

        threshImg.setFromPixels(diffImg.getPixels());
        threshold(threshImg, mouseX);
        threshImg.update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    //grabber.draw(grabber.getWidth(), 0);

    cam.enableOrtho();

    cam.begin();

    //int a = 0;

    ofPushMatrix();

    ofScale(1, -1);

    for (int a = 0; a < grabber.getHeight(); a += div) {
        
        //ofSetLineWidth(1 + sin(linewidthstep));

        int scan = (s % div);
        float phi = (a * ((PI / 2) / grabber.getHeight())) + scan * ((PI/2) / grabber.getHeight());

        ofPolyline line;

        for (int b = 0; b < grabber.getWidth(); b += 1) {
            //ofDrawCircle(400 + (rad / 2)*cos(theta), 400 + (rad / 2) * sin(theta), 2);

            float theta = b * (PI / grabber.getWidth());

            ofSetColor(255, 255, 255);

            brightness = diffImg.getPixels().getColor(b, a + scan).getBrightness();
            if (brightness < 75) {
                brightness = 0;
            }

            brightness = 0.5 * brightSmooth + 0.5 * brightness;

            float x = (rad / 2) * sin(phi) * cos(theta) + 10*(sqrt(brightness));
            float y = (rad / 2) * sin(phi) * sin(theta) + 10*(sqrt(brightness));
            float z = ((rad / 2) * cos(phi)) + brightness;

            line.addVertex(x, y, z);
        }

        //line.close();
        line.draw();

        //linewidthstep += (TWO_PI / grabber.getHeight());
    }

   /*for (float phi = 0; phi < PI / 2; phi += (PI / 2) / 400) {

        a++;

        ofPolyline line;

        for (float theta = 0; theta < PI; theta += PI / 600)
        {
            //ofDrawCircle(400 + (rad / 2)*cos(theta), 400 + (rad / 2) * sin(theta), 2);

            ofSetColor(255, 255, 255);

            float x = (rad / 2) * sin(phi) * cos(theta);
            float y = (rad / 2) * sin(phi) * sin(theta);
            float z = (rad / 2) * cos(phi);

            line.addVertex(x, y, z);
        }

        //line.close();
        line.draw();
    }*/

    //cout << a << endl;

    ofPopMatrix();

    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' ') {
        bRecordBg = true;
    }
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
