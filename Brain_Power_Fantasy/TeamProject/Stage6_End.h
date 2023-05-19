#pragma once
#include "GamePhase.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <windows.h>
#include "Input.h"
#include "Script.h"

class Stage6_End : public PhaseInterface
{
public:
	Stage6_End();
	~Stage6_End();
	virtual void HandleEvents();
	virtual void Update();
	virtual void Render();
	Input input;
private:
	TTF_Font * game_font;
	Script *script[1];
	int line;
	int state;
};

