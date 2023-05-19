#include "GamePhase.h"
#include "Stage2_End.h"
#include "TextureManager.h"
#include <iostream>
#include <windows.h>
#include <atlstr.h>

extern SDL_Renderer* g_renderer;
extern bool g_flag_running;

Conversation conv8[] = {
	// 0:MC 1:이청훈 2:칠린
	2, L"하핫~ 역시 젊은이에게는 못 당한단 말이야~ 훌륭하구먼!"
};

Stage2_End::Stage2_End()
{
	TextureManager *tm = TextureManager::GetSingleton();

	tm->LoadTexture("bg", "../Resources/Story_bg.png");
	tm->LoadTexture("UI", "../Resources/Story_UI.png");
	tm->LoadTexture("Enemy", "../Resources/Stage2_End.png");

	tm->AddSpriteRect("TextBox", 21, 17, 823, 226);
	tm->AddSpriteRect("EndPoint", 888, 288, 19, 15);
	tm->AddSpriteRect("name_Enemy", 21, 373, 201, 51);

	// Script 
	{
		game_font = TTF_OpenFont("../Resources/O_BMHANNAPro.ttf", 35);
		for (int i = 0; i < 1; i++)
		{
			script[i] = new Script(game_font, conv8[i].text, 300, 535);
		}
		std::cout << "Script created." << std::endl;
	}
	line = 0;
}


void Stage2_End::Update()
{
	state = script[line]->GenerateScript();
}


void Stage2_End::Render()
{
	// SDL_SetRenderDrawColor(g_renderer, 255,255,255,255);
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color

	TextureManager *tm = TextureManager::GetSingleton();

	tm->DrawSprite("bg");

	if (conv8[line].state == 2)
	{
		// 스노브의 대화
		tm->DrawSprite("Enemy");
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_Enemy", 280, 447);
	}

	// Draw a Script
	{
		script[line]->RenderScript();
	}
	SDL_RenderPresent(g_renderer); // draw to the screen

	input.RefreshButton();
	/*	if (state == 2 && line < 0)
	{
	line++;
	std::cout << "line++;" << std::endl;
	}
	else*/
	if (state == 2 && line == 0)
	{
		g_current_game_phase = PHASE_STAGE5_INTRO; // Stage5 Intro
	}
}

void Stage2_End::HandleEvents()
{
	input.HandleEvents();
}



Stage2_End::~Stage2_End()
{

}

