#include "ofApp.h"
#include "ofxGifEncoder.h"

ofxGifEncoder encoder;

ofColor c1;
ofColor c2;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 10);
    ofSetBackgroundAuto(false);
    ofSetCircleResolution(100);
    ofSetColor(0);
//    encoder.setup(ofGetWidth(), ofGetHeight(), 1/24, 8); // colors = 8
//    ofAddListener(ofxGifEncoder::OFX_GIF_SAVE_FINISHED, this, &ofApp::onGifSaved);
    
    c1 = ofColor(154,25,55);
    c2 = ofColor(88,123,171);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // update colors
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float b = (negative) ? 0 : 255;
    ofBackground(b, 10);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    ofPolyline card;
    float t = framesCurr;
    float f = ofMap(ofNoise(t/500),0,1,-0.3,0.3);
    
    float r1 = ofMap(ofNoise(t/100 + 10), 0, 1, 0, 200);
    float g1 = ofMap(ofNoise(t/200 + 20), 0, 1, 0, 200);
    float b1 = ofMap(ofNoise(t/600 + 30), 0, 1, 0, 200);
    float r2 = ofMap(ofNoise(t/100 + 40), 0, 1, 0, 200);
    float g2 = ofMap(ofNoise(t/400 + 60), 0, 1, 0, 200);
    float b2 = ofMap(ofNoise(t/1000 + 70), 0, 1, 0, 200);
    
    if(negative) {
        c1 = ofColor(r1,g1,b1).getInverted();
        c2 = ofColor(r2,g2,b2).getInverted();
    } else {
        c1 = ofColor(r1,g1,b1);
        c2 = ofColor(r2,g2,b2);
    }
    
    float petals = 30;
    
    ofPushMatrix();
    
    //    float t = (framesCurr % framesTotal) / static_cast<float>(framesTotal);
    
    
    //    ofRotate(-360*t);
        ofRotate(-t/10);
        ofColor c;
    
    //    float f = sinf(t * TWO_PI)*0.3;
    
        for(float i=0; i<TWO_PI ; i+=TWO_PI/100) {
            
            // cardiod
            float radius = ((f * 200.0) +  sin(i) * (ofMap(sin(TWO_PI/100),-1,1,20,110))) * 3.5;
            
            float x = radius * sin(i);
            float y = radius * cos(i);
            
            card.addVertex(x, y);
            
            
        }
        card.close();
    
        if(petals > 0) {
            float d_alpha = 360/petals;
            for(float i = 0 ; i < 360 ; i += d_alpha) {
                ofRotate(d_alpha);
                if(colors) {
                    c = c1.getLerped(c2, ofMap(i, 0, 360, 0, 1));
                } else {
                    c = (negative) ? ofColor(255) : ofColor(0);
                }
                
                ofSetColor(c);
                card.draw();
            }
        }
    
    ofPopMatrix();
    
//    ofPushMatrix();
//
//    petals = 0;
//
//    //    ofRotate(-360*t);
//    ofRotate(t/11);
//
//
//    //    float f = sinf(t * TWO_PI)*0.3;
//
//    for(float i=0; i<TWO_PI ; i+=TWO_PI/100) {
//
//        // cardiod
//        float radius = ((f * 200.0) +  sin(i) * (ofMap(sin(TWO_PI/100),-1,1,20,110))) * 2;
//
//        float x = radius * sin(i);
//        float y = radius * cos(i);
//
//        card.addVertex(x, y);
//
//
//    }
//    card.close();
//
//    if(petals >0) {
//            float d_alpha = 360/petals;
//            for(float i = 0 ; i < 360 ; i += d_alpha) {
//                ofRotate(d_alpha);
//                if(colors) {
//                    c = c1.getLerped(c2, ofMap(i, 0, 360, 0, 1));
//                } else {
//                    c = (negative) ? ofColor(255) : ofColor(0);
//                }
//                ofSetColor(c);
//                card.draw();
//            }
//    }
//
//    ofPopMatrix();
    
//    if(framesCurr < framesTotal) {
//        img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
//        encoder.addFrame(img, 0.033f);
//    }
//
//    if(framesCurr == framesTotal) {
//        cout << "save now" << endl;
//        encoder.save("test.gif");
//    }
    framesCurr++;
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'q') {
        negative = !negative;
    } else if(key == 'c') {
        colors = !colors;
    } else if(key == 's') {
        ofSaveScreen(ofToString(ofGetFrameNum())+".png");
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

void ofApp::onGifSaved(string &fileName) {
    cout << "gif saved as " << fileName << endl;
}




