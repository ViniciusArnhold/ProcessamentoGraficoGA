#include <Windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include "Retangulo.h"
#include  <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <sstream>

Retangulo matrixRet[20][40];
float posicao = 0;
int pontos = 0;
int posicaoQuadradoI = 0;
int posicaoQuadradoJ = 0;
int rodada = 1;
std::string jogador = "Reni";
std::string mensagem = "Jogo das Cores - Jogador: ";


float escreverTexto(std::string str, float x, float y, float charWidth) {

	glColor3i(255, 255, 255);

	for (int i = 0; i < str.length(); i++) {
		glRasterPos2d(x, y);
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)str.at(i));
		x += charWidth;
	}

	return x;

}

void desenharQuadrados(float posicaoX, float posicaoY, float w, float h, float red, float green, float blue) {

	glColor3f(red / 255, green / 255, blue / 255);
	//glColor(red, green, blue);
	glVertex2d(posicaoX, posicaoY);
	glVertex2d(posicaoX, posicaoY + h);
	glVertex2d(posicaoX + w, posicaoY + h);
	glVertex2d(posicaoX + w, posicaoY);
}

void gerarQuadrados() {
	/*  clear all pixels  */
	glClear(GL_COLOR_BUFFER_BIT);

	float posicaoX = 0;
	float posicaoY = 0;
	float largura = 1024 / 20;
	float altura = 512 / 40;

	glBegin(GL_QUADS);

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 40; j++) {

			if (matrixRet[i][j].isVisivel() == true) {
				float red = matrixRet[i][j].getRed();
				float green = matrixRet[i][j].getGreen();
				float blue = matrixRet[i][j].getBlue();
				desenharQuadrados(posicaoX, posicaoY, largura, altura, red, green, blue);
			}
			posicaoY += altura;
		}
		posicaoY = 0;
		posicaoX += largura;
		if (i == 19) {
			desenharQuadrados(5, 490, 1010, 20, 255, 255, 255);
		}
	}

	glEnd();


	glFlush();
}

bool calcDistancia(Retangulo c, Retangulo o, double diff) {
	double dmax = 441.673;
	float frac = (pow((c.getRed() - o.getRed()), 2)) +
		(pow((c.getGreen() - o.getGreen()), 2)) +
		(pow((c.getBlue() - o.getBlue()), 2));
	frac = sqrt(frac);
	double dis = frac / dmax;
	return dis <= diff;
}

void resetRandom() {
	pontos = 0;
	rodada = 1;
	gerarQuadrados();
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 20; j++) {
			matrixRet[j][i].generate();
		}
	}
	gerarQuadrados();
}

void reset() {
	pontos = 0;
	rodada = 1;

	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 20; j++) {
			matrixRet[j][i].setVisibility(true);
		}
	}
}

int apagarQuadrados(Retangulo c, int rodada) {

	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 20; j++) {
			if (calcDistancia(c, matrixRet[j][i], 0.15) && matrixRet[j][i].isVisivel()) {
				matrixRet[j][i].setVisibility(false);
				if (rodada == 1) {
					pontos += 10;
				}
				else if (rodada == 2) {
					pontos += 5;
				}
				else if (rodada == 3) {
					pontos += 2;
				}
				else if (rodada = 4) {
					pontos += 1;
				} 
			}
		}
	}
	return pontos;
}

void mouse(int button, int state, int x, int y) {
	int posicaoX = x;
	int posicaoY = 512 - y;
	int alturaQuadrados = 512 / 40;
	int larguraQuadrados = 1024 / 20;


	//printf("posicaoX = %d \n", posicaoX);
	//printf("posicaoY = %d \n", posicaoY);
	//printf("alturaQuadrados = %d \n", alturaQuadrados);
	//printf("larguraQuadrados = %d \n", larguraQuadrados);

	int posI = -1;
	int posJ = -1;

	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			for (int i = 0; i < 40; i++) {
				for (int j = 0; j < 20; j++) {
					if (i*alturaQuadrados < posicaoY && posicaoY < (i + 1)*alturaQuadrados) {
						if (j*larguraQuadrados < posicaoX && posicaoX < (j + 1)*larguraQuadrados && matrixRet[j][i].isVisivel()) {
							posI = i;
							posJ = j;
						}
					}
				}
			}
			if (posI==-1 || posJ==-2) {
				break;
			}
			posicaoQuadradoI = posI;
			posicaoQuadradoJ = posJ;

			printf("PosicaoQuadradoI = %d, PosicaoQuadradoJ = %d \n", posicaoQuadradoI, posicaoQuadradoJ);

			apagarQuadrados(matrixRet[posicaoQuadradoJ][posicaoQuadradoI], rodada);

			mensagem = "Jogo das Cores - Jogador: " + jogador + " - Pontos:" + (std::to_string(pontos)) + " - Rodada: " + (std::to_string(rodada));
			printf((mensagem + "\n").c_str());
			escreverTexto(mensagem, 10, 495, 10);
			rodada++;
			gerarQuadrados();
			if (rodada >= 5) {
				resetRandom();
			}
		}
		break;
	case GLUT_MIDDLE_BUTTON:
		if (state == GLUT_DOWN) {
			resetRandom();
			mensagem = "Jogo das Cores - Jogador: " + jogador + " - Pontos:" + (std::to_string(pontos))+" - Rodada: "+(std::to_string(rodada));
			printf((mensagem + "\n").c_str());
			escreverTexto(mensagem, 10, 495, 10);
		}
		break;
	default:
		break;
	}


}

void init(void)
{
	/*  select clearing (background) color       */
	glClearColor(0.0, 0.0, 0.0, 0.0);

	/*  initialize viewing values  */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1024, 0, 512, -1.0, 1.0);
}

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1024, 512);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Jogo das Cores");
	init();
	glutDisplayFunc(gerarQuadrados);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}