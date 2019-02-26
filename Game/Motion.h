#pragma once

#include "Main.h"

namespace Motion {
	bool MoveTo(float toX, float toY);
	bool StopMove(float toX, float toY);
	bool Gravity(float& X, float& Y);
}