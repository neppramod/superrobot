#pragma once
#ifndef OGL_OBJECT
#define OGL_OBJECT

#include <gl\glew.h>
#include <glm\glm.hpp>
#include <map>
using std::map;
#include <string>
using std::string;

#include "OGLGameObject.h"
#include "OGLReferenceFrame.h"


struct Component {
	unsigned int count;
	GLenum type;
	unsigned int bytesToNext;
	unsigned int bytesToFirst;
};

struct VBOObject {
	string name;
	GLuint vbo;
	GLuint ibo;
	GLenum primitiveType;
	void * buffer;
	unsigned int bufferSizeInBytes;
	unsigned int numberOfVertices;
	void * indexData;
	unsigned int indexSizeInBytes;
	unsigned int numberOfIndexes;
	Component positionComponent;
	Component colorComponent;
	Component normalComponent;
	Component textureComponent;
};

enum VBOType {ARRAY_BUFFER, INDEXED_ARRAY};

class OGLBufferedObject;
class OGLElementArrayBuffer;

// OGLObject -> OGLGameObject -> GameObject -> BaseObject
class OGLObject : public OGLGameObject
{
public:
	OGLReferenceFrame referenceFrame;

protected:
	//map<string, VBOObject *> objects;
	map<string, OGLBufferedObject*> buffers;
	
	//VBOType vboType;
	
	float speed;

	GLenum targetBufferObject;

//private:
//	unsigned int positionCount, colorCount, normalCount, textureCount;
	
public:
	OGLObject(string name);

	virtual ~OGLObject();

	void update(float elapsedSeconds);

	void render() = 0;

	virtual void render(OGLReferenceFrame& frame) = 0;

	void setTexture(Texture* texture);

	void setShaderProgram(GLuint shaderProgram);

	//void setArrayBufferType() { this->vboType = ARRAY_BUFFER; }

	//void setIndexedArrayType() { this->vboType = INDEXED_ARRAY; }

	//void sendBuffersToGPU(VBOObject * object);
	void sendBuffersToGPU();

	//VBOObject* getBufferedObject(string name);
	OGLBufferedObject* getBufferedObject(const string& name);

	//VBOObject* createArrayBuffer(string name, float* vertexData, GLenum primitiveType);
	void createArrayBuffer(string name, float* vertexData, GLuint numberOfElements, GLenum primitiveType);

	//VBOObject* createElementArray(
	//	string name, float* vertexData, short* indexData, GLenum primitiveType = GL_TRIANGLES);
	OGLElementArrayBuffer* createElementArray(const string& name, float* vertexData, short* indexData, GLenum primitiveType = GL_TRIANGLES);

	void createElementArrayPC(const string& name, float* vertexData, short* indexData, GLenum primitiveType = GL_TRIANGLES);
	void createElementArrayPCN(const string& name, float* vertexData, short* indexData, GLenum primitiveType = GL_TRIANGLES);
	void createElementArrayPCNT(const string& name, float* vertexData, short* indexData, GLenum primitiveType = GL_TRIANGLES);

	//VBOObject* createTextureVBOObject(
	//	string name, float* vertexData, short* indexData, GLenum primitiveType = GL_TRIANGLES);

	void setSpeed(float speed) { 
		this->speed = speed;
	}

	float getSpeed() {
		return this->speed;
	}

	//void setPositionCount(unsigned int positionCount) {
	//	this->positionCount = positionCount;
	//}

	//void setColorCount(unsigned int colorCount) {
	//	this->colorCount = colorCount;
	//}

	//void setNormalCount(unsigned int normalCount) {
	//	this->normalCount = normalCount;
	//}

	//void setTextureCount(unsigned int textureCount) {
	//	this->textureCount = textureCount;
	//}

	void sendMaterialDataToGPU();

	//void updateBufferObject(GLuint bufferObjectID, const void* bufferData, GLsizei bufferSize);

protected:
	//GLuint createBufferObject(GLenum target, const void* bufferData, GLsizei bufferSize);

	void renderBufferedObjects();

	//virtual void renderBufferedObject(OGLBufferedObject* object);

	//void enablePositions(VBOObject * object);
	//void enableColors(VBOObject * object);
	//void enableNormals(VBOObject * object);
	//void enableTextures(VBOObject * object);

	//void drawObject(VBOObject * object);

};

#endif

