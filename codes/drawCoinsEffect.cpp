#include "drawCoinsEffect.h"

//funtion to delay the effect after getting a coin
void coineffectdelay()
{
    for (int i = 0; i < 5; i++)
    {
        if (L1WindowCoins[i].rect.x == 300)
        {
            L1WindowCoins_Effect[i].rect.h = 0;
            L1WindowCoins_Effect[i].rect.w = 0;
        }
    }
}
//funtion to determine what happens after getting a coin
void coinseffectupdateanimation()
{

    L1PointEffAnimSpeed[0] -= 8;
    if (L1PointEffAnimSpeed[0] < -1280)
    {
        L1PointEffAnimSpeed[0] = WINDOW_WIDTH;
        //setting the coin getting effect to zero when new window arrives
        L1WindowCoins_Effect[0].rect.h = 0;
        L1WindowCoins_Effect[0].rect.w = 0;
        L1WindowCoins_Effect[0].rect.y = L1WindowCoins[0].rect.y;
    }

    L1PointEffAnimSpeed[1] -= 7;
    if (L1PointEffAnimSpeed[1] < -1280)
    {
        L1PointEffAnimSpeed[1] = WINDOW_WIDTH;

        L1WindowCoins_Effect[1].rect.h = 0;
        L1WindowCoins_Effect[1].rect.w = 0;
        L1WindowCoins_Effect[1].rect.y = L1WindowCoins[1].rect.y;
    }

    L1PointEffAnimSpeed[2] -= 6;
    if (L1PointEffAnimSpeed[2] < -1280)
    {
        L1PointEffAnimSpeed[2] = WINDOW_WIDTH;

        L1WindowCoins_Effect[2].rect.h = 0;
        L1WindowCoins_Effect[2].rect.w = 0;
        L1WindowCoins_Effect[2].rect.y = L1WindowCoins[2].rect.y;
    }

    L1PointEffAnimSpeed[3] -= 5;
    if (L1PointEffAnimSpeed[3] < -1280)
    {
        L1PointEffAnimSpeed[3] = WINDOW_WIDTH;

        L1WindowCoins_Effect[3].rect.h = 0;
        L1WindowCoins_Effect[3].rect.w = 0;
        L1WindowCoins_Effect[3].rect.y = L1WindowCoins[3].rect.y;
    }

    L1PointEffAnimSpeed[4] -= 4;
    if (L1PointEffAnimSpeed[4] < -1280)
    {
        L1PointEffAnimSpeed[4] = WINDOW_WIDTH;

        L1WindowCoins_Effect[4].rect.h = 0;
        L1WindowCoins_Effect[4].rect.w = 0;
        L1WindowCoins_Effect[4].rect.y = L1WindowCoins[4].rect.y;
    }
}
//funtion to show the effect after getting a coin
void drawCoinsEffectFunction()
{
    coinseffectupdateanimation();
    coineffectdelay();
    for (int i = 0; i < 5; i++)
    {

        SDL_RenderCopy(app.rend, L1WindowCoins_Effect[i].tex, NULL, &L1WindowCoins_Effect[i].rect);
        L1WindowCoins_Effect[i].rect.x = L1PointEffAnimSpeed[i] + 100;
        SDL_RenderCopy(app.rend, L1WindowCoins_Effect[i].tex, NULL, &L1WindowCoins_Effect[i].rect);
    }
}
