#pragma once
#include <iostream>
#include <windows.h>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

using namespace std;

extern int g_current_game_phase;

const int PHASE_TITLE = 0;
const int PHASE_PROLOGUE = 1;
const int PHASE_TUTORIAL = 2;
const int PHASE_STAGE1_INTRO = 3;
const int PHASE_STAGE1_BATTLE = 4;
const int PHASE_STAGE1_END = 5;
const int PHASE_STAGE2_INTRO = 6;
const int PHASE_STAGE2_BATTLE = 7;
const int PHASE_STAGE2_END = 8;
const int PHASE_STAGE5_INTRO = 9;
const int PHASE_STAGE5_BATTLE = 10;
const int PHASE_STAGE5_END = 11;
const int PHASE_STAGE6_INTRO = 12;
const int PHASE_STAGE6_BATTLE = 13;
const int PHASE_STAGE6_END = 14;
const int PHASE_ENDING = 15;
const int PHASE_GAMEOVER = 16;

typedef struct Text
{
	string text;
	SDL_Rect s_rect;
	SDL_Rect d_rect;
	SDL_Texture *texture;
}Text;

class PhaseInterface {

public:
	PhaseInterface() {};
	~PhaseInterface() {};

	virtual void HandleEvents() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};