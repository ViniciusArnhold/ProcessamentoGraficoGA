/* ___                                                        _            ___            __ _                       ___   _
  / _ \_ __ ___   ___ ___  ___ ___  __ _ _ __ ___   ___ _ __ | |_ ___     / _ \_ __ __ _ / _(_) ___ ___             / _ \ /_\
 / /_)/ '__/ _ \ / __/ _ \/ __/ __|/ _` | '_ ` _ \ / _ \ '_ \| __/ _ \   / /_\/ '__/ _` | |_| |/ __/ _ \   _____   / /_\///_\\
/ ___/| | | (_) | (_|  __/\__ \__ \ (_| | | | | | |  __/ | | | || (_) | / /_\\| | | (_| |  _| | (_| (_) | |_____| / /_\\/  _  \
\/    |_|  \___/ \___\___||___/___/\__,_|_| |_| |_|\___|_| |_|\__\___/  \____/|_|  \__,_|_| |_|\___\___/          \____/\_/ \_/
								Unisinos 2016 - Vinicius Pegorini Arnhold e Reni Steffenon
*/
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
//<<<<<<< HEAD
//=======
	Image* getFrame();
	int getPosX();
	int getPosY();
	void setPosX(int novaPos);
	void setPoxY(int novaPos);
//>>>>>>> origin/master
};

