#pragma once
#ifndef GAME_OBJECT
#define GAME_OBJECT

#include "BaseObject.h"
#include "RGBA.h"
#include "BoundingBox.h"

#include <string>
using std::string;
#include <map>
using std::map;

class IBehavior;
class Texture;

struct Material {
	float ambientIntensity; // Light emitted by this object
	RGBA specular; 
	float shininess; 
};

// GameObject -> BaseObject
class GameObject : public BaseObject
{
protected:
	// Must be allocated on the heap, the first element stores
	// the size
	//float * vertexData;
	// Must be allocated on the heap, the first element stores
	// the size
	//short* indexData;

	bool visible;

	IBehavior* behavior;

	Texture* texture;

	map<string, GameObject*> objectsColliding;

public:
	Material material;

	BoundingBox boundingBox;

	bool showBoundingBox;

public:
	GameObject(string name);

	virtual ~GameObject();

	//void setVertexData(float * vertexData) { this->vertexData = vertexData; }

	//float* getVertexData() { return this->vertexData; }

	//void setIndexData(short* indexData) { this->indexData = indexData; }

	//short* getIndexData() { return this->indexData; }

	virtual void setTexture(Texture* texture) { this->texture = texture; }

	bool isTextured() { return this->texture != nullptr; }

	virtual void update(float elapsedSeconds);

	virtual void render() = 0;

	void setVisibility(bool visible) { this->visible = visible; }

	bool isVisible() const { return this->visible; }

	void setBehavior(IBehavior* behavior) { this->behavior = behavior; }

	bool checkForCollision(GameObject* otherObject);

	bool isCollidingWith(GameObject* otherObject);

	bool isColliding() { return this->objectsColliding.size() > 0; }

	void clearCollisions() { this->objectsColliding.clear(); }
};

#endif

