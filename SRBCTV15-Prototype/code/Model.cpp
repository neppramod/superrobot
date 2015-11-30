#include "Model.h"
#include "ObjectGenerator.h"
#include "Logger.h"
#include "IBehavior.h"


Model::Model(string name) : OGL3DCompositeObject(name)
{
}

Model::Model(string name, Model* base) : OGL3DCompositeObject(name)
{
	for (auto it = base->meshes.begin(); it != base->meshes.end(); it++)
	{
		this->meshes[it->second->getName()] = new Mesh(it->second->getName(), it->second->getVertexData(), it->second->getIndexData());
	}
}

Model::~Model()
{
	//for (
	//	auto iterator = this->meshes.begin();
	//	iterator != this->meshes.end();
	//	iterator++) {
	//	delete iterator;
	//}
}

void Model::setTexture(Texture* texture)
{
	for (
		auto iterator = this->meshes.begin();
		iterator != this->meshes.end();
		iterator++)
	{
		iterator->second->setTexture(texture);
	}

}

void Model::setShaderProgram(GLuint shaderProgram)
{
	for (
		auto iterator = this->meshes.begin();
		iterator != this->meshes.end();
		iterator++)
	{
		iterator->second->setShaderProgram(shaderProgram);
	}

}

void Model::update(float elapsedSeconds)
{
	for (
		auto iterator = this->meshes.begin();
		iterator != this->meshes.end();
		iterator++)
	{
		iterator->second->referenceFrame = this->referenceFrame;
	}
	if(this->behavior)
		this->behavior->update(this, elapsedSeconds);

}

void Model::render()
{
	for (
		auto iterator = this->meshes.begin();
		iterator != this->meshes.end();
		iterator++)
	{
		iterator->second->render();
	}

}

Mesh* Model::getMesh(const string& name)
{
	Mesh* mesh = nullptr;
	if(this->meshes.find(name) != this->meshes.end())
	{
		mesh = this->meshes[name];
	}
	return mesh;
}

void Model::loadModel(string path)
{
	Assimp::Importer import;
	const aiScene* scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

	if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		this->logger->debug("Failed to load: " + path);
		return;
	}

	this->processNode(scene->mRootNode, scene);

}

void Model::processNode(aiNode* node, const aiScene* scene)
{
	// Process all the node's meshes (if any)
	for (auto i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		this->processMesh(node->mName.C_Str(), mesh, scene);
	}
	// Then do the same for each of its children
	for (auto i = 0; i < node->mNumChildren; i++)
	{
		this->processNode(node->mChildren[i], scene);
	}

}

void Model::processMesh(const char* name, aiMesh* mesh, const aiScene* scene)
{
	ObjectGenerator gen;
	gen.clear();

	//Vertex Data
	for (int i = 0; i < mesh->mNumVertices; i++)
	{
		//Position
		gen.positions[i] = {
			mesh->mVertices[i].x,
			mesh->mVertices[i].y,
			mesh->mVertices[i].z,
			1 
		};


		//Color
		gen.colors[i] = { 1.0f, 1.0f, 1.0f, 1.0f };

		//Normals
		gen.normals[i] = {
			mesh->mNormals[i].x,
			mesh->mNormals[i].y,
			mesh->mNormals[i].z
		};

		//Texture Coord
		if (mesh->mTextureCoords[0]) // Does the mesh contain texture coordinates?
		{
			gen.textureCoords[i] = {
				mesh->mTextureCoords[0][i].x,
				mesh->mTextureCoords[0][i].y
			};
		} else
		{
			gen.textureCoords[i] = { 0.0f, 0.0f };
		}
	}

	//Index Data
	for (int i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		gen.triangles.push_back({ face.mIndices[0], face.mIndices[1], face.mIndices[2] });
	}
	this->meshes[name] = new Mesh(name, gen.generateVertexData(), gen.generateIndexData());;
}
