#pragma once
#include "GamePhase.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <windows.h>
#include "Input.h"
#include "Script.h"

class Stage5_Intro : public PhaseInterface
{
public:
	Stage5_Intro();
	~Stage5_Intro();
	virtual void HandleEvents();
	virtual void Update();
	virtual void Render();

	Input input;
private:
	TTF_Font * game_font;
	Script *script[49];
	int line;
	int state;
};