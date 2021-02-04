#include "Camera.h"

void Camera::Click(const Scene& scene)
{
    std::ofstream inp("binary.ppm", std::ios::out | std::ios::binary);
    if (inp.is_open()) {
        inp << "P6\n";
        inp << m_width;
        inp << " ";
        inp << m_height << "\n";
        inp << "255" << "\n";
        std::cout << scene.m_backgroundColor.x;
        for (int i = 0; i < m_height * m_width; ++i) {
            char color[3];
            color[0] = (char)(255 * scene.m_backgroundColor.x);
            color[1] = (char)(255 * scene.m_backgroundColor.y);
            color[2] = (char)(255 * scene.m_backgroundColor.z);
            inp.write(color, 3);
        }
    }
    inp.close();
}
