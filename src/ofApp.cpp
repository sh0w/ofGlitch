#include "ofApp.h"
#include <fstream>


//--------------------------------------------------------------
void ofApp::setup(){
    tdf.loadImage("images/img.jpg");
    tdf2.loadImage("images/img2.jpg");
    resetImage();
}

//--------------------------------------------------------------
void ofApp::update(){
	ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::draw(){	
	ofSetColor(255);

    tdf.draw(0,0,ofGetWidth()/2,ofGetHeight());
    tdf2.draw(ofGetWidth()/2,0,ofGetWidth()/2,ofGetHeight());
    
    if(ofGetFrameNum() % 3 == 0) {
        glitchedLines.push_back(ofRandom(3,1617));
        glitchImage();
    }
}

void ofApp::glitchImage() {
    
    
    ifstream fin;
    fin.open( ofToDataPath("images/img.jpg").c_str() );
    
    ofstream myfile;
    myfile.open (ofToDataPath("images/img2.jpg").c_str() );
    
    //vector<string> data; //declare a vector of strings to store data
    
    int i = 0;
    
    while(fin!=NULL) {
        string str;
        getline(fin, str);
        if(std::find(glitchedLines.begin(), glitchedLines.end(), i) != glitchedLines.end()) {
            ofLogNotice("glitched line");
            ofLogNotice(ofToString(i));
        } else {
            myfile << str << "\n";
        }
        i++;
    }
    
    myfile.close();
    fin.close();
    
    tdf2.loadImage("images/img2.jpg");
}

void ofApp::resetImage() {
    glitchedLines.clear();
    glitchImage();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == ' ') {
        resetImage();
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    // add a glitch:
    glitchedLines.push_back(ofRandom(3,1617));
    
    glitchImage();
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
