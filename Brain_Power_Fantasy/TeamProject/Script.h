#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "Input.h"
#include "iostream"

extern SDL_Renderer* g_renderer;

class Script
{
private:
	TTF_Font *font;
	std::wstring script;
	SDL_Texture *texture;
	SDL_Texture *texture_2nd;
	SDL_Rect s_rect;
	SDL_Rect d_rect;
	SDL_Rect s_rect_2nd;
	SDL_Rect d_rect_2nd;
	int length;
	int print_cnt; // ��縦 �� ���ھ� ����ϴ� ī����
	int time_cnt; // print_cnt�� ������Ű�� ���� �ð��� ���õ� ī����
	int w;
	int h;
	int w_2;
	int pivot;
	int text_width;
	int state;

	static SDL_Texture *end_texture;

	// Temporary storage
	SDL_Surface *temp_surface;
	SDL_Surface *temp_surface_2nd;
	std::wstring temp_script;
public:
	Script(TTF_Font *_font, std::wstring _script, int _x, int _y);
	int GenerateScript();
	void RenderScript();
};

typedef struct Conversation
{
	int state;
	std::wstring text;
}Conversation;