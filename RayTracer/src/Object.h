#pragma once
#include "global.h"
#include "Vector.h"
class Object
{
public:
	Object() {}

	virtual ~Object() = default;
	virtual bool intersect(const Vector3f&, const Vector3f&, float&, uint32_t&, Vector2f&) const = 0;
};

