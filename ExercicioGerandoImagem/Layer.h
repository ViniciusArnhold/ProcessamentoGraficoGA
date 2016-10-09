#include "Image.h"
#include "GameObject.h"
#include <vector>
#pragma once

using namespace std;
class Layer
{
	float rateX;
	float rateY;
	float posX;
	float posY;
	Image background;
	vector<GameObject*> elements[20];

public:
	Layer(float rateX, float rateY);
	void scroll(bool right);
	void plot(Image* vpImage, char zBuffer[]);
	void computeScrollRateX(int mainWidth);
	void computeScrollRateY(int mainHeight);
	void setBackground(Image image);
	void setGameObject(GameObject objeto);
};

