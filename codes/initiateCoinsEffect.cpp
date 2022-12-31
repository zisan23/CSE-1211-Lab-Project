#include "initiateCoinsEffect.h"

// funtion to load the effect after collecting coins
void levelOneCoinsEffectLoad(void)
{
    for (int i = 0; i < 5; i++)
    {
        window.surface = IMG_Load("images/levelone/point.png");

        if (!window.surface)
        {
            printf("coinseffect[i] Error: %s\n", IMG_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }

        L1WindowCoins_Effect[i].tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
        SDL_FreeSurface(window.surface);
        if (!L1WindowCoins_Effect[i].tex)
        {
            printf("coinseffects[i] Texture %s\n", SDL_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }

        SDL_QueryTexture(L1WindowCoins_Effect[i].tex, NULL, NULL, &L1WindowCoins_Effect[i].rect.w, &L1WindowCoins_Effect[i].rect.h);
        L1WindowCoins_Effect[i].rect.w = (int)0;
        L1WindowCoins_Effect[i].rect.h = (int)0;
        L1WindowCoins_Effect[i].rect.x = (int)0;
        L1WindowCoins_Effect[i].rect.y = L1WindowCoins[i].rect.y;
    }
}

// function to destroy the textures of coinseffect
void levelOneCoinsEffectCleanUp()
{
    for (int i = 0; i < 5; i++)
    {
        SDL_DestroyTexture(L1WindowCoins_Effect[i].tex);
    }

    IMG_Quit();
}
