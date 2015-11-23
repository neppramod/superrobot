#include "GameAssetLoader.h"
#include "TextureManager.h"
#include "BMPTextureLoader.h"
#include "OGL2DTexture.h"
#include "OGLObject.h"
#include "GameObjectManager.h"
#include "Axis.h"
#include "OGLTexturedFlatSurface.h"
#include "Sphere.h"
#include "Cuboid.h"
#include "OGLShaderManager.h"
#include "GameEngine.h"
#include "OGLGraphicsSystem.h"
#include "GameWorld.h"
#include "OGLVertexShader.h"
#include "TextFileReader.h"
#include "CoreSystem.h"
#include "OGLFragmentShader.h"
#include "Uniform.h"
#include "LightSource.h"
#include "TexturedCuboid.h"
#include "LineBox.h"
#include "SOILTexture.h"

GameAssetLoader::GameAssetLoader()
{
}

GameAssetLoader::~GameAssetLoader()
{
}

void GameAssetLoader::loadAssets()
{
	GameObjectManager* gameObjectManager = 
		this->gameEngine->getGraphicsSystem()->getGameWorld()->getObjectManager();
	this->setAtStart();
	if (this->currLine() != "<assets>") return;
	while (!this->atEnd() && this->nextLine() != "</assets>") {
		if (this->currLine() == "<textures>") {
			this->loadTextures();
		}
		else if (this->currLine() == "<gameobjects>") {
			this->loadGameObjects();
		}
	}
}

void GameAssetLoader::loadOnlyTheShaders()
{
	this->setAtStart();
	if (this->currLine() != "<assets>") return;
	while (!this->atEnd() && this->nextLine() != "</assets>") {
		if (this->currLine() == "<shaders>") {
			this->loadShaders();
			break;
		}
	}
}

void GameAssetLoader::loadOnlyTheUniforms()
{
	OGLGraphicsSystem* graphics =
		(OGLGraphicsSystem*)this->gameEngine->getGraphicsSystem();
	OGLShaderManager* shaderMgr = graphics->getOGLShaderManager();
	OGLShaderProgram *shader;
	shader = (OGLShaderProgram*)shaderMgr->getShader("SimpleShader");
	this->setAtStart();
	if (this->currLine() != "<assets>") return;
	while (!this->atEnd() && this->nextLine() != "</assets>") {
		if (this->currLine() == "<uniforms>") {
			this->loadUniforms();
			break;
		}
	}
}

void GameAssetLoader::loadShaders()
{
	while (!this->atEnd() && this->nextLine() != "</shaders>") {
		if (this->currLine() == "<vertexShaders>") {
			this->loadVertexShaders();
		}
		else if (this->currLine() == "<fragmentShaders>") {
			this->loadFragmentShaders();
		}
		else if (this->currLine() == "<shaderPrograms>") {
			this->loadShaderPrograms();
		}
	}
}

void GameAssetLoader::loadVertexShaders()
{
	OGLGraphicsSystem* graphics = 
		(OGLGraphicsSystem*)this->gameEngine->getGraphicsSystem();
	CoreSystem* core = this->gameEngine->getCoreSystem();
	TextFileReader *reader = core->getTextFileReader();

	string shaderName;
	string fileName;
	vector<string> fields;
	while (!this->atEnd() && this->nextLine() != "</vertexShaders>") {
		this->split(fields, this->currLine());
		shaderName = fields[0];
		switch (fields.size()) {
		case 1:
			graphics->addVertexShader(
				shaderName,
				new OGLVertexShader()
			);
			break;
		case 2:
			fileName = fields[1];
			graphics->addVertexShader(
				shaderName,
				new OGLVertexShader(),
				reader->readContents(fileName)
			);
			break;
		}
		fields.clear();
	}
}

void GameAssetLoader::loadFragmentShaders()
{
	OGLGraphicsSystem* graphics =
		(OGLGraphicsSystem*)this->gameEngine->getGraphicsSystem();
	CoreSystem* core = this->gameEngine->getCoreSystem();
	TextFileReader *reader = core->getTextFileReader();

	string shaderName;
	string fileName;
	vector<string> fields;
	while (!this->atEnd() && this->nextLine() != "</fragmentShaders>") {
		this->split(fields, this->currLine());
		shaderName = fields[0];
		switch (fields.size()) {
		case 1:
			graphics->addFragmentShader(
				shaderName,
				new OGLFragmentShader()
				);
			break;
		case 2:
			fileName = fields[1];
			graphics->addFragmentShader(
				shaderName,
				new OGLFragmentShader(),
				reader->readContents(fileName)
				);
			break;
		}
		fields.clear();
	}
}

void GameAssetLoader::loadShaderPrograms()
{
	OGLGraphicsSystem* graphics =
		(OGLGraphicsSystem*)this->gameEngine->getGraphicsSystem();

	string shaderName, vertexName, fragmentName;
	vector<string> fields;
	while (!this->atEnd() && this->nextLine() != "</shaderPrograms>") {
		this->split(fields, this->currLine());
		shaderName = fields[0];
		vertexName = fields[1];
		fragmentName = fields[2];
		graphics->addShaderProgram(
			shaderName,
			new OGLShaderProgram(),
			vertexName, fragmentName
			);
		fields.clear();
	}
}

void GameAssetLoader::loadUniforms()
{
	OGLGraphicsSystem* graphics = (OGLGraphicsSystem*)this->gameEngine->getGraphicsSystem();
	OGLShaderManager* shaderMgr = graphics->getOGLShaderManager();
	OGLShaderProgram *shader;

	string shaderName, uniformName, uniformTypeName;
	vector<string> fields;
	while (!this->atEnd() && this->nextLine() != "</uniforms>") {
		this->split(fields, this->currLine());
		shaderName = fields[0];
		uniformName = fields[1];
		uniformTypeName = fields[2];
		shader = (OGLShaderProgram*)shaderMgr->getShader(shaderName);
		shader->addUniform(uniformName, Uniform::getType(uniformTypeName));
		fields.clear();
	}
}

void GameAssetLoader::loadGameObjects()
{
	vector<string> fields;
	while (!this->atEnd() && this->nextLine() != "</gameobjects>") {
		if (this->currLine() == "<axis>") {
			this->loadAxis();
		}
		else if (this->currLine() == "<otfs>") {
			this->loadOTFS();
		}
		else if (this->currLine() == "<localLightSources>") {
			this->loadLocalLightSources();
		}
		else if (this->currLine() == "<texturedCuboid>") {
			this->loadTexturedCuboid();
		}
		else if (this->currLine() == "<sphere>") {
			this->loadSphere();
		}
		else if (this->currLine() == "<cuboid>") {
			this->loadCuboid();
		}
		else if (this->currLine() == "<linebox>") {
			this->loadLineBox();
		}
	}
}

void GameAssetLoader::loadAxis()
{
	OGLObject *object = nullptr;
	std::string::size_type sz;
	vector<string> fields;

	string name;
	float length = 1;
	string shaderName;

	while (!this->atEnd() && this->nextLine() != "</axis>") {
		if (this->currLine() == "<name>") {
			this->loadElement(fields, "</name>");
			name = fields[0];
		}
		else if (this->currLine() == "<length>") {
			this->loadElement(fields, "</length>");
			length = std::stof(fields[0], &sz);
		}
		else if (this->currLine() == "<shaderName>") {
			this->loadElement(fields, "</shaderName>");
			shaderName = fields[0];
		}
		fields.clear();
	}

	OGLGraphicsSystem* graphics = (OGLGraphicsSystem*)this->gameEngine->getGraphicsSystem();
	GameObjectManager* objectMgr = graphics->getGameWorld()->getObjectManager();
	OGLShaderManager* shaderMgr = graphics->getOGLShaderManager();
	OGLShaderProgram *shader = (OGLShaderProgram*)shaderMgr->getShader(shaderName);

	object = new Axis(name, length);
	object->setShaderProgram(shader->getHandle());
	objectMgr->addObject(name, object);
}

void GameAssetLoader::loadOTFS()
{
	OGLObject *object = nullptr;
	std::string::size_type sz;
	vector<string> fields;

	string name;
	float width = 5, depth = 5;
	unsigned int widthSegments = 5, depthSegments = 5;
	RGBA color = { 1, 1, 1, 1 };
	string textureName, shaderName;
	
	while (!this->atEnd() && this->nextLine() != "</otfs>") {
		if (this->currLine() == "<name>") {
			this->loadElement(fields, "</name>");
			name = fields[0];
		}
		else if (this->currLine() == "<width>") {
			this->loadElement(fields, "</width>");
			width = std::stof(fields[0], &sz);
		}
		else if (this->currLine() == "<depth>") {
			this->loadElement(fields, "</depth>");
			depth = std::stof(fields[0], &sz);
		}
		else if (this->currLine() == "<widthSegments>") {
			this->loadElement(fields, "</widthSegments>");
			widthSegments = std::stoi(fields[0], &sz);
		}
		else if (this->currLine() == "<depthSegments>") {
			this->loadElement(fields, "</depthSegments>");
			depthSegments = std::stoi(fields[0], &sz);
		}
		else if (this->currLine() == "<color>") {
			this->loadElement(fields, "</color>");
			color = {
				std::stof(fields[0], &sz),
				std::stof(fields[1], &sz),
				std::stof(fields[2], &sz),
				std::stof(fields[3], &sz)
			};
		}
		else if (this->currLine() == "<textureName>") {
			this->loadElement(fields, "</textureName>");
			textureName = fields[0];
		}
		else if (this->currLine() == "<shaderName>") {
			this->loadElement(fields, "</shaderName>");
			shaderName = fields[0];
		}
		fields.clear();
	}

	OGLGraphicsSystem* graphics = (OGLGraphicsSystem*)this->gameEngine->getGraphicsSystem();
	GameObjectManager* objectMgr = graphics->getGameWorld()->getObjectManager();
	TextureManager* textureMgr = (TextureManager*)graphics->getTextureManager();
	OGLShaderManager* shaderMgr = graphics->getOGLShaderManager();
	OGLShaderProgram *shader = (OGLShaderProgram*)shaderMgr->getShader(shaderName);

	object = new OGLTexturedFlatSurface(name, width, depth, widthSegments, depthSegments, color);
	Texture* texture = textureMgr->getTexture(textureName);
	object->setTexture(texture);
	object->setShaderProgram(shader->getHandle());
	objectMgr->addObject(name, object);
}

void GameAssetLoader::loadTexturedCuboid()
{
	OGLObject *object = nullptr;
	std::string::size_type sz;
	vector<string> fields;

	string name;
	float width = 1, depth = 1, height = 1;
	RGBA color = { 1, 1, 1, 1 };
	string textureName, shaderName;

	while (!this->atEnd() && this->nextLine() != "</texturedCuboid>") {
		if (this->currLine() == "<name>") {
			this->loadElement(fields, "</name>");
			name = fields[0];
		}
		else if (this->currLine() == "<width>") {
			this->loadElement(fields, "</width>");
			width = std::stof(fields[0], &sz);
		}
		else if (this->currLine() == "<depth>") {
			this->loadElement(fields, "</depth>");
			depth = std::stof(fields[0], &sz);
		}
		else if (this->currLine() == "<height>") {
			this->loadElement(fields, "</height>");
			height = std::stof(fields[0], &sz);
		}
		else if (this->currLine() == "<color>") {
			this->loadElement(fields, "</color>");
			color = {
				std::stof(fields[0], &sz),
				std::stof(fields[1], &sz),
				std::stof(fields[2], &sz),
				std::stof(fields[3], &sz)
			};
		}
		else if (this->currLine() == "<textureName>") {
			this->loadElement(fields, "</textureName>");
			textureName = fields[0];
		}
		else if (this->currLine() == "<shaderName>") {
			this->loadElement(fields, "</shaderName>");
			shaderName = fields[0];
		}
		fields.clear();
	}

	OGLGraphicsSystem* graphics = (OGLGraphicsSystem*)this->gameEngine->getGraphicsSystem();
	GameObjectManager* objectMgr = graphics->getGameWorld()->getObjectManager();
	TextureManager* textureMgr = (TextureManager*)graphics->getTextureManager();
	OGLShaderManager* shaderMgr = graphics->getOGLShaderManager();
	OGLShaderProgram *shader = (OGLShaderProgram*)shaderMgr->getShader(shaderName);

	object = new TexturedCuboid(name, width, depth, height, color);
	Texture* texture = textureMgr->getTexture(textureName);
	object->setTexture(texture);
	object->setShaderProgram(shader->getHandle());
	objectMgr->addObject(name, object);
}

void GameAssetLoader::loadCuboid()
{
	OGLObject *object = nullptr;
	std::string::size_type sz;
	vector<string> fields;

	string name;
	float width = 1, depth = 1, height = 1;
	RGBA color = { 1, 1, 1, 1 };
	string shaderName;

	while (!this->atEnd() && this->nextLine() != "</cuboid>") {
		if (this->currLine() == "<name>") {
			this->loadElement(fields, "</name>");
			name = fields[0];
		}
		else if (this->currLine() == "<width>") {
			this->loadElement(fields, "</width>");
			width = std::stof(fields[0], &sz);
		}
		else if (this->currLine() == "<depth>") {
			this->loadElement(fields, "</depth>");
			depth = std::stof(fields[0], &sz);
		}
		else if (this->currLine() == "<height>") {
			this->loadElement(fields, "</height>");
			height = std::stof(fields[0], &sz);
		}
		else if (this->currLine() == "<color>") {
			this->loadElement(fields, "</color>");
			color = {
				std::stof(fields[0], &sz),
				std::stof(fields[1], &sz),
				std::stof(fields[2], &sz),
				std::stof(fields[3], &sz)
			};
		}
		else if (this->currLine() == "<shaderName>") {
			this->loadElement(fields, "</shaderName>");
			shaderName = fields[0];
		}
		fields.clear();
	}

	OGLGraphicsSystem* graphics = (OGLGraphicsSystem*)this->gameEngine->getGraphicsSystem();
	GameObjectManager* objectMgr = graphics->getGameWorld()->getObjectManager();
	TextureManager* textureMgr = (TextureManager*)graphics->getTextureManager();
	OGLShaderManager* shaderMgr = graphics->getOGLShaderManager();
	OGLShaderProgram *shader = (OGLShaderProgram*)shaderMgr->getShader(shaderName);

	object = new Cuboid(name, width, depth, height, color);
	object->setShaderProgram(shader->getHandle());
	objectMgr->addObject(name, object);
}

void GameAssetLoader::loadLineBox()
{
	OGLObject *object = nullptr;
	std::string::size_type sz;
	vector<string> fields;

	string name;
	float width = 1, depth = 1, height = 1;
	RGBA color = { 1, 1, 1, 1 };
	string shaderName;

	while (!this->atEnd() && this->nextLine() != "</linebox>") {
		if (this->currLine() == "<name>") {
			this->loadElement(fields, "</name>");
			name = fields[0];
		}
		else if (this->currLine() == "<width>") {
			this->loadElement(fields, "</width>");
			width = std::stof(fields[0], &sz);
		}
		else if (this->currLine() == "<depth>") {
			this->loadElement(fields, "</depth>");
			depth = std::stof(fields[0], &sz);
		}
		else if (this->currLine() == "<height>") {
			this->loadElement(fields, "</height>");
			height = std::stof(fields[0], &sz);
		}
		else if (this->currLine() == "<color>") {
			this->loadElement(fields, "</color>");
			color = {
				std::stof(fields[0], &sz),
				std::stof(fields[1], &sz),
				std::stof(fields[2], &sz),
				std::stof(fields[3], &sz)
			};
		}
		else if (this->currLine() == "<shaderName>") {
			this->loadElement(fields, "</shaderName>");
			shaderName = fields[0];
		}
		fields.clear();
	}

	OGLGraphicsSystem* graphics = (OGLGraphicsSystem*)this->gameEngine->getGraphicsSystem();
	GameObjectManager* objectMgr = graphics->getGameWorld()->getObjectManager();
	TextureManager* textureMgr = (TextureManager*)graphics->getTextureManager();
	OGLShaderManager* shaderMgr = graphics->getOGLShaderManager();
	OGLShaderProgram *shader = (OGLShaderProgram*)shaderMgr->getShader(shaderName);

	object = new LineBox(name, width, depth, height, color);
	object->setShaderProgram(shader->getHandle());
	objectMgr->addObject(name, object);
}

void GameAssetLoader::loadSphere()
{
	OGLObject *object = nullptr;
	std::string::size_type sz;
	vector<string> fields;

	string name;
	float radius = 1;
	int slices = 10, stacks = 10;
	RGBA color = { 1, 1, 1, 1 };
	string shaderName;

	while (!this->atEnd() && this->nextLine() != "</sphere>") {
		if (this->currLine() == "<name>") {
			this->loadElement(fields, "</name>");
			name = fields[0];
		}
		else if (this->currLine() == "<radius>") {
			this->loadElement(fields, "</radius>");
			radius = std::stof(fields[0], &sz);
		}
		else if (this->currLine() == "<slices>") {
			this->loadElement(fields, "</slices>");
			slices = std::stoi(fields[0], &sz);
		}
		else if (this->currLine() == "<stacks>") {
			this->loadElement(fields, "</stacks>");
			stacks = std::stoi(fields[0], &sz);
		}
		else if (this->currLine() == "<color>") {
			this->loadElement(fields, "</color>");
			color = {
				std::stof(fields[0], &sz),
				std::stof(fields[1], &sz),
				std::stof(fields[2], &sz),
				std::stof(fields[3], &sz)
			};
		}
		else if (this->currLine() == "<shaderName>") {
			this->loadElement(fields, "</shaderName>");
			shaderName = fields[0];
		}
		fields.clear();
	}

	OGLGraphicsSystem* graphics = (OGLGraphicsSystem*)this->gameEngine->getGraphicsSystem();
	GameObjectManager* objectMgr = graphics->getGameWorld()->getObjectManager();
	TextureManager* textureMgr = (TextureManager*)graphics->getTextureManager();
	OGLShaderManager* shaderMgr = graphics->getOGLShaderManager();
	OGLShaderProgram *shader = (OGLShaderProgram*)shaderMgr->getShader(shaderName);

	object = new Sphere(name, radius, slices, stacks, color);
	object->setShaderProgram(shader->getHandle());
	objectMgr->addObject(name, object);
}

void GameAssetLoader::loadLocalLightSources(char delimeter)
{
	LightSource* light;
	OGLGraphicsSystem* graphics = (OGLGraphicsSystem*)this->gameEngine->getGraphicsSystem();
	std::string::size_type sz;
	float x, y, z, intensity;
	vector<string> fields;
	while (!this->atEnd() && this->nextLine() != "</localLightSources>") {
		this->split(fields, this->currLine(), delimeter);
		x = std::stof(fields[0], &sz);
		y = std::stof(fields[1], &sz);
		z = std::stof(fields[2], &sz);
		intensity = std::stof(fields[3], &sz);
		light = new LightSource();
		light->setPosition(x, y, z);
		light->setIntensity(intensity);
		graphics->getGameWorld()->localLights.push_back(light);
		fields.clear();
	}
}

void GameAssetLoader::loadObject(vector<string>& fields)
{
	Texture* texture = nullptr;
	OGLObject *object = nullptr;
	std::string::size_type sz;
	string name;
	if (fields[0] == "<axis>") {
		name = fields[1];
		float length = std::stof(fields[2], &sz);
		object = new Axis(name, length);
	}

	if (object) {
		GameObjectManager* objectMgr =
			this->gameEngine->getGraphicsSystem()->getGameWorld()->getObjectManager();
		objectMgr->addObject(name, object);
	}
}

void GameAssetLoader::loadTextures()
{
	string type, filepath, textureName;
	Texture* texture;
	vector<string> fields;
	while (!this->atEnd() && this->nextLine() != "</textures>") {
		fields.clear();
		this->split(fields, this->currLine(), ',');
		type = fields[0];
		filepath = fields[1];
		textureName = fields[2];
		texture = this->loadTexture(type, filepath);
		if (texture) {
			TextureManager* textureMgr =
				(TextureManager*)this->gameEngine->getGraphicsSystem()->getTextureManager();
			textureMgr->addTexture(textureName, texture);
		}
	}
}

Texture* GameAssetLoader::loadTexture(const string& type, const string& filepath)
{
	Texture* texture = nullptr;
	if (type == "BMP") {
		texture = this->loadBmpTexture(filepath);
	}
	return texture;
}

Texture* GameAssetLoader::loadBmpTexture(const string& filepath)
{
	BMPTextureLoader bmpLoader;
	bmpLoader.setFilePath(filepath);
	//OGL2DTexture* texture = new OGL2DTexture(bmpLoader.load());
	SOILTexture* texture = new SOILTexture(filepath);
	texture->setTexelFormat(GL_BGR);
	texture->setTypeOfData(GL_UNSIGNED_BYTE);
	texture->create();
	return texture;
}


