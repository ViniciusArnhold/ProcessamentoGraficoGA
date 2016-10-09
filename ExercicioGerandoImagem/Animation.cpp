#include "Animation.h"



Animation::Animation()
{
	vector<Image*> frames;
	int frameCount;
}

void Animation::addFrame(Image * img)
{
	frames.push_back(img);
}

Image* Animation::getFrame(int index)
{
	return frames.at(index);
}
