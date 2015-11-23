#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glutilD.lib")

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
#include "WindowsTimer.h"
#include "OGLFirstPersonCamera.h"
#include "TheGame.h"
#include "TextureManager.h"
#include "GameAssetLoader.h"
#include "SoundManager.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
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
				new OGLFirstPersonCamera()),
			new OGLViewingFrustum(),
			new TextureManager()),
		new GameWindow(
			L"The Game Window", 
			1000, 
			800),
		new PCInputSystem(),
		new WindowsTimer()
	);
	gameEngine.loadShaders("code/ShaderAssets.data");
	gameEngine.initializeWindowAndGraphics("code/ShaderAssets.data");
	gameEngine.setupGame("code/GameAssets.data");
	SoundManager::createInstance().playSound("canary", glm::vec3(1.0, 0.5, 1.0));
	gameEngine.run();

	return 0;
}
