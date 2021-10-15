#pragma once
#include <glm/glm.hpp>
#include <GL/glew.h>
#include "ECS/Base/Component.h"

class Vertex
{
public:
	Vertex(const glm::vec3& pos, const glm::vec2& textCoord)
	{
		this->pos = pos;
		this->textCoord = textCoord;
	}

	inline glm::vec3* getPos() { return &pos; }
	inline glm::vec2* getTextCoord() { return &textCoord; }

private:
	glm::vec3 pos;
	glm::vec2 textCoord;
};


struct Mesh : public ECS::Component
{
	Mesh(Vertex* vertices, unsigned int numVertices)
	{
		_vertexArrayObject = 0;
		for(int i = 0; i < NUM_BUFFERS; i++)
			_vertexArrayBuffers[i] = GLuint(0);

		_vertices = vertices;
		_drawCount = numVertices;
	}

	virtual ~Mesh() {}

	enum {
		POSITION_VB,
		TEXTCOORD_VB,

		NUM_BUFFERS
	};

	GLuint _vertexArrayObject;
	GLuint _vertexArrayBuffers[NUM_BUFFERS];
	unsigned int _drawCount;
	Vertex* _vertices;
};

