#pragma once
#include "Model.h"
#include <map>

class ModelFactory
{
public:
	ModelFactory();
	~ModelFactory();
	Model * GetModel(string fileName);
private:
	map<string, Model*> models;
};

