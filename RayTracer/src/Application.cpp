
#include "Camera.h"
#include "Scene.h"
#include "Sphere.h"
int main()
{
	Scene scene;
	
	std::unique_ptr<Sphere> sph1 = std::make_unique<Sphere>(Vector3f(0, 0, -1), 0.5);
	scene.Add(std::move(sph1));
	Camera camera;
	camera.Click(scene);
}