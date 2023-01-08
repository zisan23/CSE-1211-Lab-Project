#include "drawCoins.h"

//funtion to determine the speeds of the coins
void coinsupdateanimation()
{
    //giving each coins different speeds
    L1PointAnimSpeed[0] -= 8;
    if (L1PointAnimSpeed[0] < -WINDOW_WIDTH + 100)
    {
        L1PointAnimSpeed[0] = WINDOW_WIDTH + 100;

        L1WindowCoins[0].rect.h = 40;
        L1WindowCoins[0].rect.w = 40;
        //randomly setting the coin positions
        L1WindowCoins[0].rect.y = 630 - rand() % 500;
    }

    L1PointAnimSpeed[1] -= 7;
    if (L1PointAnimSpeed[1] < -WINDOW_WIDTH + 100)
    {
        L1PointAnimSpeed[1] = WINDOW_WIDTH + 100;

        L1WindowCoins[1].rect.h = 40;
        L1WindowCoins[1].rect.w = 40;
        //randomly setting the coin positions
        L1WindowCoins[1].rect.y = 630 - rand() % 500;
    }

    L1PointAnimSpeed[2] -= 6;
    if (L1PointAnimSpeed[2] < -WINDOW_WIDTH + 100)
    {
        L1PointAnimSpeed[2] = WINDOW_WIDTH + 100;

        L1WindowCoins[2].rect.h = 40;
        L1WindowCoins[2].rect.w = 40;
        //randomly setting the coin positions
        L1WindowCoins[2].rect.y = 630 - rand() % 500;
    }

    L1PointAnimSpeed[3] -= 5;
    if (L1PointAnimSpeed[3] < -WINDOW_WIDTH + 100)
    {
        L1PointAnimSpeed[3] = WINDOW_WIDTH + 100;

        L1WindowCoins[3].rect.h = 40;
        L1WindowCoins[3].rect.w = 40;
        //randomly setting the coin positions
        L1WindowCoins[3].rect.y = 630 - rand() % 500;
    }

    L1PointAnimSpeed[4] -= 4;
    if (L1PointAnimSpeed[4] < -WINDOW_WIDTH + 100)
    {
        L1PointAnimSpeed[4] = WINDOW_WIDTH + 100;

        L1WindowCoins[4].rect.h = 40;
        L1WindowCoins[4].rect.w = 40;
        //randomly setting the coin positions
        L1WindowCoins[4].rect.y = 630 - rand() % 500;
    }
}
//funtion to render the coins of levelOne
void drawCoinsFunction()
{
    coinsupdateanimation();
    for (int i = 0; i < 5; i++)
    {
        SDL_RenderCopy(app.rend, L1WindowCoins[i].tex, NULL, &L1WindowCoins[i].rect);
        L1WindowCoins[i].rect.x = L1PointAnimSpeed[i];
        SDL_RenderCopy(app.rend, L1WindowCoins[i].tex, NULL, &L1WindowCoins[i].rect);
    }
}
