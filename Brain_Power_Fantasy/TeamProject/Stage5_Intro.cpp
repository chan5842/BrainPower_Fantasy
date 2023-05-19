#include "GamePhase.h"
#include "Stage5_Intro.h"
#include "TextureManager.h"
#include <iostream>
#include <windows.h>
#include <atlstr.h>

extern SDL_Renderer* g_renderer;
extern bool g_flag_running;

Conversation conv9[] = {
	// 0:MC 1:이청훈 4: 위즈덤맨
	0, L"자-아~ 열기가 최고조로 오른 가운데 이제 모든 경기가 종료되었습니다!",
	0, L"마침내 마지막에 남은 선수는 바로...... 이청훈 선수입니다!",
	1, L"'최종 승리자를 향한 관중의 환호성이 들려온다. 근데… 내가 인간이어도 정말 상관없는 거야?'",
	0, L"워후~! 엄청 뜨겁군요! 자, 마지막으로 남은 No. 1 이청훈 선수",
	0, L"여기 단상으로 올라오시길 바랍니다.",
	1, L"'후, 일단 여기까지 해내긴 했네... 이렇게 끝나는 건가?'",
	0, L"자… No. 1에게 트로피를 수여하도록 하겠습니다…… 하기 전에",
	0, L"여러분, 여기서 끝날 것이라고 생각했지만... 과연 그럴까요 ?",
	1, L"???",
	0, L"여기서 그냥 바로 ‘특별 엑시비전(Exhibition) 챌린지(Challenge) 매치’",
	0, L"없이 끝나면 재미가 확 떨어지지 않겠어요~? 그! 래! 서!",
	0, L"모두의 관심을 끄는 엄청난 스케일의 대폭발로 등장하다니, 누가 이런 기발한	생각을 했으려나?",
	0, L"으우, 이 몸의 화려한 스포트라이트를 위해 정말 참을 수 없었단 말야!",
	1, L"네 놈, 대체 누구냐! MC로서 이런 신성한 스테이지를 먹칠하다니, 제정신이냐!",
	4, L"아, 네놈들이 있었군. 뭐, 자기 소개라도 할까나. 이 몸은 위즈덤맨, 위대한 악마이시다",
	1, L"악마… 라구요? 뭘 하려는 거죠?",
	4, L"훗, 이 올림피아드는 정말로 쓸모 있었어. 올림피아드에서 펼쳐지는 여러 명의 똑똑한 인재들의",
	4, L"인텔리전스 에너지와 간의 여러 번의 경기를 통해 발생한 엄청난 인텔리전스 에너지가 모여",
	4, L"위대한 신이신 ‘그 분’의 부할과 힘을 얻기 위한 충분한 양이 모였지.",
	1, L"신…? 부활…? 그래서 뭘 하려는 거에요?",
	4, L"후후... 모르면 사라지면 되는 거다. 방해되는 버러지들은 모조리 사라지기만 하면 되니까",
	1, L"그나저나 MC가 갑자기 이렇게 나온다고? 아냐, 뭐 뻔한 클리셰... 일려나...",
	4, L"뭐... 뭐시라? 뻔한 클리셰? 감히 위대한 이 몸한테 그런 말을 내뱉다니 겁을 상실한 거냐?",
	1, L"뭐야, 그렇게까지 흥분할 일이에요?",
	4, L"흥, 네놈은 밑바닥에서 벌레처럼 기어다니는 삶을 겪어보고 그런 소리가 나오나?",
	1, L"무슨 소리에요?",
	4, L"이 외뿔 때문에, 태어날 때부터 지게 된 이 외뿔 때문에 지금까지 다른 악마들에게 당하고 있어야 했던",
	4, L"무시와 차별, 업신여김과 조롱을, 네놈은 아느냐 말이다.",
	4, L"그리고 가문에 먹칠을 한 오점으로 취급되며 느낀 소외감과 절망감을, 네놈은 아느냐 말이다.",
	1, L"......",
	4, L"그런 와중에 만난 그 분은, 내게 희망과 구원을 약속하셨다. 내게 큰 신념과 힘을 주셨다.",
	4, L"그런 난, 지금까지 그 분을 위해 모든 걸 바쳤지. 그리고 이제서야, 난 부활한 그 분과 함께",
	4, L"이 지긋지긋한 세계와 다른 차원의 세계를 모조리 지워버리고, 오직 그 분을 위해 만들어진 새로운 세계에서,",
	4, L"난 구원받을 것이고 지금까지 받아온 모든 고난과 수모에 대한 보상을 받게 될 것이다.",
	4, L"하, 하하하… 누가 알았겠나? 모두가 비웃던 외뿔의 패배자가 이렇게 큰 일을 해낼 줄을!",
	1, L"....... 뭔 헛소리야..",
	4, L"뭐라고?",
	1, L"이해를 못하겠네요. 그게 정말 구원받고 행복할 거라고 생각하는 거에요?",
	1, L"당신이 지금까지 받은 고통을 이해 못 하는 건 아니에요.",
	1, L"저도 옛날에 남들과는 달리 공부도 못 하고 운동도 못 해서 왕따를 당한 적이 있으니까요.",
	1, L"하지만, 난 그에 굴하지 않고 나 자신에게 떳떳해질 수 있도록",
	1, L"나를 위해서 열심히 내가 할 수 있는 것을 찾아가면서 그것을 위해 최선을 다했고",
	1, L"지금의	내가 될 수 있었어요.나 말고도 다른 분들도 노력하면서 살아가요. 모두가요.",
	1, L"그런 저와 그들의 모든 노력을… 없애겠다는 것은, 절대로 용서할 수 없어요!",
	1, L"당신들이 그럴 권리는 이 세상 어디에도 있을 수 없어요!",
	4, L"마지막으로 할 말은 이미 거머쥔 자들의 잘난 배부른 소리였던 거냐? 뭐, 좋아.",
	4, L"이제 이 경기가 네 놈의 최후의 경기가 될 테니까 말야.",
	4, L"그 분을 위해서 네놈의 에너지 또한 고맙게 앗아가도록 하겠다.",
	1, L"결국 제 말은 듣지 않으신다는 건가요… 좋아요, 제가 막겠습니다!"
};

Stage5_Intro::Stage5_Intro()
{
	TextureManager *tm = TextureManager::GetSingleton();

	tm->LoadTexture("bg", "../Resources/Story_bg.png");
	tm->LoadTexture("UI", "../Resources/Story_UI.png");
	tm->LoadTexture("Hero", "../Resources/Story_Hero.png");
	tm->LoadTexture("Hero_black", "../Resources/Story_Hero.png");
	tm->LoadTexture("Enemy", "../Resources/Story_Stage5_enemy.png");
	tm->LoadTexture("Enemy_black", "../Resources/Story_Stage5_enemy.png");

	tm->SetTextureColorMode("Hero_black", 100, 100, 100);
	tm->SetTextureColorMode("Enemy_black", 100, 100, 100);

	tm->AddSpriteRect("TextBox", 21, 17, 823, 226);
	tm->AddSpriteRect("EndPoint", 888, 288, 19, 15);
	tm->AddSpriteRect("name_MC", 779, 419, 257, 51);
	tm->AddSpriteRect("name_Hero", 21, 256, 201, 51);
	tm->AddSpriteRect("name_Enemy", 21, 556, 201, 51);

	tm->AddSpriteRect("story_Hero", 0, 0, 261, 648);
	tm->AddSpriteRect("story_Enemy", 0, 0, 380, 580);

	// Script 
	{
		game_font = TTF_OpenFont("../Resources/O_BMHANNAPro.ttf", 35);
		for (int i = 0; i < 49; i++)
		{
			script[i] = new Script(game_font, conv9[i].text, 300, 535);
		}
		std::cout << "Script created." << std::endl;
	}
	line = 0;
}


void Stage5_Intro::Update()
{
	state = script[line]->GenerateScript();
}


void Stage5_Intro::Render()
{
	// SDL_SetRenderDrawColor(g_renderer, 255,255,255,255);
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color

	TextureManager *tm = TextureManager::GetSingleton();

	tm->DrawSprite("bg");

	if (conv9[line].state == 0)
	{
		// MC 파이의 대화
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_MC", 280, 447);
	}
	else if (conv9[line].state == 1)
	{
		// 주인공의 대화
		tm->DrawSprite("Hero", "story_Hero", 300, 100);
		tm->DrawSprite("Enemy_black", "story_Enemy", 700, 100);
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_Hero", 280, 447);
	}
	else if (conv9[line].state == 4)
	{
		// 위즈덤맨의 대화
		tm->DrawSprite("Hero_black", "story_Hero", 300, 100);
		tm->DrawSprite("Enemy", "story_Enemy", 700,100);
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_Enemy", 280, 447);
	}

	// Draw a Script
	{
		script[line]->RenderScript();
	}
	SDL_RenderPresent(g_renderer); // draw to the screen

	input.RefreshButton();
	if (state == 2 && line < 48)
	{
		line++;
		std::cout << "line++;" << std::endl;
	}
	else if (state == 2 && line == 48)
	{
		g_current_game_phase = 10; // Stage5 Battle
	}
}

void Stage5_Intro::HandleEvents()
{
	input.HandleEvents();
}



Stage5_Intro::~Stage5_Intro()
{

}

