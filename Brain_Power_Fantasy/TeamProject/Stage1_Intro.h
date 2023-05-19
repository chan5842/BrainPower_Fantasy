#pragma once
#include "GamePhase.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <windows.h>
#include "Input.h"
#include "Script.h"

class Stage1_Intro : public PhaseInterface
{
public:
	Stage1_Intro();
	~Stage1_Intro();
	virtual void HandleEvents();
	virtual void Update();
	virtual void Render();

	Input input;
private:
	TTF_Font *game_font;
	Script *script[16];
	int line;
	int state;
};