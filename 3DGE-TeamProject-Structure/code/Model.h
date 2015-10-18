#pragma once
#include <string>
#include <vector>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

using namespace std;
struct Mesh
{
	float * vertexData;
	int * indexData;
};

struct Texture
{
	
};

class Model
{
public:
	Model(string fileName) { this->loadModel(fileName); }
	~Model();

	vector<Mesh> GetMeshes() { return this->meshes; }

private:
	vector<Mesh> meshes;
	void loadModel(string path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type,
		string typeName);
};

