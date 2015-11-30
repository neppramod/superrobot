#include "Button.h"


Button::Button() : Label(), isMouseOver(false), isPress(false), state(Enums::BUTTON_DEFAULT),
currentColor(sf::Color::White)
{

}
Button::Button(const std::string& display) : Label(display, true),
isMouseOver(false), isPress(false), currentColor(sf::Color::White), state(Enums::BUTTON_DEFAULT)
{

}

Button::Button(const std::string& display, float x, float y, Commands::Command* commnd) : Label(display, x, y, true),
isMouseOver(false), isPress(false), currentColor(sf::Color::White), state(Enums::BUTTON_DEFAULT), command(commnd)
{

}
sf::FloatRect& Button::getBounds() { return Text().getGlobalBounds(); }
void Button::setState(Enums::BUTTON_STATES sta) { state = sta; }

void Button::update(const sf::Event& event) {

	switch (state) {
	case Enums::BUTTON_DEFAULT:
		Text().setColor(sf::Color::White);
		break;
	case Enums::BUTTON_PRESSED:
		Text().setColor(sf::Color::Red);
		break;
	case Enums::BUTTON_SELECTED:
		Text().setColor(sf::Color::Yellow);
		break;
	}

}

//these deconstrs in the gui classes aren't needed, but will keep for now
//if kept, remember to do rule of 3/5/0
Button::~Button()
{
}
