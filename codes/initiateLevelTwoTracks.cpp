#include "initiateLevelTwoTracks.h"

void InvisibleBorderLoad()
{   
    for(int i=0; i<2; i++)
    {
        window.surface = IMG_Load("images/level2obstacles/border.png");

    if (!window.surface)
    {
        printf("levelTwoInvisibleBorder Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelTwoInvisibleBorder[i].tex = SDL_CreateTextureFromSurface(app.rend, window.surface);

    SDL_FreeSurface(window.surface);

    if (!levelTwoInvisibleBorder[i].tex)
    {
        printf("levelTwoInvisibleBorder Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(levelTwoInvisibleBorder[i].tex, NULL, NULL, &levelTwoInvisibleBorder[i].rect.w, &levelTwoInvisibleBorder[i].rect.h);
    levelTwoInvisibleBorder[i].rect.w = levelTwoTrack[i].rect.w;
    levelTwoInvisibleBorder[i].rect.h = 30;
    levelTwoInvisibleBorder[i].rect.x = (int)WINDOW_WIDTH / 2;
    levelTwoInvisibleBorder[i].rect.y = (int)WINDOW_HEIGHT / 2 - 100 + 30;

    }
    
}

void InvisibleBorderCleanUp()
{
    for(int i=0; i<2; i++)
    {
       SDL_DestroyTexture(levelTwoInvisibleBorder[i].tex);
    }

    IMG_Quit();
}

void LevelTwoTracksLoad(void)
{
    for(int i=0; i<2; i++)
    {
        window.surface = IMG_Load("images/leveltwo/hell_upper_track.png");

    if (!window.surface)
    {
        printf("levelTwoTrack Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelTwoTrack[i].tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!levelTwoTrack[i].tex)
    {
        printf("levelTwoTrack Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(levelTwoTrack[i].tex, NULL, NULL, &levelTwoTrack[i].rect.w, &levelTwoTrack[i].rect.h);

    levelTwoTrack[i].rect.w = (int)634;
    levelTwoTrack[i].rect.h = (int)105;
    levelTwoTrack[i].rect.x = (int)WINDOW_WIDTH / 2;
    levelTwoTrack[i].rect.y = (int)WINDOW_HEIGHT / 2 - 100;
    
    }
    
    InvisibleBorderLoad();
}

void LevelTwoTracksCleanUp()
{   
    for(int i=0; i<2; i++)
    {
        SDL_DestroyTexture(levelTwoTrack[i].tex);
    }
   
    InvisibleBorderCleanUp();
    IMG_Quit();
}
