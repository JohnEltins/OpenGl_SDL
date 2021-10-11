#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Transform
{
public:
	Transform(const glm::vec3& pos = glm::vec3(), const glm::vec3& rot = glm::vec3(), const glm::vec3& scale = glm::vec3(1.0, 1.0, 1.0))
		: _pos(pos), _rot(rot), _scale(scale) {}

	inline glm::mat4 getModel()const
	{
		glm::mat4 posMatrix = glm::translate(_pos);

		glm::mat4 rotXMatrix = glm::rotate(_rot.x, glm::vec3(1, 0, 0));
		glm::mat4 rotYMatrix = glm::rotate(_rot.y, glm::vec3(0, 1, 0));
		glm::mat4 rotZMatrix = glm::rotate(_rot.z, glm::vec3(0, 0, 1));

		glm::mat4 scaleMatrix = glm::scale(_scale);

		//ordem da multiplica��o de matriz importa, X, Y Z, !ordem oposta!

		glm::mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;

		//escala, gira e movimenta, nessa ordem
		return posMatrix * rotMatrix * scaleMatrix;
	}

	inline glm::vec3& getPos() { return _pos; }
	inline glm::vec3& getRot() { return _rot; }
	inline glm::vec3& getScale() { return _scale; }

	inline void setPos(const glm::vec3& pos) { _pos = pos; }
	inline void setRot(const glm::vec3& rot) {  _rot = rot; }
	inline void setScale(const glm::vec3& scale) { _scale = scale; }

private:
	glm::vec3 _pos;
	glm::vec3 _rot;
	glm::vec3 _scale;
};
