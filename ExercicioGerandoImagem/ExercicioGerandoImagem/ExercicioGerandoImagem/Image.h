#pragma once
class Image
{
	int *pixels;
	int width, height;
public:
	Image(int w, int h);
	void setPixel(int rgb, int x, int y);
	void setPixel(int r, int g, int b, int x, int y);
	int getPixel(int x, int y);
	int* getPixels();
	int getWidth();
	int getHeight();
	
};
