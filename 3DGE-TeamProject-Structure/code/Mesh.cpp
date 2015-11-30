#include "Mesh.h"



Mesh::Mesh(string name, float * vertexData, short * indexData) : OGL3DObject(name)
{
	this->vertexData = vertexData;
	this->indexData = indexData;
	this->generate();
}


Mesh::~Mesh()
{
	delete[] vertexData;
	delete[] indexData;
}

void Mesh::generate()
{
	this->createElementArrayPCNT(this->name, this->vertexData, this->indexData, GL_TRIANGLES);
}
