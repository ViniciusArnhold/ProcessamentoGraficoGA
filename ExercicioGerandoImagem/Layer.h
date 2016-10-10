#include "Image.h"
#include "GameObject.h"
#include <vector>
#pragma once

using namespace std;
class Layer
{
//<<<<<<< HEAD
	float rateX;
	float rateY;
	float posX;
	float posY;
	//Image background;
//=======
//	float rateX = 0;
//	float rateY = 0;
//	float posX = 0;
//	float posY = 0;
	Image* background;
//>>>>>>> origin/master
	vector<GameObject*> elements;

public:
	Layer(float rateX, float rateY);
	void scroll(bool right);
	void plot(Image* vpImage, char zBuffer[]);
	void computeScrollRateX(int mainWidth);
	void computeScrollRateY(int mainHeight);
	void setBackground(Image* image);
	void addGameObject(GameObject* ob);
	Image* getBackground();
};

