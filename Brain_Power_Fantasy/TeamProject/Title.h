#pragma once
#include "GamePhase.h"
#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include <iostream>
#include <windows.h>

class Title : public PhaseInterface
{
public:
	Title();
	~Title();
	virtual void HandleEvents();
	virtual void Update();
	virtual void Render();

private:

};