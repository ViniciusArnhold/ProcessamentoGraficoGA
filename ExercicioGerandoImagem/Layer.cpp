/* ___                                                        _            ___            __ _                       ___   _
  / _ \_ __ ___   ___ ___  ___ ___  __ _ _ __ ___   ___ _ __ | |_ ___     / _ \_ __ __ _ / _(_) ___ ___             / _ \ /_\
 / /_)/ '__/ _ \ / __/ _ \/ __/ __|/ _` | '_ ` _ \ / _ \ '_ \| __/ _ \   / /_\/ '__/ _` | |_| |/ __/ _ \   _____   / /_\///_\\
/ ___/| | | (_) | (_|  __/\__ \__ \ (_| | | | | | |  __/ | | | || (_) | / /_\\| | | (_| |  _| | (_| (_) | |_____| / /_\\/  _  \
\/    |_|  \___/ \___\___||___/___/\__,_|_| |_| |_|\___|_| |_|\__\___/  \____/|_|  \__,_|_| |_|\___\___/          \____/\_/ \_/
								Unisinos 2016 - Vinicius Pegorini Arnhold e Reni Steffenon
*/
#include "Layer.h"

Layer::Layer(float rateX, float rateY)
{
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
	this->rateX = mainWidth * 0, 75;
}

void Layer::computeScrollRateY(int mainHeight)
{
	this->rateY = mainHeight * 0, 75;
}

void Layer::setBackground(Image* image) {
	this->background = image;
}

void Layer::addGameObject(GameObject* go) {
	this->elements.push_back(go);
}

Image* Layer::getBackground() {
	return background;
}