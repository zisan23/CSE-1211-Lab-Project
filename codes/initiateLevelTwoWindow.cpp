#include "initiateLevelTwoWindow.h"

void levelTwoWindowLoad(void)
{
    // level 2 Sky load

    window.surface = IMG_Load("images/leveltwo/hell_bg.png");

    if (!window.surface)
    {
        printf("level 2 Sky error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    L2_WindowSky.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!L2_WindowSky.tex)
    {
        printf("level 2 Sky Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(L2_WindowSky.tex, NULL, NULL, &L2_WindowSky.rect.w, &L2_WindowSky.rect.h);
    L2_WindowSky.rect.w = (int)WINDOW_WIDTH;
    L2_WindowSky.rect.h = (int)WINDOW_HEIGHT;
    L2_WindowSky.rect.x = (int)0;
    L2_WindowSky.rect.y = (int)0;

   

    //level 2 WindowTrack load
    window.surface = IMG_Load("images/leveltwo/hell_lower_track.png");

    if (!window.surface)
    {
        printf("L2_WindowTrack Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    L2_WindowTrack.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!L2_WindowTrack.tex)
    {
        printf("L2_WindowTrack Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(L2_WindowTrack.tex, NULL, NULL, &L2_WindowTrack.rect.w, &L2_WindowTrack.rect.h);
    L2_WindowTrack.rect.w = (int)WINDOW_WIDTH;
    L2_WindowTrack.rect.h = (int)200;
    L2_WindowTrack.rect.x = (int)0;
    L2_WindowTrack.rect.y = (int)760;

    // level 2 Window Character load
    L2_WindowChar.surface = IMG_Load("images/level2obstacles/run2.png");

    if (!L2_WindowChar.surface)
    {
        printf("L2_WindowChar Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    L2_WindowChar.tex = SDL_CreateTextureFromSurface(app.rend, L2_WindowChar.surface);

    if (!L2_WindowChar.tex)
    {
        printf("L2_WindowChar Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(L2_WindowChar.tex, NULL, NULL, &L2_CharTextureHeight, &L2_CharTextureWidth);

    L2_CharFrameWidth = L2_CharTextureWidth / 2;
    L2_CharFrameHeight = L2_CharTextureHeight / 2;
    L2_WindowChar.rect.w = L2_CharFrameWidth;
    L2_WindowChar.rect.h = L2_CharFrameHeight;
    L2_WindowChar.rect.x = 0;
    L2_WindowChar.rect.y = 0;
    L2_WindowCharPosition.rect.w = L2_CharFrameWidth;
    L2_WindowCharPosition.rect.h = L2_CharFrameHeight;
    L2_WindowCharPosition.rect.x = 30;
    L2_WindowCharPosition.rect.y = 720;
    float CHARACTER2_X_POS = (float)100;
    float CHARACTER2_Y_POS = (float)700;

    // L2_Finishline load

    window.surface = IMG_Load("images/newcomponents/gate.png");

    if (!window.surface)
    {
        printf("levelTwoL2_Finishline Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    L2_Finishline.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!L2_Finishline.tex)
    {
        printf("levelTwoL2_Finishline Texture Error %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(L2_Finishline.tex, NULL, NULL, &L2_Finishline.rect.w, &L2_Finishline.rect.h);
    L2_Finishline.rect.w = (int)1000;
    L2_Finishline.rect.h = (int)950;
    L2_Finishline.rect.x = (int)finishlineForLevelTwo;
    L2_Finishline.rect.y = (int)0;

    LevelTwoTracksLoad();
    LevelTwoCoinsload();
    BossUFOLoad();
    LevelTwoLifeLoad();
    updateLevelTwoScore();
}

void levelTwoWindowCleanUp()
{
    SDL_DestroyTexture(L2_WindowSky.tex);
    SDL_DestroyTexture(L2_WindowTrack.tex);
    SDL_FreeSurface(L2_WindowChar.surface);
    SDL_DestroyTexture(L2_WindowChar.tex);
    LevelTwoTracksCleanUp();
    LevelTwoCoinsCleanUp();
    BossUFOCleanUp();
    HeartCleanUp();
    IMG_Quit();
}
