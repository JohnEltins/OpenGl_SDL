#pragma once
#include <string>
#include <GL/glew.h>
#include "Transform.h"

class Shader
{
public:
	Shader(const std::string& filename);
	virtual ~Shader();

	void bind();
	void updateUniforms(const Transform& tranform);

private:
	enum SHADERS
	{
		VertexShader, FragmentShader, NUM_SHADERS
	};

	enum UNIFORMS
	{
		TRANSFORM_U,

		NUM_UNIFORMS
	};


	Shader(const Shader& other) {}
	void operator=(const Shader& other) {}

	GLuint _program;
	GLuint _shaders[SHADERS::NUM_SHADERS];
	GLuint _uniforms[UNIFORMS::NUM_UNIFORMS];
};

