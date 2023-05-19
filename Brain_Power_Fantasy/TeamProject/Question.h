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
	int q_type; // 문제 유형
	std::wstring text[2]; // 계산문제는 1줄, 사지선다는 2줄의 문자열을 출력한다.
	std::string answer; // 답
	Uint32 time; // 주어지는 시간
	bool t_state; // 시간초를 세기 시작하는지 상태를 확인한다.

	// 텍스트 출력에 필요한 변수들
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
