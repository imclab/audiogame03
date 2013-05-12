/*
 *  scenario.h
 *  week5_audioRMSandZeroCrossingPitch
 *
 *  Created by Gustavo Simões De Faria on 23/04/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */



#include "ofMain.h"

#ifndef week5_audioRMSandZeroCrossingPitch__scenario_h
#define week5_audioRMSandZeroCrossingPitch__scenario_h

class scenario {
	
public:
    void setup();
    void update();
    void draw(float x);
	
	float xPosRoad;
	
};



#endif