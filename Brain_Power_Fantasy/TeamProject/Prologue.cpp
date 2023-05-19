#include "GamePhase.h"
#include "Prologue.h"
#include "TextureManager.h"
#include <iostream>
#include <windows.h>
#include <atlstr.h>

extern SDL_Renderer* g_renderer;
extern bool g_flag_running;

Conversation conv1[] = {
	// 0:나레이션 1:이청훈_solo 2:??? 3:이청훈 4:알먼 5:캬투스 6:MC 파이
	0, L"그것은... 어느 날 갑자기 일어났다.",
	1, L"뭐야! 아아아아아아!!!",
	0, L"크툴루 신화에만 나올 것 같았던 거대한 촉수들이 기분 나쁜 이상한 차원 구멍으로부터",
	0, L"나를 휘감아 순식간에 끌고 가 버렸다.",
	1, L"이 기분 나쁜 촉수와 저 구멍은 또 뭔데!?!? 설마 평범한 인간의 이세계 전이 클리셰란 말이야!?",
	2, L"TARGET : 인간 '이청훈' 확보. MISSION COMPLETE.",
	1, L"......자...잠깐? 날 어디로 끌고 가는 거야?",
	1, L"아아아아아아아아아아아아아아아......", // 7
	// 검은배경
	0, L"정신이 아득해진다...",
	2, L"자 그럼, 인간, 당신에게 운명을 걸어보도록 하겠어요.",
	0, L"눈이 조금씩 떠진다. 아, 정말 기분 나쁜 느낌이었어.",
	0, L"그리고 눈 앞에 나타난 것은...",
	2, L"...이게 당신이 말한 그 인간 맞나?",
	2, L"그래, 확실해.",
	// 고블린 부부의 방
	0, L"......고블린 남자와 여자?",
	0, L"뭐지, 이거 꿈? 가상현실? 아님... 아니야, 설마...",
	3, L"여긴 어디죠? 일단 지구는 아닌 것 같은데? 그리고 당신들은 누구고 이 기분 나쁜 촉수는 뭐에요?",
	4, L"아, 드디어 정신을 차린건가.",
	5, L"뭐, 정신력은 금방 말짱하게 돌아오는군.",
	4, L"아차, 통성명. 내 이름은 알먼이라네.",
	5, L"캬투스다.",
	4, L"청훈 군, 내츄스(Nattus)에 온 것을 환영하네. 오는 길은 어지럽진 않았나?",
	3, L"(뭐야, 내 이름을 어떻게 알지...? 뭐지? 계획된 납치인 것을 암시하는 것인가?)",
	3, L"내츄스...? 츄...러스 브랜드인가요?",
	4, L"하...? 무슨 재미없는 개그를...... 여기는 인간들이 사는 지구와는 다른 차원의 세계.",
	4, L"인간들이 없는 다양한 종족의 시민들이 살아가는 세계라네.",
	3, L"뭐라구요? 그럼 정말 이세계란 말이에요? 뭐... 뭐야 몰라요 그거, 무서워요!",
	3, L"당장 날 집에 보내줘요!",
	5, L"물론 원래 있던 곳으로 다시 보내줄 것이다. 다만...",
	3, L"다만...?",
	4, L"다만 자네가 올림피아드에서 우승을 한다면 말이야.",
	3, L"...올림피아드요? 무슨 수학 올림피아드 말하는 거에요?",
	5, L"말이 빨리 통하는군, 그렇다. 내츄스에서는 매 4년 주기로 큰 규모의 올림피아드를 개최하지.",
	5, L"네가 말하는 대로 수학 올림피아드를 말이야.",
	5, L"수학 문제를 풀아나가 상대를 차례대로 쓰러뜨려 우승까지 올라가는 시합이지.",
	4, L"우리들은 각자 우승까지 해서 그 영광과 부를 누리게 되었지만...",
	4, L"문제는 우리 뒤를 이어야 할 아들 녀석이 머리가 안 좋아서 말이야...",
	4, L"그리 똑똑하지 못하다는 것이지.",
	4, L"그래서 똑똑한 인간을 한 명 데려와, 대신 올림피아드에 출전하도록 할 것이었네.",
	4, L"그래서... 완벽한 인간을 찾던 중, 자네를 발견하게 되었지.",
	3, L"즉, 대리 참가인가요.",
	5, L"??? 갑자기 진정했군. 놀라운 걸.",
	3, L"뭐, 아직까지 믿기진 않지만 더 이상 이 상황에 대한 판단을 그만 두었거든요.",
	3, L"훗, 또한 전 안 똑똑은 하죠. 잘 찾아오셨네요.",
	3, L"그나저나 저... 나름 청렴하게 살아온 순수 청년인데...",
	4, L"그건 걱정 말게. 우리 고블린들은 뒷받침 정도는 완벽하고 확실하게 해 내니까.",
	3, L"하, 과연... 그런 쪽으로 밝으신 건가요.",
	3, L"일단 전 집으로 돌아가는 게 중요하니 따를 수밖에 없네요...",
	3, L"좋아요...! 까짓거 한 번 해보죠.",
	5, L"좋아, 빠른 이해와 결정. 마음에 드는군",
	4, L"그럼... 믿고 있겠네. 그 전까지는 우리가 최대한 자네를 위해 지원을 아끼지 않겠네.",
	4, L"당분간 준비된 초특급 호화 호텔에서 머물고 있게나. 건투를 빌겠네.",
	3, L"서비스는 확실하시군요. 고마워요.",
	5, L"똑바로 열심히 하도록.",
	// 스테이지 진행 전
	0, L"마침내 막이 오른 올림피아드. 정말, 많은 종족들이 한 가운데 모였다.",
	0, L"출전하는 다른 분들도 다 다르고, 엄청나 보이는데...",
	4, L"자, 준비는 되었는가?",
	5, L"혹시... 긴장하고 있나?",
	3, L"확실히 긴장은 되네요. 제가 할 수 있을지도 모르고.",
	4, L"약한 소리는 하지 말게. 자네는 우리가 찾던 완벽한 인간이니까.",
	5, L"그렇다. 힘내도록.",
	3, L"가... 감사합니다. 앗, 이제 시작하네요!",
	6, L"네~~~ 여러분, 안녕하세요! 올해도 내츄스 올림피아드에 오신 것을 환영합니다!!!",
	0, L"우렁찬 환호성... 심장 박동 소리와 함께 고조된다."
};

Prologue::Prologue()
{
	TextureManager *tm = TextureManager::GetSingleton();

	tm->LoadTexture("bg", "../Resources/Story_bg.png");
	tm->LoadTexture("bg_Street", "../Resources/Street.png");
	tm->LoadTexture("bg_Go_room", "../Resources/Go_room.png");
	tm->LoadTexture("UI", "../Resources/Story_UI.png");
	tm->LoadTexture("Hero", "../Resources/Story_Hero.png");
	tm->LoadTexture("Hero_black", "../Resources/Story_Hero.png");
	tm->LoadTexture("Go1", "../Resources/go1.png");
	tm->LoadTexture("Go1_black", "../Resources/go1.png");
	tm->LoadTexture("Go2", "../Resources/go2.png");
	tm->LoadTexture("Go2_black", "../Resources/go2.png");


	tm->SetTextureColorMode("Hero_black", 100, 100, 100);
	tm->SetTextureColorMode("Go1_black", 100, 100, 100);
	tm->SetTextureColorMode("Go2_black", 100, 100, 100);

	tm->AddSpriteRect("TextBox", 21, 17, 823, 226);
	tm->AddSpriteRect("EndPoint", 888, 288, 19, 15);
	tm->AddSpriteRect("name_MC", 779, 419, 257, 51);
	tm->AddSpriteRect("name_Hero", 21, 256, 201, 51);

	tm->AddSpriteRect("story_Hero", 0, 0, 260, 648);
	tm->AddSpriteRect("story_Go1", 0, 0, 239, 500);
	tm->AddSpriteRect("story_Go2", 0, 0, 311, 500);

	// Script 
	{
		game_font = TTF_OpenFont("../Resources/O_BMHANNAPro.ttf", 35);
		for (int i = 0; i < 64; i++)
		{
			script[i] = new Script(game_font, conv1[i].text, 300, 535);
		}
		std::cout << "Script created." << std::endl;
	}
	line = 0;
}


void Prologue::Update()
{
	state = script[line]->GenerateScript();
}


void Prologue::Render()
{
	SDL_SetRenderDrawColor(g_renderer, 50, 50, 50, 255);
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color

	TextureManager *tm = TextureManager::GetSingleton();

	if (line < 8)
	{
		tm->DrawSprite("bg_Street");
	}
	else if (line < 13)
	{

	}
	else if (line < 54)
	{
		tm->DrawSprite("bg_Go_room");
	}
	else
	{
		tm->DrawSprite("bg");
	}



	// 0:나레이션 1:이청훈_solo 2:??? 3:이청훈 4:알먼 5:캬투스 6:MC 파이
	if (conv1[line].state == 0)
	{
		// 나래이션
		tm->DrawSprite("UI", "TextBox", 228, 447);
	}
	else if(conv1[line].state == 1)
	{
		// 이청훈_solo
		tm->DrawSprite("Hero", "story_Hero", 300, 100);
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_Hero", 280, 447);
	}
	else if (conv1[line].state == 2)
	{
		// ???
		tm->DrawSprite("Hero_black", "story_Hero", 300, 100);
		tm->DrawSprite("UI", "TextBox", 228, 447);
	}
	else if (conv1[line].state == 3)
	{
		// 이청훈
		tm->DrawSprite("Hero", "story_Hero", 300, 100);
		tm->DrawSprite("Go1_black", "story_Go1", 700, 200);
		tm->DrawSprite("Go2_black", "story_Go2", 900, 200);
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_Hero", 280, 447);
	}
	else if (conv1[line].state == 4)
	{
		// 알먼
		tm->DrawSprite("Hero_black", "story_Hero", 300, 100);
		tm->DrawSprite("Go1", "story_Go1", 700, 200);
		tm->DrawSprite("Go2_black", "story_Go2", 900, 200);
		tm->DrawSprite("UI", "TextBox", 228, 447);
	}
	else if (conv1[line].state == 5)
	{
		// 캬투스
		tm->DrawSprite("Hero_black", "story_Hero", 300, 100);
		tm->DrawSprite("Go1_black", "story_Go1", 700, 200);
		tm->DrawSprite("Go2", "story_Go2", 900, 200);
		tm->DrawSprite("UI", "TextBox", 228, 447);
	}
	else if (conv1[line].state == 6)
	{
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_MC", 280, 447);
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
		g_current_game_phase = 3; // Stage1_Intro
	}
}



void Prologue::HandleEvents()
{
	input.HandleEvents();
}



Prologue::~Prologue()
{

}

