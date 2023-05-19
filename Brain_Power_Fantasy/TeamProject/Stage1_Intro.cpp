#include "GamePhase.h"
#include "Stage1_Intro.h"
#include "TextureManager.h"
#include <iostream>
#include <windows.h>
#include <atlstr.h>

extern SDL_Renderer* g_renderer;
extern bool g_flag_running;

Conversation conv3[] = {
	// 0:MC 1:이청훈 2:스노브
	0, L"이청훈! 그 상대는.... 스노브, 고귀한 엘프의 왕자!",
	1, L"오... 실물이 더 잘 생겼군... 좀 놀 줄 아는 분인가? 패션도 마치 인사이더(Insider) 같잖아?",
	2, L"아, 오늘도 난 역시 멋지고 아름답군...",
	2, L"음? 아니? 인간이 어떻게 여기에 있을 수 있지? 허나 자네한테는 어떠한 악의도 느껴지지 않는군.",
	1, L"에... 음, 그건... 사정이 좀 깁니다만. 그나저나 악의라니요...?",
	2, L"흠... 뭐, 긴 건 묻지 않겠다. 단지 네놈은 이 위대한 짐을 위해 즐거움이 되어 주어야 겠다.",
	2, L"나의 이 멋진 아름다움과 뛰어난 지능을 여기 모인 불쌍한 이들에게 펼치도록 하겠다.",
	1, L"잠깐... 그나저나 지금 들고 계신 그건...",
	2, L"응? 설마 네놈은 내츄스의 유명한 Technology Company인 드래곤프루트를 모르는 건가?",
	2, L"첨단 기술을 선물한 마른 땅의 단비 같은 회사이지.",
	2, L"이 태블릿과 펜슬 덕분에 짐의 아름다운 디자인 작업도 한 층 수월해졌지.",
	2, L"아...! 하이-테크의 힘이란...!",
	1, L"과연… 왕자님이시자 디자이너였군요.",
	2, L"훗, 자 이제 슬슬 자기 소개는 끝내고 본 시합으로 들어가보도록 하지.",
	2, L"자, 인간. 나를 마음껏 즐겁게 해 보거라.",
	1, L"바로 들어가는 것인가요... 좋아요, (재수없지만) 한 즐거움 해 드리도록 할까요?"
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
		// MC 파이의 대화
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_MC", 280, 447);
	}
	else if(conv3[line].state == 1)
	{
		// 주인공의 대화
		tm->DrawSprite("Hero", "story_Hero", 300, 100);
		tm->DrawSprite("Enemy_black", "story_Enemy", 700, 100);
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_Hero", 280, 447);
	}
	else if (conv3[line].state == 2)
	{
		// 스노브의 대화
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

