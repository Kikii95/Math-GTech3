#include "Mesh.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Mesh::Mesh(int meshResolution)
    : resolution(meshResolution)
{
}

void Mesh::AddVertex(float x, float y, float z)
{
    Vertex vertex;
    vertex.x = x;
    vertex.y = y;
    vertex.z = z;
    vertices.push_back(vertex);
}

void Mesh::DebugMesh() const
{
    std::cout << "MeshResolution : " << resolution << std::endl;
    std::cout << "Mesh avec " << vertices.size() << " vertices :" << std::endl;

    for (const auto& v : vertices) {
        v.DebugVertex();
    }
}

void Mesh::GenerateCircle(float radius)
{
    vertices.clear();

    for (int i = 0; i < resolution; ++i)
    {
        float angle = 2.0f * M_PI * i / resolution;
        float x = radius * std::cos(angle);
        float y = radius * std::sin(angle);
        AddVertex(x, y, 0.0f);
    }
}

void Mesh::GenerateHalfCircle(float radius)
{
    vertices.clear();

    for (int i = 0; i <= resolution; ++i)
    {
        float angle = M_PI * i / resolution;
        float x = radius * std::cos(angle);
        float y = radius * std::sin(angle);
        AddVertex(x, y, 0.0f);
    }
}

void Mesh::GenerateRectangle(float width, float height)
{
    vertices.clear();

    for (int i = 0; i < resolution; ++i)
    {
        for (int j = 0; j < resolution; ++j)
        {
            float x = (2.0f * i / (resolution - 1)) - 1.0f;
            float y = (2.0f * j / (resolution - 1)) - 1.0f;
            AddVertex(x * width, y * height, 0.0f);
        }
    }
}

void Mesh::GenerateSquare(float size)
{
    GenerateRectangle(size, size);
}
