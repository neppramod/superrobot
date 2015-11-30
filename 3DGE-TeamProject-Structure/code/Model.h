#pragma once
#include <string>
#include <vector>

#include "Mesh.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "OGL3DCompositeObject.h"

using namespace std;

class Model : public OGL3DCompositeObject
{
public:
	Model(string name);
	Model(string name, Model * base);
	~Model();
	void loadModel(string path);

	void setTexture(Texture* texture);

	void setShaderProgram(GLuint shaderProgram);

	void update(float elapsedSeconds);

	void render();

	Mesh* getMesh(const string& name);

	map<string, Mesh*> meshes;
private:
	float* vertexData;
	short* indexData;
	void processNode(aiNode* node, const aiScene* scene);
	void processMesh(const char* name, aiMesh* mesh, const aiScene* scene);
};

