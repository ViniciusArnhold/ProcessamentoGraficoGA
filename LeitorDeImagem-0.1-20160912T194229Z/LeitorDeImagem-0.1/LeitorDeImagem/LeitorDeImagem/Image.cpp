#include "Image.h"



Image::Image(int largura, int altura) {
	width = largura;
	height = altura;
	pixels = new int[width*height];
}

void Image::setPixel(int rgb, int x, int y) {
	pixels[x + y*width] = rgb;
}

int Image::getPixel(int x, int y) {
	return pixels[x + y*width];
}

void Image::setPixel(int a, int r, int g, int b, int x, int y) {
	pixels[x + y*width] = (a << 24) | (r << 16) | (g << 8) | (b);
}
int* Image::getPixels() {
	return pixels;
}

int Image::getWidth() {
	return width;
}

int Image::getHeight() {
	return height;
}

int Image::getAlpha(int x, int y)
{
	return (pixels[x + y*width] >> 24) & 0xff;
}

int Image::getRed(int x, int y)
{
	return (pixels[x + y*width] >> 16) & 0xff;
}

int Image::getGreen(int x, int y)
{
	return (pixels[x + y*width] >> 8) & 0xff;
}

int Image::getBlue(int x, int y)
{
	return pixels[x + y*width] & 0xff;
}
