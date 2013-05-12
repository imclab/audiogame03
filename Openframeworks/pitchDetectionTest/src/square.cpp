/*
 *  square.cpp
 *  node_communication
 *
 *  Created by Gustavo Simões De Faria on 03/05/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "square.h"


void square::setup(int tempY){
	
	int carType = (int) ofRandom(2);
	
	xPos = ofGetWindowWidth();
	xSpeed = ofRandom(1,10);
	yPos = ofRandom(ofGetWindowHeight());
	
	if (carType == 0)
		enemy.loadImage("enemy.png");
	if (carType == 1)
		enemy.loadImage("enemy2.png");
	
	collision = false;
	
    
	yPos = tempY; //draw the enemie whenever the browser is hit...
}

void square::update(){
	//xPos-= xSpeed; // ofRandom(1,10);
	xPos -= 10;
	


    
}

void square::draw(float x, float y){
	
	
	if (collision == true) {
		ofSetColor(255, 0, 0);
		
		
	} else {
		ofSetColor(255);
	}
	
	
	
	
	ofNoFill();
	enemy.draw(xPos, yPos);	
	
	
		
    
}

