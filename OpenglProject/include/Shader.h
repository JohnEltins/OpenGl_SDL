#pragma once
#include <string>
#include <GL/glew.h>

class Shader
{
public:
	Shader(const std::string& filename);
	virtual ~Shader();

	void bind();

private:
	enum 
	{
		VertexShader, FragmentShader, NUM_SHADERS
	};

	Shader(const Shader& other) {}
	void operator=(const Shader& other) {}

	GLuint _program;
	GLuint _shaders[NUM_SHADERS];
};

