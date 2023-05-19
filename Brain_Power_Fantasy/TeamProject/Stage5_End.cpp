#include "GamePhase.h"
#include "Stage5_End.h"
#include "TextureManager.h"
#include <iostream>
#include <windows.h>
#include <atlstr.h>

extern SDL_Renderer* g_renderer;
extern bool g_flag_running;

Conversation conv11[] = {
	// 0:MC 1:이청훈 2:위즈덤맨
	2, L"...뭐? 뭐라고? 이 몸이 졌다고? 아니야, 인정할 수 없어! 인정할 수 없어!"
};

Stage5_End::Stage5_End()
{
	TextureManager *tm = TextureManager::GetSingleton();

	tm->LoadTexture("bg", "../Resources/Story_bg.png");
	tm->LoadTexture("UI", "../Resources/Story_UI.png");
	tm->LoadTexture("Enemy", "../Resources/Stage5_End.png");

	tm->AddSpriteRect("TextBox", 21, 17, 823, 226);
	tm->AddSpriteRect("EndPoint", 888, 288, 19, 15);
	tm->AddSpriteRect("name_Enemy", 21, 556, 201, 51);

	// Script 
	{
		game_font = TTF_OpenFont("../Resources/O_BMHANNAPro.ttf", 35);
		for (int i = 0; i < 1; i++)
		{
			script[i] = new Script(game_font, conv11[i].text, 300, 535);
		}
		std::cout << "Script created." << std::endl;
	}
	line = 0;
}


void Stage5_End::Update()
{
	state = script[line]->GenerateScript();
}


void Stage5_End::Render()
{
	// SDL_SetRenderDrawColor(g_renderer, 255,255,255,255);
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color

	TextureManager *tm = TextureManager::GetSingleton();

	tm->DrawSprite("bg");

	if (conv11[line].state == 2)
	{
		// 위즈덤맨 대화
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
		g_current_game_phase = 12; // Stage6 Intro
	}
}

void Stage5_End::HandleEvents()
{
	input.HandleEvents();
}



Stage5_End::~Stage5_End()
{

}

