#include <Windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include "Retangulo.h"
#include  <stdio.h>
#include <stdlib.h>


Retangulo::Retangulo()
{
	r = rand() % 256;
	g = rand() % 256;
	b = rand() % 256;
	visibility = true;
}

void Retangulo::setVisibility() {
	visibility = false;
}
bool Retangulo::isVisivel() {
	return visibility;
}
float Retangulo::getRed() {
	return r;
}
float Retangulo::getGreen() {
	return g;
}
float Retangulo::getBlue() {
	return b;
}

