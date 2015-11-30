#pragma once
#ifndef THE_GAME
#define THE_GAME

#include "BaseObject.h"

#include <string>
using std::string;
#include <vector>
using std::vector;

class GameEngine;
class AssetLoader;

class TheGame : public BaseObject
{
public:
	GameEngine *gameEngine;

public:
	TheGame();

	virtual ~TheGame();

	void loadShaders(const string& shaderAssetFilename);

	void setupGraphicsParameters(const string& uniformAssetFilename);

	void setupViewingEnvironment();

	void sendShaderData();

	void setup(const string& gameAssetFilename);

	void processInputs();
};

#endif

