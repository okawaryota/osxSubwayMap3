#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define PORT 12345
#define NUM_MSG_STRINGS 20

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxOscReceiver receiver;
    ofVec2f yourPos;
    ofVec2f mapSize;
    ofVec2f orientations;
    float soundVol_R,soundPan_GB;
    
    ofImage subwayMap;
    ofImage grabbedImage;
    int save;
    string saveName;
    
	bool flag = false;
    
    ofEasyCam   cam;
    
    ofMesh mesh;
    float z,c;
    ofColor color;
    int time;
    
};
