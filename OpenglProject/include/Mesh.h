#pragma once
#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex
{
public:
	Vertex(const glm::vec3& pos)
	{
		this->pos = pos;
	}

private:
	glm::vec3 pos;
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
		POSITION_VB, NUM_BUFFERS
	};

	GLuint _vertexArrayObject;
	GLuint _vertexArrayBuffers[NUM_BUFFERS];
	unsigned int _drawCount;
};

