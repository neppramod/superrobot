#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glutilD.lib")

#include "Game.h"
#include "OptionsMenu.h"
#include "World.h"
#include "CharacterCreation.h"
#include "GameEngine.h"
#include "WindowsConsoleLogger.h"
#include "GameWindow.h"
#include "OGLVertexShader.h"
#include "OGLFragmentShader.h"
#include "OGLShaderProgram.h"
#include "OGLShaderManager.h"
#include "TextFileReader.h"
#include "OGLGraphicsSystem.h"
#include "CoreSystem.h"
#include "GameWorld.h"
#include "GameObjectManager.h"
#include "OGLSphericalCamera.h"
#include "OGLViewingFrustum.h"
#include "StockObjectLoader.h"
#include "PCInputSystem.h"
//#include "WindowsTimer.h"
#include "OGLFirstPersonCamera.h"
#include "TheGame.h"
#include "TextureManager.h"
#include "GameAssetLoader.h"


#include <iostream>

std::vector<Container*> MenuRenderHelper = {};

OptionsMenu optionsMenu;
World world;
CharacterCreation characterCreation;

int main(void)
{
	//free the current console so that the logger can create one
	//FreeConsole();
	WindowsConsoleLogger* logger = new WindowsConsoleLogger();
	logger->log("Initializing engine");
	//Game* gameWindow = new Game();
	GameEngine gameEngine(
		logger,
		new TheGame(),
		new GameAssetLoader(),
		new CoreSystem(
			new TextFileReader()), 
		new OGLGraphicsSystem(
			new OGLShaderManager(), 
			new GameWorld(
				new GameObjectManager(),
				new OGLSphericalCamera()),
			new OGLViewingFrustum(),
			new TextureManager()),
		new Game(),
		//gameWindow,
		new PCInputSystem()
	);
	gameEngine.getLogger()->log("Engine initialized");
	logger->log("Loading Shaders...");
	gameEngine.loadShaders("code/ShaderAssets.data");

	logger->log("Initializing window and graphics..");
	gameEngine.initializeWindowAndGraphics("code/ShaderAssets.data");

	logger->log("Setting up game...");
	gameEngine.setupGame("code/GameAssets.data");

	logger->log("Assiging world the engine...");
	world.setEngine(&gameEngine);

	GraphicsSystem *graphics = gameEngine.getGraphicsSystem();

	logger->log("Assiging world the graphics...");
	world.setGraphicsSystem(graphics);

	sf::RenderWindow* window = gameEngine.getGameWindow()->getWindow();

	logger->log("Assiging world the window...");
	world.setWindow(window);

	logger->log("Running the game...");
	gameEngine.run();

	logger->log("Exiting the game...");
	return 0;
}
