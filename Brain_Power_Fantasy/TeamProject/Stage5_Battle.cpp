#include "Stage5_Battle.h"

extern SDL_Window *g_window;
extern SDL_Renderer *g_renderer;
extern bool g_flag_running;
extern int g_current_game_phase;

Stage5_Battle::Stage5_Battle()
{
	bgm = Mix_LoadMUS("../Resources/Battle.mp3");
	correct = Mix_LoadWAV("../Resources/Correct.wav");
	incorrect = Mix_LoadWAV("../Resources/Incorrect.wav");
	wow = Mix_LoadWAV("../Resources/Stadium.wav");
	Mix_VolumeMusic(128);
	Mix_PlayMusic(bgm, -1);
	Mix_PlayChannel(-1, wow, 0);
	// 변수들의 초기화
	{
		effect_cnt = 0;
		current_effect = 0;
		time = 60;
		started = true;

		cnt = 0;

		type = 0;

		c_font = TTF_OpenFont("../Resources/Hack-Bold.ttf", 50);	// 커서 폰트
		time_font = TTF_OpenFont("../Resources/arose.ttf", 40);
		ip_font = TTF_OpenFont("../Resources/malgun.ttf", 20);

		// 문제들을 vector에 삽입한다.
		q.push_back(Question(1, L"7+6 = ?", L"Test", "13"));
		q.push_back(Question(1, L"8+3 = ?", L"Test", "11"));
		q.push_back(Question(1, L"17-9 = ?", L"Test", "8"));
		q.push_back(Question(2, L"using namespace ???;", L"1)wow 2)std 3)stl 4)cnt", "2"));
		q.push_back(Question(1, L"방금 전 문제의 wow의 위치는?", L"Test", "1"));
		q.push_back(Question(1, L"10+2*2 = ?", L"Test", "14"));
		q.push_back(Question(1, L"6*2*3 = ?", L"Test", "36"));
		q.push_back(Question(2, L"만나면 하는 행동?", L"1)인사 2)시비 3)절도 4)연구", "1"));
		q.push_back(Question(1, L"35+45 = ?", L"Test", "80"));
		q.push_back(Question(2, L"Hello,", L"1)Land 2)Room 3)World 4)Hi", "3"));
		q.push_back(Question(1, L"3+9+3 = ?", L"Test", "15"));
		q.push_back(Question(1, L"4*4*4 = ?", L"Test", "64"));
		q.push_back(Question(1, L"2*2*2*2*2*3! = ?", L"Test", "96"));

		// 초기값 설정
		L_IP = 100;
		R_IP = 100;

		input_text.s_rect.x = 0;
		input_text.s_rect.y = 0;
	}

	TextureManager *tm = TextureManager::GetSingleton();

	// ui
	{
		tm->LoadTexture("ui", "../Resources/ui.png");
		tm->AddSpriteRect("ui_time", 569, 29, 168, 136);
		tm->AddSpriteRect("LeftBar", 802, 54, 41, 359);
		tm->AddSpriteRect("RightBar", 979, 54, 41, 359);
		tm->AddSpriteRect("ui_question", 18, 421, 742, 225);
		tm->AddSpriteRect("ui_pad", 1237, 54, 298, 317);
		tm->AddSpriteRect("compute", 796, 501, 180, 44);
		tm->AddSpriteRect("select", 1039, 504, 180, 49);

		t_srect.x = 18; // TimeBar Rect
		t_srect.y = 685;
		t_srect.h = 13;
		t_drect.x = 280;
		t_drect.y = 39;
		t_drect.h = 18;
		L_srect.x = 802; // Left IP Bar
		L_srect.w = 41;  // s_y, s_h, d_y, d_h 값이 IP에 따라 변해야한다.
		L_drect.x = 17;
		L_drect.w = 41;
		R_srect.x = 979; // Right IP Bar
		R_srect.w = 41;  // s_y, s_h, d_y, d_h 값이 IP에 따라 변해야한다.
		R_drect.x = 1220;
		R_drect.w = 41;
	}
	tm->LoadTexture("stage_bg", "../Resources/F_BackGround.png");
	tm->LoadTexture("ui_bg", "../Resources/black_frame.png");

	// Character
	{
		tm->LoadTexture("Character", "../Resources/Character.png");
		tm->AddSpriteRect("Hero", 13, 134, 303, 444);
		tm->LoadTexture("Enemy", "../Resources/Stage5_enemy.png");
		tm->AddSpriteRect("Stage5_Battle_enemy", 0, 0, 396, 571);
	}

	// 커서
	{
		cursor.text = "_";
		temp_cursor = TTF_RenderUTF8_Blended(c_font, cursor.text.c_str(), { 0, 0, 0, 255 });
		cursor.texture = SDL_CreateTextureFromSurface(g_renderer, temp_cursor);
		cursor.s_rect.x = 0;
		cursor.s_rect.y = 0;
		cursor.s_rect.w = temp_cursor->w;
		cursor.s_rect.h = temp_cursor->h;
		cursor.d_rect.w = temp_cursor->w;
		cursor.d_rect.h = temp_cursor->h;
	}

	tm->LoadTexture("Effect", "../Resources/Effect.png");
	tm->AddSpriteRect("atk_Damage", 695, 146, 377, 495); // 1
	tm->AddSpriteRect("taken_Damage", 310, 146, 377, 495); // 2
}

Stage5_Battle::~Stage5_Battle()
{
	TTF_CloseFont(time_font);
	TTF_CloseFont(ip_font);
	Mix_HaltMusic();
	Mix_HaltChannel(-1);
	TTF_CloseFont(c_font);
	std::cout << "delete Stage5_Battle" << std::endl;
}

// 스테이지 제한시간 
void Stage5_Battle::UpdateTimeTexture(int ms)
{
	if (text_time != 0)
	{
		SDL_DestroyTexture(text_time);
		text_time = 0;
	}

	SDL_Color white = { 255, 255, 255, 0 };
	SDL_Surface *t_surface = TTF_RenderText_Blended(time_font, to_string((long long)time).c_str(), white);

	text_time_rect.x = 135;
	text_time_rect.y = 150;
	text_time_rect.w = t_surface->w;
	text_time_rect.h = t_surface->h;

	text_time = SDL_CreateTextureFromSurface(g_renderer, t_surface);

	SDL_FreeSurface(t_surface);
}

void Stage5_Battle::Update()
{
	TextureManager *tm = TextureManager::GetSingleton();
	if (input.ScanInput())
	{
		// 입력값이 정답과 일치하면
		if (Input::input_space != "")
		{
			if (q[cnt].Q_Update(Input::input_space.c_str())) // 정답
			{
				Input::input_space = ""; // 입력공간이 공백이 된다.
				Mix_PlayChannel(-1, correct, 0);
				R_IP -= 10; // 적의 체력이 줄어든다.
							// 적의 ip가 0이 되었을 경우
				effect_cnt = SDL_GetTicks();
				current_effect = 1;
				if (R_IP == 0)
				{
					g_current_game_phase = PHASE_STAGE5_END;
				}
				else
				{
					cnt++; // 다음 문제로 이동
				}
			}
			else // 오답
			{
				Input::input_space = ""; // 입력공간이 공백이 된다.
				Mix_PlayChannel(-1, incorrect, 0);
				current_effect = 2;
				effect_cnt = SDL_GetTicks();
				cnt++; // 다음 문제로 이동
				L_IP -= 40; // 나의 체력이 줄어든다.
							// 주인공의 ip가 0이 되었을 경우
				if (L_IP == 0 || L_IP < 0)
				{
					g_current_game_phase = PHASE_GAMEOVER;
				}
			}
		}
	}
	// 시간에 따른 바 변화
	t_drect.w = q[cnt].Q_Time();
	t_srect.w = t_drect.w;
	if (t_drect.w <= 0)
	{
		// 시간을 초과하면 체력이 줄어든다.
		cnt++;
		L_IP = L_IP - 40;
		Mix_PlayChannel(-1, incorrect, 0);

		// 주인공의 ip가 0이 되었을 경우
		if (L_IP == 0 && L_IP < 0)
		{
			g_current_game_phase = PHASE_GAMEOVER;
		}
	}
	if (Input::input_space == "") // 입력공간이 빈 상태면
	{
		temp = TTF_RenderUTF8_Blended(c_font, " ", { 0, 0, 0, 255 }); // Answer이 나온다.
		input_text.texture = SDL_CreateTextureFromSurface(g_renderer, temp);
	}
	else
	{
		temp = TTF_RenderUTF8_Blended(c_font, Input::input_space.c_str(), { 0, 0, 0, 255 });
		input_text.texture = SDL_CreateTextureFromSurface(g_renderer, temp);
	}

	// IP Bar Rect 설정
	// s_y, s_h, d_y, d_h 값이 IP에 따라 변해야한다.
	L_srect.y = 54 + ((100 - L_IP) * 359 / 100);
	L_srect.h = 359 * (float)(L_IP / 100.f);
	L_drect.y = 308 + ((100 - L_IP) * 359 / 100);
	L_drect.h = 359 * (float)(L_IP / 100.f);
	R_srect.y = 54 + ((100 - R_IP) * 359 / 100);
	R_srect.h = 359 * (float)(R_IP / 100.f);
	R_drect.y = 308 + ((100 - R_IP) * 359 / 100);
	R_drect.h = 359 * (float)(R_IP / 100.f);


	// Rect 연산
	input_text.s_rect.w = temp->w;
	input_text.s_rect.h = temp->h;
	input_text.d_rect.w = temp->w;
	input_text.d_rect.h = temp->h;
	input_text.d_rect.x = 1280 / 2 - temp->w / 2;
	input_text.d_rect.y = 503;
	cursor.d_rect.x = input_text.d_rect.x + input_text.d_rect.w - cursor.s_rect.w;
	cursor.d_rect.y = input_text.d_rect.y + 10;

	// 스테이지 제한시간 text
	{
		static Uint32 last_ticks = SDL_GetTicks();
		Uint32 current_ticks = SDL_GetTicks();

		// 스테이지 제한시간이 0이 되었을 경우
		if (time == 0)
		{
			g_current_game_phase = PHASE_GAMEOVER;
		}
		time -= (current_ticks / 1000) - (last_ticks / 1000);
		UpdateTimeTexture(time);

		last_ticks = current_ticks;
	}

	// IP text
	{
		SDL_Color white = { 255, 255, 255, 0 };
		SDL_Surface *h_ip_surface = TTF_RenderText_Blended(ip_font, to_string((long long)L_IP).c_str(), white);
		SDL_Surface *e_ip_surface = TTF_RenderText_Blended(ip_font, to_string((long long)R_IP).c_str(), white);

		text_ip_rect[0].x = 21;
		text_ip_rect[0].y = 279;
		text_ip_rect[0].w = h_ip_surface->w;
		text_ip_rect[0].h = h_ip_surface->h;

		text_ip_rect[1].x = 1220;
		text_ip_rect[1].y = 279;
		text_ip_rect[1].w = e_ip_surface->w;
		text_ip_rect[1].h = e_ip_surface->h;

		text_ip[0] = SDL_CreateTextureFromSurface(g_renderer, h_ip_surface);
		text_ip[1] = SDL_CreateTextureFromSurface(g_renderer, e_ip_surface);

		SDL_FreeSurface(h_ip_surface);
		SDL_FreeSurface(e_ip_surface);
	}
	type = q[cnt].Q_Type();
}

void Stage5_Battle::Render()
{
	TextureManager *tm = TextureManager::GetSingleton();

	SDL_SetRenderDrawColor(g_renderer, 255, 255, 255, 255);
	SDL_RenderClear(g_renderer); // clear the renderer to the draw color

	tm->DrawSprite("stage_bg");
	tm->DrawSprite("ui_bg");

	// ui
	{
		tm->DrawSprite("ui", "ui_time", 79, 85);
		tm->DrawSprite("ui", t_srect, t_drect);
		tm->DrawSprite("ui", L_srect, L_drect);
		tm->DrawSprite("ui", R_srect, R_drect);
		tm->DrawSprite("ui", "ui_question", 268, 66);
	}

	// character
	{
		tm->DrawSprite("Character", "Hero", 176, 276);
		tm->DrawSprite("Enemy", "Stage5_Battle_enemy", 825, 256);
	}
	// Effect
	if (SDL_GetTicks() - effect_cnt < 1000)
	{
		if (current_effect == 1)
		{
			tm->DrawSprite("Effect", "taken_Damage", 150, 225);
		}
		else if (current_effect == 2)
		{
			tm->DrawSprite("Effect", "atk_Damage", 150, 225);
		}
	}
	tm->DrawSprite("ui", "ui_pad", 491, 403);
	if (type == 1)
	{
		tm->DrawSprite("ui", "compute", 553, 454);
	}
	else if (type == 2)
	{
		tm->DrawSprite("ui", "select", 553, 453);
	}
	SDL_RenderCopy(g_renderer, text_time, 0, &text_time_rect);
	SDL_RenderCopy(g_renderer, text_ip[0], 0, &text_ip_rect[0]);
	SDL_RenderCopy(g_renderer, text_ip[1], 0, &text_ip_rect[1]);
	SDL_RenderCopy(g_renderer, input_text.texture, &input_text.s_rect, &input_text.d_rect);
	SDL_RenderCopy(g_renderer, cursor.texture, &cursor.s_rect, &cursor.d_rect);
	q[cnt].Q_Draw();

	SDL_RenderPresent(g_renderer);
}

void Stage5_Battle::HandleEvents()
{
	input.HandleEvents();
}