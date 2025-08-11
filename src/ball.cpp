#include "ball.h"
#include <raylib.h>
#include <cmath>

Ball::Ball() 
    : x(100)
    , y(100)
    , speedX(5)
    , speedY(5)
    , radius(15) 
    , isplayercontrolled()
{
}
Ball::Ball(int startX, int startY, int sX, int sY, int r, bool is_player_controlled)
    : x(startX), y(startY), speedX(sX), speedY(sY), radius(r), isplayercontrolled(is_player_controlled)
{
}

void Ball::Update()
{
    if (isplayercontrolled)
    {
        if (IsKeyDown(KEY_W)) y -= speedY;
        if (IsKeyDown(KEY_S)) y += speedY;
        if (IsKeyDown(KEY_A)) x -= speedX;
        if (IsKeyDown(KEY_D)) x += speedX;
    }
    else
    {
        x += speedX;
        y += speedY;

        const int screenWidth = GetScreenWidth();
        const int screenHeight = GetScreenHeight();

        if ((x + radius >= screenWidth) || (x - radius <= 0)) {
            speedX *= -1;
        }
        if ((y + radius >= screenHeight) || (y - radius <= 0)) {
            speedY *= -1;
        }
    }
}

void Ball::Draw() const
{
    DrawCircle(x, y, radius, WHITE);
}

bool Ball::IsCollidingWith(const Ball& other) const
{
    int dx = x - other.x;
    int dy = y - other.y;
    int distanceSquared = dx * dx + dy * dy;
    int radiusSum = radius + other.radius;

    return distanceSquared <= radiusSum * radiusSum;
}