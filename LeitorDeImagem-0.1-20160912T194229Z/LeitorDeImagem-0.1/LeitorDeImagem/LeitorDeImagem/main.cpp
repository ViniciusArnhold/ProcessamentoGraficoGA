#include <Windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
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

void display(void)
{
}

void init(void)
{
}

int main(int argc, char** argv)
{

	/*
	int r=;buffer<<24
	int g=;buffer<<16
	int b=;buffer<<8
	int a=;buffer

	*/
	using namespace std;

	ifstream input("C:\geraldImagem.ptm", std::ios::binary);
	

#pragma region Codigo confiavel
	
	char buffer[256];

	int altura = 0;
	int largura = 0;

	input >> buffer;
	input >> buffer;
	altura += buffer[0] * 100;
	altura += buffer[1] * 10;
	altura += buffer[2];

	largura += buffer[4] * 100;
	largura += buffer[5] * 100;
	largura += buffer[6];

	input >> buffer;
	char *bufferImagem = new char[altura*largura * 4];

	input.read(bufferImagem, altura*largura * 4);

	int a;
	int r;
	int g;
	int b;
	int count = 0;
	for (int j = 0; j < altura; j++) {
		for (int i = 0; i < largura; i++) {
			a = buffer[count++] &&  0xfff;
			cout << a << " ";
		}
	}
	

	/*if (input) {
		//Tamanho arquivo
		input.seekg(0, input.end);
		int length = input.tellg();
		input.seekg(0, input.beg);
		std::cout << "Tamanho do arquivo: " << length << " caracteres\n";
		char buffer[256];
		int count = 0;
		while (!input.eof() && count < 30) {
			input.read(buffer, 256);
			for (int i = 0; i < sizeof(buffer); i++) {
				std::cout << int(buffer[i]) << " ";
			}
			count++;
		}

	}*/
#pragma endregion Codigo confiavel



	/*std::string linha;
	std::size_t countLinhas = 0;
	char buffer[256];
	int count = 0;
	while (!input.eof()&&count<10) {
		input >> buffer;
		for (int i = 0; i < 256; i++) {
			std::cout << int(buffer[i]) << " ";
		}
		printf("- Fim da linha -\n");
		count++;
	}*/

#pragma region Codigo c++.com
	/*	if (is) {
			// get length of file:
			is.seekg(0, is.end); // Vai ate o final do arquivo
			int length = is.tellg(); // Retorna o caminho percorrido ate agora
			is.seekg(0, is.beg); //Volta ao inicio

			char * buffer = new char[length]; //Cria um buffer com o tamanho do arquivo

			std::cout << "Reading " << length << " characters... ";
			// read data as a block:
			is.read(buffer, length);

			if (is)
				std::cout << "all characters read successfully.";
			else
				std::cout << "error: only " << is.gcount() << " could be read";
			is.close();

			// ...buffer contains the entire file...

			delete[] buffer;

		}*/
#pragma endregion Codigo c++.com

#pragma region Codigo Antigo
	/*char buffer[256];
	std::ifstream arq("C:\\Users\\Vinicius\\Desktop\\colorgrid.ptm", std::ios::binary);
	arq >> buffer;
	int count = 1;
	int a = 0;


	while (!arq.eof() && count < 50) {
		//printf("%d",count);
		while (count < 50) {
			arq >> buffer;
			int i = 0;
			while (buffer[i] != -52) {
				a = buffer[count];
				printf("%d", a);
				printf(" ");
				i++;
			}
			count++;
			printf("\n");
			printf("\n");
		}

	}
	std::cin.get();
	return 0; */
#pragma endregion Codigo Antigo

	std::cin.get();
	return 0;
}