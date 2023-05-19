#pragma once
#include "GamePhase.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <windows.h>
#include "Input.h"
#include "Script.h"

class Prologue : public PhaseInterface
{
public:
	Prologue();
	~Prologue();
	virtual void HandleEvents();
	virtual void Update();
	virtual void Render();
private:
	Input input;
	TTF_Font *game_font;
	Script *script[64];
	int line;
	int state;
};