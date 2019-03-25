#include "pch.h"

#include "MainHero.h"
#include "Motion.h"

MainHero::MainHero() : Entity()
{
	TypeEntity = PLAYER;
	MaxHP = HP = 100;
}

void MainHero::OnLoop() {

	this->Entity::OnLoop();

	if (Motion::MoveTo(X + speedr, Y)) {
		X += speedr;
	}
	else {
		//speedr = 0;
	}
	if (speedr != 0) {
		(speedr > 0 ? side = 0 : side = 1);
	}
	X = round(X * 10) / 10;
	Y = round(Y * 10) / 10;
	if (FLYING < EPS) {
		if (!Motion::Gravity(speedf, X, Y)) {
			Y = round(Y);
			if (App::Game_Map.MAP[X][Y + 1].TypeID == TILE_TYPE_BLOCK) {
				X = round(X);
			}
			STAY = true;
			speedf = 0;
			if (fabs(speedr) > EPS) {
				Anim_Control.OnAnimate();
			}
		}
		else {
			STAY = false;
		}
	}
	else {
		Motion::Jump(FLYING, STAY, X, Y);
	}
}