#include "Script.h"
#include "TextureManager.h"
#include <atlstr.h>
Input key_input;
Script::Script(TTF_Font *_font, std::wstring _script, int _x, int _y)
{
	font = _font;
	script = _script;
	length = script.length();
	print_cnt = 1;
	time_cnt = 0;
	d_rect.x = _x;
	d_rect.y = _y;
	temp_script = L"";
	pivot = length + 1;
	text_width = 675;
	state = 0;

	TTF_SizeUTF8(font, CW2A(script.c_str(), CP_UTF8), &w, &h);

	if (w > text_width)
	{
		std::wstring temp;
		for (int i = 0; i < length; i++)
		{
			temp = script.substr(0, length - i);
			TTF_SizeUTF8(font, CW2A(temp.c_str(), CP_UTF8), &w, &h);
			if (w < text_width)
			{
				pivot = length - i;
				break;
			}
		}
		if (script.at(pivot) == ' ')
		{
			script.erase(pivot, 1);
			length = script.length();
		}
		d_rect_2nd.x = d_rect.x;
		d_rect_2nd.y = d_rect.y + h + 10;
	}
}

int Script::GenerateScript()
{
	if (print_cnt == length)
	{
		if (key_input.ScanEnter() == true) state = 2;
		else state = 1;
	}
	else state = 0;
	if (key_input.ScanEnter() == true)
	{
		print_cnt = length;
	}
	if (print_cnt < length)
	{
		if (time_cnt > 0)
		{
			print_cnt++;
			time_cnt = 0;
		}
	}

	if (print_cnt > pivot)
	{
		temp_script = script.substr(0, pivot);
		if (!(temp_surface = TTF_RenderUTF8_Blended(font, CW2A(temp_script.c_str(), CP_UTF8), { 255, 255, 255, 255 })))
		{
			std::cout << "Script \"TTF_RenderUTF8_Blended\" failed." << std::endl;
			std::cout << SDL_GetError() << std::endl;
		}

		temp_script = script.substr(pivot, print_cnt - pivot);

		TTF_SizeUTF8(font, CW2A(temp_script.c_str(), CP_UTF8), &w_2, &h);

		temp_surface_2nd = TTF_RenderUTF8_Blended(font, CW2A(temp_script.c_str(), CP_UTF8), { 255, 255, 255, 255 });

		s_rect_2nd.x = 0;
		s_rect_2nd.y = 0;
		s_rect_2nd.w = temp_surface_2nd->w;
		s_rect_2nd.h = temp_surface_2nd->h;
		d_rect_2nd.w = temp_surface_2nd->w;
		d_rect_2nd.h = temp_surface_2nd->h;

		if (!(texture_2nd = SDL_CreateTextureFromSurface(g_renderer, temp_surface_2nd)))
		{
			std::cout << "Script \"SDL_CreateTextureFromSurface\" failed." << std::endl;
		}
	}
	else
	{
		temp_script = script.substr(0, print_cnt);
		if (!(temp_surface = TTF_RenderUTF8_Blended(font, CW2A(temp_script.c_str(), CP_UTF8), { 255, 255, 255, 255 })))
		{
			std::cout << "Script \"TTF_RenderUTF8_Blended\" failed." << std::endl;
		}
	}

	s_rect.x = 0;
	s_rect.y = 0;
	s_rect.w = temp_surface->w;
	s_rect.h = temp_surface->h;
	d_rect.w = temp_surface->w;
	d_rect.h = temp_surface->h;



	time_cnt++;
	if (!(texture = SDL_CreateTextureFromSurface(g_renderer, temp_surface)))
	{
		std::cout << "Script \"SDL_CreateTextureFromSurface\" failed." << std::endl;
	}
	return state;
}

void Script::RenderScript()
{
	TextureManager *tm = TextureManager::GetSingleton();
	SDL_RenderCopy(g_renderer, texture, &s_rect, &d_rect);
	if (print_cnt > pivot) SDL_RenderCopy(g_renderer, texture_2nd, &s_rect_2nd, &d_rect_2nd);
	if (state == 1) 
	{
		if (print_cnt < pivot)
		{
			tm->DrawSprite("UI", "EndPoint", d_rect.x + w + 10, d_rect.y + 20);
		}
		else
		{
			tm->DrawSprite("UI", "EndPoint", d_rect.x + w_2 + 10, d_rect.y + h + 30);
		}

	}
}

