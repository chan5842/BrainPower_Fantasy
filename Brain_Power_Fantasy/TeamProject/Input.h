#pragma once
#include "SDL.h"

#include <iostream>
class Input
{
private:
public:
	static bool key_state[13];
	// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, Enter, Backspace
	static std::string input_space;
	Input();
	~Input();
	static void HandleEvents();
	static bool ScanInput();
	static bool ScanEnter();
	static void RefreshButton();
};