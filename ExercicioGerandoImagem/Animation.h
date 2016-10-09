#include <vector>
#include "Image.h"
#pragma once
using namespace std;

class Animation
{
	int frameCount = 0;
	vector<Image*> frames;

public:
	Animation();
	void addFrame(Image* img);
	Image* getFrame(int index);
	int getSize();
};

