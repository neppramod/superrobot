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

std::vector<Container*> MenuRenderHelper = {};

OptionsMenu optionsMenu;
World world;
CharacterCreation characterCreation;

int main(void)
{
	Game* gameWindow = new Game();
	gameWindow->getWindow()->setVisible(false);
	GameEngine gameEngine(
		new WindowsConsoleLogger(), 
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
	gameEngine.loadShaders("code/ShaderAssets.data");
	gameEngine.initializeWindowAndGraphics("code/ShaderAssets.data");
	gameEngine.setupGame("code/GameAssets.data");
	world.setEngine(&gameEngine);
	GraphicsSystem *graphics = gameEngine.getGraphicsSystem();
	world.setGraphicsSystem(graphics);
	gameWindow->getWindow()->setVisible(true);
	
	gameEngine.run();

	return 0;
}
