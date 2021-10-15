#pragma once

#include "ECS/Base/EntityManager.h"
#include "ECS/Components/Transform.h"
#include "ECS/Base/System.h"


struct TransformHandler : public ECS::System
{
	TransformHandler(ECS::EntityManager* manager)
		: System(manager)
	{
		addComponentSignature<Transform>();
		i = 0.0f;
	}

	void init(const ECS::EntityID entity) override
	{
		_manager->getComponent<Transform>(entity)._model = getModel(entity);
	}

	void update(const ECS::EntityID entity) override
	{
		setPos(entity, glm::vec3(cosf(i) / 2, sinf(i) / 2, 0.0f));
		getRot(entity).z = i;

		_manager->getComponent<Transform>(entity)._model = getModel(entity);
		i += 0.1;
	}

	glm::mat4 getModel(const ECS::ComponentTypeID entity)
	{
		glm::mat4 posMatrix = glm::translate(_manager->getComponent<Transform>(entity)._pos);

		glm::mat4 rotXMatrix = glm::rotate(_manager->getComponent<Transform>(entity)._rot.x, glm::vec3(1, 0, 0));
		glm::mat4 rotYMatrix = glm::rotate(_manager->getComponent<Transform>(entity)._rot.y, glm::vec3(0, 1, 0));
		glm::mat4 rotZMatrix = glm::rotate(_manager->getComponent<Transform>(entity)._rot.z, glm::vec3(0, 0, 1));

		glm::mat4 scaleMatrix = glm::scale(_manager->getComponent<Transform>(entity)._scale);

		//ordem da multiplica��o de matriz importa, X, Y Z, !ordem oposta!

		glm::mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;

		//escala, gira e movimenta, nessa ordem
		return posMatrix * rotMatrix * scaleMatrix;
	}

	glm::vec3& getPos(const ECS::ComponentTypeID entity) { return _manager->getComponent<Transform>(entity)._pos; }
	glm::vec3& getRot(const ECS::ComponentTypeID entity) { return _manager->getComponent<Transform>(entity)._rot; }
	glm::vec3& getScale(const ECS::ComponentTypeID entity) { return _manager->getComponent<Transform>(entity)._scale; }

	void setPos(const ECS::ComponentTypeID entity, const glm::vec3& pos) { _manager->getComponent<Transform>(entity)._pos = pos; }
	void setRot(const ECS::ComponentTypeID entity, const glm::vec3& rot) { _manager->getComponent<Transform>(entity)._rot = rot; }
	void setScale(const ECS::ComponentTypeID entity, const glm::vec3& scale) { _manager->getComponent<Transform>(entity)._scale = scale; }

	float i;
};
