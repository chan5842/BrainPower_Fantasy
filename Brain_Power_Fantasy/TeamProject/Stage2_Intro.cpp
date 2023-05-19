#include "GamePhase.h"
#include "Stage2_Intro.h"
#include "TextureManager.h"
#include <iostream>
#include <windows.h>
#include <atlstr.h>

extern SDL_Renderer* g_renderer;
extern bool g_flag_running;

Conversation conv6[] = {
	// 0:MC 1:��û�� 2:ĥ��
	0, L"��û��! �� ����.... ĥ��, ������ ������ ������ �������� �����!",
	2, L"��ȣ��, �ڳװ� �ٷ� ȭ���� �� �ΰ��̱���! �ΰ��� ���� ���� �� ������ ���ӵ���������",
	2, L"�ڳ״� ����ϴٰ� �������� �ʴ±���.����, ��ĥ�ϰ� �Ѹ��ϰ� �� ���� �������ϼ�!",
	1, L"��...�����մϴ�, �Ҿƹ���...?",
	1, L"�׳����� �Ҿƹ����� �º��ϰ� ����Ʈ ��ġ ��û���� �ߴٷ�ô� �� ������, ���� ����Ͻñ���!",
	2, L"��, �̰͵� ���ΰ�? ����~ �ű��ؼ� �������ٰ� ��� �� ������� �� ������ ����!",
	2, L"�����̶� �� �����!���� �� �������� �̰ɷ� ���������� �� �� ������ ������ �ű��Ҽ�!",
	1, L"�졦 �������̶� �ճ�� ������ �͵� �� ���Ͻô� �ǰ���.",
	2, L"������, �װ� ���� �Ǽ��� ���� �̲����� ���� ���� ���ϼ�.",
	1, L"'�� ��硦 ���� �ӿ��� ��� ��ȭ�ϸ鼭 �� �� ������ ��� ſ�ϱ?'",
	2, L"����, �ƹ�ư �����ϰ� �� �� �غ����� �ϼ�.",
	2, L"�ڳ�, ���� ���� ����ٰ� ���ְų� �ϸ� �ȵȴٳס� ? �̷����� �� �Ҿƺ� �� �ؾ� �ϴϱ�, ����!",
	1, L"���� ����� ������� �����ϱ��, �ּ��� ���غ���!"
};

Stage2_Intro::Stage2_Intro()
{
	TextureManager *tm = TextureManager::GetSingleton();

	tm->LoadTexture("bg", "../Resources/Story_bg.png");
	tm->LoadTexture("UI", "../Resources/Story_UI.png");
	tm->LoadTexture("Hero", "../Resources/Story_Hero.png");
	tm->LoadTexture("Hero_black", "../Resources/Story_Hero.png");
	tm->LoadTexture("Enemy", "../Resources/Story_Stage2_enemy.png");
	tm->LoadTexture("Enemy_black", "../Resources/Story_Stage2_enemy.png");

	tm->SetTextureColorMode("Hero_black", 100, 100, 100);
	tm->SetTextureColorMode("Enemy_black", 100, 100, 100);

	tm->AddSpriteRect("TextBox", 21, 17, 823, 226);
	tm->AddSpriteRect("EndPoint", 888, 288, 19, 15);
	tm->AddSpriteRect("name_MC", 779, 419, 257, 51);
	tm->AddSpriteRect("name_Hero", 21, 256, 201, 51);
	tm->AddSpriteRect("name_Enemy", 21, 373, 201, 51);

	tm->AddSpriteRect("story_Hero", 0, 0, 261, 648);
	tm->AddSpriteRect("story_Enemy", 0, 0, 500, 595);

	// Script 
	{
		game_font = TTF_OpenFont("../Resources/O_BMHANNAPro.ttf", 35);
		for (int i = 0; i < 13; i++)
		{
			script[i] = new Script(game_font, conv6[i].text, 300, 535);
		}
		std::cout << "Script created." << std::endl;
	}
	line = 0;
}


void Stage2_Intro::Update()
{
	state = script[line]->GenerateScript();
}


void Stage2_Intro::Render()
{
	// SDL_SetRenderDrawColor(g_renderer, 255,255,255,255);
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color

	TextureManager *tm = TextureManager::GetSingleton();

	tm->DrawSprite("bg");

	if (conv6[line].state == 0)
	{
		// MC ������ ��ȭ
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_MC", 280, 447);
	}
	else if (conv6[line].state == 1)
	{
		// ���ΰ��� ��ȭ
		tm->DrawSprite("Hero", "story_Hero", 300, 100);
		tm->DrawSprite("Enemy_black", "story_Enemy", 700, 200);
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_Hero", 280, 447);
	}
	else if (conv6[line].state == 2)
	{
		// ĥ���� ��ȭ
		tm->DrawSprite("Hero_black", "story_Hero", 300, 100);
		tm->DrawSprite("Enemy", "story_Enemy", 700, 200);
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_Enemy", 280, 447);
	}

	// Draw a Script
	{
		script[line]->RenderScript();
	}
	SDL_RenderPresent(g_renderer); // draw to the screen

	input.RefreshButton();
	if (state == 2 && line < 12)
	{
		line++;
		std::cout << "line++;" << std::endl;
	}
	else if (state == 2 && line == 12)
	{
		g_current_game_phase = 7; // Stage2 Battle
	}
}

void Stage2_Intro::HandleEvents()
{
	input.HandleEvents();
}



Stage2_Intro::~Stage2_Intro()
{

}

