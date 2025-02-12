#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
#include <SDL_ttf.h>

SDL_Texture* LoadImage(std::string, SDL_Renderer *);
void DrawTexture(float x, float y, SDL_Texture *, SDL_Renderer *);
bool DrawTexture(SDL_Texture* tex, SDL_Renderer* rend, float X, float Y, float X2, float Y2, float W, float H);
void DrawText(SDL_Renderer* rend, SDL_Color color, TTF_Font* font, std::string text, float X, float Y, float width, float height);