#include "GamePhase.h"
#include "Stage6_End.h"
#include "TextureManager.h"
#include <iostream>
#include <windows.h>
#include <atlstr.h>

extern SDL_Renderer* g_renderer;
extern bool g_flag_running;

Conversation conv14[] = {
	// 0:MC 1:이청훈 2: 딜리트
	2, L"이.... 이건? 계산에 없었던 일이었을텐데? 전지 전능한 이 내가??"
};

Stage6_End::Stage6_End()
{
	TextureManager *tm = TextureManager::GetSingleton();

	tm->LoadTexture("bg", "../Resources/Story_bg.png");
	tm->LoadTexture("UI", "../Resources/Story_UI.png");
	tm->LoadTexture("Enemy", "../Resources/Stage6_End.png");

	tm->AddSpriteRect("TextBox", 21, 17, 823, 226);
	tm->AddSpriteRect("EndPoint", 888, 288, 19, 15);
	tm->AddSpriteRect("name_Enemy", 21, 618, 274, 51);

	// Script 
	{
		game_font = TTF_OpenFont("../Resources/O_BMHANNAPro.ttf", 35);
		for (int i = 0; i < 1; i++)
		{
			script[i] = new Script(game_font, conv14[i].text, 300, 535);
		}
		std::cout << "Script created." << std::endl;
	}
	line = 0;
}


void Stage6_End::Update()
{
	state = script[line]->GenerateScript();
}


void Stage6_End::Render()
{
	// SDL_SetRenderDrawColor(g_renderer, 255,255,255,255);
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color

	TextureManager *tm = TextureManager::GetSingleton();

	tm->DrawSprite("bg");

	if (conv14[line].state == 2)
	{
		// 딜리트의 대화
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
		g_current_game_phase = 15; // Epilogue
	}
}

void Stage6_End::HandleEvents()
{
	input.HandleEvents();
}



Stage6_End::~Stage6_End()
{

}

