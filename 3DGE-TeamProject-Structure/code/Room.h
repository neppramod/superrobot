#pragma once
#ifndef ROOM
#define ROOM

#include "OGL3DCompositeObject.h"

#include <vector>
using std::vector;

class OGLTexturedFlatSurface;

class Room : public OGL3DCompositeObject
{
protected:
	vector<OGLTexturedFlatSurface*> floors;

public:
	Room();
	virtual ~Room();

	void setShaderProgram(GLuint shaderProgram);

	void update(float elapsedSeconds);

	void render();

	void addFloor(OGLTexturedFlatSurface* floor) {
		this->floors.push_back(floor);
	}
};

#endif

