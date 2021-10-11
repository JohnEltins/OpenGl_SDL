#include "Shader.h"
#include <fstream>
#include <iostream>


static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string errorMessage);
static std::string LoadShader(const std::string& fileName);
static GLuint CreateShader(const std::string txt, GLenum shaderType);

Shader::Shader(const std::string& filename)
{
	_program = glCreateProgram();
	_shaders[SHADERS::VertexShader] = CreateShader(LoadShader(filename + ".vs"), GL_VERTEX_SHADER);
	_shaders[SHADERS::FragmentShader] = CreateShader(LoadShader(filename + ".fs"), GL_FRAGMENT_SHADER);

	for (unsigned int i = 0; i < SHADERS::NUM_SHADERS; i++)
		glAttachShader(_program, _shaders[i]);

	glBindAttribLocation(_program, 0, "position");
	glBindAttribLocation(_program, 1, "texCoord");

	glLinkProgram(_program);
	CheckShaderError(_program, GL_LINK_STATUS, true, "Error shader program failed to link: ");

	glValidateProgram(_program);
	CheckShaderError(_program, GL_VALIDATE_STATUS, true, "Error shader program is invalid: ");

	_uniforms[TRANSFORM_U] = glGetUniformLocation(_program, "transform");
}

Shader::~Shader()
{
	for (unsigned int i = 0; i < SHADERS::NUM_SHADERS; i++)
	{
		glDetachShader(_program, _shaders[i]);
		glDeleteShader(_shaders[i]);
	}

	glDeleteProgram(_program);
}

void Shader::bind()
{
	glUseProgram(_program);
}

void Shader::updateUniforms(const Transform& tranform)
{
	glm::mat4 model = tranform.getModel();
	glUniformMatrix4fv(_uniforms[UNIFORMS::TRANSFORM_U], 1, GL_FALSE, &model[0][0]);
}

void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string errorMessage)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };

	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);

	if (success == GL_FALSE)
	{
		if (isProgram)
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);

		std::cerr << errorMessage << ": '" << error << "'" << std::endl;
	}
}

std::string LoadShader(const std::string& fileName)
{
	std::ifstream file;
	file.open((fileName).c_str());

	std::string output;
	std::string line;

	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);
			output.append(line + "\n");
		}
	}
	else
	{
		std::cerr << "Unable to Load shader: " << fileName << std::endl;
	}

	std::cout << output << std::endl;
	return output;
}

GLuint CreateShader(const std::string txt, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);

	if (shader == 0)
		std::cerr << "Error: shader creation failed!" << std::endl;

	const GLchar* shaderSourceStrings[1];
	GLint shaderSouceStringLenghts[1];

	shaderSourceStrings[0] = txt.c_str();
	shaderSouceStringLenghts[0] = txt.length();

	glShaderSource(shader, 1, shaderSourceStrings, shaderSouceStringLenghts);
	glCompileShader(shader);

	CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error shader failed to compile: ");

	return shader;
}
