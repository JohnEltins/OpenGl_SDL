#pragma once

#include "Types.h"

namespace ECS {
	struct Component
	{
	Component() : _entityID() {}
	virtual ~Component() {}
	inline const EntityID getID() const { return _entityID; }
		
	protected:
		friend class EntityManager;
		EntityID _entityID;
	};
}

