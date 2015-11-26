#include "Label.h"


Label::Label() : text(), font(), Component()
{
	text.setColor(sf::Color::Red);
	text.setString("unnamed");
	if (!font.loadFromFile("Sansation.ttf"))
	{

	}
	text.setFont(font);
	text.setCharacterSize(35);
}

Label::Label(const std::string& txt, bool selectable) : text(), font(), Component(selectable)
{
	text.setColor(sf::Color::White);
	text.setString(txt);
	if (!font.loadFromFile("Sansation.ttf"))
	{

	}
	text.setFont(font);
	text.setCharacterSize(35);
}

Label::Label(const std::string& txt, float x, float y, bool selectable) : text(), font(), Component(selectable)
{
	text.setColor(sf::Color::White);
	text.setString(txt);
	if (!font.loadFromFile("Sansation.ttf"))
	{

	}
	text.setFont(font);
	text.setCharacterSize(35);
	text.setPosition(x, y);
}

Label::Label(const std::string& txt, float x, float y, bool selectable, const std::string& fontType, const sf::Color& color, int characterSize) {
	text.setColor(color);
	text.setString(txt);
	if (!font.loadFromFile(fontType))
	{

	}
	text.setFont(font);
	text.setCharacterSize(characterSize);
	text.setPosition(x, y);



};

void Label::draw(sf::RenderTarget& t, sf::RenderStates states) const {

	///Each component will be drawn per menu or HUD/UI
	t.draw(text, states);
	//cout << "did we reach here?";


};

sf::FloatRect& Label::getBounds() { return Text().getGlobalBounds(); }

Label::~Label()
{
}
