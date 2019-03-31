#pragma once

#include <SDL.h>
#include <Define.h>

class GameTime {
private:
	int start_timer, next_part;
	partOfDay cur_part;
public:
	GameTime();
	void SetPart(partOfDay);
	partOfDay GetPart();
	void OnLoop();
};