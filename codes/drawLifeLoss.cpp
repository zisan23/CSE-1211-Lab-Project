#include "drawLifeLoss.h"

//funtion to control the effects after losing a life
void lifeUpdateAnimation()
{
    //setting the speed of the life loss balloon
    L1LifeAnimSpeed[0] -= 3;
    if (L1LifeAnimSpeed[0] < 10)
    {
        L1LifeAnimSpeed[0] = 700;
        //setting life loss rect to zero whenever new window comes
        L1_LifeLoss[0].rect.w = (int)0;
        L1_LifeLoss[0].rect.h = (int)0;
    }
    L1LifeAnimSpeed[1] -= 3;
    if (L1LifeAnimSpeed[1] < -10)
    {
        L1LifeAnimSpeed[1] = 700;
        L1_LifeLoss[1].rect.w = (int)0;
        L1_LifeLoss[1].rect.h = (int)0;
    }

    L1LifeAnimSpeed[2] -= 3;
    if (L1LifeAnimSpeed[2] < 10)
    {
        L1LifeAnimSpeed[2] = 700;
        L1_LifeLoss[2].rect.w = (int)0;
        L1_LifeLoss[2].rect.h = (int)0;
    }
}
//funtion to render the life losing effect
void levelOneDrawLifeLossFunction()
{
    lifeUpdateAnimation();

    for (int i = 0; i < 3; i++)
    {
        L1_LifeLoss[i].rect.y = L1LifeAnimSpeed[i];
        L1_LifeLoss[i].rect.x = 700;
        SDL_RenderCopy(app.rend, L1_LifeLoss[i].tex, NULL, &L1_LifeLoss[i].rect);

        
    }
}
