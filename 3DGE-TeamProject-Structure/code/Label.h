#ifndef _LABEL_
#define _LABEL_
#include "Component.h"
#include <string>
class Label : public Component
{
public:
	Label();
	Label(const std::string& display, bool selectable);
	Label(const std::string& display, float x, float y, bool selectable);
	Label::Label(const std::string& txt, float x, float y, bool selectable, const std::string& fontType, const sf::Color& color, int charSize);
	virtual ~Label();
	void draw(sf::RenderTarget& t, sf::RenderStates states) const;
	sf::FloatRect& getBounds();
	inline sf::Text& Text() { return text; };
	inline sf::Font& Font() { return font; };

private:
	sf::Text text;
	sf::Font font;
};

#endif