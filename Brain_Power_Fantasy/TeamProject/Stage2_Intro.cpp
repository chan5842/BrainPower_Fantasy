#include "GamePhase.h"
#include "Stage2_Intro.h"
#include "TextureManager.h"
#include <iostream>
#include <windows.h>
#include <atlstr.h>

extern SDL_Renderer* g_renderer;
extern bool g_flag_running;

Conversation conv6[] = {
	// 0:MC 1:이청훈 2:칠린
	0, L"이청훈! 그 상대는.... 칠린, 얼음을 가르는 강인한 대장장이 드워프!",
	2, L"오호라, 자네가 바로 화제의 그 인간이구만! 인간은 오래 전에 본 저급한 족속들이지만…",
	2, L"자네는 사악하다고 느껴지지 않는구먼.히힛, 훤칠하고 총명하게 잘 생긴 젊은이일세!",
	1, L"가...감사합니다, 할아버지...?",
	1, L"그나저나 할아버지도 태블릿하고 스마트 워치 엄청나게 잘다루시는 것 같은데, 정말 대단하시군요!",
	2, L"오, 이것들 말인가? 헷헤~ 신기해서 만져보다가 어느 새 여기까지 와 버렸지 뭔가!",
	2, L"과학이란 참 대단혀!세상 참 좋아져서 이걸로 여러가지를 할 수 있으니 참으로 신기할세!",
	1, L"흠… 대장장이라서 손놀림이 좋으신 것도 한 몫하시는 건가요.",
	2, L"어이쿠, 그게 물론 실수로 손이 미끄러질 때도 있지 말일세.",
	1, L"'이 대사… 게임 속에서 장비를 강화하면서 들어본 것 같지만 기분 탓일까…?'",
	2, L"엣헴, 아무튼 각설하고 한 판 해보도록 하세.",
	2, L"자네, 내가 나이 들었다고 봐주거나 하면 안된다네… ? 이래봐도 이 할아비도 한 솜씨 하니까, 껄껄!",
	1, L"저는 절대로 방심하지 않으니까요, 최선을 다해보죠!"
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
		// MC 파이의 대화
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_MC", 280, 447);
	}
	else if (conv6[line].state == 1)
	{
		// 주인공의 대화
		tm->DrawSprite("Hero", "story_Hero", 300, 100);
		tm->DrawSprite("Enemy_black", "story_Enemy", 700, 200);
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_Hero", 280, 447);
	}
	else if (conv6[line].state == 2)
	{
		// 칠린의 대화
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

