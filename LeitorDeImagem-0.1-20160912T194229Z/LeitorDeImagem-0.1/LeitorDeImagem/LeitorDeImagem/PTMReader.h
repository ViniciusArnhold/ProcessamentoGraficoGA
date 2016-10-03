#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include "Image.h"

class PTMReader
{
	Image img;
public:
	PTMReader(char* caminho);
	char* nextLine();
	Image getImage();
	void ler(char* caminho);
};

