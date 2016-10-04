#include <Windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include  <stdio.h>
#include <stdlib.h>
#include "Image.h"
#include "PTMReader.h"
#include <iostream>

#pragma warning( disable : 4244)//Conversao sempre estara no range

using namespace std;

//Sprites
int numSpritesLargura = 4;
int numSpritesAltura = 4;
int widthSprites = 0;
int heightSprites = 0;

int xSprite = 0;
int ySprite = 0;

Image imagem;
Image sprite;


void updateScene(int value) {

	Image impressao = imagem.clone();


	widthSprites = floor(sprite.getWidth() / numSpritesLargura);
	heightSprites = floor(sprite.getHeight() / numSpritesAltura);

	Image personagem1(64, 64);

	sprite.subImage(&personagem1, xSprite*widthSprites, ySprite*heightSprites);

	impressao.plot(personagem1, 50, 50);

	if (ySprite == numSpritesAltura - 1 && xSprite == numSpritesLargura - 1) {
		ySprite = 0;
		xSprite = 0;
	}
	else if (xSprite == numSpritesLargura - 1) {
		xSprite = 0;
		ySprite++;
	}
	else {
		xSprite++;
	}

	cout << xSprite << " " << ySprite << endl << widthSprites << " " << heightSprites << endl;

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glDrawPixels(impressao.getWidth(), impressao.getHeight(), GL_BGRA_EXT, GL_UNSIGNED_BYTE,
		impressao.getPixels());
	glFlush();

	glutTimerFunc(500, updateScene, 1);
}

void display(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glDrawPixels(imagem.getWidth(), imagem.getHeight(), GL_BGRA_EXT, GL_UNSIGNED_BYTE,
		imagem.getPixels());
	glFlush();
}

void keyboard(int key,int x,int y) {
	switch (key)
	{
	case GLUT_KEY_RIGHT:

		break;
	case GLUT_KEY_LEFT:
		break;
	default:
		break;
	}
}

void init(void)
{
	/*  select clearing (background) color       */
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	/*  initialize viewing values  */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

	PTMReader leitorFundo = PTMReader();
	leitorFundo.ler("C:\\Teste1.ptm");
	imagem = leitorFundo.getImage();

	PTMReader leitorPersonagem = PTMReader();
	leitorPersonagem.ler("C:\\Sully.ptm");
	sprite = leitorPersonagem.getImage();

}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	init();
	glutInitWindowSize(imagem.getWidth(), imagem.getHeight());
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Gerar Imagem exercicio 4");
	glutDisplayFunc(display);
	updateScene(1);
	glutMainLoop();
	return 0;   /* ISO C requires main to return int. */
}