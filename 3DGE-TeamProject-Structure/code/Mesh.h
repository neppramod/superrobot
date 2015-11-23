#pragma once
#include "OGL3DObject.h"
class Mesh :
	public OGL3DObject
{
private:
	float * vertexData;
	short * indexData;

	void generate();

public:
	Mesh(string name, float * vertexData, short * indexData);
	~Mesh();
	float* getVertexData() { return this->vertexData; }
	short* getIndexData() { return this->indexData; }
};

