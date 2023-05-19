#include "Title.h"

extern SDL_Window* g_window;
extern SDL_Renderer* g_renderer;
extern bool g_flag_running;
extern int g_current_game_phase;

Mix_Music *title_bgm;

Title::Title()
{
	TextureManager *tm = TextureManager::GetSingleton();
	Mix_VolumeMusic(128);
	title_bgm = Mix_LoadMUS("../Resources/Title_Intro.mp3");
	Mix_PlayMusic(title_bgm, -1);
	tm->LoadTexture("Title", "../Resources/Title.png");
}

Title::~Title()
{
	Mix_HaltMusic();
	Mix_FreeMusic(title_bgm);
}

void Title::Update()
{

}

void Title::Render()
{
	//SDL_SetRenderDrawColor(g_renderer, 255, 255, 0, 255);
	TextureManager *tm = TextureManager::GetSingleton();

	SDL_RenderClear(g_renderer); // clear the renderer to the draw color
	tm->DrawSprite("Title");

	SDL_RenderPresent(g_renderer); // draw to the screen
}

void Title::HandleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			g_flag_running = false;
			break;

		case SDL_MOUSEBUTTONDOWN:

			// If the mouse left button is pressed. 
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				g_current_game_phase = 1; // Prologue
			}
			break;

		default:
			break;
		}
	}
}