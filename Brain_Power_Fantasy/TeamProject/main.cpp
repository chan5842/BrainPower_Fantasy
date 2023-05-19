#include <iostream>
#include <windows.h>
#include "SDL.h"
#include "Title.h"
#include "Prologue.h"
#include "Stage1_Intro.h"
#include "Stage1_Battle.h"
#include "Stage1_End.h"
#include "Stage2_Intro.h"
#include "Stage2_Battle.h"
#include "Stage2_End.h"
#include "Stage5_Intro.h"
#include "Stage5_Battle.h"
#include "Stage5_End.h"
#include "Stage6_Intro.h"
#include "Stage6_Battle.h"
#include "Stage6_End.h"
#include "Epilogue.h"
#include "GameOver.h"
#include "GamePhase.h"
#include "Script.h"
#include "TextureManager.h"

SDL_Window* g_window;
SDL_Renderer* g_renderer;
Uint32 g_last_time_ms;

bool g_flag_running;
int g_current_game_phase;

Uint32 game_speed;

bool InitializeWindow(const char* title, int xpos, int ypos, int width, int height, int fullscreen);
void ClearWindow();

int main(int argc, char* argv[])
{
	InitializeWindow("Tales of Math Beyond Dimensions", 10, 1, 1280, 720, true);
	TTF_Init();

	game_speed = 18;

	// Audio init
	int audio_rate = 44100;
	Uint16 audio_format = MIX_DEFAULT_FORMAT;
	int audio_channels = 2;
	if (Mix_OpenAudio(audio_rate, audio_format, audio_channels, 4096) < 0)
	{
		fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError());
		Mix_CloseAudio();
	}
	else
	{
		Mix_QuerySpec(&audio_rate, &audio_format, &audio_channels);
		printf("Opened audio at %d Hz %d bit %s\n", audio_rate,
			(audio_format & 0xFF),
			(audio_channels > 2) ? "surround" :
			(audio_channels > 1) ? "stereo" : "mono");
	}

	g_last_time_ms = SDL_GetTicks();

	Question::Q_Font_Load();

	TextureManager::CreateInstance();

	g_current_game_phase = 0;

	while (g_flag_running)
	{
		// Title
		if (g_current_game_phase == 0)
		{
			Title Scene;

			while (g_flag_running)
			{
				Uint32 cur_time_ms = SDL_GetTicks();

				if (cur_time_ms - g_last_time_ms < game_speed)
					continue;
				Scene.HandleEvents();
				Scene.Update();
				Scene.Render();
				std::cout << g_current_game_phase << std::endl;
				g_last_time_ms = cur_time_ms;
				if (g_current_game_phase != 0)
				{
					break;
				}
			}
		}
		// Prologue
		if (g_current_game_phase == 1)
		{
			Prologue Scene;

			while (g_flag_running)
			{
				Uint32 cur_time_ms = SDL_GetTicks();

				if (cur_time_ms - g_last_time_ms < game_speed)
					continue;
				Scene.HandleEvents();
				Scene.Update();
				Scene.Render();
				std::cout << g_current_game_phase << std::endl;
				g_last_time_ms = cur_time_ms;
				if (g_current_game_phase != 1)
				{
					break;
				}
			}
		}
		//// Tutorial
		//if (g_current_game_phase == 2)
		//{
		//	Tutorial Scene;

		//	while (g_flag_running)
		//	{
		//		Uint32 cur_time_ms = SDL_GetTicks();

		//		if (cur_time_ms - g_last_time_ms < game_speed)
		//			continue;
		//		Scene.HandleEvents();
		//		Scene.Update();
		//		Scene.Render();
		//		std::cout << g_current_game_phase << std::endl;
		//		g_last_time_ms = cur_time_ms;
		//		if (g_current_game_phase != 2)
		//		{
		//			break;
		//		}
		//	}
		//}

		// Stage1 Intro
		if (g_current_game_phase == 3)
		{
			Stage1_Intro Scene;
			std::cout << "Stage1 is created." << std::endl;
			while (g_flag_running)
			{
				std::cout << "Stage1 is running." << std::endl;
				Uint32 cur_time_ms = SDL_GetTicks();

				if (cur_time_ms - g_last_time_ms < game_speed)
					continue;

				Scene.HandleEvents();
				Scene.Update();
				Scene.Render();

				g_last_time_ms = cur_time_ms;
				if (g_current_game_phase != 3)
				{
					std::cout << "Was it deleted?" << std::endl;
					break;
				}
			}
		}
		// Stage1 Battle
		if (g_current_game_phase == 4)
		{
			Stage1_Battle Scene;
			while (g_flag_running)
			{
				Uint32 cur_time_ms = SDL_GetTicks();

				if (cur_time_ms - g_last_time_ms < game_speed)
					continue;

				Scene.HandleEvents();
				Scene.Update();
				Scene.Render();

				g_last_time_ms = cur_time_ms;
				if (g_current_game_phase != 4)
				{
					std::cout << "Was it deleted2?" << std::endl;
					break;
				}
			}
		}
		// stage1 End
		if (g_current_game_phase == 5)
		{
			Stage1_End Scene;
			while (g_flag_running)
			{
				Uint32 cur_time_ms = SDL_GetTicks();

				if (cur_time_ms - g_last_time_ms < game_speed)
					continue;

				Scene.HandleEvents();
				Scene.Update();
				Scene.Render();

				g_last_time_ms = cur_time_ms;
				if (g_current_game_phase != 5)
				{
					break;
				}
			}
		}

		// Stage2 Intro
		if (g_current_game_phase == 6)
		{
			Stage2_Intro Scene;

			while (g_flag_running)
			{
				Uint32 cur_time_ms = SDL_GetTicks();

				if (cur_time_ms - g_last_time_ms < game_speed)
					continue;
				Scene.HandleEvents();
				Scene.Update();
				Scene.Render();

				g_last_time_ms = cur_time_ms;
				if (g_current_game_phase != 6)
				{
					break;
				}
			}
		}
		// Stage2 Battle
		if (g_current_game_phase == 7)
		{
			Stage2_Battle Scene;

			while (g_flag_running)
			{
				Uint32 cur_time_ms = SDL_GetTicks();

				if (cur_time_ms - g_last_time_ms < game_speed)
					continue;
				Scene.HandleEvents();
				Scene.Update();
				Scene.Render();

				g_last_time_ms = cur_time_ms;
				if (g_current_game_phase != 7)
				{
					break;
				}
			}
		}
		// Stage2 End
		if (g_current_game_phase == 8)
		{
			Stage2_End Scene;

			while (g_flag_running)
			{
				Uint32 cur_time_ms = SDL_GetTicks();

				if (cur_time_ms - g_last_time_ms < game_speed)
					continue;
				Scene.HandleEvents();
				Scene.Update();
				Scene.Render();

				g_last_time_ms = cur_time_ms;
				if (g_current_game_phase != 8)
				{
					break;
				}
			}
		}
		// Stage5 Intro
		if (g_current_game_phase == 9)
		{
			Stage5_Intro Scene;

			while (g_flag_running)
			{
				Uint32 cur_time_ms = SDL_GetTicks();

				if (cur_time_ms - g_last_time_ms < game_speed)
					continue;
				Scene.HandleEvents();
				Scene.Update();
				Scene.Render();

				g_last_time_ms = cur_time_ms;
				if (g_current_game_phase != 9)
				{
					break;
				}
			}
		}

		// Stage5 Battle
		if (g_current_game_phase == 10)
		{
			Stage5_Battle Scene;

			while (g_flag_running)
			{
				Uint32 cur_time_ms = SDL_GetTicks();

				if (cur_time_ms - g_last_time_ms < game_speed)
					continue;
				Scene.HandleEvents();
				Scene.Update();
				Scene.Render();

				g_last_time_ms = cur_time_ms;
				if (g_current_game_phase != 10)
				{
					break;
				}
			}
		}

		// Stage5 End
		if (g_current_game_phase == 11)
		{
			Stage5_End Scene;

			while (g_flag_running)
			{
				Uint32 cur_time_ms = SDL_GetTicks();

				if (cur_time_ms - g_last_time_ms < game_speed)
					continue;
				Scene.HandleEvents();
				Scene.Update();
				Scene.Render();

				g_last_time_ms = cur_time_ms;
				if (g_current_game_phase != 11)
				{
					break;
				}
			}
		}

		// Stage6 Intro
		if (g_current_game_phase == 12)
		{
			Stage6_Intro Scene;

			while (g_flag_running)
			{
				Uint32 cur_time_ms = SDL_GetTicks();

				if (cur_time_ms - g_last_time_ms < game_speed)
					continue;
				Scene.HandleEvents();
				Scene.Update();
				Scene.Render();

				g_last_time_ms = cur_time_ms;
				if (g_current_game_phase != 12)
				{
					break;
				}
			}
		}

		// Stage6 Battle
		if (g_current_game_phase == 13)
		{
			Stage6_Battle Scene;

			while (g_flag_running)
			{
				Uint32 cur_time_ms = SDL_GetTicks();

				if (cur_time_ms - g_last_time_ms < game_speed)
					continue;
				Scene.HandleEvents();
				Scene.Update();
				Scene.Render();

				g_last_time_ms = cur_time_ms;
				if (g_current_game_phase != 13)
				{
					break;
				}
			}
		}

		// Stage6 End
		if (g_current_game_phase == 14)
		{
			Stage6_End Scene;

			while (g_flag_running)
			{
				Uint32 cur_time_ms = SDL_GetTicks();

				if (cur_time_ms - g_last_time_ms < game_speed)
					continue;
				Scene.HandleEvents();
				Scene.Update();
				Scene.Render();

				g_last_time_ms = cur_time_ms;
				if (g_current_game_phase != 14)
				{
					break;
				}
			}
		}

		// Epilogue
		if (g_current_game_phase == 15)
		{
			Epilogue Scene;

			while (g_flag_running)
			{
				Uint32 cur_time_ms = SDL_GetTicks();

				if (cur_time_ms - g_last_time_ms < game_speed)
					continue;
				Scene.HandleEvents();
				Scene.Update();
				Scene.Render();

				g_last_time_ms = cur_time_ms;
				if (g_current_game_phase != 15)
				{
					break;
				}
			}
		}
		// GameOver
		if (g_current_game_phase == 16)
		{
			GameOver Scene;

			while (g_flag_running)
			{
				Uint32 cur_time_ms = SDL_GetTicks();

				if (cur_time_ms - g_last_time_ms < game_speed)
					continue;
				Scene.HandleEvents();
				Scene.Update();
				Scene.Render();

				g_last_time_ms = cur_time_ms;
				if (g_current_game_phase != 16)
				{
					break;
				}
			}
		}
	}

	ClearWindow();
	TTF_Quit();

	return 0;
}

bool InitializeWindow(const char* title, int xpos, int ypos, int width, int height, int fullscreen)
{
	/*
	SDL -> Window -> Renderer 순서로 Initialize를 수행한다.
	모두 성공하면 g_flag_running = true가 되어 main loop가 시작된다.
	*/
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success\n";

		g_window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (g_window != 0)
		{
			std::cout << "window creation success\n";
			g_renderer = SDL_CreateRenderer(g_window, -1, 0);
			if (g_renderer != 0)
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(g_renderer, 255, 255, 255, 255);
			}
			else
			{
				std::cout << "renderer init fail\n";
				return false;
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false;
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false;
	}
	std::cout << "init success\n";
	g_flag_running = true;

	return true;
}

void ClearWindow()
{
	cout << "Close game\n";
	SDL_DestroyWindow(g_window);
	SDL_DestroyRenderer(g_renderer);
	SDL_Quit();
}