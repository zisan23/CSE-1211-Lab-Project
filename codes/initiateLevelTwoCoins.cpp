#include "initiateLevelTwoCoins.h"

void LevelTwoCoinsload(void)
{
    for (int i = 0; i < 7; i++)
    {
        window.surface = IMG_Load("images/level2obstacles/fruit.png");

        if (!window.surface)
        {
            printf("levelTwoCoins Error: %s\n", IMG_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }

        L2_WindowCoins[i].tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
        SDL_FreeSurface(window.surface);

        if (!L2_WindowCoins[i].tex)
        {
            printf("levelTwoCoins Texture Error: %s\n", SDL_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }

        SDL_QueryTexture(L2_WindowCoins[i].tex, NULL, NULL, &L2_WindowCoins[i].rect.w, &L2_WindowCoins[i].rect.h);
        L2_WindowCoins[i].rect.w = (int)60;
        L2_WindowCoins[i].rect.h = (int)60;
        L2_WindowCoins[i].rect.x = (int)levelTwoTrack[0].rect.x + 150;
        L2_WindowCoins[i].rect.y = (int)levelTwoTrack[0].rect.y - 70;

        SDL_QueryTexture(L2_WindowCoins[i].tex, NULL, NULL, &L2_CoinTextureHeight, &L2_CoinTextureWidth);

        // variables for animating the rotatingCoins
        L2_Coin_FrameWidth = L2_CoinTextureWidth;
        L2_Coin_FrameHeight = L2_CoinTextureHeight;

        levelTwoRotatingCoin.rect.w = (int)L2_Coin_FrameWidth;
        levelTwoRotatingCoin.rect.h = (int)L2_Coin_FrameHeight;
        levelTwoRotatingCoin.rect.x = (int)0;
        levelTwoRotatingCoin.rect.y = (int)0;
    }
}

void LevelTwoCoinsCleanUp()
{
    for (int i = 0; i < 7; i++)
    {
        SDL_DestroyTexture(L2_WindowCoins[i].tex);
    }

    IMG_Quit();
}
