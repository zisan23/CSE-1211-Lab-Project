#include "initiateCoins.h"

//funtion to load the coins of levelOne
void levelOneCoinsLoad(void)
{
    for (int i = 0; i < 5; i++)
    {
        window.surface = IMG_Load("images/levelone/reward.png");

        if (!window.surface)
        {
            printf("coins[i] error: %s\n", IMG_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }

        L1WindowCoins[i].tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
        SDL_FreeSurface(window.surface);
        if (!L1WindowCoins[i].tex)
        {
            printf("coins[i]  texture %s\n", SDL_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }

        SDL_QueryTexture(L1WindowCoins[i].tex, NULL, NULL, &L1WindowCoins[i].rect.w, &L1WindowCoins[i].rect.h);
        L1WindowCoins[i].rect.w = (int)40;
        L1WindowCoins[i].rect.h = (int)40;
        L1WindowCoins[i].rect.x = (int)WINDOW_WIDTH + 100;
        L1WindowCoins[i].rect.y = (int)500;
    }
}
//funtion to cleanup the textures of the coins of LevelOne
void levelOneCoinsCleanUp()
{
    for (int i = 0; i < 5; i++)
    {
        SDL_DestroyTexture(L1WindowCoins[i].tex);
    }

    IMG_Quit();
}
