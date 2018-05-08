//
//  brush.hpp
//  myFinalWork
//
//  Created by Shuting Jiang on 5/7/18.
//


#include "ofMain.h"


class Brush: public ofBaseApp{
public:
    vector<Brush> parentBrushList;
    float paintSize;
    float x, y;
    float angle;
    ofColor clr;
    int components[100];
    float easeOutQuint(float x);
    
    Brush(vector<Brush> brushes, float sz);
    void paint(int counter);
};
