#include "Mesh.h"

Mesh::Mesh(int meshResolution)
    : resolution(meshResolution)
{
    Create({ -1, -1, 0 });
    Create({ -1,  1, 0 });
    Create({ 1, -1, 0 });
    Create({ 1,  1, 0 });

}

void Mesh::Create(const std::vector<int>& v)
{
    if (v.size() < 3) return;

    Vertex vertex;
    vertex.x = v[0];
    vertex.y = v[1];
    vertex.z = v[2];

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

void Mesh::GenerateCircle(float radius) {

}

void Mesh::GenerateHalfCircle(float radius) {
    for (int i = 0; i < radius; i++) {
        for (int j = 0; j < radius - radius + i; j++) {
            std::cout << "--";
        }
        std::cout << "o" << std::endl;
    }
    for (int i = 0; i <= radius; i++) {
        for (int j = 0; j < radius - i; j++) {
            std::cout << "--";
        }
        std::cout << "o" << std::endl;
    }
}

void Mesh::GenerateRectangle(float width, float height) {

}

void Mesh::GenerateSquare(float size) {

}
