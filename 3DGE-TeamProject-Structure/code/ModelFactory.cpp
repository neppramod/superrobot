#include "ModelFactory.h"


ModelFactory::ModelFactory()
{
}


ModelFactory::~ModelFactory()
{
	for (
		auto iterator = this->models.begin();
		iterator != this->models.end();
		iterator++) {
		delete iterator->second;
	}
}

Model* ModelFactory::GetModel(string fileName)
{
	if(!models[fileName])
	{
		models[fileName] = new Model(fileName);
	}

	return models[fileName];
}