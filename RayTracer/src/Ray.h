#pragma once
#include "Vector.h"
class Ray {
public:
    Ray() {}
    Ray(const Vector3f& origin, const Vector3f& direction)
        : orig(origin), dir(direction)
    {}

    Vector3f origin() const { return orig; }
    Vector3f direction() const { return dir; }

    Vector3f at(double t) const {
        return orig + t * dir;
    }

public:
    Vector3f orig;
    Vector3f dir;
};