#include "Container.h"
#include "Button.h"

Container::Container() :components()
{
}

void Container::update(const sf::Event& event, const sf::RenderWindow& window) {
	for (const_iterator a = cbegin(); a != cend(); a++)
	{
		sf::FloatRect boundingbox = (*a)->getBounds();
		sf::Vector2f point = { static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y) };
		if (event.type == sf::Event::MouseButtonPressed && boundingbox.contains(sf::Vector2f(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y))) && (*a)->isSelectable() == true)
		{
			(*a)->setState(Enums::BUTTON_PRESSED);

		}
		else if (event.type == sf::Event::MouseButtonReleased && boundingbox.contains(sf::Vector2f(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y))) && (*a)->isSelectable() == true)
		{
			static_cast<Button*>((*a))->getCommand().execute();

		}
		else if (event.type == sf::Event::MouseMoved && boundingbox.contains(point) && (*a)->isSelectable() == true)
			(*a)->setState(Enums::BUTTON_SELECTED);
		else if (!boundingbox.contains(point))
			(*a)->setState(Enums::BUTTON_DEFAULT);
		(*a)->update(event);
	}
}

void Container::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	for (const_iterator a = cbegin(); a != cend(); a++)
	{
		(*a)->draw(target, states);
	}

};

Container::~Container()
{
}
