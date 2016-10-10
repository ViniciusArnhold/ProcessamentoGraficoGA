/* ___                                                        _            ___            __ _                       ___   _
  / _ \_ __ ___   ___ ___  ___ ___  __ _ _ __ ___   ___ _ __ | |_ ___     / _ \_ __ __ _ / _(_) ___ ___             / _ \ /_\
 / /_)/ '__/ _ \ / __/ _ \/ __/ __|/ _` | '_ ` _ \ / _ \ '_ \| __/ _ \   / /_\/ '__/ _` | |_| |/ __/ _ \   _____   / /_\///_\\
/ ___/| | | (_) | (_|  __/\__ \__ \ (_| | | | | | |  __/ | | | || (_) | / /_\\| | | (_| |  _| | (_| (_) | |_____| / /_\\/  _  \
\/    |_|  \___/ \___\___||___/___/\__,_|_| |_| |_|\___|_| |_|\__\___/  \____/|_|  \__,_|_| |_|\___\___/          \____/\_/ \_/
								Unisinos 2016 - Vinicius Pegorini Arnhold e Reni Steffenon
*/

#pragma once

#include <Windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include  <stdio.h>
#include <stdlib.h>
#include "Image.h"
#include "PTMReader.h"
#include <iostream>
#include "Layer.h"
#include "Animation.h"
#include "Timer.h"


#pragma warning( disable : 4244)//Conversao sempre estara no range

using namespace std;

//Tamanhos
int xPA = 57;
int yPA;
int xPP = 54;
int yPP;
int xCobra = 300;
int yCobra;

vector<Layer> layers;
Image scene, backup;
char *zBuffer, *zBuffer2;

Animation animPerAndando = Animation();
Animation animPerPulando = Animation();
Animation animCobra = Animation();
Animation animCaixa = Animation();
Animation animSpike = Animation();

GameObject objPerPulando = GameObject();
GameObject objPerAndando = GameObject();
GameObject objCobra = GameObject();
GameObject objCaixa = GameObject();
GameObject objSpike = GameObject();
Timer timer = Timer();

PTMReader leitor = PTMReader();

bool playing = true;

void updateScene(int value) {

	glutTimerFunc(500, updateScene, 1);

}

void display(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glDrawPixels(500, 500, GL_BGRA_EXT, GL_UNSIGNED_BYTE,
		scene.getPixels());
	glFlush();
}

void update(int value) {
	timer.start();
	objCobra.incCurrentFrame();
	glutPostRedisplay();
	timer.finish();
	int waitingTime = timer.calcWaitingTime(30, timer.getElapsedTimeMs());
	if (playing) {
		glutTimerFunc(waitingTime, update, 5);
	}
}

void keyboard(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_RIGHT:
		for (int i = 0; i < layers.size(); i++)
		{
			layers.at(i).scroll(true);
		}
		break;
	case GLUT_KEY_LEFT:
		for (int i = 0; i < layers.size(); i++)
		{
			layers.at(i).scroll(false);
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
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	/*  initialize viewing values  */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

	/*
		1) carregar imagens das camadas e   2) inicia a layer
	*/
	Layer layer = Layer();
	leitor.ler("C:\\Imagens\zMinus3.ptm");
	layer.setBackground(leitor.getImage());
	layers.push_back(layer);
	leitor.ler("C:\\Imagens\zMinus2.ptm");
	layer = Layer();
	layer.setBackground(leitor.getImage());
	layers.push_back(layer);
	leitor.ler("C:\\Imagens\zMinus1.ptm");
	layer = Layer();
	layer.setBackground(leitor.getImage());
	layers.push_back(layer);
	leitor.ler("C:\\Imagens\zMinus0.ptm");
	layer = Layer();
	layer.setBackground(leitor.getImage());
	layers.push_back(layer);
	leitor.ler("C:\\Imagens\zPlus1.ptm");
	layer = Layer();
	layer.setBackground(leitor.getImage());
	layers.push_back(layer);

	/*
		3) Carregar anima��es objetos do jogo
	*/
	leitor.ler("PersonagemAndando");
	Image backup = Image(xPP, yPP);
	for (int i = 0; i < 3; i++) {
		leitor.getImage().subImage(&backup, i*xPA, 0);
		animPerPulando.addFrame(backup);
	}
	leitor.ler("PersonagemPulando");
	backup = Image(xPA, yPA);
	for (int i = 0; i < 3; i++) {
		leitor.getImage().subImage(&backup, i*xPA, 0);
		animPerAndando.addFrame(backup);
	}

	leitor.ler("Cobra");
	backup = Image(xCobra, yCobra);
	for (int i = 0; i < 8; i++) {
		leitor.getImage().subImage(&backup, i*xPA, 0);
		animCobra.addFrame(backup);
	}

	objPerPulando.setSprite(animPerPulando);
	objPerPulando.setPosX(50);
	objPerPulando.setPoxY(0);
	objPerAndando.setSprite(animPerAndando);
	objPerPulando.setPosX(50);
	objPerPulando.setPoxY(0);
	objCobra.setSprite(animCobra);
	objPerPulando.setPosX(500);
	objPerPulando.setPoxY(0);

	/*
		4) Inicializar scene, backup, zBuffer e zBuffer2

	*/
	layers.at(2).addGameObject(objPerPulando);
	layers.at(2).addGameObject(objPerAndando);
	layers.at(2).addGameObject(objCobra);

	for (int i = 0; i < layers.size(); i++) {
		layers.at(0).computeScrollRateX(500);
	}


}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	init();
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Processamento Grafico - GA");
	glutDisplayFunc(display);
	updateScene(1);
	glutMainLoop();
	return 0;   /* ISO C requires main to return int. */

	//TODO Deletar Ponteiros Criados
}