/*
 *  scenario.cpp
 *  week5_audioRMSandZeroCrossingPitch
 *
 *  Created by Gustavo Simões De Faria on 23/04/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "scenario.h"

//--------------------------------------------------------------
void scenario::setup(){
	
	xPosRoad = ofGetWindowWidth();
	
}

//--------------------------------------------------------------
void scenario::update(){
	
	xPosRoad-=4;
	
}

//--------------------------------------------------------------
void scenario::draw(float x){
	
	
	ofFill();
	ofSetColor(255, 142, 15);

	//LATERAIS
	ofPushMatrix();
	ofRect(0, 20, ofGetWindowWidth()*2, 10);
	ofRect(0, ofGetWindowHeight() - 30, ofGetWindowWidth()*2, 10);
	ofPopMatrix();
	
	
	//CENTER
	ofPushMatrix();
	ofRect(0, ofGetWindowHeight()/2+10, ofGetWindowWidth()*2, 7);
	ofRect(0, ofGetWindowHeight()/2-10, ofGetWindowWidth()*2, 7);
	ofPopMatrix();	
	
	
	
	//WHITE RECTANGLES
	ofPushMatrix();
	ofFill();
	ofSetColor(255);
	ofRect(xPosRoad, ofGetWindowHeight()/4, 60, 7);
	ofRect(xPosRoad, ofGetWindowHeight()/4*3, 60, 7);
	ofPopMatrix();

}