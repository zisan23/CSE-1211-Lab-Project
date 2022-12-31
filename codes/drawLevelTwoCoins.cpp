#include "drawLevelTwoCoins.h"

void updateCoinsPosition()
{
    for (int i = 0; i < 7; i++)
    {
        L2_WindowCoins[i].rect.w = (int)60;
        L2_WindowCoins[i].rect.h = (int)60;
    }

    // adjusting tracks position and keeping it into the frame
    if (levelTwoTrack[0].rect.y < WINDOW_HEIGHT / 2 || levelTwoTrack[0].rect.y >= WINDOW_HEIGHT - 400)
    {
        levelTwoTrack[0].rect.y = WINDOW_HEIGHT / 2 + rand() % 100;
    }

    // updating coins position with respect to tracks
    L2_WindowCoins[0].rect.y = levelTwoTrack[0].rect.y - 70 - rand() % 200;
    L2_WindowCoins[1].rect.y = levelTwoTrack[0].rect.y - 70 - rand() % 300;
    L2_WindowCoins[2].rect.y = levelTwoTrack[0].rect.y - 70 - rand() % 400;
    L2_WindowCoins[3].rect.y = levelTwoTrack[0].rect.y - 70 - rand() % 500;
    L2_WindowCoins[4].rect.y = levelTwoTrack[0].rect.y - 70 - rand() % 100;

    L2_WindowCoins[0].rect.x = rand() % (WINDOW_WIDTH - 150);
    L2_WindowCoins[1].rect.x = rand() % (WINDOW_WIDTH - 150);
    L2_WindowCoins[2].rect.x = rand() % (WINDOW_WIDTH - 150);
    L2_WindowCoins[3].rect.x = rand() % (WINDOW_WIDTH - 150);
    L2_WindowCoins[4].rect.x = rand() % (WINDOW_WIDTH - 150);

    L2_WindowCoins[5].rect.y = levelTwoTrack[1].rect.y - 70 - rand() % 200;
    L2_WindowCoins[6].rect.y = levelTwoTrack[1].rect.y - 70 - rand() % 200;

    L2_WindowCoins[5].rect.x = rand() % (WINDOW_WIDTH - 150);
    L2_WindowCoins[6].rect.x = rand() % (WINDOW_WIDTH - 150);
}

void drawLevelTwoCoinsFunction()
{
    for (int i = 0; i < 7; i++)
    {
        SDL_RenderCopy(app.rend, L2_WindowCoins[i].tex, &levelTwoRotatingCoin.rect, &L2_WindowCoins[i].rect);
    }
}
