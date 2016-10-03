#include "PTMReader.h"
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
#include "main.h"
#include "PTMReader.h"
#include "Image.h"
#include <string>


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

	ifstream input("C:\\Users\\Vinicius\\Desktop\\colorgrid.ptm", std::ios::binary);
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
		input >> buffer;

		int a = 0;
		int r = 0;
		int g = 0;
		int b = 0;

		int alt = 0;
		int lar = 0;

		for (int i = 0; i < (altura*largura * 4); i++) {
			a = buffer[i] - '0';
			r = buffer[i++] - '0';
			g = buffer[i++] - '0';
			b = buffer[i++] - '0';
			if (largura == lar) {
				alt++;
				lar = 0;
			}
			img.setPixel(a, r, g, b, alt, lar);
			lar++;
			cout << a << " - " << r << " - " << g << " - " << b << endl;
		}


	}

	std::cin.get();
}
