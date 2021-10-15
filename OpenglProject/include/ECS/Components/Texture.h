#pragma once
#include<string>
#include<GL/glew.h>

struct Texture : public ECS::Component
{
	Texture(const std::string& filename)
	{
		_filename = filename;
	}

	virtual ~Texture() {}


	GLuint _texture;
	std::string _filename;
};

