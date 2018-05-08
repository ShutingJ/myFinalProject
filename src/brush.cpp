//
//  brush.cpp
//  myFinalWork
//
//  Created by Shuting Jiang on 5/7/18.
//

#include "brush.h"

float Brush::easeOutQuint(float x) {
    return pow((x - 1.0f), 5.0f) + 1.0f;
}

//--------------------------------------------------------------
void Brush::paint(int counter){
    
    
    float a = 0;
    float r = 50;
    float x1 = 0;
    float y1 = 0;
    
    ofFill();
    //    noStroke();
    ofPushMatrix();
    ofTranslate(x, y);
    ofRotate(angle);
    ofBeginShape();
    
    while (a < TWO_PI) {
        float v = ofRandom(easeOutQuint(ofMap(ofClamp(r, 0, 300), 0, 500, 0, 1)), 1);
        x1 = r * cos(angle + a) * v;
        y1 = r * sin(angle + a) * v;
        ofVertex(x1, y1);
        a += PI / 180;
        for (int i = 0; i < 2; i++) {
            r += sin(a * components[i]) * 0.004 * r;
        }
    }
    ofEndShape();
    ofPopMatrix();

//    if(counter >= 100) {
        
//            cout << counter << endl;
 //           parentBrushList.erase(parentBrushList.begin(), parentBrushList.begin()+counter);
     //   }
}

Brush::Brush(vector<Brush> brushes, float sz) {
    parentBrushList = brushes;
    paintSize = sz;
    x = ofRandom(20, ofGetWidth() - 20);
    y = ofRandom(20, ofGetHeight() - 20);
    angle = ofRandom(TWO_PI);
    clr = ofColor(ofRandom(60, 300), ofRandom(10, 70), 100, 5);
    for (int i = 0; i < 2; i++) {
        components[i] = int(ofRandom(1, 5));
    }
}
