#include "ofApp.h"
#include <fstream>


//--------------------------------------------------------------
void ofApp::setup(){
    tdf.loadImage("images/tdf_1972_poster.jpg");
    tdf2.loadImage("images/tdf_1972_poster2.jpg");
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
    
    ofFile file;
    
    file.open(ofToDataPath("images/tdf_1972_poster.jpg"), ofFile::ReadWrite, false);
    ofBuffer buff = file.readToBuffer();
    
    ofLogNotice(buff.getText());
    
    //string imgContent = buff.getText();
    //imgContent.erase (imgContent.begin()+imgContent.length()/2, imgContent.end() - 1000);
    
    ofBuffer * dataBuffer = new ofBuffer(file.readToBuffer().getFirstLine());
    
    ofBufferToFile("images/tdf_1972_poster2.jpg", *dataBuffer);
    
    
    ifstream fin;
    fin.open( ofToDataPath("images/tdf_1972_poster.jpg").c_str() );
    
    ofstream myfile;
    myfile.open (ofToDataPath("images/tdf_1972_poster2.jpg").c_str() );
    
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
    
    tdf2.loadImage("images/tdf_1972_poster2.jpg");
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
