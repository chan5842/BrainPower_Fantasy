#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <string>
#include <atlstr.h>
#include <iostream>
#include <vector>

#include "GamePhase.h"
#include "TextureManager.h"
#include "Question.h"
#include "Input.h"

class Stage2_Battle : public PhaseInterface
{
public:
	Mix_Chunk * incorrect;
	Mix_Chunk *correct;
	Mix_Chunk *wow;
	Mix_Music *bgm;

	Stage2_Battle();
	~Stage2_Battle();

	virtual void HandleEvents();
	virtual void Update();
	virtual void Render();

	void UpdateTimeTexture(int ms);
	vector<Question> q;


private:
	Uint32 effect_cnt;
	int current_effect;

	int type;

	// 스테이지 제한시간
	TTF_Font *time_font;
	SDL_Texture *text_time;
	SDL_Rect text_time_rect;

	// Interligence Point Text
	TTF_Font *ip_font;
	SDL_Texture *text_ip[2];
	SDL_Rect text_ip_rect[2];

	// 제한시간 문자로 표현
	bool started;
	int time;

	// ip 문자로 표현
	int cnt;
	Text input_text;
	Text cursor;
	TTF_Font *c_font;
	SDL_Surface *temp;
	SDL_Surface *temp_cursor;
	Input input;
	SDL_Rect t_srect;
	SDL_Rect t_drect;
	SDL_Rect L_srect;
	SDL_Rect L_drect;
	SDL_Rect R_srect;
	SDL_Rect R_drect;
	int L_IP;
	int R_IP;
};
