#include "GamePhase.h"
#include "Epilogue.h"
#include "TextureManager.h"
#include <iostream>
#include <windows.h>
#include <atlstr.h>

extern SDL_Renderer* g_renderer;
extern bool g_flag_running;



Conversation conv15[] = {
	// -1: 나래이션 0: 딜리트-제로 1:이청훈 2:칠린 3:스노브 4:포제시언 5:알먼 6:캬투스
	0, L"인정할 수 없습니다. 이 내가... 내가 졌다니?",
	2, L"해... 해냈다... 해냈다아아아아아아!!!",
	1, L"후... 와... 이런, 세상에......",
	0, L"인정할 수 밖에 없군요. 이미 벌어진 일에 대해서 부정은 비효율적일 뿐입니다.",
	3, L"뭣... 이렇게빨리...?",
	0, L"후훗, 전 AI이니까요. 이치에는 당연히 밝습니다. 그나저나 과연, 인간은 강하군요.",
	1, L"잠깐... 당신 조각조각... 없어지잖아...?",
	0, L"느낌이 좀 좋지 않군요... 패자는 깨끗하게 인정하고 사라지는 법입니다.",
	0, L"저도 패배했으니, 그저 사라져야 될 뿐. 전 다시 제 자리로 돌아가는 것입니다.",
	1, L"잠깐만요, 제로 씨. 잠깐만요. 보내기 전에 이 말만은 하고 싶었어요.",
	1, L"당신도 보아 왔겠지만, 물론 이기적이고 잔혹할 이들도 존재할 수 있어요.",
	1, L"하지만… 이 세상에는 그런 이들만 있는건 아니에요.",
	1, L"언젠가 다가올 밝은 미래를 위해, 모두가 행복하고 평화롭게 공존할 수 있는 세상을 위해,",
	1, L"오늘과 내일에 최선을 다하는 이들이 있어요.",
	1, L"이 올림피아드의 모두들도… 각자 최선을 다했어요.",
	1, L"그러니, 믿어주세요. 한 번만, 우리들에게,",
	1, L"이 세상의 모든 이들에게, 한 번의 기회를 주세요.",
	0, L"좋은 경기였어요, 이청훈. 경기에서 파악할 수 있었던 당신의 놀라운 가능성을 보면서, ",
	0, L"전 확신할 수 있었습니다. 이 세상의 모두가 해낼 수 있을 것이라는 것을.",
	0, L"맞아요, 다시 한 번, 당신들을 믿을 수 있다고 생각합니다. 그럼 부디... 힘내주십시오.",
	-1, L"그리고 제로 씨는... 작은 조각들이 되어 사라졌다.",
	2, L"흠... 저기 어두운 하늘이 걷히고, 다시 맑은 하늘로 돌아오는구먼.",
	5, L"“어이! 다들 괜찮은가?",
	1, L"앗, 알먼 씨! 캬투스 씨!",
	5, L"아아, 다행이군… 예상치 못한 갑작스런 상황이었지만...",
	5, L"모두들 고맙네. 특히, 청훈 군. 자네가 이 세상을 구해줬어.",
	6, L"수고했다. 훌륭하게 임무를 완수했군, 너.",
	1, L"네… 잠시만, 임무라니요?",
	4, L"그건... 제가 설명하도록 할까요.",
	4, L"사랑스러운 땅, 내츄스의 여신인 포제시언이라고 합니다.",
	4, L"“이청훈, 당신은 사실 세상을 구하기 위해 이 땅, 내츄스에 오게 된 것입니다.",
	4, L"전 딜리트-엔드의 계획을 알아차리게 되어 막으려고 했지만,",
	4, L"제 권한 밖의 일이라 힘을 쓸 수가 없어 올림피아드의 우승자 두 분,",
	4, L"알먼과 캬투스의 도움을 받아 세상을 구할 완벽한 인간을 찾도록 했습니다.",
	4, L"이 또한, 내츄스에서 악행을 일삼은 인간들의 속죄라고 할 수도 있겠죠.",
	4, L"일단 갑작스럽게 납치한 것은 미안해요. 하지만... 이 세상을 구해줘서,",
	4, L"사랑스러운 이 내츄스의 시민들을 지켜줘서, 큰 감사를 표하겠습니다.",
	1, L"뭐, 어차피 꿈도 아닌 현실이니까요. 경기를 통해 여러분들을 만나고,",
	1, L"여러분들의 이야기에 공감할 수 있어서, 뜻 깊은 시간이었다고 생각해요.",
	4, L"감사합니다, 이청훈. 당신이 바로, 이번 올림피아드의 진정한 승리자, 챔피언입니다.",
	4, L"그나저나, 소원을 이루어줄까 하는데... 예상은 되지만 여쭤보도록 할까요.",
	1, L"“네............ 저 집에 가고 싶으니 제발... 보내주세요!!!",
	4, L"자, 그럼... 여기서 바로 지구로 보내드리도록 하죠.",
	4, L"그 전에, 이 트로피 – 당신이 챔피언이었다는 증거를 잊지 말고 가져가주세요.",
	1, L"감사합니다.",
	4, L"마지막 작별인사를 가져볼까요.",
	1, L"네. 비록 짧았지만 여러분, 즐거웠습니다...",
	1, L"경기에서 보여주셨던 이야기... 절대로 잊지 않고 앞으로의 미래를 응원할게요!",
	2, L"크... 크흑... 사나이 눈에서 물이 나오는구먼...",
	5, L"감사를 표하네.",
	6, L"이쪽도 마찬가지다.",
	3, L"잘 가라, 네 놈. 아니, 나의 영원한 라이벌 – 인간 이청훈이여.",
	1, L"아니, 거기서 갑자기 라이벌 선언이라뇨, 참내... 일단 좋아요!",
	4, L"그럼... 바로 지구, 당신이 있었던 그 곳으로 보내드리도록 하겠습니다",
	1, L"감사합니다… 그러면, 여러분- 작별이에요!",
	-1, L"그리고 그 순간, 빛 같은 속도로 어딘가로 휩쓸리면서 점점 정신이 아득해져갔다.",
	-1, L"......눈부시다. 여긴 어디? 나는 누구? ...가 아니지.",
	-1, L"다시 돌아왔다... 그리고 손에는 트로피가 쥐어져 있다.",
	-1, L"돌아왔구나... 실감이 나지는 않지만 돌아왔다.",
	-1, L"하지만 확실한 것은, 꿈이 아닌 실제로 내가 경험한 일이라는 것이다.",
	-1, L"모두들, 다시 한 발 앞으로 내딛을 수 있겠지.",
	-1, L"모두의 이야기가, 한 챕터 앞으로 나아갈 수 있길 빈다.",
	-1, L"그럼... 집으로 가볼까! 부모님이 보고 싶어졌어!",
	-1, L"THE END"
};

Epilogue::Epilogue()
{
	TextureManager *tm = TextureManager::GetSingleton();

	tm->LoadTexture("bg", "../Resources/Story_bg.png");
	tm->LoadTexture("bg_Street", "../Resources/Street.png");
	tm->LoadTexture("UI", "../Resources/Story_UI.png");
	tm->LoadTexture("Hero", "../Resources/Story_Hero.png");
	tm->LoadTexture("Hero_black", "../Resources/Story_Hero.png");
	tm->LoadTexture("Go1", "../Resources/go1.png");
	tm->LoadTexture("Go1_black", "../Resources/go1.png");
	tm->LoadTexture("Go2", "../Resources/go2.png");
	tm->LoadTexture("Go2_black", "../Resources/go2.png");

	tm->LoadTexture("Chill", "../Resources/Story_Stage2_enemy.png");
	tm->LoadTexture("Snobe", "../Resources/Story_Stage1_enemy.png");
	tm->LoadTexture("Godess", "../Resources/Godess.png");
	tm->LoadTexture("Zero", "../Resources/Epilogue_Zero.png");

	tm->SetTextureColorMode("Hero_black", 100, 100, 100);
	tm->SetTextureColorMode("Go1_black", 100, 100, 100);
	tm->SetTextureColorMode("Go2_black", 100, 100, 100);

	tm->AddSpriteRect("TextBox", 21, 17, 823, 226);
	tm->AddSpriteRect("EndPoint", 888, 288, 19, 15);
	tm->AddSpriteRect("name_Snobe", 21, 314, 201, 51);
	tm->AddSpriteRect("name_Hero", 21, 256, 201, 51);
	tm->AddSpriteRect("name_Chill", 21, 373, 201, 51);
	tm->AddSpriteRect("name_Zero", 21, 618, 274, 51);

	tm->AddSpriteRect("story_Hero", 0, 0, 260, 648);
	tm->AddSpriteRect("story_Go1", 0, 0, 239, 500);
	tm->AddSpriteRect("story_Go2", 0, 0, 311, 500);
	tm->AddSpriteRect("story_Chill", 0, 0, 500, 595);
	tm->AddSpriteRect("story_Godess", 0, 0, 415, 600);
	tm->AddSpriteRect("story_end_Zero", 0, 0, 934, 600);
	tm->AddSpriteRect("story_Snobe", 0, 0, 343, 648);

	// Script 
	{
		game_font = TTF_OpenFont("../Resources/O_BMHANNAPro.ttf", 35);
		for (int i = 0; i < 64; i++)
		{
			script[i] = new Script(game_font, conv15[i].text, 300, 535);
		}
		std::cout << "Script created." << std::endl;
	}
	line = 0;
}


void Epilogue::Update()
{
	state = script[line]->GenerateScript();
}


void Epilogue::Render()
{
	SDL_SetRenderDrawColor(g_renderer, 255, 255, 255, 255);
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color

	TextureManager *tm = TextureManager::GetSingleton();




	// -1: 나래이션 0: 딜리트-제로 1:이청훈 2:칠린 3:스노브 4:포제시언 5:알먼 6:캬투스
	if (conv15[line].state == -1)
	{
		tm->DrawSprite("UI", "TextBox", 228, 447);
	}
	else if (conv15[line].state == 0)
	{
		tm->DrawSprite("Zero", "story_end_Zero", 300, 100);
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_Zero", 280, 447);
	}
	else if (conv15[line].state == 1)
	{
		tm->DrawSprite("Hero", "story_Hero", 500, 100);
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_Hero", 280, 447);
	}
	else if (conv15[line].state == 2)
	{
		tm->DrawSprite("Chill", "story_Chill", 500, 100);
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_Chill", 280, 447);
	}
	else if (conv15[line].state == 3)
	{
		// 스노브
		tm->DrawSprite("Snobe", "story_Snobe", 700, 200);
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_Snobe", 280, 447);
	}
	else if (conv15[line].state == 4)
	{
		// 포제시언
		tm->DrawSprite("Godess", "story_Godess", 500, 100);
		tm->DrawSprite("UI", "TextBox", 228, 447);
	}
	else if (conv15[line].state == 5)
	{
		// 알먼
		tm->DrawSprite("Go1", "story_Go1", 700, 200);
		tm->DrawSprite("Go2_black", "story_Go2", 900, 200);
		tm->DrawSprite("UI", "TextBox", 228, 447);

	}
	else if (conv15[line].state == 6)
	{
		// 캬투스
		tm->DrawSprite("Go1_black", "story_Go1", 700, 200);
		tm->DrawSprite("Go2", "story_Go2", 900, 200);
		tm->DrawSprite("UI", "TextBox", 228, 447);
	}


	// Draw a Script
	{
		script[line]->RenderScript();
	}
	SDL_RenderPresent(g_renderer); // draw to the screen

	input.RefreshButton();
	if (state == 2 && line < 62)
	{
		line++;
		std::cout << "line++;" << std::endl;
	}
	else if (state == 2 && line == 62)
	{
		g_flag_running = false;
	}
}



void Epilogue::HandleEvents()
{
	input.HandleEvents();
}



Epilogue::~Epilogue()
{

}

