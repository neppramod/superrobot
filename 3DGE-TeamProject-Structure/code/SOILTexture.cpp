#include "SOILTexture.h"



SOILTexture::SOILTexture() : OGL2DTexture()
{
}


SOILTexture::SOILTexture(std::string file) : OGL2DTexture()
{
	this->typeOfData = GL_UNSIGNED_BYTE;
	auto image = SOIL_load_image(file.c_str(), &this->width, &this->height, 0, SOIL_LOAD_RGB);
	this->set(image, this->width, this->height);
	this->create();
}

SOILTexture::~SOILTexture()
{
}
