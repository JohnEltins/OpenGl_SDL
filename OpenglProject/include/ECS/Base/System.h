#pragma once

#include "Types.h"

namespace ECS {
	struct System
	{
		System() = default;
		virtual ~System() = default;

		void removeEntity(const EntityID entity)
		{
			_entities.erase(entity);
		}

		void addEntity(const EntityID entity)
		{
			_entities.insert(entity);
		}

		const EntitySignature getSignature() const
		{
			return _signature;
		}

		template<typename T>
		void addComponentSignature()
		{
			_signature.insert(CompType<T>());
		}

		virtual void init(){}
		virtual void update()
		{
			for (auto i : _entities)
			{
				std::cout << i << " ";
			}

			std::cout << std::endl;
		}

		virtual void render(){}
		virtual void destroy(){}

	protected:
		friend class EntityManager;
		EntitySignature _signature;
		std::set<EntityID> _entities;
	};
}

