
#ifndef _COMPONENT_
#define _COMPONENT_
#include "SFML\Graphics.hpp"
#include "Enums.h"

class Component : public sf::Drawable, public sf::Transformable, sf::NonCopyable
{
public:
	Component();
	Component(bool isSelectable);
	virtual ~Component();
	void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	void virtual update(const sf::Event&) {};
	void virtual update(const sf::Window&) {};
	void virtual update() {};
	void virtual setState(Enums::BUTTON_STATES sta) {};
	virtual sf::FloatRect& getBounds() = 0;
	inline bool isSelectable() const { return isSelectabl; };
private:
	bool isSelectabl;
};

#endif