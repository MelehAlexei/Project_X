#include "pch.h"

#include "Entity.h"
#include <string>

std::vector<Entity*> Entity::EntityList;

Entity::Entity() {
	Texture_Entity = NULL;

	TypeEntity = KIND_NPC;

	X = Y = 0.0f;

	Width = Height = 0;

	AnimState = 0;
}

Entity::~Entity() {
}

bool Entity::OnLoad(std::string File, SDL_Renderer* renderer, int Width, int Height, int MaxFrames) {
	if ((Texture_Entity = LoadImage(File, renderer)) == NULL) {
		return false;
	}

	//Texture::Transparent(Texture_Entity, 255, 0, 255);

	this->Width = Width;
	this->Height = Height;

	Anim_Control.MaxFrames = MaxFrames;

	return true;
}

void Entity::OnLoop() {
	Anim_Control.OnAnimate();
}

void Entity::OnRender(SDL_Renderer* renderer) {
	if (Texture_Entity == NULL || renderer == NULL) return;

	DrawTexture(Texture_Entity, renderer, X, Y, AnimState * Width, Anim_Control.GetCurrentFrame() * Height, Width, Height);
}

void Entity::OnCleanup() {
	if (Texture_Entity) {
		SDL_DestroyTexture(Texture_Entity);
	}

	Texture_Entity = NULL;
}