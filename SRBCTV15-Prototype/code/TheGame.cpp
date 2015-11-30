#include <Windows.h>
#include "TheGame.h"
#include "OGLShaderManager.h"
#include "GameEngine.h"
#include "OGLShaderManager.h"
#include "OGLGraphicsSystem.h"
#include "OGLViewingFrustum.h"
#include "GameWorld.h"
#include "LightSource.h"
#include "OGLCamera.h"
#include "CoreSystem.h"
#include "OGLVertexShader.h"
#include "TextFileReader.h"
#include "OGLFragmentShader.h"
#include "AssetLoader.h"
#include "OGLFirstPersonCamera.h"
#include "OGLSphericalCamera.h"
#include "OGLObject.h"
#include "RotateYBehavior.h"
#include "GameObjectManager.h"
#include "PCInputSystem.h"
#include "BackForthBehavior.h"
#include "OGL3DObject.h"
//#include "OGL2DTextDisplay.h"
#include "BMPTextureLoader.h"
#include "OGL2DTexture.h"
#include "Plane.h"
#include "CustomTexture.h"
#include "TexturedCuboid.h"
#include "TextureManager.h"
#include "GameAssetLoader.h"
#include "LineBox.h"
#include "Sphere.h"
#include "ModelManager.h"
#include "Model.h"
#include "PawnBehavior.h"

//#include <gl\glew.h>

#include <glm\gtc\type_ptr.hpp>
#include "SOILTexture.h"

TheGame::TheGame() : BaseObject(nullptr)
{
}

TheGame::~TheGame()
{
}

void TheGame::loadShaders(const string& shaderAssetFilename)
{
	GameAssetLoader* loader = (GameAssetLoader*)this->gameEngine->getAssetLoader();
	loader->loadAssetFile(shaderAssetFilename);
	loader->loadOnlyTheShaders();
}

void TheGame::setupGraphicsParameters(const string& uniformAssetFilename)
{
	GameAssetLoader* loader = (GameAssetLoader*)this->gameEngine->getAssetLoader();
	loader->loadAssetFile(uniformAssetFilename);
	loader->loadOnlyTheUniforms();
}

void TheGame::setupViewingEnvironment()
{

	OGLGraphicsSystem* graphics = (OGLGraphicsSystem*)this->gameEngine->getGraphicsSystem();
	OGLViewingFrustum* frustum = (OGLViewingFrustum*)graphics->getViewingFrustum();
	OGLShaderManager* shaderMgr = graphics->getOGLShaderManager();
	OGLShaderProgram* shader = 
		(OGLShaderProgram*)shaderMgr->getShader("ShaderProgramIllumination");
	shader->setUniformData(
		"cameraToScreenMatrix",
		(void*)glm::value_ptr(frustum->getMatrix()));
	shader->sendData("cameraToScreenMatrix");

	shader = (OGLShaderProgram*)shaderMgr->getShader("ShaderProgram3d");
	shader->setUniformData(
		"cameraToScreenMatrix",
		(void*)glm::value_ptr(frustum->getMatrix()));
	shader->sendData("cameraToScreenMatrix");

	shader = (OGLShaderProgram*)shaderMgr->getShader("TextureShader");
	shader->setUniformData(
		"cameraToScreenMatrix",
		(void*)glm::value_ptr(frustum->getMatrix()));
	shader->sendData("cameraToScreenMatrix");

	// Cull back faces and use counter-clockwise winding of front faces
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	// Enable depth testing
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LEQUAL);
	glDepthRange(0.0f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	
}

void TheGame::sendShaderData()
{
	OGLGraphicsSystem* graphics = (OGLGraphicsSystem*)this->gameEngine->getGraphicsSystem();
	OGLViewingFrustum* frustum = (OGLViewingFrustum*)graphics->getViewingFrustum();
	OGLShaderManager* shaderMgr = graphics->getOGLShaderManager();
	OGLShaderProgram* shader =
		(OGLShaderProgram*)shaderMgr->getShader("ShaderProgramIllumination");

	glm::vec3 globalLightPos = glm::vec3(100, 100, 0);
	shader->setUniformData(
		"worldGlobalLightPos",
		(void*)glm::value_ptr(globalLightPos));
	shader->sendData("worldGlobalLightPos");

	float globalLightIntensity = 0.1f;
	shader->setUniformData(
		"globalLightIntensity",
		(void*)&globalLightIntensity);
	shader->sendData("globalLightIntensity");

	GameWorld* gameWorld = graphics->getGameWorld();

	int numberOfLights = (int)gameWorld->localLights.size();
	shader->setUniformData(
		"numberOfLights",
		(void*)&numberOfLights);
	shader->sendData("numberOfLights");

	Vector3f lightPositions[10];
	float lightIntensities[10];
	for (int i = 0; i < numberOfLights; i++) {
		lightPositions[i] = gameWorld->localLights[i]->getPosition();
		lightIntensities[i] = gameWorld->localLights[i]->getIntensity();
	}
	shader->setUniformData(
		"lightPositions",
		(void*)lightPositions);
	shader->sendData("lightPositions");

	shader->setUniformData(
		"lightIntensities",
		(void*)lightIntensities);
	shader->sendData("lightIntensities");

	OGLCamera *camera = (OGLCamera*)gameWorld->getCamera();

	shader->setUniformData(
		"worldToCameraMatrix",
		(void*)glm::value_ptr(camera->orientation));
	shader->sendData("worldToCameraMatrix");

	shader->setUniformData(
		"worldCameraPos",
		(void*)glm::value_ptr(glm::vec3(camera->orientation[3])));
	shader->sendData("worldCameraPos");

	// Texture Shader
	shader = (OGLShaderProgram*)shaderMgr->getShader("TextureShader");

	shader->setUniformData(
		"worldGlobalLightPos",
		(void*)glm::value_ptr(globalLightPos));
	shader->sendData("worldGlobalLightPos");

	shader->setUniformData(
		"globalLightIntensity",
		(void*)&globalLightIntensity);
	shader->sendData("globalLightIntensity");

	shader->setUniformData(
		"numberOfLights",
		(void*)&numberOfLights);
	shader->sendData("numberOfLights");

	shader->setUniformData(
		"lightPositions",
		(void*)lightPositions);
	shader->sendData("lightPositions");

	shader->setUniformData(
		"lightIntensities",
		(void*)lightIntensities);
	shader->sendData("lightIntensities");

	shader->setUniformData(
		"worldToCameraMatrix",
		(void*)glm::value_ptr(camera->orientation));
	shader->sendData("worldToCameraMatrix");

	shader->setUniformData(
		"worldCameraPos",
		(void*)glm::value_ptr(glm::vec3(camera->orientation[3])));
	shader->sendData("worldCameraPos");

	shader = (OGLShaderProgram*)shaderMgr->getShader("ShaderProgram3d");

	shader->setUniformData(
		"worldToCameraMatrix",
		(void*)glm::value_ptr(camera->orientation));
	shader->sendData("worldToCameraMatrix");

	shader->setUniformData(
		"worldCameraPos",
		(void*)glm::value_ptr(glm::vec3(camera->orientation[3])));
	shader->sendData("worldCameraPos");
}

void TheGame::setup(const string& gameAssetFilename)
{
	OGLGraphicsSystem* graphics = (OGLGraphicsSystem*)this->gameEngine->getGraphicsSystem();
	OGLShaderManager* shaderMgr = graphics->getOGLShaderManager();
	TextureManager* texMgr = graphics->getTextureManager();
	GameObjectManager* objectMgr = graphics->getGameWorld()->getObjectManager();

	OGLShaderProgram* plainShader3d = (OGLShaderProgram*)shaderMgr->getShader("ShaderProgram3d");
	

	AssetLoader* loader = this->gameEngine->getAssetLoader();
	loader->loadAssetFile(gameAssetFilename);
	loader->loadAssets();

	OGLSphericalCamera *camera =
		(OGLSphericalCamera *)graphics->getGameWorld()->getCamera();
	camera->setPosition(20.0f, -70.0f, 0.0f);
	camera->setTarget(0, 0, 0);
	

	OGLObject* object = (OGLObject*)graphics->getGameObject("Axes");
	if (object) {
		object->setVisibility(true);
	}


	object = (OGLObject*)graphics->getGameObject("Ground");
	object->setVisibility(true);

	object = (OGLObject*)graphics->getGameObject("DD");
	if (object) {
		object->referenceFrame.setPosition(5, 8, 0);
		object->setBehavior(new RotateYBehavior(60));
	}

	

	OGL2DTexture* texture = new SOILTexture("Floor.jpg");
	texture->create();
	object = new TexturedCuboid("mine");
	object->referenceFrame.setPosition(0, 0, 0);
	object->setTexture(texture);
	object->setVisibility(true);
	object->setShaderProgram(shaderMgr->getShaderHandle("TextureShader"));
	objectMgr->addObject("mine",object);


	//textDisplay->addText("Bounding Box Demonstration", -1, 1);

	ModelManager mManager;
	mManager.setLogger(this->logger);
	mManager.loadModel("rook", "assets/players/model/Rook.obj");
	mManager.loadModel("pawn", "assets/players/model/Pawn.obj");
	texMgr->addTexture("rook", new SOILTexture("assets/players/texture/Rook_Tower.png"));
	texMgr->addTexture("pawn", new SOILTexture("assets/players/texture/Pawn.png"));

	object = (OGLObject*)mManager.getModel("rook");

	object->referenceFrame.setPosition(0, 0, 0);
	object->referenceFrame.scale(0.5f);
	object->setVisibility(true);
	object->setTexture(texMgr->getTexture("rook"));
	object->setShaderProgram(shaderMgr->getShaderHandle("TextureShader"));
	objectMgr->addObject("rook", object);

	Model* pawn = new Model("pawn1", mManager.getModel("pawn"));

	pawn->referenceFrame.setPosition(5, 0, 0);
	pawn->referenceFrame.scale(0.5f);
	pawn->setBehavior(new PawnBehavior());
	pawn->setVisibility(true);
	pawn->setTexture(texMgr->getTexture("pawn"));
	pawn->setShaderProgram(shaderMgr->getShaderHandle("TextureShader"));
	objectMgr->addObject("pawn", pawn);

	Model* pawn2 = new Model("pawn2", mManager.getModel("pawn"));

	pawn2->referenceFrame.setPosition(-5, 0, 0);
	pawn2->referenceFrame.scale(0.5f);
	pawn2->setBehavior(new PawnBehavior());
	pawn2->setVisibility(true);
	pawn2->setTexture(texMgr->getTexture("pawn"));
	pawn2->setShaderProgram(shaderMgr->getShaderHandle("TextureShader"));
	objectMgr->addObject("pawn2", pawn2);

}

void TheGame::processInputs()
{
	OGLGraphicsSystem* graphics = 
		(OGLGraphicsSystem*)this->gameEngine->getGraphicsSystem();
	OGLFirstPersonCamera *camera = 
		(OGLFirstPersonCamera *)graphics->getGameWorld()->getCamera();
	PCInputSystem* inputSystem = this->gameEngine->getInputSystem();

	camera->setJustLooking();
	camera->setNotMoving();

	/*if (inputSystem->keys[VK_LEFT]) {
		camera->setLookingLeft();
	}
	else if (inputSystem->keys[VK_RIGHT]) {
		camera->setLookingRight();
	}

	if (inputSystem->keys[VK_UP]) {
		camera->setLookingUp();
	}
	else if (inputSystem->keys[VK_DOWN]) {
		camera->setLookingDown();
	}

	if (inputSystem->keys['W']) {
		camera->setMovingForward();
	}
	else if (inputSystem->keys['S']) {
		camera->setMovingBackward();
	}
	if (inputSystem->keys['A']) {
		camera->setMovingLeft();
	}
	else if (inputSystem->keys['D']) {
		camera->setMovingRight();
	}

	if (inputSystem->isMouseMovingLeft()) {
		camera->setLookingLeft();
	}
	else if (inputSystem->isMouseMovingRight()) {
		camera->setLookingRight();
	}

	if (inputSystem->isMouseMovingUp()) {
		camera->setLookingUp();
	}
	else if (inputSystem->isMouseMovingDown()) {
		camera->setLookingDown();
	}*/
}
