#include "ofApp.h"
#include <random>

void ofApp::setup(){

    //Setup variables
    srand (time(NULL));
    grid::setDoUpdate(true);
    debugger::setDebug(debug);

    //Log that app has started
	debugger::log("App started");

    //Setting up game vars
    game::setEatFlag(true);
    frameCount = 0;
	tile::setSize(30);

    //Setup grid vars
    g.setGH(30);
	g.setGW(60);
	g.setLineColour(ofColor::fromHex(0xCCCCCC));
	g.createGrid();

    //Setup snake vars
    s.setX(15);
    s.setY(30);
    s.setDirection(1);

    //Setup completed, log
    debugger::log("Setup complete");
}

void ofApp::update(){
    //Increment frame counter, handle keypresses, check if we need to spawn food
    frameCount++;
    handleKeypresses();
    game::checkFood();

    //If the grid is being updated, then get ready to draw it
    if(grid::getDoUpdate()){
        grid::resetGrid();

        //Only move the snake every 10 frames
        if(frameCount % 10 == 0){
            s.move();
        }
    }
}

void ofApp::draw(){    
    ofBackground(20);   //Clear background
    s.draw();           //Draw snake
    game::drawFood();   //Draw food
    g.drawGrid();       //Draw grid
}

void ofApp::handleKeypresses(){
    //Pause key (Enter)
    if(keys[13]){ grid::setDoUpdate(!grid::getDoUpdate()); }

    //I key (Toggle debug)
    if(keys[105]){ debugger::setDebug(!debugger::getDebug()); }

    //Directional keys: W, A, S, D
    if(grid::getDoUpdate()){
        switch(s.getDirection()){
            case 0: //Heading up
                if(keys[97] && !keys[100]){ //Pressing A and not D
                    s.turn(true);
                } else if(keys[100] && !keys[97]){ //Pressing D and not A
                    s.turn(false);
                }
                break;
            case 1: //Heading right
            if(keys[115] && !keys[119]){ //Pressing S and not W
                s.turn(false);
            } else if(keys[119] && !keys[115]){  //Pressing W and not S
                s.turn(true);
            }
                break;
            case 2: //Heading down
            if(keys[97] && !keys[100]){ //Pressing A and not D
                s.turn(false);
            } else if(keys[100] && !keys[97]){ //Pressing D and not A
                s.turn(true);
            }
                break;
            case 3: //Heading left
            if(keys[115] && !keys[119]){ //Pressing S and not W
                s.turn(true);
            } else if(keys[119] && !keys[115]){  //Pressing W and not S
                s.turn(false);
            }
                break;
        }
     }

    //Reset all keys to make sure they're not registering as multiple inputs
    keys[13] = false;
    keys[97] = false;
    keys[100] = false;
    keys[105] = false;
    keys[115] = false;
    keys[119] = false;
}

void ofApp::keyPressed(int key){
    //Log key press
    std::string msg = "Key "; msg += key; msg += "("; msg += std::to_string(key); msg += ")"; msg += " pressed on frame "; msg += std::to_string(frameCount);
    debugger::log(msg);

    //Show specified key as being pressed
    keys[key] = true;
}


//Not used
void ofApp::keyReleased(int key){}
void ofApp::mouseMoved(int x, int y ){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::mouseEntered(int x, int y){}
void ofApp::mouseExited(int x, int y){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){}
