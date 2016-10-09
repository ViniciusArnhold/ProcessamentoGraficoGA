#include "Animation.h"
#pragma once
class GameObject
{
	int currentFrame;
	int posX;
	int posY;
	Animation anim;
public:
	GameObject();
	void incCurrentFrame();
	void setSprite(Animation anim);
};

