#include <Windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include "Retangulo.h"
#include  <stdio.h>
#include <stdlib.h>


Retangulo matrixRet[40][20];

void drawRect(int xx,int yy,int w,int h,int red,int green,int blue) {


}

void display()
{
	/*  clear all pixels  */
	glClear(GL_COLOR_BUFFER_BIT);
	int countX = 0;
	int countY = 0;

	double xx = 1024 / 20;
	double yy = 768 / 40;

	glBegin(GL_QUADS);
	for (int i = 0; i < 1024; i+=xx)
	{
		for (int j = 0; j < 768; j+=yy)
		{
			int red = matrixRet[countX][countY].getRed();
			int green = matrixRet[countX][countY].getGreen();
			int blue = matrixRet[countX][countY].getBlue();
			
			drawRect(i,j,xx,yy,red,green,blue);
			countX++;
		}
		countY++;
	}
	glEnd();


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
	glOrtho(0.0, 1024.0, 0.0, 768.0, -1.0, 1.0);
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
	int posX = 0;
	int posY = 0;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Jogo das Cores");
	init();
	glutDisplayFunc(display);

	glutMainLoop();
	return 0;   /* ISO C requires main to return int. */
}