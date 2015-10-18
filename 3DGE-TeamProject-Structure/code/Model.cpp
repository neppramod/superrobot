#include "Model.h"



Model::~Model()
{
	for (
		auto iterator = this->meshes.begin();
		iterator != this->meshes.end();
		iterator++) {
		delete[] iterator->vertexData;
		delete[] iterator->indexData;
	}
}

void Model::loadModel(string path)
{
	Assimp::Importer import;
	const aiScene* scene = import.ReadFile(path, aiProcess_Triangulate );

	if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
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
		this->meshes.push_back(this->processMesh(mesh, scene));
	}
	// Then do the same for each of its children
	for (auto i = 0; i < node->mNumChildren; i++)
	{
		this->processNode(node->mChildren[i], scene);
	}

}

Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene)
{
	Mesh meshData;
	meshData.vertexData = new float[((mesh->mNumVertices * 4) * 2) + 1];
	meshData.vertexData[0] = ((mesh->mNumVertices * 4) * 2);
	meshData.indexData = new int[(mesh->mNumFaces * 3) + 1];
	meshData.indexData[0] = (mesh->mNumFaces * 3);

	//Vertex Data
	int i = 1;
	int j = (meshData.vertexData[0] / 2) + 1;
	for (int k = 0; k < mesh->mNumVertices; k++)
	{
		//Position
		meshData.vertexData[i++] = mesh->mVertices[k].x;
		meshData.vertexData[i++] = mesh->mVertices[k].y;
		meshData.vertexData[i++] = mesh->mVertices[k].z;
		meshData.vertexData[i++] = 1;

		//Color
		meshData.vertexData[j++] = 1.0f;
		meshData.vertexData[j++] = 1.0f;
		meshData.vertexData[j++] = 1.0f;
		meshData.vertexData[j++] = 1.0f;
	}

	//Index Data
	for (i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		for (j = 0; j < face.mNumIndices; j++)
			meshData.indexData[((i*(face.mNumIndices)) + j) + 1] = face.mIndices[j];
	}

	return meshData;

}

vector<Texture> Model::loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName)
{
	return {};
}