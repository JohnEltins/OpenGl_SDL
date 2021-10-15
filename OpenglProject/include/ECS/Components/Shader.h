#pragma once
#include <string>
#include <GL/glew.h>
#include "Transform.h"
#include "ECS/Base/Component.h"

class Shader : public ECS::Component
{
public:
	Shader(const std::string& filename)
	{
		_filename = filename;
	}
	virtual ~Shader() {}

	enum SHADERS
	{
		VertexShader, FragmentShader, NUM_SHADERS
	};

	enum UNIFORMS
	{
		TRANSFORM_U,

		NUM_UNIFORMS
	};


	std::string _filename;
	GLuint _program;
	GLuint _shaders[SHADERS::NUM_SHADERS];
	GLuint _uniforms[UNIFORMS::NUM_UNIFORMS];
};

