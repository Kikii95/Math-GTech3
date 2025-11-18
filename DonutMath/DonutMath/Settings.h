#pragma once
#include <string>
#include <vector>

class Settings
{
public:
    Settings(int argc, char* argv[]);

    int GetScreenWidth() const { return screenWidth; }
    int GetScreenHeight() const { return screenHeight; }
    int GetMeshResolution() const { return meshResolution; }
    char GetScreenBackground() const { return screenBackground; }
    char GetScreenMeshProjection() const { return screenMeshProjection; }
    float GetScreenPosition() const { return screenPosition; }
    float GetViewerPosition() const { return viewerPosition; }

private:
    int screenWidth;
    int screenHeight;
    int meshResolution;
    char screenBackground;
    char screenMeshProjection;
    float screenPosition;
    float viewerPosition;

    void ParseArguments(int argc, char* argv[]);
};
