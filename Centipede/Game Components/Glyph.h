#ifndef _Glyph
#define _Glyph

#include "SFML\Graphics.hpp"
#include "TEAL/CommonElements.h"

class SpriteSheet;

class Glyph : public GameObject
{
public:
	Glyph();
	Glyph(SpriteSheet* sheet, int cellInd, sf::Vector2f pos);
	virtual void Draw();
	virtual void Destroy();

private:
	SpriteSheet* sprsheet;
	int cellIndex;
	sf::Vector2f position;

};


#endif _Glyph
