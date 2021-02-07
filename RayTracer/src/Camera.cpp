#include "Camera.h"

Camera::Camera()
{
    m_nearWidth = m_nearHeight * m_aspectRatio;
    m_w = normalize(m_camPosition - m_lookAt); //z
    m_u = normalize(crossProduct(m_Up, m_w)); // x
    m_v = normalize(crossProduct(m_w, m_u)); // y

}

void Camera::Click(const Scene& scene)
{
    std::vector<Vector3f> framebuffer(m_imageplane.width * m_imageplane.height);

    int m = 0;
    Vector3f nearOri = m_camPosition - m_nearWidth * m_u / 2 - m_nearHeight * m_v / 2 - m_fol * m_w;
    for (int j = 0; j < m_imageplane.height; ++j)
    {
        for (int i = 0; i < m_imageplane.width; ++i)
        {
            // generate primary ray direction
            float u = double(i) / (m_imageplane.width - 1);
            float v = double(j) / (m_imageplane.height - 1);
            Vector3f dir = nearOri + u* m_nearWidth * m_u + v* m_nearHeight * m_v - m_camPosition;
            framebuffer[m++] = CastRay(m_camPosition, dir, scene, 0);
        }
        UpdateProgress(j / (float)m_imageplane.height);
    }



    std::ofstream inp("binary.ppm", std::ios::out | std::ios::binary);
    if (inp.is_open()) {
        inp << "P6\n";
        inp << m_imageplane.width;
        inp << " ";
        inp << m_imageplane.height << "\n";
        inp << "255" << "\n";
        for (int i = 0; i < m_imageplane.height * m_imageplane.width; ++i) {
            char color[3];
            color[0] = (char)(255 * framebuffer[i].x);
            color[1] = (char)(255 * framebuffer[i].y);
            color[2] = (char)(255 * framebuffer[i].z);
            inp.write(color, 3);
        }
    }
    inp.close();
}

Vector3f Camera::CastRay(const Vector3f& orig, const Vector3f& dir, const Scene& scene, int depth) const
{
    
    for (const auto& i : scene.get_objects()) {
        float tnear;
        uint32_t indexK;
        Vector2f uvK;
        if (i->intersect(orig, dir, tnear, indexK, uvK)) {
            return Vector3f(1, 0, 0);
        }
    }
    
    
    float t = 0.5 * (dir.y + 1.0);
    return (1.0 - t) * Vector3f(1.0, 1.0, 1.0) + t * Vector3f(0.5, 0.7, 1.0);
}
