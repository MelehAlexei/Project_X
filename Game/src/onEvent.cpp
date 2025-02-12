#include "pch.h"

#include "Main.h"

void App::onEvent(SDL_Event* Event)
{
	Events::OnEvent(Event);
}

void App::OnExit() {
	Running = false;
}

void App::OnKeyDown(SDL_Keycode sym, int mod, int unicode){
	switch (sym) {
	//case SDLK_UP:    if (Motion::MoveTo(Hero.X, Hero.Y - 1)) Hero.Y -= STEP; break;
	//case SDLK_DOWN:  if (Motion::MoveTo(Hero.X, Hero.Y + 1)) Hero.Y += STEP; break;
	case SDLK_a:		flags["A"] = true; break;
	case SDLK_d:		flags["D"] = true; break;
	case SDLK_SPACE:	flags["SPACE"] = true; break;

	default: {
	}
	}
}

void App::OnKeyUp(SDL_Keycode sym, int mod, int unicode) {
	switch (sym) {
	case SDLK_a:		flags["A"] = false; Hero.speedr = 0; break;
	case SDLK_d:		flags["D"] = false; Hero.speedr = 0; break;
	case SDLK_SPACE:	flags["SPACE"] = false; Hero.CAN_JUMP = true; break;

	default: {
	}
	}
}

void App::CheckFlags() {
	if (flags["A"] == true) {
		Hero.speedr -= STEP; Hero.speedr = std::max(-STEP * 1.0, 1.0 * Hero.speedr);
	}
	if (flags["D"] == true) {
		Hero.speedr += STEP; Hero.speedr = std::min(STEP * 1.0, 1.0 * Hero.speedr);
	}
	if (flags["SPACE"] == true) {
		if (Hero.STAY && Hero.CAN_JUMP) {
			Hero.FLYING = 4, Hero.CAN_JUMP = false;
		}
	}
}