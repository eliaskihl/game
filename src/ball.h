#pragma once

class Ball
{
public:
    Ball();
    Ball(int startX, int startY, int sX, int sY, int rad, bool isplayercontrolled);
    void Update();
    void Draw() const;
    bool IsCollidingWith(const Ball& ball) const;

private:
    int x;
    int y;
    int speedX;
    int speedY;
    int radius;
    bool isplayercontrolled;
};