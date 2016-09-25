#include <Windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include  <stdio.h>
#include <stdlib.h>
#include "Image.h"
#include "PTMReader.h"

Image imagem;
int inicioPersonagem = 0;
int posicaoPersonagemX = 200;
int sentido = 0;


void updateScene(int value) {
	PTMReader leitorFundo = PTMReader();
	leitorFundo.ler("C:\\Geralt-de-Rivia.ptm");
	imagem = leitorFundo.getImage();
	int xPersonagem = 0;
	int yPersonagem = 0;

	PTMReader leitorPersonagem = PTMReader();
	leitorPersonagem.ler("C:\\Sully.ptm");
	Image aux = leitorPersonagem.getImage();
	Image personagem(64, 64);

	for (int x = inicioPersonagem * 64; x < (inicioPersonagem * 64) + 64; x++) {
		for (int y = 128; y < 192; y++) {
			personagem.setPixel(aux.getPixel(x, y), xPersonagem, yPersonagem);
			yPersonagem++;
		}
		yPersonagem = 0;
		xPersonagem++;
	}
	if (inicioPersonagem == 3) {
		inicioPersonagem = 0;
	}
	else {
		inicioPersonagem++;
	}
	imagem.plot(personagem, posicaoPersonagemX, 50);

	if (posicaoPersonagemX > 399) {
		sentido = 1;
	}
	else {
		if (posicaoPersonagemX < 201) {
			sentido = 0;
		}
	}

	if (sentido == 0) {
		posicaoPersonagemX += 25;
	}
	else {
		posicaoPersonagemX -= 25;
	}

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glDrawPixels(imagem.getWidth(), imagem.getHeight(), GL_BGRA_EXT, GL_UNSIGNED_BYTE,
		imagem.getPixels());
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
	leitorFundo.ler("C:\\Geralt-de-Rivia.ptm");
	Image fundo = leitorFundo.getImage();

	imagem = fundo;
}

/*
*  Declare initial window size, position, and display mode
*  (single buffer and RGBA).  Open window with "hello"
*  in its title bar.  Call initialization routines.
*  Register callback function to display graphics.
*  Enter main loop and process events.
*/
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