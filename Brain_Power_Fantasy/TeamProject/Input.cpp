#include "Input.h"
#include "GamePhase.h"``
extern bool g_flag_running;

bool Input::key_state[13];
std::string Input::input_space;
Input::Input()
{
	for (int i = 0; i < 11; i++) key_state[i] = false;
	input_space = "";
}
Input::~Input()
{
}
void Input::HandleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			g_flag_running = false;
			break;

		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_0 || event.key.keysym.sym == SDLK_KP_0)
			{
				key_state[0] = true;
			}
			if (event.key.keysym.sym == SDLK_1 || event.key.keysym.sym == SDLK_KP_1) key_state[1] = true;
			if (event.key.keysym.sym == SDLK_2 || event.key.keysym.sym == SDLK_KP_2) key_state[2] = true;
			if (event.key.keysym.sym == SDLK_3 || event.key.keysym.sym == SDLK_KP_3) key_state[3] = true;
			if (event.key.keysym.sym == SDLK_4 || event.key.keysym.sym == SDLK_KP_4) key_state[4] = true;
			if (event.key.keysym.sym == SDLK_5 || event.key.keysym.sym == SDLK_KP_5) key_state[5] = true;
			if (event.key.keysym.sym == SDLK_6 || event.key.keysym.sym == SDLK_KP_6) key_state[6] = true;
			if (event.key.keysym.sym == SDLK_7 || event.key.keysym.sym == SDLK_KP_7) key_state[7] = true;
			if (event.key.keysym.sym == SDLK_8 || event.key.keysym.sym == SDLK_KP_8) key_state[8] = true;
			if (event.key.keysym.sym == SDLK_9 || event.key.keysym.sym == SDLK_KP_9) key_state[9] = true;
			if (event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_KP_ENTER) { key_state[10] = true; std::cout << "Enter is Pressed!" << std::endl; }
			if (event.key.keysym.sym == SDLK_BACKSPACE)	key_state[11] = true;
			if (event.key.keysym.sym == SDLK_SPACE)
			{
				key_state[12] = true;
				g_current_game_phase = PHASE_STAGE1_BATTLE;
			}
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				g_flag_running = false;
			}
			break;

		case SDL_KEYUP:
			if (event.key.keysym.sym == SDLK_0 || event.key.keysym.sym == SDLK_KP_0) key_state[0] = false;
			if (event.key.keysym.sym == SDLK_1 || event.key.keysym.sym == SDLK_KP_1) key_state[1] = false;
			if (event.key.keysym.sym == SDLK_2 || event.key.keysym.sym == SDLK_KP_2) key_state[2] = false;
			if (event.key.keysym.sym == SDLK_3 || event.key.keysym.sym == SDLK_KP_3) key_state[3] = false;
			if (event.key.keysym.sym == SDLK_4 || event.key.keysym.sym == SDLK_KP_4) key_state[4] = false;
			if (event.key.keysym.sym == SDLK_5 || event.key.keysym.sym == SDLK_KP_5) key_state[5] = false;
			if (event.key.keysym.sym == SDLK_6 || event.key.keysym.sym == SDLK_KP_6) key_state[6] = false;
			if (event.key.keysym.sym == SDLK_7 || event.key.keysym.sym == SDLK_KP_7) key_state[7] = false;
			if (event.key.keysym.sym == SDLK_8 || event.key.keysym.sym == SDLK_KP_8) key_state[8] = false;
			if (event.key.keysym.sym == SDLK_9 || event.key.keysym.sym == SDLK_KP_9) key_state[9] = false;
			if (event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_KP_ENTER) key_state[10] = false;
			if (event.key.keysym.sym == SDLK_BACKSPACE)	key_state[11] = false;
			if (event.key.keysym.sym == SDLK_SPACE) key_state[12] = false;
			break;

		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
			{

			}
			break;

		default:
			break;
		}
	}
}

bool Input::ScanInput()
{
	for (int i = 0; i < 10; i++)
	{
		if (key_state[i] == true)
		{
			input_space = input_space + (char)(i + 48);
			std::cout << input_space.c_str() << std::endl;
			key_state[i] = false;
		}
	}
	if (key_state[11] == true)
	{
		input_space = input_space.substr(0, input_space.length() - 1);
		key_state[11] = false;
	}
	if (key_state[10] == true)
	{
		key_state[10] = false;
		return true;
	}
	if (key_state[12] == true)
	{
		key_state[12] = false;
		return true;
	}
	return false;
}

bool Input::ScanEnter()
{
	if (key_state[10] == true)
	{
		std::cout << "Enter returned true!" << std::endl;
		return true;
	}
	return false;
}

void Input::RefreshButton()
{
	key_state[0] = false;
	key_state[1] = false;
	key_state[2] = false;
	key_state[3] = false;
	key_state[4] = false;
	key_state[5] = false;
	key_state[6] = false;
	key_state[7] = false;
	key_state[8] = false;
	key_state[9] = false;
	key_state[10] = false;
	key_state[11] = false;
}