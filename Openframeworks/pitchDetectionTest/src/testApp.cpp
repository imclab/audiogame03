#include "testApp.h"
#include "stdio.h"

//--------------------------------------------------------------
void testApp::setup(){	 
	
	ofBackground(54, 54, 54);	
	
	// 0 output channels, 
	// 2 input channels
	// 44100 samples per second
	// 256 samples per buffer
	// 4 num buffers (latency)
	
	
	
	
	ofSetCircleResolution(100);
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofEnableAlphaBlending();
	
    AA.setup();
    
	//setup of sound input
	ofSoundStreamSetup(0, 2, this, 44100, 256, 4);
	left = new float[256];	
	right = new float[256];
	
	
    bThisFrameOK = false;
    bLastFrameOK = false;
    bFirstFrameSmooth = true;
    
    diffSmooth = 0;
	
	dinFont.loadFont("DIN.otf", 10);
	
	
	
	// MY CAR STUFF
	myCar.loadImage("car.png");
	pos.x = 200;
	pos.y = ofGetWindowHeight()/2;
	vel.y = 0;
	
	
	// MY ENEMIES INICIAL POSITION
	posEnemies.x = 0;
	posEnemies.y = 0;
	
	
	//CONNECTION
	oscReceiver.setup(3333);
	
	
	// SCENARIO
	for (int i=0; i<myScenario.size(); i++) {
		myScenario[i].setup();
	}


	
}

//--------------------------------------------------------------
void testApp::update(){
	
	//UPDATE ENEMIES
	ofFill();
    ofSetColor(255, 0, 0);
    for (int i=0; i<squares.size(); i++) {
        squares[i].update();
		
	}
	
	
	
	// SET VELOCITY ACCORDING TO THE DIFFERENCE PITCH ONLY IF THE SOUND IS HIGH ENOUGH
	if (AA.amplitude > 0.05) {
		vel.y = diffSmooth*2;
	}  else {
		vel.y = 0;
	}
	
	pos.y += vel.y;
	
	
	//CONNECTION
	while(oscReceiver.hasWaitingMessages()) {
		ofxOscMessage message;
		oscReceiver.getNextMessage(&message);
		
		
		
		if(message.getAddress() == "/mousePositionY") {
			posEnemies.y = message.getArgAsInt32(0);
			
		}
		
		if(message.getAddress() == "/mousePositionX") {
			posEnemies.x = message.getArgAsInt32(0);
			
			
		}
		
		// CREATE ENEMIES
		square tempSquare;  
		int tempY = posEnemies.y;
		tempSquare.setup(tempY);
		squares.push_back(tempSquare);		
	}
	
	
	
	//UPDATE THE SCENARIO
	for (int i=0; i<myScenario.size(); i++) {
		myScenario[i].update();
		//ERASE OBJECT WHEN IT GET OUT OF THE SCEEN
		if (myScenario[i].xPosRoad < -100) {
			myScenario.erase(myScenario.begin() + i);
		}
	}
	
	//COUNTER SCENARIO
	float roadTime = ofGetElapsedTimef() - lastTime;
    if (roadTime > duration){
		
        lastTime = ofGetElapsedTimef();
        duration = 0.5;
		
		scenario tempScenario;  
		tempScenario.setup();
		myScenario.push_back(tempScenario);
	}
	
	
	

    
}


//--------------------------------------------------------------
void testApp::draw(){
	
	
	for (int i=0; i<myScenario.size(); i++) {
		myScenario[i].draw(i*10);
	}
	
	// DRAW MY CAR //-------------------------------------------------------------- DRAW MY CAR
	ofSetColor(255);
	myCar.draw(150, pos.y);
	
	// DRAW ENEMIES //-------------------------------------------------------------- DRAW ENEMIES
    for (int i=0; i<squares.size(); i++) {
		
		squares[i].draw(posEnemies.x, posEnemies.y);	
		
	}
	
	 
	// DON'T GO OUT OF THE SCREEN //-------------------------------------------------------------- DON'T GO OUT OF THE SCREEN
	if (pos.y < 0) {
		pos.y = 0;
	} else if (pos.y > ofGetWindowHeight()-100) {
		pos.y = ofGetWindowHeight()-100;
	}
	
	
	
	// DRAW AUDIO STUFF //--------------------------------------------------------------  DRAW AUDIO STUFF
	// draw the left:
	ofSetHexColor(0x333333);
	ofRect(0,0,256,200);
	ofSetHexColor(0xFFFFFF);
	for (int i = 0; i < 256; i++){
		ofLine(i,100,i,100+left[i]*200);
	}

	
	
	// DEBUG //-------------------------------------------------------------- DEBUG
	ofSetHexColor(0x000000);
	ofSetColor(255);
	dinFont.drawString( "pitch is : " + ofToString((int)AA.pitch), 10,250);
    dinFont.drawString( "amplitude is : " + ofToString(AA.amplitude,3), 10,270);
	dinFont.drawString( "confidence is : " + ofToString(AA.confidence), 10,290);
	dinFont.drawString( "diffSmooth is : " + ofToString(diffSmooth), 10,310);

}


//--------------------------------------------------------------
void testApp::audioReceived (float * input, int bufferSize, int nChannels){	
	
	
	// samples are "interleaved"
	for (int i = 0; i < bufferSize; i++){
		left[i] = input[i*2];		
		right[i] = input[i*2+1];
	}

	AA.processAudio(left, bufferSize);
    
    
    if (AA.amplitude > 0.01 && AA.confidence > 0.7){
        
        bThisFrameOK = true;
    } else {
        
        bThisFrameOK = false;
        
    }
    
    
    if (bLastFrameOK && bThisFrameOK){
        
       
        //cout << " " << prevPitch << " " << AA.pitch << endl;
        float diffPitch  = AA.pitch - prevPitch;
        
            diffSmooth = 0.99 * diffSmooth + 0.01 * diffPitch;
            
        cout << diffSmooth << endl;
    } else {
        
//		diffSmooth *= 0.93; // FADEEEEE OUT
		//diffSmooth = 0;
        bFirstFrameSmooth = true;
		
		
    }
    
    
    if (bThisFrameOK){
        prevPitch = AA.pitch;
    }
    
    // at the end:
    bLastFrameOK = bThisFrameOK;
	
    
}



//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
    

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	
}


