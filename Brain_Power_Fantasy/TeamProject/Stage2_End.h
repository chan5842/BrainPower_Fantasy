#pragma once
#include "GamePhase.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <windows.h>
#include "Input.h"
#include "Script.h"

class Stage2_End : public PhaseInterface
{
public:
	Stage2_End();
	~Stage2_End();
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
