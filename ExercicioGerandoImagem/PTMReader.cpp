#include <Windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include  <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>
#include "PTMReader.h"
#include "Image.h"
#include <string>
#include "hello.h"

PTMReader::PTMReader() {

}

char * PTMReader::nextLine()
{
	return nullptr;
}

Image PTMReader::getImage()
{
	return img;
}

void PTMReader::ler(char* caminho)
{

	using namespace std;

	ifstream input(caminho, std::ios::binary);
	int largura = 0;
	int altura = 0;
	string str;

#pragma region Codigo confiavel
	if (input) {

		//Tamanho arquivo
		char textBuffer[256];

		cout << "Leitor de arquivo PTM.";
		input >> textBuffer;//Primeira linha
		cout << "Tipo de Arquivo: " << textBuffer << endl;

		input >> textBuffer;//Segunda linha
		str = textBuffer;
		largura = stoi(str);
		cout << "Largura: " << largura << endl;

		input >> textBuffer;//Terceira linha
		str = textBuffer;
		altura = stoi(str);
		cout << "Altura: " << altura << endl;

		input >> textBuffer;//Quarta linha
		cout << "Numero de cores: " << textBuffer << endl;

		cout << endl <<
				"  ---------------------  " << endl;
		cout << "Iniciando leitura binaria" << endl;
		cout << "  ---------------------  " << endl << endl;

		img = Image(largura, altura);

		//Binary
		char * buffer = new char[altura*largura * 4];
		input.read(buffer, altura*largura * 4);

		int larL = largura - 1;
		int altL = 0;

		int a = 0;
		int r = 0;
		int g = 0;
		int b = 0;

		int alt = 0;
		int lar = 0;
		int i = 0;
		for (int y = altura - 1; y > 0; y--) {
			for (int x = 0; x < largura; x++) {
				b = 0xff & buffer[i++];//aaaaaa
				a = 0xff & buffer[i++];//rrr
				r = 0xff & buffer[i++];//gg
				g = 0xff & buffer[i++];//b
				img.setPixel(a, r, g, b, x, y);
			}
		}

		cout << "Arquivo " << caminho << "terminou de ser lido.";
	}
}