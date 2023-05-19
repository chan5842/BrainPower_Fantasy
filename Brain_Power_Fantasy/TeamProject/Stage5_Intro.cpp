#include "GamePhase.h"
#include "Stage5_Intro.h"
#include "TextureManager.h"
#include <iostream>
#include <windows.h>
#include <atlstr.h>

extern SDL_Renderer* g_renderer;
extern bool g_flag_running;

Conversation conv9[] = {
	// 0:MC 1:��û�� 4: �������
	0, L"��-��~ ���Ⱑ �ְ����� ���� ��� ���� ��� ��Ⱑ ����Ǿ����ϴ�!",
	0, L"��ħ�� �������� ���� ������ �ٷ�...... ��û�� �����Դϴ�!",
	1, L"'���� �¸��ڸ� ���� ������ ȯȣ���� ����´�. �ٵ��� ���� �ΰ��̾ ���� ������� �ž�?'",
	0, L"����~! ��û �̱߰���! ��, ���������� ���� No. 1 ��û�� ����",
	0, L"���� �ܻ����� �ö���ñ� �ٶ��ϴ�.",
	1, L"'��, �ϴ� ������� �س��� �߳�... �̷��� ������ �ǰ�?'",
	0, L"�ڡ� No. 1���� Ʈ���Ǹ� �����ϵ��� �ϰڽ��ϴ١��� �ϱ� ����",
	0, L"������, ���⼭ ���� ���̶�� ����������... ���� �׷���� ?",
	1, L"???",
	0, L"���⼭ �׳� �ٷ� ��Ư�� ���ú���(Exhibition) ç����(Challenge) ��ġ��",
	0, L"���� ������ ��̰� Ȯ �������� �ʰھ��~? ��! ��! ��!",
	0, L"����� ������ ���� ��û�� �������� �����߷� �����ϴٴ�, ���� �̷� �����	������ ��������?",
	0, L"����, �� ���� ȭ���� ����Ʈ����Ʈ�� ���� ���� ���� �� ������ ����!",
	1, L"�� ��, ��ü ������! MC�μ� �̷� �ż��� ���������� ��ĥ�ϴٴ�, �������̳�!",
	4, L"��, �׳���� �־���. ��, �ڱ� �Ұ��� �ұ. �� ���� �������, ������ �Ǹ��̽ô�",
	1, L"�Ǹ��� �󱸿�? �� �Ϸ��� ����?",
	4, L"��, �� �ø��ǾƵ�� ������ ���� �־���. �ø��ǾƵ忡�� �������� ���� ���� �ȶ��� �������",
	4, L"���ڸ����� �������� ���� ���� ���� ��⸦ ���� �߻��� ��û�� ���ڸ����� �������� ��",
	4, L"������ ���̽� ���� �С��� ���Ұ� ���� ��� ���� ����� ���� ����.",
	1, L"�š�? ��Ȱ��? �׷��� �� �Ϸ��� �ſ���?",
	4, L"����... �𸣸� ������� �Ǵ� �Ŵ�. ���صǴ� ���������� ������ ������⸸ �ϸ� �Ǵϱ�",
	1, L"�׳����� MC�� ���ڱ� �̷��� ���´ٰ�? �Ƴ�, �� ���� Ŭ����... �Ϸ���...",
	4, L"��... ���ö�? ���� Ŭ����? ���� ������ �� ������ �׷� ���� ����ٴ� ���� ����� �ų�?",
	1, L"����, �׷��Ա��� ����� ���̿���?",
	4, L"��, �׳��� �عٴڿ��� ����ó�� ���ٴϴ� ���� �޾�� �׷� �Ҹ��� ������?",
	1, L"���� �Ҹ�����?",
	4, L"�� �ܻ� ������, �¾ ������ ���� �� �� �ܻ� ������ ���ݱ��� �ٸ� �Ǹ��鿡�� ���ϰ� �־�� �ߴ�",
	4, L"���ÿ� ����, ���ſ���� ������, �׳��� �ƴ��� ���̴�.",
	4, L"�׸��� ������ ��ĥ�� �� �������� ��޵Ǹ� ���� �ҿܰ��� ��������, �׳��� �ƴ��� ���̴�.",
	1, L"......",
	4, L"�׷� ���߿� ���� �� ����, ���� ����� ������ ����ϼ̴�. ���� ū �ų�� ���� �̴ּ�.",
	4, L"�׷� ��, ���ݱ��� �� ���� ���� ��� �� ������. �׸��� ��������, �� ��Ȱ�� �� �а� �Բ�",
	4, L"�� ���������� ����� �ٸ� ������ ���踦 ������ ����������, ���� �� ���� ���� ������� ���ο� ���迡��,",
	4, L"�� �������� ���̰� ���ݱ��� �޾ƿ� ��� ���� ���� ���� ������ �ް� �� ���̴�.",
	4, L"��, �����ϡ� ���� �˾Ұڳ�? ��ΰ� ����� �ܻ��� �й��ڰ� �̷��� ū ���� �س� ����!",
	1, L"....... �� ��Ҹ���..",
	4, L"�����?",
	1, L"���ظ� ���ϰڳ׿�. �װ� ���� �����ް� �ູ�� �Ŷ�� �����ϴ� �ſ���?",
	1, L"����� ���ݱ��� ���� ������ ���� �� �ϴ� �� �ƴϿ���.",
	1, L"���� ������ ������� �޸� ���ε� �� �ϰ� ��� �� �ؼ� �յ��� ���� ���� �����ϱ��.",
	1, L"������, �� �׿� ������ �ʰ� �� �ڽſ��� �������� �� �ֵ���",
	1, L"���� ���ؼ� ������ ���� �� �� �ִ� ���� ã�ư��鼭 �װ��� ���� �ּ��� ���߰�",
	1, L"������	���� �� �� �־����.�� ���� �ٸ� �е鵵 ����ϸ鼭 ��ư���. ��ΰ���.",
	1, L"�׷� ���� �׵��� ��� ������� ���ְڴٴ� ����, ����� �뼭�� �� �����!",
	1, L"��ŵ��� �׷� �Ǹ��� �� ���� ��𿡵� ���� �� �����!",
	4, L"���������� �� ���� �̹� �Ÿ��� �ڵ��� �߳� ��θ� �Ҹ����� �ų�? ��, ����.",
	4, L"���� �� ��Ⱑ �� ���� ������ ��Ⱑ �� �״ϱ� ����.",
	4, L"�� ���� ���ؼ� �׳��� ������ ���� ���� �Ѿư����� �ϰڴ�.",
	1, L"�ᱹ �� ���� ���� �����Ŵٴ� �ǰ��䡦 ���ƿ�, ���� ���ڽ��ϴ�!"
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
		// MC ������ ��ȭ
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_MC", 280, 447);
	}
	else if (conv9[line].state == 1)
	{
		// ���ΰ��� ��ȭ
		tm->DrawSprite("Hero", "story_Hero", 300, 100);
		tm->DrawSprite("Enemy_black", "story_Enemy", 700, 100);
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_Hero", 280, 447);
	}
	else if (conv9[line].state == 4)
	{
		// ��������� ��ȭ
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

