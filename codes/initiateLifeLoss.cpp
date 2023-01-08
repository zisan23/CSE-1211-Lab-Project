#include "initiateLifeLoss.h"

//funtion to load life losing effect
void L1_LifeLossLoad(void)
{

    for (int i = 0; i < 3; i++)
    {

        window.surface = IMG_Load("images/levelone/heartbreak.png");
        if (!window.surface)
        {
            printf("lifeloss[i] Error: %s\n", IMG_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }

        L1_LifeLoss[i].tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
        SDL_FreeSurface(window.surface);
        if (!L1WindowObs[i].tex)
        {
            printf("lifeloss[i]  Texture %s\n", SDL_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }

        SDL_QueryTexture(L1_LifeLoss[i].tex, NULL, NULL, &L1_LifeLoss[i].rect.w, &L1_LifeLoss[i].rect.h);
        L1_LifeLoss[i].rect.w = (int)0;
        L1_LifeLoss[i].rect.h = (int)0;
        L1_LifeLoss[i].rect.x = L1WindowObs[i].rect.x;
        L1_LifeLoss[i].rect.y = (int)700;
    }
}

//funtion to destroy the texture of lifelosing
void L1_LifeLossCleanUp()
{
    for (int i = 0; i < 3; i++)
    {
        SDL_DestroyTexture(L1_LifeLoss[i].tex);
    }

    IMG_Quit();
}
