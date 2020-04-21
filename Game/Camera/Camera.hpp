#pragma once

class Camera
{
    int width = 0, height = 0;
    
public:
    int x = 0, y = 0;
    
    Camera(int, int);
    int calculateX(int, int);
    int calculateY(int, int);
};

