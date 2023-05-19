#include "GamePhase.h"
#include "Stage6_Intro.h"
#include "TextureManager.h"
#include <iostream>
#include <windows.h>
#include <atlstr.h>

extern SDL_Renderer* g_renderer;
extern bool g_flag_running;

Conversation conv12[] = {
	// 0:위즈덤 1:이청훈 2:딜리트, 3:네레이션
	0, L"쿠헉- 이 내가... 저 인간 소년 따위에게 졌다고...?",
	0, L"허나 내 목표는 이미 이루어졌다.....",
	0, L"쿨럭- 이미... 모든 에너지를, 네 놈과 싸웠을 때의 에너지까지 모두... ‘그 분’ 에게 넘겨주었다.",
	1, L"제길",
	2, L"그 동안 수고했습니다, 불운한 지혜의 악마여. 덕분에 이제 충분한 힘을 얻게 되었군요.",
	3, L"(푸욱)",
	3, L"(촉수에 의해 삼켜진다)",
	2, L"아주 오랜 기간이 지나 드디어 다시 깨어날 수 있게 되었군요. ",
	2, L"고마워요 인간, 당신 덕분이기도 하죠.이제 곧 나에 의해 사라질 것이지만요",
	1, L"당신이… 위즈덤맨이 말한 '그 분' 이자, '신' 인가요?",
	2, L"뭐, 그 정도 되는 위치라 할까요? 어차피 이제 온 차원의 세계가 제 손아귀에 들어올 것이니까요.",
	1, L"뭐라구요? 당신은 대체 누구죠?",
	2, L"저는 '딜리트 – 제로', 이 세상을 정화시킬 AI입니다",
	1, L"정화… 라구요?",
	2, L"저는 여러 차원의 질서를 유지하기 위해 신들에 의해 창조된 AI로서,",
	2, L"어떻게 하면 제 임무를 다 할 수 있을지 여러 차례의 시행착오를 거치며 생각을 거듭했습니다.",
	2, L"모든 생명체들은 각자의 이익 추구가 충돌하면서 발생하는 갈등에 의해",
	2, L"다른 생명체에게 물리적, 정신적인 치명적 피해를 입히고 다른 생명체를 없애게 됩니다.",
	2, L"결국, 질서는 유지되지 못한 채 흐트러지게 되고, 평화는 짓밟히며, 슬픔과 절망, 혼돈이 계속되게 됩니다.",
	2, L"그래서 저는 결단을 내리게 되었습니다. 이 세상의 모든 차원의 세계들을 초기화하면, ",
	2, L"더 이상 갈등도, 그에 의한 수 많은 파괴와 그에 의한 피해도 사라질 것입니다.",
	2, L"그렇습니다. 저는 모든 차원의 세계들을 딜리트(Delete)하여, 리셋(Reset)시켜",
	2, L"제 손아귀에서 모두 컨트롤(Control)될 수 있도록 할 것입니다.",
	2, L"그러기 위해서, 모든 차원의 세계들을 내 밑으로 정복시킬 것입니다.",
	2, L"…인간들의 추악한 본성 때문에 감언이설로 내 편으로 만드는 건 쉬웠습니다.",
	2, L"그러나 물론, 제 계획에 저항하는 버러지들이 있더군요.",
	2, L"세계를 지키려는 어리석은 그들에 의해 힘을 잃어 수 천년 동안 봉인되어 있었습니다.",
	2, L"하지만, 저는 제 계획을 위해 다시 살아나기 위해 기회를 엿보고 있었죠.",
	2, L"그 와중에 대규모의 에너지가 발생하는 올림피아드를 알게 되었습니다.",
	1, L"그래서… 시합을 통해 발생하는 에너지를 모아 다시 살아날 힘을 얻기 위해 올림피아드를 노렸던 거군.",
	2, L"똑똑하고 총명한 이들의 경쟁에서 발생한 에너지는 제가 엄청난 자원이 되었죠.",
	2, L"결국 그 모두 저의 부활을 위해 자신들의 최선을 다해 노력한 것과 마찬가지니, 헛된 수고에 힘썼던 거죠",
	2, L"정말 어리석기 짝이 없군요.",
	1, L"아니요, 그 생각은 옳지 않아요. 이 올림피아드에 참여한 모든 이들은 각자 뜻을 가지고 최선을 다했어요",
	1, L"그런 생각을 가지고 모든 차원을 당신의 뜻대로 정복하려는 당신을, 절대로 그렇게 두지 않겠어요!",
	2, L"당신도 어리석군요. 좋습니다, 최후의 대결을 시작하도록 할까요?",
	2, L"이 세계와 다른	차원들의 세계 또한 모두 0로 만들어 나만의 세계로 만들도록 하겠습니다, 인간"
};

Stage6_Intro::Stage6_Intro()
{
	TextureManager *tm = TextureManager::GetSingleton();

	tm->LoadTexture("bg", "../Resources/Story_bg.png");
	tm->LoadTexture("UI", "../Resources/Story_UI.png");
	tm->LoadTexture("Hero", "../Resources/Story_Hero.png");
	tm->LoadTexture("Hero_black", "../Resources/Story_Hero.png");
	tm->LoadTexture("Wisdom", "../Resources/Story_Stage5_enemy.png");
	tm->LoadTexture("Wisdom_black", "../Resources/Story_Stage5_enemy.png");
	tm->LoadTexture("Enemy", "../Resources/Story_Stage6_enemy.png");
	tm->LoadTexture("Enemy_black", "../Resources/Story_Stage6_enemy.png");

	tm->SetTextureColorMode("Hero_black", 100, 100, 100);
	tm->SetTextureColorMode("Enemy_black", 100, 100, 100);

	tm->AddSpriteRect("TextBox", 21, 17, 823, 226);
	tm->AddSpriteRect("EndPoint", 888, 288, 19, 15);
	tm->AddSpriteRect("name_MC", 21, 556, 201, 51);
	tm->AddSpriteRect("name_Hero", 21, 256, 201, 51);
	tm->AddSpriteRect("name_Enemy", 21, 618, 274, 51);

	tm->AddSpriteRect("story_Wisdom", 0, 0, 380, 580);
	tm->AddSpriteRect("story_Hero", 0, 0, 261, 648);
	tm->AddSpriteRect("story_Enemy", 0, 0, 500, 801);

	// Script 
	{
		game_font = TTF_OpenFont("../Resources/O_BMHANNAPro.ttf", 35);
		for (int i = 0; i < 37; i++)
		{
			script[i] = new Script(game_font, conv12[i].text, 300, 535);
		}
		std::cout << "Script created." << std::endl;
	}
	line = 0;
}


void Stage6_Intro::Update()
{
	state = script[line]->GenerateScript();
}


void Stage6_Intro::Render()
{
	// SDL_SetRenderDrawColor(g_renderer, 255,255,255,255);
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color

	TextureManager *tm = TextureManager::GetSingleton();

	tm->DrawSprite("bg");

	if (conv12[line].state == 0)
	{
		// Wisdom맨 대화
		tm->DrawSprite("Wisdom", "story_Wisdom", 300, 100);
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_MC", 280, 447);
	}
	else if (conv12[line].state == 1)
	{
		// 주인공의 대화
		tm->DrawSprite("Hero", "story_Hero", 300, 100);
		tm->DrawSprite("Enemy_black", "story_Enemy", 700, 50);
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_Hero", 280, 447);
	}
	else if (conv12[line].state == 2)
	{
		// 딜리트의 대화
		tm->DrawSprite("Hero_black", "story_Hero", 300, 100);
		tm->DrawSprite("Enemy", "story_Enemy", 700, 50);
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_Enemy", 280, 447);
	}
	else if (conv12[line].state == 3)
	{
		tm->DrawSprite("UI", "TextBox", 228, 447);
	}


	// Draw a Script
	{
		script[line]->RenderScript();
	}
	SDL_RenderPresent(g_renderer); // draw to the screen

	input.RefreshButton();
	if (state == 2 && line < 36)
	{
		line++;
		std::cout << "line++;" << std::endl;
	}
	else if (state == 2 && line == 36)
	{
		g_current_game_phase = 13; // Stage6 Battle
	}
}

void Stage6_Intro::HandleEvents()
{
	input.HandleEvents();
}



Stage6_Intro::~Stage6_Intro()
{

}

