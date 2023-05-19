#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "TextureManager.h"
#include <atlstr.h>
#include <iostream>

class Question
{
private:
	int q_type; // ���� ����
	std::wstring text[2]; // ��깮���� 1��, �������ٴ� 2���� ���ڿ��� ����Ѵ�.
	std::string answer; // ��
	Uint32 time; // �־����� �ð�
	bool t_state; // �ð��ʸ� ���� �����ϴ��� ���¸� Ȯ���Ѵ�.

	// �ؽ�Ʈ ��¿� �ʿ��� ������
	SDL_Surface *temp_surface[2];
	SDL_Texture *texture[2];
	SDL_Rect s_rect[2];
	SDL_Rect d_rect[2];

	static TTF_Font *q_font;
public:
	Question(int type, std::wstring _text1, std::wstring _text2, std::string _answer);
	~Question();
	void Q_Draw();
	int Q_Update(std::string _answer);
	int Q_Time();
	int Q_Type();
	static void Q_Font_Load();
};
