#pragma once
class Image
{
	int *pixels;
	int width, height;
public:
	Image(int w, int h);
	void setPixel(int argb, int x, int y);
	void setPixel(int a, int r, int g, int b, int x, int y);
	int getPixel(int x, int y);
	int* getPixels();
	int getWidth();
	int getHeight();
	int getAlpha(int x, int y);
	int getRed(int x, int y);
	int getGreen(int x, int y);
	int getBlue(int x, int y);
	
};
