#pragma once
#include <glm/glm.hpp>
#include <GL/glew.h>

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


class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned int numVertices);

	void draw();

	virtual ~Mesh();

private:
	Mesh(const Mesh& other) {}
	void operator=(const Mesh& other) {}

	enum {
		POSITION_VB,
		TEXTCOORD_VB,

		NUM_BUFFERS
	};

	GLuint _vertexArrayObject;
	GLuint _vertexArrayBuffers[NUM_BUFFERS];
	unsigned int _drawCount;
};

