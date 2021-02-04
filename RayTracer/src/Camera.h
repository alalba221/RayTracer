#pragma once
#include <fstream>
#include"Scene.h"

class Camera
{
private:
	int m_width = 1280;
	int m_height = 960;
public:
	Camera() {};
	~Camera() {};
	inline float clamp(const float& lo, const float& hi, const float& v)
	{
		return std::max(lo, std::min(hi, v));
	}

	void Click(const Scene& scene);

};

