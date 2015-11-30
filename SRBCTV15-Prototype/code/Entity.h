#ifndef _ENTITY_
#define _ENTITY_
#include "Component.h"
#include <SFML/Graphics.hpp>
#include "Enums.h"
#include <string>
class Entity : public Component
{
public:
	Entity();
	//Entity(const sf::Texture& textureOfEntity);
	Entity(/*const sf::Texture& textureOfEntity, Enums::TYPE, Enums::CLASS,*/ const std::string& name);//   <- if we make it to multiple chess pieces as mobs
	void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::FloatRect& getBounds();// 2D collision detection funct
	virtual void update();
	virtual ~Entity();
	virtual void moveLeft();
	virtual void moveRight();
	virtual void moveUp();
	virtual void moveDown();
	virtual void moveUpLeft();
	virtual void moveUpRight();
	virtual void moveDownLeft();
	virtual void moveDownRight();
	
private:
	//Enums::TYPE type;
//	Enums::CLASS Entclass;
	std::string name; //ideal to not be a reference to string


};
#endif