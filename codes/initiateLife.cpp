#include "initiateLife.h"

//funtion to load the lives of level one
void levelOneLifeLoad(void)
{
    for (int i = 0; i < 6; i++)
    {
        window.surface = IMG_Load("images/levelone/obstacles/redlife.png");

        if (!window.surface)
        {
            printf("life [i] Error: %s\n", IMG_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }

        L1WindowLife[i].tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
        SDL_FreeSurface(window.surface);
        if (!L1WindowLife[i].tex)
        {
            printf("Life [i] Texture %s\n", SDL_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }

        SDL_QueryTexture(L1WindowLife[i].tex, NULL, NULL, &L1WindowLife[i].rect.w, &L1WindowLife[i].rect.h);
        L1WindowLife[i].rect.w = (int)56;
        L1WindowLife[i].rect.h = (int)40;
        L1WindowLife[i].rect.x = (int)600;
        L1WindowLife[i].rect.y = (int)500;
    }
}
//funtion to cleanup the textures of lives
void levelOneLifeCleanUp()
{
    for (int i = 0; i < 6; i++)
    {
        SDL_DestroyTexture(L1WindowLife[i].tex);
    }

    IMG_Quit();
}
