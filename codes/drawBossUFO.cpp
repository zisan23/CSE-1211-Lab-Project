#include "drawBossUFO.h"

void BossUFO()
{

    L2_BossUFO_Pos.rect.x = 1050;

    // implementing the boss ufo and updating its motion
    if (((L2_BossUFO_Pos.rect.y + L2_BossUFO_Pos.rect.h <= 150) && L2_Missile.rect.x <= 0))
    {

        L2_BossUFO_Pos.rect.y = WINDOW_HEIGHT - 150;
        L2_Missile.rect.x = L2_BossUFO_Pos.rect.x;
        L2_Missile.rect.w = 0;
        L2_Missile.rect.h = 0;
        randomGenerator = L2_WindowCharPosition.rect.y;
    }
    else
    {
        L2_BossUFO_Pos.rect.y -= 2;
    }

    if (abs(randomGenerator - L2_BossUFO_Pos.rect.y) <= 18)
    {
        L2_Missile.rect.y = randomGenerator;
        L2_Missile.rect.x = L2_BossUFO_Pos.rect.x;
        L2_Missile.rect.w = (int)40;
        L2_Missile.rect.h = (int)50;
    }

    if (L2_Missile.rect.y == randomGenerator) // missile launches when it possess the same y position as the character
    {
        L2_Missile.rect.x -= 25; // speed for missile
    }
}
void drawBossUFOFunction()
{
    BossUFO();
    SDL_RenderCopy(app.rend, L2_Missile.tex, NULL, &L2_Missile.rect);
    SDL_RenderCopy(app.rend, L2_BossUFO.tex, &L2_BossUFO.rect, &L2_BossUFO_Pos.rect);
    SDL_RenderCopy(app.rend, L2_Explosion.tex, NULL, &L2_Explosion.rect);
}
