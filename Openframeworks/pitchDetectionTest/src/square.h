/*
 *  square.h
 *  node_communication
 *
 *  Created by Gustavo Simões De Faria on 03/05/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofMain.h"

#ifndef vectorExample_square_h
#define vectorExample_square_h


class square {
	
public:
    void setup(int tempY);
    void update();
    void draw(float x, float y);
    
    float xPos, yPos, score, xSpeed;
	
	ofImage enemy;
	bool collision;
	
};


#endif