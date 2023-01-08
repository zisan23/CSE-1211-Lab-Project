#include "drawObstacle.h"

//function to control the speeeds of the obstacles
void levelOneObstacleUpdateAnimation()
{

    L1ObstacleAnimSpeed[0] -= 5;
    //reloading the obstacles everytime new window arrives
    if (L1ObstacleAnimSpeed[0] < -WINDOW_WIDTH - 100)
    {
        L1ObstacleAnimSpeed[0] = WINDOW_WIDTH + 100;
        L1WindowObs[0].rect.w = (int)160;
        L1WindowObs[0].rect.h = (int)140;
    }
    L1ObstacleAnimSpeed[1] -= 5;
    if (L1ObstacleAnimSpeed[1] < -WINDOW_WIDTH - 100)
    {
        L1ObstacleAnimSpeed[1] = WINDOW_WIDTH * 2;
        L1WindowObs[1].rect.w = (int)224;
        L1WindowObs[1].rect.h = (int)136;
    }

    L1ObstacleAnimSpeed[2] -= 5;
    if (L1ObstacleAnimSpeed[2] < -WINDOW_WIDTH - 100)
    {
        L1ObstacleAnimSpeed[2] = WINDOW_WIDTH * 3;
        L1WindowObs[2].rect.w = (int)285;
        L1WindowObs[2].rect.h = (int)259;
    }
}
//funtion to load the obstacle animations
void levelOneDrawObstacleFunction()
{
    levelOneObstacleUpdateAnimation();
    //rendering the obstacles
    for (int i = 0; i < 3; i++)
    {
        L1WindowObs[i].rect.x = L1ObstacleAnimSpeed[i] + 500 * i;
        SDL_RenderCopy(app.rend, L1WindowObs[i].tex, NULL, &L1WindowObs[i].rect);
    }
}
