#include "Font.h"
#include "TEAL\ResourceManager.h"

Font::Font()
	: SpriteSheet(ResourceManager::GetTexture("Font"), 16, 3)
{}

int Font::CharToIndex(char& c)
{
	int cellIndex = 0;

	if (c >= 'a' && c <= 'z')
		c -= 32;

	if (c >= '0' && c <= '9')
		cellIndex = (int)c - (int) '0';
	else if (c >= 'A' && c <= 'Z')
		cellIndex = (int)c - (int) 'A' + 17;
	else
		switch (c)
		{
		case ' ':	
			cellIndex = 16;
			break;
		case ':':	
			cellIndex = 10;
			break;
		case '/':	
			cellIndex = 11;
			break;
		case '[':	// Copyright
			cellIndex = 12;
			break;
		case ']':	// Publisher
			cellIndex = 14;
			break;
		default:
			cellIndex = 16;
		}

	return cellIndex;
}