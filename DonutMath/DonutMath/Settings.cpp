#include "Settings.h"
#include <iostream>

Settings::Settings(int argc, char* argv[])
    : screenWidth(100)
    , screenHeight(20)
    , meshResolution(32)
    , screenBackground(' ')
    , screenMeshProjection('X')
    , screenPosition(9.0f)
    , viewerPosition(10.0f)
{
    ParseArguments(argc, argv);
}

void Settings::ParseArguments(int argc, char* argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];

        if (arg == "-w" && i + 1 < argc)
        {
            try {
                screenWidth = std::stoi(argv[++i]);
            }
            catch (...) {
                std::cerr << "Invalid value for -w, using default: 100\n";
                screenWidth = 100;
            }
        }
        else if (arg == "-h" && i + 1 < argc)
        {
            try {
                screenHeight = std::stoi(argv[++i]);
            }
            catch (...) {
                std::cerr << "Invalid value for -h, using default: 20\n";
                screenHeight = 20;
            }
        }
        else if (arg == "-r" && i + 1 < argc)
        {
            try {
                meshResolution = std::stoi(argv[++i]);
            }
            catch (...) {
                std::cerr << "Invalid value for -r, using default: 32\n";
                meshResolution = 32;
            }
        }
        else if (arg == "-b" && i + 1 < argc)
        {
            screenBackground = argv[++i][0];
        }
        else if (arg == "-p" && i + 1 < argc)
        {
            screenMeshProjection = argv[++i][0];
        }
        else if (arg == "-s" && i + 1 < argc)
        {
            try {
                screenPosition = std::stof(argv[++i]);
            }
            catch (...) {
                std::cerr << "Invalid value for -s, using default: 9.0\n";
                screenPosition = 9.0f;
            }
        }
        else if (arg == "-v" && i + 1 < argc)
        {
            try {
                viewerPosition = std::stof(argv[++i]);
            }
            catch (...) {
                std::cerr << "Invalid value for -v, using default: 10.0\n";
                viewerPosition = 10.0f;
            }
        }
    }
}
