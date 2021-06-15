#include "StateMachine.h"

void StateMachine::addState(States* newState, bool toReplace=true){
	this->states.push(newState);
}

States* StateMachine::getActiveState(){
	this->states.top();
}

