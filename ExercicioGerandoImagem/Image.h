#pragma once
class Image
{
	unsigned int *pixels;
	int width, height;
public:
	Image(int w, int h);
	Image();
	void setPixel(int rgb, int x, int y);
	void setPixel(int a, int r, int g, int b, int x, int y);
	int getPixel(int x, int y);
	unsigned int* getPixels();
	int getWidth();
	int getHeight();
	void setWidth(int w);
	void setHeight(int h);
	void calcular();
	void plot(Image sobreposta, int posicaoX , int posicaoY);
	int calcularPixels(int sobreposta, int fundo);
	
};
