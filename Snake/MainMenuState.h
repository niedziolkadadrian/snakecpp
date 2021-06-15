#pragma once
#include "states.h"
class MainMenuState: public States
{
public:
	void Initialize();
	void Inputs();
	void Update();
	void Draw();
};

