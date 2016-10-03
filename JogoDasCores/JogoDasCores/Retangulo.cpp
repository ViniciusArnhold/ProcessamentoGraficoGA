#include <Windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include "Retangulo.h"
#include  <stdio.h>
#include <stdlib.h>


Retangulo::~Retangulo(){}

Retangulo::Retangulo()
{
	r = rand() % 256;
	g = rand() % 256;
	b = rand() % 256;
	visibility = true;
}

Retangulo::Retangulo(int red, int green, int blue)
{
	r = red;
	g = green;
	b = blue;
	visibility = true;
}
void Retangulo::setVisibility() {
	visibility = false;
}
bool Retangulo::isVisivel() {
	return visibility;
}
int Retangulo::getRed() {
	return r;
}
int Retangulo::getGreen() {
	return g;
}
int Retangulo::getBlue() {
	return b;
}

