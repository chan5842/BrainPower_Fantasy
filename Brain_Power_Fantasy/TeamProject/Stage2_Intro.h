#pragma once
#include "GamePhase.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <windows.h>
#include "Input.h"
#include "Script.h"

class Stage2_Intro : public PhaseInterface
{
public:
	Stage2_Intro();
	~Stage2_Intro();
	virtual void HandleEvents();
	virtual void Update();
	virtual void Render();

	Input input;
private:
	TTF_Font * game_font;
	Script *script[13];
	int line;
	int state;
};