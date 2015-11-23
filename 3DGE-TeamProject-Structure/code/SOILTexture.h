#pragma once
#include "OGL2DTexture.h"
#include  "Soil.h"

class SOILTexture :
	public OGL2DTexture
{
private:
	int width, height;
	unsigned char* image;
public:
	SOILTexture();
	SOILTexture(std::string file);
	~SOILTexture();
};

