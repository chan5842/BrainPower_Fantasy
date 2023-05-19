#include "GameOver.h"

extern SDL_Window* g_window;
extern SDL_Renderer* g_renderer;
extern bool g_flag_running;
extern int g_current_game_phase;

GameOver::GameOver()
{
	TextureManager *tm = TextureManager::GetSingleton();

	tm->LoadTexture("ending_bg", "../Resources/GameOver.png");
}

GameOver::~GameOver()
{
}

void GameOver::Update()
{
}

void GameOver::Render()
{
	//SDL_SetRenderDrawColor(g_renderer, 255, 255, 0, 255);
	TextureManager *tm = TextureManager::GetSingleton();

	SDL_RenderClear(g_renderer); // clear the renderer to the draw color
	tm->DrawSprite("ending_bg");

	SDL_RenderPresent(g_renderer); // draw to the screen
}

void GameOver::HandleEvents()
{
}