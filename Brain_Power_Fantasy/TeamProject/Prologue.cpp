#include "GamePhase.h"
#include "Prologue.h"
#include "TextureManager.h"
#include <iostream>
#include <windows.h>
#include <atlstr.h>

extern SDL_Renderer* g_renderer;
extern bool g_flag_running;

Conversation conv1[] = {
	// 0:�����̼� 1:��û��_solo 2:??? 3:��û�� 4:�˸� 5:ļ���� 6:MC ����
	0, L"�װ���... ��� �� ���ڱ� �Ͼ��.",
	1, L"����! �ƾƾƾƾƾ�!!!",
	0, L"ũ���� ��ȭ���� ���� �� ���Ҵ� �Ŵ��� �˼����� ��� ���� �̻��� ���� �������κ���",
	0, L"���� �ְ��� ���İ��� ���� �� ���ȴ�.",
	1, L"�� ��� ���� �˼��� �� ������ �� ����!?!? ���� ����� �ΰ��� �̼��� ���� Ŭ���ζ� ���̾�!?",
	2, L"TARGET : �ΰ� '��û��' Ȯ��. MISSION COMPLETE.",
	1, L"......��...���? �� ���� ���� ���� �ž�?",
	1, L"�ƾƾƾƾƾƾƾƾƾƾƾƾƾƾ�......", // 7
	// �������
	0, L"������ �Ƶ�������...",
	2, L"�� �׷�, �ΰ�, ��ſ��� ����� �ɾ���� �ϰھ��.",
	0, L"���� ���ݾ� ������. ��, ���� ��� ���� �����̾���.",
	0, L"�׸��� �� �տ� ��Ÿ�� ����...",
	2, L"...�̰� ����� ���� �� �ΰ� �³�?",
	2, L"�׷�, Ȯ����.",
	// ��� �κ��� ��
	0, L"......��� ���ڿ� ����?",
	0, L"����, �̰� ��? ��������? �ƴ�... �ƴϾ�, ����...",
	3, L"���� �����? �ϴ� ������ �ƴ� �� ������? �׸��� ��ŵ��� ������ �� ��� ���� �˼��� ������?",
	4, L"��, ���� ������ �����ǰ�.",
	5, L"��, ���ŷ��� �ݹ� ��¯�ϰ� ���ƿ��±�.",
	4, L"����, �뼺��. �� �̸��� �˸��̶��.",
	5, L"ļ������.",
	4, L"û�� ��, ����(Nattus)�� �� ���� ȯ���ϳ�. ���� ���� �������� �ʾҳ�?",
	3, L"(����, �� �̸��� ��� ����...? ����? ��ȹ�� ��ġ�� ���� �Ͻ��ϴ� ���ΰ�?)",
	3, L"����...? ��...���� �귣���ΰ���?",
	4, L"��...? ���� ��̾��� ���׸�...... ����� �ΰ����� ��� �����ʹ� �ٸ� ������ ����.",
	4, L"�ΰ����� ���� �پ��� ������ �ùε��� ��ư��� ������.",
	3, L"���󱸿�? �׷� ���� �̼���� ���̿���? ��... ���� ����� �װ�, ��������!",
	3, L"���� �� ���� �������!",
	5, L"���� ���� �ִ� ������ �ٽ� ������ ���̴�. �ٸ�...",
	3, L"�ٸ�...?",
	4, L"�ٸ� �ڳװ� �ø��ǾƵ忡�� ����� �Ѵٸ� ���̾�.",
	3, L"...�ø��ǾƵ��? ���� ���� �ø��ǾƵ� ���ϴ� �ſ���?",
	5, L"���� ���� ���ϴ±�, �׷���. ���򽺿����� �� 4�� �ֱ�� ū �Ը��� �ø��ǾƵ带 ��������.",
	5, L"�װ� ���ϴ� ��� ���� �ø��ǾƵ带 ���̾�.",
	5, L"���� ������ Ǯ�Ƴ��� ��븦 ���ʴ�� �����߷� ��±��� �ö󰡴� ��������.",
	4, L"�츮���� ���� ��±��� �ؼ� �� ������ �θ� ������ �Ǿ�����...",
	4, L"������ �츮 �ڸ� �̾�� �� �Ƶ� �༮�� �Ӹ��� �� ���Ƽ� ���̾�...",
	4, L"�׸� �ȶ����� ���ϴٴ� ������.",
	4, L"�׷��� �ȶ��� �ΰ��� �� �� ������, ��� �ø��ǾƵ忡 �����ϵ��� �� ���̾���.",
	4, L"�׷���... �Ϻ��� �ΰ��� ã�� ��, �ڳ׸� �߰��ϰ� �Ǿ���.",
	3, L"��, �븮 �����ΰ���.",
	5, L"??? ���ڱ� �����߱�. ���� ��.",
	3, L"��, �������� �ϱ��� ������ �� �̻� �� ��Ȳ�� ���� �Ǵ��� �׸� �ξ��ŵ��.",
	3, L"��, ���� �� �� �ȶ��� ����. �� ã�ƿ��̳׿�.",
	3, L"�׳����� ��... ���� û���ϰ� ��ƿ� ���� û���ε�...",
	4, L"�װ� ���� ����. �츮 ������� �޹�ħ ������ �Ϻ��ϰ� Ȯ���ϰ� �� ���ϱ�.",
	3, L"��, ����... �׷� ������ ������ �ǰ���.",
	3, L"�ϴ� �� ������ ���ư��� �� �߿��ϴ� ���� ���ۿ� ���׿�...",
	3, L"���ƿ�...! ������ �� �� �غ���.",
	5, L"����, ���� ���ؿ� ����. ������ ��±�",
	4, L"�׷�... �ϰ� �ְڳ�. �� �������� �츮�� �ִ��� �ڳ׸� ���� ������ �Ƴ��� �ʰڳ�.",
	4, L"��а� �غ�� ��Ư�� ȣȭ ȣ�ڿ��� �ӹ��� �ְԳ�. ������ ���ڳ�.",
	3, L"���񽺴� Ȯ���Ͻñ���. ������.",
	5, L"�ȹٷ� ������ �ϵ���.",
	// �������� ���� ��
	0, L"��ħ�� ���� ���� �ø��ǾƵ�. ����, ���� �������� �� ��� �𿴴�.",
	0, L"�����ϴ� �ٸ� �е鵵 �� �ٸ���, ��û�� ���̴µ�...",
	4, L"��, �غ�� �Ǿ��°�?",
	5, L"Ȥ��... �����ϰ� �ֳ�?",
	3, L"Ȯ���� ������ �ǳ׿�. ���� �� �� �������� �𸣰�.",
	4, L"���� �Ҹ��� ���� ����. �ڳ״� �츮�� ã�� �Ϻ��� �ΰ��̴ϱ�.",
	5, L"�׷���. ��������.",
	3, L"��... �����մϴ�. ��, ���� �����ϳ׿�!",
	6, L"��~~~ ������, �ȳ��ϼ���! ���ص� ���� �ø��ǾƵ忡 ���� ���� ȯ���մϴ�!!!",
	0, L"�췷�� ȯȣ��... ���� �ڵ� �Ҹ��� �Բ� �����ȴ�."
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



	// 0:�����̼� 1:��û��_solo 2:??? 3:��û�� 4:�˸� 5:ļ���� 6:MC ����
	if (conv1[line].state == 0)
	{
		// �����̼�
		tm->DrawSprite("UI", "TextBox", 228, 447);
	}
	else if(conv1[line].state == 1)
	{
		// ��û��_solo
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
		// ��û��
		tm->DrawSprite("Hero", "story_Hero", 300, 100);
		tm->DrawSprite("Go1_black", "story_Go1", 700, 200);
		tm->DrawSprite("Go2_black", "story_Go2", 900, 200);
		tm->DrawSprite("UI", "TextBox", 228, 447);
		tm->DrawSprite("UI", "name_Hero", 280, 447);
	}
	else if (conv1[line].state == 4)
	{
		// �˸�
		tm->DrawSprite("Hero_black", "story_Hero", 300, 100);
		tm->DrawSprite("Go1", "story_Go1", 700, 200);
		tm->DrawSprite("Go2_black", "story_Go2", 900, 200);
		tm->DrawSprite("UI", "TextBox", 228, 447);
	}
	else if (conv1[line].state == 5)
	{
		// ļ����
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

