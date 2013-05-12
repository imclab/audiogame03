#ifndef _TEST_APP
#define _TEST_APP



#include "ofMain.h"
#include "aubioAnalyzer.h"
#include "ofxOsc.h"
#include "square.h"
#include "scenario.h"


class testApp : public ofSimpleApp{
	
	public:
				
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased();		
		void audioReceived		(float * input, int bufferSize, int nChannels); 
		
		//AUDIO
		float * left;
		float * right;
	
		aubioAnalyzer AA;
	
		ofTrueTypeFont dinFont;
    
        bool bThisFrameOK;
        bool bLastFrameOK;
        bool bFirstFrameSmooth;
    
        float diffSmooth;
        float prevPitch;
        bool bFullscreen;
		
		// CONNECTION
		ofxOscReceiver oscReceiver;	
	
	
		//ENEMIES
		ofPoint posEnemies;
		vector<square> squares;
	
		
		//MY CAR
		ofImage myCar;
		ofPoint pos, vel;
	
	
	// SCENARIO
	vector<scenario> myScenario;
	float lastTime;
	float duration;
	

    
    
	
};

#endif	

