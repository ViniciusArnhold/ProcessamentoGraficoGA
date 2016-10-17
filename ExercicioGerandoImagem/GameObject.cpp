/* ___                                                        _            ___            __ _                       ___   _
  / _ \_ __ ___   ___ ___  ___ ___  __ _ _ __ ___   ___ _ __ | |_ ___     / _ \_ __ __ _ / _(_) ___ ___             / _ \ /_\
 / /_)/ '__/ _ \ / __/ _ \/ __/ __|/ _` | '_ ` _ \ / _ \ '_ \| __/ _ \   / /_\/ '__/ _` | |_| |/ __/ _ \   _____   / /_\///_\\
/ ___/| | | (_) | (_|  __/\__ \__ \ (_| | | | | | |  __/ | | | || (_) | / /_\\| | | (_| |  _| | (_| (_) | |_____| / /_\\/  _  \
\/    |_|  \___/ \___\___||___/___/\__,_|_| |_| |_|\___|_| |_|\__\___/  \____/|_|  \__,_|_| |_|\___\___/          \____/\_/ \_/
								Unisinos 2016 - Vinicius Pegorini Arnhold e Reni Steffenon
*/
#include "GameObject.h"
#include "Animation.h"
#include <iostream>
using namespace std;

GameObject::GameObject()
{
	int currentFrame = 0;
}

void GameObject::incCurrentFrame()
{
	currentFrame = (currentFrame + 1) % this->anim->getSize();
}

void GameObject::setSprite(Animation* anim)
{
	this->anim = anim;
}

int GameObject::getCurFrameNum()
{
	return currentFrame;
}

Image* GameObject::getFrame()
{
	return this->anim->getFrame(currentFrame);
}

int GameObject::getPosX()
{
	return this->posX;
}
void GameObject::setPosX(int novaPos)
{
	this->posX = novaPos;
}

int GameObject::getPosY()
{
	return this->posY;
}
void GameObject::setPoxY(int novaPos)
{
	this->posY = novaPos;
}

