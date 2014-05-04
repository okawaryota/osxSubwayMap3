#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    //cam.setGlobalPosition(400, -400, 0);
    receiver.setup(PORT);
    subwayMap.loadImage("image/subwayMap01.png");
    
    ofxOscMessage m;
    receiver.getNextMessage(&m);
    if(m.getAddress() == "/window"){
        mapSize.x = m.getArgAsFloat(0);
        mapSize.y = m.getArgAsFloat(1);
    }
    mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    save =0;
}

//--------------------------------------------------------------
void ofApp::update(){
    while(receiver.hasWaitingMessages()){
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(&m);
        if(m.getAddress() == "/your/data"){
			yourPos.x = m.getArgAsFloat(0);
			yourPos.y = m.getArgAsFloat(1);
            yourPos.y = (-yourPos.y)+ mapSize.y;
            orientations.x = m.getArgAsFloat(2);
            orientations.y = m.getArgAsFloat(3);
            soundVol_R = m.getArgAsFloat(4);
            soundPan_GB = m.getArgAsFloat(5);
            
        }
        
        if(m.getAddress() == "/window"){
			mapSize.x = m.getArgAsFloat(0);
            mapSize.y = m.getArgAsFloat(1);
        }
        
    }
    
    z = ofMap(soundVol_R, 0,1, -300, 300);
    c = ofMap(soundVol_R, 0,1, 100, 255);
    time += 1;
    if(time == 100){
        time = 30;
    }
    color = ofColor(c+time*1.2,150-time,time*1.5);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofBackground(0);
    cam.begin();
    
    ofTranslate(-mapSize.x/2, -mapSize.y/2.0, 0.0);
    ofSetColor(255,255,255,50);
    subwayMap.draw(0,0,-200,mapSize.x,mapSize.y);
    
    
    //mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    mesh.addColor(color);
    ofVec3f pos(yourPos.x, yourPos.y, z);
    mesh.addVertex(pos);
    
    mesh.draw();
    ofSetColor(255,0,0);
    ofCircle(yourPos.x,yourPos.y,10,2);
    cam.end();
    
    //--------------------------------------------------------------
    if(flag){
        ofSetColor(0, 0, 0,50);
        ofRect(10, 90, 240, 80);
        ofSetColor(255,255,255);
        ofDrawBitmapString("mapX: "+ofToString(mapSize.x), 10, 120);
        ofDrawBitmapString("mapY: "+ofToString(mapSize.y), 10, 130);
        ofDrawBitmapString("posX: "+ofToString(yourPos.x), 10, 100);
        ofDrawBitmapString("posY: "+ofToString(yourPos.y), 10, 110);
        ofDrawBitmapString("orientationX: "+ofToString(orientations.x), 10, 160);
        ofDrawBitmapString("orientationY: "+ofToString(orientations.y), 10, 170);
        ofDrawBitmapString("soundVol: "+ofToString(soundVol_R), 10, 140);
        ofDrawBitmapString("soundPan1: "+ofToString(soundPan_GB), 10, 150);
    }
    //--------------------------------------------------------------
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //display debug mode
    if(key == 'd'){
        if(flag == false){
            flag = true;
        }else{
            flag = false;
        }
    }
    // clear lines
    if(key == 'c'){
        mesh.clearVertices();
    }
    
    if(key == 's'){
        save++;
        saveName = "saveImage/map" + ofToString(save) + ".png";
        grabbedImage.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        grabbedImage.saveImage(saveName);
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
