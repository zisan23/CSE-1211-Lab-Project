#include "collisionLevelOne.h"

// funtion to detect collisions for levelOne
void collision()
{

    for (int i = 0; i < 5; i++)
    {
        // detecting collision between character and coins
        if (SDL_HasIntersection(&charFramePos.rect, &L1WindowCoins[i].rect))
        {
            Mix_VolumeChunk(levelOneCoingain, 40);
            Mix_PlayChannel(-1, levelOneCoingain, 0);

            L1WindowCoins[i].rect.h = 0;
            L1WindowCoins[i].rect.w = 0;

            L1WindowCoins_Effect[i].rect.h = int(100);
            L1WindowCoins_Effect[i].rect.w = int(100);

            L1CurrentScore += 1;
            coineffectdelay();
        }
    }
    for (int i = 0; i < 3; i++)
    {
        // detecting collisions between character and obstacles
        if (SDL_HasIntersection(&charFramePos.rect, &L1WindowObs[i].rect))
        {

            Mix_PlayChannel(-1, hitLevelOne, 0);

            SDL_SetTextureColorMod(L1WindowChar.tex, 255, 0, 0);

            L1WindowObs[i].rect.h = 0;
            L1WindowObs[i].rect.w = 0;
            L1LifeAnimSpeed[i] = 700;

            L1_LifeLoss[i].rect.h = int(60);
            L1_LifeLoss[i].rect.w = int(60);

            // after collision with obstacles character loses life
            if (lifeSize >= 1)
            {
                lifeSize--;
                break;
            }
        }
    }
}
