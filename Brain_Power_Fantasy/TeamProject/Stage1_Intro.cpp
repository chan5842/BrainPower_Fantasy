#include "GamePhase.h"
#include "Stage1_Intro.h"
#include "TextureManager.h"
#include <iostream>
#include <windows.h>
#include <atlstr.h>

extern SDL_Renderer* g_renderer;
extern bool g_flag_running;

Conversation conv3[] = {
	// 0:MC 1:��û�� 2:�����
	0, L"��û��! �� ����.... �����, ����� ������ ����!",
	1, L"��... �ǹ��� �� �� ���屺... �� �� �� �ƴ� ���ΰ�? �мǵ� ��ġ �λ��̴�(Insider) ���ݾ�?",
	2, L"��, ���õ� �� ���� ������ �Ƹ��䱺...",
	2, L"��? �ƴ�? �ΰ��� ��� ���⿡ ���� �� ����? �㳪 �ڳ����״� ��� ���ǵ� �������� �ʴ±�.",
	1, L"��... ��, �װ�... ������ �� ��ϴٸ�. �׳����� ���Ƕ�Ͽ�...?",
	2, L"��... ��, �� �� ���� �ʰڴ�. ���� �׳��� �� ������ ���� ���� ��ſ��� �Ǿ� �־�� �ڴ�.",
	2, L"���� �� ���� �Ƹ��ٿ�� �پ ������ ���� ���� �ҽ��� �̵鿡�� ��ġ���� �ϰڴ�.",
	1, L"���... �׳����� ���� ��� ��� �װ�...",
	2, L"��? ���� �׳��� ������ ������ Technology Company�� �巡������Ʈ�� �𸣴� �ǰ�?",
	2, L"÷�� ����� ������ ���� ���� �ܺ� ���� ȸ������.",
	2, L"�� �º��� �潽 ���п� ���� �Ƹ��ٿ� ������ �۾��� �� �� ����������.",
	2, L"��...! ����-��ũ�� ���̶�...!",
	1, L"������ ���ڴ��̽��� �����̳ʿ�����.",
	2, L"��, �� ���� ���� �ڱ� �Ұ��� ������ �� �������� �������� ����.",
	2, L"��, �ΰ�. ���� ������ ��̰� �� ���Ŷ�.",
	1, L"�ٷ� ���� ���ΰ���... ���ƿ�, (���������) �� ��ſ� �� �帮���� �ұ��?"
};

Stage1_Intro::Stage1_Intro()
{
	TextureManager *tm = TextureManager::GetSingleton();

	tm->LoadTexture("bg", "../Resources/Story_bg.png");
	tm->LoadTexture("UI", "../Resources/Story_UI.png");
	tm->LoadTexture("Hero", "../Resources/Story_Hero.png");
	tm->LoadTexture("Hero_black", "../Resources/Story_Hero.png");
	tm->LoadTexture("Enemy", "../Resources/Story_Stage1_enemy.png");
	tm->LoadTexture("Enemy_black", "../Resources/Story_Stage1_enemy.png");

	tm->SetTextureColorMode("Hero_black", 100, 100, 100);
	tm->SetTextureColorMode("Enemy_black", 100, 100, 100);

	tm->AddSpriteRect("TextBox", 21, 17, 823, 226);
	tm->AddSpriteRect("EndPoint", 888, 288, 19, 15);
	tm->AddSpriteRect("name_MC", 779, 419, 257, 51);
	tm->AddSpriteRect("name_Hero", 21, 256, 201, 51);
	tm->AddSpriteRect("name_Enemy", 21, 314, 201, 51);

	tm->AddSpriteRect("story_Hero", 0, 0, 261, 648);
	tm->AddSpriteRect("story_Enemy", 0, 0, 343, 648);

	// Script 
	{
		game_font = TTF_OpenFont("../Resources/O_BMHANNAPro.ttf", 35);
		for (int i = 0; i < 16; i++)
		{
			script[i] = new Script(game_font, conv3[i].text, 300, 535);
		}
		std::cout << "Script created." << std::endl;
	}
	line = 0;
}


void Stage1_Intro::Update()
{
	state = script[line]->GenerateScript();
}


void Stage1_Intro::Render()
{
	// SDL_SetRenderDrawColor(g_renderer, 255,255,255,255);
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color

	TextureManager *tm = TextureManager::GetSingleton();

	tm->DrawSprite("bg");

	if (conv3[line].state == 0)
	{
		// MC ������ ��ȭ
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_MC", 280, 447);
	}
	else if(conv3[line].state == 1)
	{
		// ���ΰ��� ��ȭ
		tm->DrawSprite("Hero", "story_Hero", 300, 100);
		tm->DrawSprite("Enemy_black", "story_Enemy", 700, 100);
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_Hero", 280, 447);
	}
	else if (conv3[line].state == 2)
	{
		// ������� ��ȭ
		tm->DrawSprite("Hero_black", "story_Hero", 300, 100);
		tm->DrawSprite("Enemy", "story_Enemy", 700, 100);
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_Enemy", 280, 447);
	}

	// Draw a Script
	{
		script[line]->RenderScript();
	}
	SDL_RenderPresent(g_renderer); // draw to the screen

	input.RefreshButton();
	if (state == 2 && line < 15)
	{
		line++;
		std::cout << "line++;" << std::endl;
	}
	else if (state == 2 && line == 15)
	{
		g_current_game_phase = 4; // Stage1 Battle
	}
}

void Stage1_Intro::HandleEvents()
{
	input.HandleEvents();
}



Stage1_Intro::~Stage1_Intro()
{

}

