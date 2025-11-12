// DonutMath.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>  
#include "Mesh.h"

int main(int argc, char* argv[])
{
    int meshResolution = 4;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-r" && i + 1 < argc) {
            try {
                meshResolution = std::stoi(argv[++i]);
            }
            catch (...) {
                std::cerr << "Valeur invalide pour -r, using default : 32\n";
                meshResolution = 32;
            }
        }
    }

    Mesh* mesh = new Mesh(meshResolution);

    mesh->DebugMesh();

    mesh->GenerateHalfCircle(8);

    delete mesh; 
    return 0;
}
