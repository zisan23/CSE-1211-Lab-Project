#include "drawLife.h"

//function to set the life sizes and rendering them
void levelOneDrawLifeFunction()
{

    for (int i = 0; i < lifeSize; i++)
    {
        L1WindowLife[i].rect.x = i * 40 + 1000;
        L1WindowLife[i].rect.y = 30;

        L1WindowLife[i].rect.h = 30;
        L1WindowLife[i].rect.w = 30;
        SDL_RenderCopy(app.rend, L1WindowLife[i].tex, NULL, &L1WindowLife[i].rect);
    }
}
