#pragma once

#include "SDL.h"
#include <vector>
#include <map>
#include <string>


class TextureManager
{
private:
	TextureManager() {};
	static TextureManager* instance_;

public:

	// Singleton
	static void CreateInstance();
	static void DestroyInstance();
	static TextureManager* GetSingleton();

	// Load Texture 
	bool LoadTexture(std::string texture_id, std::string file_name);
	bool LoadTexture(std::string texture_id, std::string file_name, unsigned char color_key_r, unsigned char color_key_g, unsigned char color_key_b);
	void AddSpriteRect(std::string sprite_id, int x, int y, int w, int h);

	// Texture Mode
	void SetTextureColorMode(std::string texture_id, int R, int G, int B);

	// Draw
	void DrawSprite(std::string texture_id);
	void DrawSprite(std::string texture_id, std::string sprite_id, int x, int y);
	void DrawSprite(std::string texture_id, SDL_Rect s_rect, SDL_Rect d_rect);


	SDL_Rect GetSpriteRect(std::string sprite_id) const { return sprite_rects_.find(sprite_id)->second; }
	SDL_Texture* GetTexture(std::string texture_id) { return texture_map_[texture_id]; }
private:
	std::map<std::string, SDL_Texture*> texture_map_;
	std::map<std::string, SDL_Rect> sprite_rects_;


};

