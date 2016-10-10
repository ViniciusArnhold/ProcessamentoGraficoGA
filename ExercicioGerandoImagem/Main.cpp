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


#pragma warning( disable : 4244)//Conversao sempre estara no range

using namespace std;

vector<Layer *> layers;
vector<Animation *> animations;
Image *scene, *backup;
char *zBuffer, *zBuffer2;


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

void keyboard(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_RIGHT:
		for each (Layer* layer in layers)
		{
			layer->scroll(true);
		}
		break;
	case GLUT_KEY_LEFT:
		for each (Layer* layer in layers)
		{
			layer->scroll(false);
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
		1) carregar imagens das camadas
	*/
	PTMReader leitorFundo = PTMReader();
	leitorFundo.ler("C:\\Users\Administrador\Documents\ProcessamentoGrafico\Imagens\montanhas.ptm");
	imagem = leitorFundo.getImage();

	/*
		2) Inicializar Layers, para cada layer da cena
	*/
	Layer cena1 = Layer(0,0);
	cena1.setBackground(&imagem);
	/*
		3) Carregar animações objetos do jogo
	*/
		PTMReader leitorPersonagem = PTMReader();
		leitorPersonagem.ler("C:\\Users\Administrador\Documents\ProcessamentoGrafico\Imagens\T-rex.ptm");
		sprite = leitorPersonagem.getImage();
		GameObject personagemDireita = GameObject();
		GameObject personagemEsquerda = GameObject();
		Animation animacaoPersonagemDireita = Animation();
		Animation animacaoPersonagemEsquerda = Animation();
		for (int x = 0; x < sprite.getHeight()+1; x += 242) {
			for (int y = 0; y < sprite.getWidth()/2+1; y += 126) {
				if (x = 242) {
					Image aux = Image(242, 126);
					Image *p = &aux;
					sprite.subImage(p, x, y);
					animacaoPersonagemDireita.addFrame(&aux);
					delete p;
				}
				else {
					Image aux = Image(242, 126);
					Image *p = &aux;
					sprite.subImage(p, x, y);
					animacaoPersonagemEsquerda.addFrame(&aux);
					delete p;
				}
			}
		}
		personagemDireita.setSprite(animacaoPersonagemDireita);
		personagemEsquerda.setSprite(animacaoPersonagemEsquerda);

	/*
		4) Inicializar scene, backup, zBuffer e zBuffer2
		
	*/
		scene = &imagem;
		Image imagemBackup = imagem;
		backup = &imagemBackup;
		int tamanhox = scene->getHeight();
		char buffer[1600*900];
		char buffer2[1600*900];
		//zBuffer = &buffer;
		//zBuffer2 = &buffer2;


}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	init();
	glutInitWindowSize(imagem.getWidth(), imagem.getHeight());
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Processamento Grafico - GA");
	glutDisplayFunc(display);
	updateScene(1);
	glutMainLoop();
	return 0;   /* ISO C requires main to return int. */

	//TODO Deletar Ponteiros Criados
}