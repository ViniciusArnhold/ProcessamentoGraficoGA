#include "Image.h"



Image::Image(int largura, int altura) {
	width = largura; 
	height = altura;
	pixels = new unsigned int[width*height];
}

Image::Image() {
	width = 0;
	height = 0;
}

void Image::setWidth(int w) {
	width = w;
}

void Image::setHeight(int h) {
	height = h;
}

void Image::calcular() {
	pixels = new unsigned int[width*height];
}

void Image::setPixel(int rgb, int x, int y) {
	pixels[x + y*width] = rgb;
}

int Image::getPixel(int x, int y) {
	return pixels[x + y*width];
}

void Image::setPixel(int a, int r, int g, int b, int x, int y) {
	//unsigned long int aux = (a << 24) | (r << 16) | (g << 8) | (b);
	pixels[x + y*width] = (a << 24) | (r << 16) | (g << 8) | (b);
}
unsigned int* Image::getPixels() {
	return pixels;
}

int Image::getWidth() {
	return width;
}

int Image::getHeight() {
	return height;
}

void Image::plot(Image sobreposta, int posicaoX, int posicaoY) {

	int xSobreposta=0;
	int ySobreposta=0;

	for (int x = posicaoX; x < sobreposta.width+posicaoX; x++) {
		for (int y = posicaoY; y < posicaoY+sobreposta.height; y++) {
			int pixelSobreposta = sobreposta.getPixel(xSobreposta, ySobreposta);
			int alfa = (pixelSobreposta >> 24) & 0xff;
			if ( alfa == 0) {
			}
			else {
				if (alfa == 255) {
					setPixel(pixelSobreposta, x, y);
				}
				else {
					setPixel(calcularPixels(pixelSobreposta, getPixel(x, y)), x, y);
				}
			}
			ySobreposta++;
			
		}
		ySobreposta = 0;
		xSobreposta++;
	}
	
}

int Image::calcularPixels(int sobreposta, int fundo) {
	int aSobreposta = (sobreposta >> 24) & 0xff;
	int rSobreposta = (sobreposta >> 16) & 0xff;
	int gSobreposta = (sobreposta >> 8) & 0xff;
	int bSobreposta = sobreposta & 0xff;

	int aFundo = (fundo >> 24) & 0xff;
	int rFundo = (fundo >> 16) & 0xff;
	int gFundo = (fundo >> 8) & 0xff;
	int bFundo = fundo & 0xff;

	double alfa = aSobreposta / 255;
	int r = 0;
	int g = 0;
	int b = 0;

	r = rFundo*(1 - alfa) + rSobreposta*alfa;
	g = gFundo*(1 - alfa) + gSobreposta*alfa;
	b = bFundo*(1 - alfa) + bSobreposta*alfa;

	int resultado = (255 << 24) | (r << 16) | (g << 8) | (b);

	return resultado;
}