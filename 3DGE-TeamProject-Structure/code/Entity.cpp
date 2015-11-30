#include "Entity.h"

#include <iostream>

Entity::Entity(): Component()
{

}

//Entity::Entity(const Texture& textureOfEntity) : Component(){}

Entity::Entity(/*Enums::TYPE eType, Enums::CLASS eClass,*/ const std::string& name) :/*type(eType), Entclass(eClass),*/ name(name), Component(){}


void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	//target.draw(aModel, states);

};



void Entity::update() {



}

sf::FloatRect& Entity::getBounds() { sf::FloatRect rect;  return rect; } // does nothing -- WIP


void Entity::moveLeft() {  }
void Entity::moveRight() { }
void Entity::moveUp() {  }
void Entity::moveDown() { }
void Entity::moveUpLeft() {  }
void Entity::moveUpRight() {  }
void Entity::moveDownLeft() { }
void Entity::moveDownRight() { }

Entity::~Entity()
{
}
