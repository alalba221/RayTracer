#pragma once
#include <fstream>
#include"Scene.h"
#include "global.h"
#include <vector>

class ImagePlane {
public:
	double width = 400;
	double height;
	double ratio = 16.0 / 9.0;
	ImagePlane() {
		height = width / ratio;
	}
};
class Camera
{
public:
	double m_fol = 1.0;
	double m_nearHeight = 2.0;
	double m_aspectRatio = 16.0 / 9.0;
	double m_nearWidth;


	Vector3f m_camPosition = Vector3f(0,0,0);
	Vector3f m_lookAt = Vector3f(0, 0, -1);
	Vector3f m_Up = Vector3f(0, 1, 0);
	Vector3f m_u;
	Vector3f m_v;
	Vector3f m_w;
	
	ImagePlane m_imageplane;
public:
	Camera();
	~Camera() {};
	inline float clamp(const float& lo, const float& hi, const float& v)
	{
		return std::max(lo, std::min(hi, v));
	}

	void Click(const Scene& scene);

private:
	Vector3f CastRay(const Vector3f& orig, const Vector3f& dir, const Scene& scene,
		int depth) const;
};

