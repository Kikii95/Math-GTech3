#pragma once
#include <vector>
#include <iostream>

class Mesh
{
    struct Vertex
    {
        int x;
        int y;
        int z;

        void DebugVertex() const {
            std::cout << "x : " << x
                << " | y : " << y
                << " | z : " << z << std::endl;
        }
    };

public:
    Mesh(int meshResolution);

    void DebugMesh() const;

    void GenerateCircle(float radius);
    void GenerateHalfCircle(float radius); 
    void GenerateRectangle(float width, float height);
    void GenerateSquare(float size);

private:
    int resolution;                 
    std::vector<Vertex> vertices;   

    void Create(const std::vector<int>& v);
};
