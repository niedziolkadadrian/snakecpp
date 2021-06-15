#ifndef STATEMACHINE_H
#define STATEMACHINE_H
#include <stack>
#include "States.h"
class StateMachine
{
private:
	std::stack<States*> states;
public:
	void addState(States* newState, bool toReplace=true);
	void removeState();

	States* getActiveState();
};
#endif

