#pragma once
#include "Question.h"

extern SDL_Renderer* g_renderer;

TTF_Font* Question::q_font = 0;

void Question::Q_Font_Load()
{
	if (q_font != 0) return;
	q_font = TTF_OpenFont("../Resources/O_BMHANNAPro.ttf", 50);
}

Question::Question(int _type, std::wstring _text1, std::wstring _text2, std::string _answer)
{	
	TextureManager *tm = TextureManager::GetSingleton();

	q_type = _type;
	text[0] = _text1;
	text[1] = _text2;
	answer = _answer;

	if (q_type == 1)
	{
		if (!(temp_surface[0] = TTF_RenderUTF8_Blended(q_font, CW2A(text[0].c_str(), CP_UTF8), { 255, 255, 255, 255 })))
		{
			std::cout << "Text Error" << std::endl;
		}
		else
		{
			s_rect[0].x = 0;
			s_rect[0].y = 0;
			s_rect[0].w = temp_surface[0]->w;
			s_rect[0].h = temp_surface[0]->h;
			d_rect[0].x = 300;
			d_rect[0].y = 150;
			d_rect[0].w = s_rect[0].w;
			d_rect[0].h = s_rect[0].h;
			texture[0] = SDL_CreateTextureFromSurface(g_renderer, temp_surface[0]);
		}
		
	}
	else if (q_type == 2)
	{
		temp_surface[0] = TTF_RenderUTF8_Blended(q_font, CW2A(text[0].c_str(), CP_UTF8), { 255, 255, 255, 255 });
		texture[0] = SDL_CreateTextureFromSurface(g_renderer, temp_surface[0]);
		s_rect[0].x = 0;
		s_rect[0].y = 0;
		s_rect[0].w = temp_surface[0]->w;
		s_rect[0].h = temp_surface[0]->h;
		d_rect[0].x = 300;
		d_rect[0].y = 150;
		d_rect[0].w = s_rect[0].w;
		d_rect[0].h = s_rect[0].h;

		temp_surface[1] = TTF_RenderUTF8_Blended(q_font, CW2A(text[1].c_str(), CP_UTF8), { 255, 255, 255, 255 });
		texture[1] = SDL_CreateTextureFromSurface(g_renderer, temp_surface[1]);
		s_rect[1].x = 0;
		s_rect[1].y = 0;
		s_rect[1].w = temp_surface[1]->w;
		s_rect[1].h = temp_surface[1]->h;
		d_rect[1].x = 290;
		d_rect[1].y = 220;
		d_rect[1].w = s_rect[1].w;
		d_rect[1].h = s_rect[1].h;
	}
	t_state = 0;
}
Question::~Question()
{

}
void Question::Q_Draw()
{
	SDL_RenderCopy(g_renderer, texture[0], &s_rect[0], &d_rect[0]);
	if (q_type == 2) SDL_RenderCopy(g_renderer, texture[1], &s_rect[1], &d_rect[1]);
}
int Question::Q_Update(std::string _answer)
{
	if (answer == _answer) return 1;
	else return 0;
}
int Question::Q_Time()
{
	// 한 문제는 10초
	if (t_state == 0)
	{
		t_state = 1;
		time = SDL_GetTicks();
		return 720;
	}
	else
	{
		Uint32 cur_time = SDL_GetTicks();
		return 720 - (cur_time - time) * 720 / 10000;
	}
}

int Question::Q_Type()
{
	return q_type;
}