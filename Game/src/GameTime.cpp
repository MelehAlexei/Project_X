#include "pch.h"
#include "GameTime.h"

GameTime::GameTime() {
	start_timer = SDL_GetTicks();
	cur_part = MORNING;
	next_part = 1;
}

void GameTime::OnLoop() {
	int cur_timer = SDL_GetTicks();
	if (cur_timer - start_timer > PartDuration) {
		start_timer = cur_timer;
		cur_part = (partOfDay)((cur_part + next_part) % COUNT_PART);
	}
}

void GameTime::SetPart(partOfDay p) {
	cur_part = p;
	start_timer = SDL_GetTicks();
}

partOfDay GameTime::GetPart() {
	return cur_part;
}