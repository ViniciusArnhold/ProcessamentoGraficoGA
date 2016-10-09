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