#include "ofApp.h"

using namespace ofxCv;
//--------------------------------------------------------------
void ofApp::setup(){

    img1.load("/Users/mun/Desktop/cc.png");
    //ofSetupOpenGL(img1.getWidth(), img1.getHeight(), OF_WINDOW);
    ofSetWindowShape(img1.getWidth(), img1.getHeight());
    ofSetWindowPosition(800, 100);
    ofSetWindowTitle("Detect Blurness");
    
    cv::Mat src= toCv(img1);
    cv:: cvtColor(src, src, cv::COLOR_RGB2GRAY);
    
    // get Laplacian
    cv::Mat dst;
    cv::Laplacian(src, dst, CV_32F);
    
    // get variance
    cv::Scalar mean,stddev;
    cv::meanStdDev(dst, mean, stddev);
    blurness= stddev.val[0]*stddev.val[0];
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // image
    
    ofSetColor(255, 255, 255);
    img1.draw(0, 0, img1.getWidth(), img1.getHeight());
    
    // filled box
    ofSetColor(10, 10, 10);
    ofDrawRectangle(5, 5, 200, 60);
    
    // text
    ofSetColor(255);
    ofDrawBitmapString("DeBlurness= " + ofToString(blurness), 20, 30);

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
