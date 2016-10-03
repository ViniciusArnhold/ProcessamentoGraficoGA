#include <Windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

void poligono(void)
{
	/*  clear all pixels  */
	glClear(GL_COLOR_BUFFER_BIT);

	/*  draw white polygon (rectangle) with corners at
	*  (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
	*/
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.25, 0.25, 0.0);
	glVertex3f(0.75, 0.25, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	glVertex3f(0.25, 0.75, 0.0);
	glEnd();

	/*  don't wait!
	*  start processing buffered OpenGL routines
	*/
	glFlush();
}

void circulo(void) {

	glColor3f(0.0, 1.0, 0.0);
	#define PI 3.1415926535898
	GLfloat circle_points = 100.0f;
	GLfloat angle, raioX = 0.5f, raioY = 0.25f;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < circle_points; i++) {
		angle = 2 * PI*i / circle_points;
		glVertex2f(cos(angle)*raioX, sin(angle)*raioY);
	}
	glEnd();

	glFlush();
}


//Questão 2
void poligonoIsometrico(void) {
	float altura = 0.25;
	float largura = 0.5;
	float posicaoInicial = 0.25;

	/*  clear all pixels  */
	glClear(GL_COLOR_BUFFER_BIT);

	/*  draw white polygon (rectangle) with corners at
	*  (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
	*/
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(largura*0+posicaoInicial, altura/2+posicaoInicial, 0.0);
	glVertex3f(largura/2+posicaoInicial, altura+posicaoInicial, 0.0);
	glVertex3f(largura+posicaoInicial, altura/2+posicaoInicial, 0.0);
	glVertex3f(largura/2+posicaoInicial, altura*0+posicaoInicial, 0.0);
	glEnd();

	/*  don't wait!
	*  start processing buffered OpenGL routines
	*/
	glFlush();
}

//Questão 3
void poligonoIsometricoDois(void) {
	float altura = 0.25;
	float largura = 0.5;
	float posicaoInicial = 0.25;

	/*  clear all pixels  */
	glClear(GL_COLOR_BUFFER_BIT);

	/*  draw white polygon (rectangle) with corners at
	*  (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
	*/
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glVertex3f(largura * 0 + posicaoInicial, altura / 2 + posicaoInicial, 0.0);
	glVertex3f(largura / 2 + posicaoInicial, altura + posicaoInicial, 0.0);
	glVertex3f(largura + posicaoInicial, altura / 2 + posicaoInicial, 0.0);
	glVertex3f(largura / 2 + posicaoInicial, altura * 0 + posicaoInicial, 0.0);
	glEnd();
	
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(largura * 0 + posicaoInicial, altura / 2 + posicaoInicial, 0.0);
	glVertex3f(largura / 2 + posicaoInicial, altura * 0 + posicaoInicial, 0.0);
	glVertex3f(largura / 2 + posicaoInicial, altura * 0 + posicaoInicial-altura/4, 0.0);
	glVertex3f(largura * 0 + posicaoInicial, altura / 2 + posicaoInicial-altura/4, 0.0);
	glEnd();

	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex3f(largura + posicaoInicial, altura / 2 + posicaoInicial, 0.0);
	glVertex3f(largura + posicaoInicial, altura / 2 + posicaoInicial-altura/4, 0.0);
	glVertex3f(largura / 2 + posicaoInicial, altura * 0 + posicaoInicial-altura/4, 0.0);
	glVertex3f(largura / 2 + posicaoInicial, altura * 0 + posicaoInicial, 0.0);
	glEnd();
	/*  don't wait!
	*  start processing buffered OpenGL routines
	*/
	glFlush();
}

//questão 4
void conjuntoPoligonos() {
	float altura = 0.1;
	float largura = 0.2;
	float posicaoX = 0.5;
	float posicaoY = 0.75;

	/*  clear all pixels  */
	glClear(GL_COLOR_BUFFER_BIT);

	/*  draw white polygon (rectangle) with corners at
	*  (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
	*/
	
	for (int i = 0; i < 12; i++) {
		
		glColor3f(0.8, 0.8, 0.8);
		glBegin(GL_POLYGON);
		glVertex3f(largura * 0 + posicaoX, altura / 2 + posicaoY, 0.0);
		glVertex3f(largura / 2 + posicaoX, altura + posicaoY, 0.0);
		glVertex3f(largura + posicaoX, altura / 2 + posicaoY, 0.0);
		glVertex3f(largura / 2 + posicaoX, altura * 0 + posicaoY, 0.0);
		glEnd();

		glColor3f(0.5, 0.5, 0.5);
		glBegin(GL_POLYGON);
		glVertex3f(largura * 0 + posicaoX, altura / 2 + posicaoY, 0.0);
		glVertex3f(largura / 2 + posicaoX, altura * 0 + posicaoY, 0.0);
		glVertex3f(largura / 2 + posicaoX, altura * 0 + posicaoY - altura / 4, 0.0);
		glVertex3f(largura * 0 + posicaoX, altura / 2 + posicaoY - altura / 4, 0.0);
		glEnd();

		glColor3f(0.3, 0.3, 0.3);
		glBegin(GL_POLYGON);
		glVertex3f(largura + posicaoX, altura / 2 + posicaoY, 0.0);
		glVertex3f(largura + posicaoX, altura / 2 + posicaoY - altura / 4, 0.0);
		glVertex3f(largura / 2 + posicaoX, altura * 0 + posicaoY - altura / 4, 0.0);
		glVertex3f(largura / 2 + posicaoX, altura * 0 + posicaoY, 0.0);
		glEnd();

		if (i < 5) {
			posicaoX = (posicaoX / 2) + posicaoX;
			posicaoY = (posicaoY / 2) - posicaoY;
		}

		else {
			if (i < 8) {
				posicaoX = (posicaoX / 2) - posicaoX;
				posicaoY = (posicaoY / 2) - posicaoY;
			}
			else {
				if (i < 11) {
					posicaoX = (posicaoX / 2) - posicaoX;
					posicaoY = (posicaoY / 2) + posicaoY;
				}
				else {
					posicaoX = (posicaoX / 2) + posicaoX;
					posicaoY = (posicaoY / 2) + posicaoY;
				}
			}
		}
		

	}
	/*  don't wait!
	*  start processing buffered OpenGL routines
	*/
	glFlush();
}

void init(void)
{
	/*  select clearing (background) color       */
	glClearColor(0.0, 0.0, 0.0, 0.0);

	/*  initialize viewing values  */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
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
	int opcao = 99;
	int opcaoUm = 99;
	while (opcao != 0) {
		printf("Digite a opcao desejada:\n "
			/**Exercicio 1**/"\n[1] Desenho de primitivas"
			/**Exercicio 2**/"\n[2] Desenho de poligono tile isometrico"
			/**Exercicio 3**/"\n[3] Desenho de poligono tile isometrico 2.5D"
			/**Sair**/"\n[0] Sair \n");
		std::cin >> opcao;

		switch (opcao)
		{

			case 1: //referente a opcao 1
				
				
				while (opcaoUm != 0) {
					printf("Digite a opcao desejada:\n "
						/**Exercicio 1**/"\n[1] Poligono"
						/**Exercicio 2**/"\n[2] circulo"
						/**Exercicio 3**/"\n[3] elipse"
						/**Sair**/"\n[0] Sair \n");
					std::cin >> opcaoUm;

					switch (opcaoUm)
					{
					case 1:
						printf("Eu escolhi a opcao 1 ");
						glutInit(&argc, argv);
						glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
						glutInitWindowSize(250, 250);
						glutInitWindowPosition(100, 100);
						glutCreateWindow("hello");
						init();
						glutDisplayFunc(poligono);
						glutMainLoop();
						return 0;   /* ISO C requires main to return int. */
						break;

					case 2:
						printf("Eu escolhi a opcao 2 ");
						glutInit(&argc, argv);
						glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
						glutInitWindowSize(500, 500);
						glutInitWindowPosition(100, 100);
						glutCreateWindow("hello");
						init();
						glutDisplayFunc(circulo);
						glutMainLoop();
						return 0;   /* ISO C requires main to return int. */
						break;

					case 0:
						break;
					
					}
				}
				break;

			case 2: //referente a opcao 2
				printf("Eu escolhi a opcao 2 : poligono isometrico ");
				glutInit(&argc, argv);
				glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
				glutInitWindowSize(250, 250);
				glutInitWindowPosition(100, 100);
				glutCreateWindow("poligono isometrico");
				init();
				glutDisplayFunc(poligonoIsometrico);
				glutMainLoop();
				return 0;   /* ISO C requires main to return int. */
				break;
			
			case 3: //sair
				printf("Eu escolhi a opcao 3 : poligono isometrico 2.5D ");
				glutInit(&argc, argv);
				glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
				glutInitWindowSize(250, 250);
				glutInitWindowPosition(100, 100);
				glutCreateWindow("poligono isometrico 2.5D");
				init();
				glutDisplayFunc(poligonoIsometricoDois);
				glutMainLoop();
				return 0;   /* ISO C requires main to return int. */
				break;

			case 4: //sair
				printf("Eu escolhi a opcao 4 : conjuto poligonos isometrico ");
				glutInit(&argc, argv);
				glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
				glutInitWindowSize(250, 250);
				glutInitWindowPosition(100, 100);
				glutCreateWindow("Conjunto de poligonos isometricos 2.5D");
				init();
				glutDisplayFunc(conjuntoPoligonos);
				glutMainLoop();
				return 0;   /* ISO C requires main to return int. */
				break;

			case 0:
				break;

		}
		return (0);
	}
}

	
