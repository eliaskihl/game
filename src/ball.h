#pragma once

class Ball
{
public:
    Ball();
    Ball(int startX, int startY, int sX, int sY, int rad);
    void Update();
    void Draw() const;

private:
    int x;
    int y;
    int speedX;
    int speedY;
    int radius;
};