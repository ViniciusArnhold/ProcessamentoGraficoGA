#pragma once
class Retangulo
{
	bool visibility;
	int r;
	int g;
	int b;
public:
	Retangulo();
	Retangulo(int r,int g,int b);
	~Retangulo();
	void setVisibility();
	bool isVisivel();
	int getRed();
	int getGreen();
	int getBlue();
};

