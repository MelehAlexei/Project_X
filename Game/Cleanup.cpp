#include "pch.h"

#include "Main.h"

void App::Cleanup()
{
	testNPC.OnCleanup();
	for (int i = 0; i < (int)Entity::EntityList.size(); i++) {
		if (!Entity::EntityList[i]) continue;

		Entity::EntityList[i]->OnCleanup();
	}
	Entity::EntityList.clear();
	testNPC.OnCleanup();
	Hero.OnCleanup();
	App::Game_Map.OnCleanup();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(background);
	SDL_DestroyWindow(Window);
	SDL_Quit();
}
