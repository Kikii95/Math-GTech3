#pragma once
#include <vector>
#include <iostream>

class Mesh
{
public:
    struct Vertex
    {
        float x;
        float y;
        float z;

        void DebugVertex() const {
            std::cout << "x : " << x
                << " | y : " << y
                << " | z : " << z << std::endl;
        }
    };

    Mesh(int meshResolution);

    void DebugMesh() const;

    void GenerateCircle(float radius);
    void GenerateHalfCircle(float radius);
    void GenerateRectangle(float width, float height);
    void GenerateSquare(float size);

    const std::vector<Vertex>& GetVertices() const { return vertices; }

private:
    int resolution;
    std::vector<Vertex> vertices;

    void AddVertex(float x, float y, float z);
};
