#include "Screen.h"
#include <iostream>
#include <cmath>
#include <windows.h>

Screen::Screen(const Settings& settings)
    : width(settings.GetScreenWidth())
    , height(settings.GetScreenHeight())
    , background(settings.GetScreenBackground())
    , projection(settings.GetScreenMeshProjection())
    , screenPosition(settings.GetScreenPosition())
    , viewerPosition(settings.GetViewerPosition())
{
    buffer.resize(width * height, background);
    InitConsole();
    HideCursor();
}

Screen::~Screen()
{
    ShowCursor();
}

void Screen::InitConsole()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hConsole, &mode);
    SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

void Screen::ClearConsole()
{
    std::cout << "\x1b[2J";
}

void Screen::HideCursor()
{
    std::cout << "\x1b[?25l";
}

void Screen::ShowCursor()
{
    std::cout << "\x1b[?25h";
}

void Screen::ResetCursorPosition()
{
    std::cout << "\x1b[H";
}

void Screen::Clear()
{
    for (int i = 0; i < width * height; ++i)
    {
        buffer[i] = background;
    }
}

void Screen::Display()
{
    ClearConsole();
    ResetCursorPosition();

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            std::cout << buffer[y * width + x];
        }
        std::cout << '\n';
    }
}

void Screen::Display(const Mesh& mesh)
{
    Clear();

    const auto& vertices = mesh.GetVertices();

    for (const auto& vertex : vertices)
    {
        float z = vertex.z + screenPosition;

        if (z <= 0.0f) continue;

        float projectedX = (vertex.x * viewerPosition) / z;
        float projectedY = (vertex.y * viewerPosition) / z;

        int screenX = static_cast<int>(projectedX + width / 2.0f);
        int screenY = static_cast<int>(projectedY + height / 2.0f);

        if (screenX >= 0 && screenX < width && screenY >= 0 && screenY < height)
        {
            buffer[screenY * width + screenX] = projection;
        }
    }

    Display();
}
