#include "Layer.h"

Layer::Layer(float rateX, float rateY)
{
	float rateX = rateX;
	float rateY = rateY;
	float posX;
	float posY;
	Image background;
	vector<GameObject*> elements;
}


void Layer::scroll(bool right)
{
	if (right) {

	}
	else {

	}
}

void Layer::plot(Image * dest, char zBuffer[])
{
	for (int i = 0; i < dest->getWidth(); i++) {
		for (int j = 0; j < dest->getHeight(); j++) {

		}
	}
}

void Layer::computeScrollRateX(int mainWidth)
{
	//TODO Implementar
}

void Layer::computeScrollRateY(int mainHeight)
{
	//TODO Implementar
}

void setBackground(Image image) {
	
}

void setGamesetGameObject(GameObject objeto) {
	
}