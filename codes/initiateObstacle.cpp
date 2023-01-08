#include "initiateObstacle.h"

//function to load obstacles of levelone
void levelOneObstacleLoad(void)
{
    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            window.surface = IMG_Load("images/levelone/obstacles/zombie1.png");
            if (!window.surface)
            {
                printf("Obstacle[i] Error: %s\n", IMG_GetError());
                SDL_DestroyRenderer(app.rend);
                SDL_DestroyWindow(app.window);
                SDL_Quit();
                exit(1);
            }

            L1WindowObs[i].tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
            SDL_FreeSurface(window.surface);
            if (!L1WindowObs[i].tex)
            {
                printf("Obstacle[i] Texture %s\n", SDL_GetError());
                SDL_DestroyRenderer(app.rend);
                SDL_DestroyWindow(app.window);
                SDL_Quit();
                exit(1);
            }

            SDL_QueryTexture(L1WindowObs[i].tex, NULL, NULL, &L1WindowObs[i].rect.w, &L1WindowObs[i].rect.h);
            L1WindowObs[i].rect.w = (int)160;
            L1WindowObs[i].rect.h = (int)140;
            L1WindowObs[i].rect.x = (int)WINDOW_WIDTH + 100;
            L1WindowObs[i].rect.y = (int)700;
        }

        if (i == 1)
        {
            window.surface = IMG_Load("images/levelone/obstacles/zombie2.png");
            if (!window.surface)
            {
                printf("Obstacle[i] Error: %s\n", IMG_GetError());
                SDL_DestroyRenderer(app.rend);
                SDL_DestroyWindow(app.window);
                SDL_Quit();
                exit(1);
            }

            L1WindowObs[i].tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
            SDL_FreeSurface(window.surface);
            if (!L1WindowObs[i].tex)
            {
                printf("Obstacle[i]_  Texture %s\n", SDL_GetError());
                SDL_DestroyRenderer(app.rend);
                SDL_DestroyWindow(app.window);
                SDL_Quit();
                exit(1);
            }

            SDL_QueryTexture(L1WindowObs[i].tex, NULL, NULL, &L1WindowObs[i].rect.w, &L1WindowObs[i].rect.h);
            L1WindowObs[i].rect.w = (int)224;
            L1WindowObs[i].rect.h = (int)136;
            L1WindowObs[i].rect.x = (int)WINDOW_WIDTH + 100;
            L1WindowObs[i].rect.y = (int)700;
        }

        if (i == 2)
        {
            window.surface = IMG_Load("images/levelone/obstacles/bigZombieboss.png");  ////////need to change for respawn too
            if (!window.surface)
            {
                printf("Obstacle[i] Error: %s\n", IMG_GetError());
                SDL_DestroyRenderer(app.rend);
                SDL_DestroyWindow(app.window);
                SDL_Quit();
                exit(1);
            }

            L1WindowObs[i].tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
            SDL_FreeSurface(window.surface);
            if (!L1WindowObs[i].tex)
            {
                printf("Obstacle[i]  Texture %s\n", SDL_GetError());
                SDL_DestroyRenderer(app.rend);
                SDL_DestroyWindow(app.window);
                SDL_Quit();
                exit(1);
            }

            SDL_QueryTexture(L1WindowObs[i].tex, NULL, NULL, &L1WindowObs[i].rect.w, &L1WindowObs[i].rect.h);
            L1WindowObs[i].rect.w = (int)285;
            L1WindowObs[i].rect.h = (int)259;
            L1WindowObs[i].rect.x = (int)WINDOW_WIDTH*3;
            L1WindowObs[i].rect.y = (int)600;
        }
    }
}

//funtion to destroy the textures of obstacles
void levelOneObstacleCleanUp()
{
    for (int i = 0; i < 3; i++)
    {
        SDL_DestroyTexture(L1WindowObs[i].tex);
    }
}
