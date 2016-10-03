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

void Image::setPixel(int r, int g, int b, int x, int y) {
	pixels[x + y*width] = (r << 16) | (g << 8) | (b);
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