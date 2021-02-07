#pragma once
#include "Vector.h"
#include "Object.h"
#include <memory>
class Scene {
public:
	Vector3f m_backgroundColor = Vector3f(0.235294, 0.67451, 0.843137);
public:
	Scene() {};
	~Scene() {};
    int maxDepth = 5;
    float epsilon = 0.00001;
    void Add(std::unique_ptr<Object> object) { objects.push_back(std::move(object)); }
    const std::vector<std::unique_ptr<Object> >& get_objects() const { return objects; }
private:
    // creating the scene (adding objects and lights)
    std::vector<std::unique_ptr<Object> > objects;
   
};

