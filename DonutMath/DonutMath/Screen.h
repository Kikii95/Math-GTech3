#pragma once
#include <vector>
#include "Settings.h"
#include "Mesh.h"

class Screen
{
public:
    Screen(const Settings& settings);
    ~Screen();

    void Clear();
    void Display();
    void Display(const Mesh& mesh);

private:
    int width;
    int height;
    char background;
    char projection;
    float screenPosition;
    float viewerPosition;

    std::vector<char> buffer;

    void InitConsole();
    void ClearConsole();
    void HideCursor();
    void ShowCursor();
    void ResetCursorPosition();
};
