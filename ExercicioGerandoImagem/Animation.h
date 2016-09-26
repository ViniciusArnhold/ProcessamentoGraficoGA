#include "Image.h"

#pragma once
class Animation
{
	Image arrayImages;
	int quadroAtual;
public:
	Animation();
	Image nextQuadro();
	void getQuadroAtual();
};

