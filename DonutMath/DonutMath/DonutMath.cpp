#include <iostream>
#include "Settings.h"
#include "Screen.h"
#include "Mesh.h"

int main(int argc, char* argv[])
{
    Settings settings(argc, argv);
    Screen screen(settings);
    Mesh mesh(settings.GetMeshResolution());

    mesh.GenerateCircle(5.0f);
	//mesh.GenerateHalfCircle(5.0f);
	//mesh.GenerateRectangle(8.0f, 4.0f);
	//mesh.GenerateSquare(6.0f);

    screen.Display(mesh);

    std::cin.get();

    return 0;
}
