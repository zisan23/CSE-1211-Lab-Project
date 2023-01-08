#include "collisionLevelTwo.h"

void collisionsLevelTwo()
{
    for (int i = 0; i < 7; i++)
    {
        //handling the collision between the character and the coins 
        SDL_bool collisionBetweenCharacterandCoins = SDL_HasIntersection(&L2_WindowCoins[i].rect, &L2_WindowCharPosition.rect);
        if (collisionBetweenCharacterandCoins)
        {
            Mix_PlayChannel(-1, coingain, 0);
            currentScore += 100;
            L2_WindowCoins[i].rect.w = 0;
            L2_WindowCoins[i].rect.h = 0;
        }
    }
    //handling the collision between the character and the bomb and the explosion effect 
    SDL_bool collisionBetweenCharacterandBomb = SDL_HasIntersection(&L2_Missile.rect, &L2_WindowCharPosition.rect);

    if (collisionBetweenCharacterandBomb && currentLife > 0)
    {
        Mix_PlayChannel(-1, explosionsound, 0);
        lifePercentage += 200;
        L2_Explosion.rect.w = (int)333 / 1.5;
        L2_Explosion.rect.h = (int)320 / 1.5;
        L2_Explosion.rect.x = L2_Missile.rect.x;
        L2_Explosion.rect.y = L2_Missile.rect.y;
        L2_Missile.rect.w = 0;
        L2_Missile.rect.h = 0;
        delayCountForExplosion = 0;
        SDL_SetTextureColorMod(L2_WindowChar.tex, 255, 0, 0);

        delayCountForCharacterCollisionEffect = 0;
        delayCountForCharacterCollisionEffect++;
    }
    else
    {
        delayCountForExplosion++;
    }
    if (delayCountForExplosion == 10 && L2_Missile.rect.w == 0)  //delaying the explosion 
    {
        L2_Explosion.rect.w = 0;
        L2_Explosion.rect.h = 0;
        delayCountForExplosion = 0;
    }
    
    //handling the collision between the character and the hearts 
    SDL_bool collisionBetweenCharacterandHeart = SDL_HasIntersection(&levelTwoHeart.rect, &L2_WindowCharPosition.rect);

    if (collisionBetweenCharacterandHeart)
    {
        Mix_PlayChannel(-1, coingain, 0);
        levelTwoHeart.rect.w = 0;
        levelTwoHeart.rect.h = 0;

        if (currentLife >= 95)
        {
            lifePercentage = 0;
        }

        levelTwoLifeBonusPopUp.rect.w = 50;
        levelTwoLifeBonusPopUp.rect.h = 50;
        levelTwoLifeBonusPopUp.rect.x = levelTwoHeart.rect.x;
        levelTwoLifeBonusPopUp.rect.y = levelTwoHeart.rect.y;
    }
}
