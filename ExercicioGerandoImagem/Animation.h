#include <vector>
#include "Image.h"
#pragma once
using namespace std;

class Animation
{
	int frameCount;
	vector<Image*> frames;

public:
	Animation();
	void addFrame(Image* img);
	Image getFrame(int index);
};

