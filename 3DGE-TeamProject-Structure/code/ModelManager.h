#pragma once

#include <map>
#include <vector>
#include "BaseObject.h"
using std::map;
#include <string>
using std::string;

class Model;
class ModelManager : public BaseObject
{
protected:
	map<string, Model*> ModelMap;

public:
	ModelManager();
	~ModelManager();

	void loadModel(const string& ModelName, string filename);

	Model* getModel(const string& ModelName);
};

