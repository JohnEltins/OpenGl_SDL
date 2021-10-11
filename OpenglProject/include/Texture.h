#pragma once
#include<string>
#include<GL/glew.h>

class Texture
{
public:
	Texture(const std::string& filename);
	virtual ~Texture();

	void bind(unsigned int unit);

private:
	Texture(const Texture& other) {}
	void operator=(const Texture& other) {}

	GLuint _texture;
};

