#include "Layer.h"



Layer::Layer(int rateX,int rateY)
{
	float rateX;
	float rateY;
	float posX;
	float posY;
	Image background;
	vector<GameObject*> elements;
}

void Layer::scroll(bool right)
{
	if (right) {

	}
	else {//left

	}
	//TODO Implementar
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