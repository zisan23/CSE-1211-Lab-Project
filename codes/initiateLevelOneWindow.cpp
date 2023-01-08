#include "initiateLevelOneWindow.h"

void levelOneWindowLoad(void)
{
    //sky load

    window.surface = IMG_Load("images/levelone/violet_sky.png");

    if (!window.surface)
    {
        printf("L1WindowSky Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    L1WindowSky.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!L1WindowSky.tex)
    {
        printf("sky_  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(L1WindowSky.tex, NULL, NULL, &L1WindowSky.rect.w, &L1WindowSky.rect.h);
    L1WindowSky.rect.w = (int)WINDOW_WIDTH;
    L1WindowSky.rect.h = (int)WINDOW_HEIGHT;
    L1WindowSky.rect.x = (int)0;
    L1WindowSky.rect.y = (int)0;

    //moon/infinite tsukuyomi load
    window.surface = IMG_Load("images/levelone/Moon.png");

    if (!window.surface)
    {
        printf("L1WindowMoon Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    L1WindowMoon.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!L1WindowMoon.tex)
    {
        printf("L1WindowMoon  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(L1WindowMoon.tex, NULL, NULL, &L1WindowMoon.rect.w, &L1WindowMoon.rect.h);
    L1WindowMoon.rect.w = (int)700;
    L1WindowMoon.rect.h = (int)400;
    L1WindowMoon.rect.x = WINDOW_WIDTH / 2 + 100;
    L1WindowMoon.rect.y = 20;


    //clouds load
    window.surface = IMG_Load("images/levelone/clouds-min.png");

    if (!window.surface)
    {
        printf("L1WindowClouds Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    L1WindowClouds.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!L1WindowClouds.tex)
    {
        printf("L1WindowClouds Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(L1WindowClouds.tex, NULL, NULL, &L1WindowClouds.rect.w, &L1WindowClouds.rect.h);
    L1WindowClouds.rect.w = (int)WINDOW_WIDTH - 200;
    L1WindowClouds.rect.h = (int)226;
    L1WindowClouds.rect.x = (int)0;
    L1WindowClouds.rect.y = 50;

    //BUILDINGS load

    window.surface = IMG_Load("images/levelone/building2.png");

    if (!window.surface)
    {
        printf("L1WindowBuildings Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    L1WindowBuildings.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!L1WindowBuildings.tex)
    {
        printf("L1WindowBuildings  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(L1WindowBuildings.tex, NULL, NULL, &L1WindowBuildings.rect.w, &L1WindowBuildings.rect.h);
    L1WindowBuildings.rect.w = (int)WINDOW_WIDTH;
    L1WindowBuildings.rect.h = (int)584;
    L1WindowBuildings.rect.x = (int)0;
    L1WindowBuildings.rect.y = (int)210;

    //ufo1 load
    window.surface = IMG_Load("images/levelone/UFO.png");

    if (!window.surface)
    {
        printf("L1WindowUfo1 Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    L1WindowUfo1.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!L1WindowUfo1.tex)
    {
        printf("L1 UFO1  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(L1WindowUfo1.tex, NULL, NULL, &L1WindowUfo1.rect.w, &L1WindowUfo1.rect.h);
    L1WindowUfo1.rect.w = (int)100;
    L1WindowUfo1.rect.h = (int)100;
    L1WindowUfo1.rect.x = (int)WINDOW_WIDTH;
    L1WindowUfo1.rect.y = (int)150;

    //UFO 1 LOADING
    window.surface = IMG_Load("images/levelone/UFO1.png");

    if (!window.surface)
    {
        printf("L1WindowUfo2 Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    L1WindowUfo2.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!L1WindowUfo2.tex)
    {
        printf("L1WindowUfo2  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(L1WindowUfo2.tex, NULL, NULL, &L1WindowUfo2.rect.w, &L1WindowUfo2.rect.h);
    L1WindowUfo2.rect.w = (int)100;
    L1WindowUfo2.rect.h = (int)80;
    L1WindowUfo2.rect.x = (int)WINDOW_WIDTH + 200;
    L1WindowUfo2.rect.y = (int)20;

    //track load
    window.surface = IMG_Load("images/levelone/trackLv1.png");

    if (!window.surface)
    {
        printf("L1WindowTrack Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    L1WindowTrack.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!L1WindowTrack.tex)
    {
        printf("track Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(L1WindowTrack.tex, NULL, NULL, &L1WindowTrack.rect.w, &L1WindowTrack.rect.h);
    L1WindowTrack.rect.w = (int)WINDOW_WIDTH;
    L1WindowTrack.rect.h = (int)200;
    L1WindowTrack.rect.x = (int)0;
    L1WindowTrack.rect.y = (int)790;



    //character load
    window.surface = IMG_Load("images/levelone/run2.png");

    if (!window.surface)
    {
        printf("L1WindowChar Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    L1WindowChar.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!L1WindowChar.tex)
    {
        printf("L1WindowChar Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(L1WindowChar.tex, NULL, NULL, &L1CharTexturewidth, &L1CharTextureheight);
    L1CharFramewidth = L1CharTexturewidth / 4 + 1;
    L1CharFrameheight = L1CharTextureheight / 2;
    L1WindowChar.rect.w = L1CharFramewidth;
    L1WindowChar.rect.h = L1CharFrameheight;
    L1WindowChar.rect.x = 0;
    L1WindowChar.rect.y = 0;
    charFramePos.rect.w = L1CharFramewidth - 140;// character sprite mota hoy plus korle, cikon hoy minus korle
    charFramePos.rect.h = L1CharFrameheight - 180;
    charFramePos.rect.x = L1CharXpos;
    charFramePos.rect.y = 0;

    //score load
    window.surface = IMG_Load("images/levelone/reward_main.png");

    if (!window.surface)
    {
        printf("levelOneWindowScore Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelOneWindowScore.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!levelOneWindowScore.tex)
    {
        printf("levelOneWindowScore Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(levelOneWindowScore.tex, NULL, NULL, &levelOneWindowScore.rect.w, &levelOneWindowScore.rect.h);
    levelOneWindowScore.rect.w = (int)35;
    levelOneWindowScore.rect.h = (int)40;
    levelOneWindowScore.rect.x = (int)60;
    levelOneWindowScore.rect.y = (int)33;

    //highScore load
    window.surface = IMG_Load("images/levelone/HighScore.png");

    if (!window.surface)
    {
        printf("levelOneWindowHighScore Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelOneWindowHighScore.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!levelOneWindowHighScore.tex)
    {
        printf("levelOneWindowHighScore Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(levelOneWindowHighScore.tex, NULL, NULL, &levelOneWindowHighScore.rect.w, &levelOneWindowHighScore.rect.h);
    levelOneWindowHighScore.rect.w = (int)300;
    levelOneWindowHighScore.rect.h = (int)40;
    levelOneWindowHighScore.rect.x = (int)80;
    levelOneWindowHighScore.rect.y = (int)105;

    //finishline load
    window.surface = IMG_Load("images/levelone/finish.png");

    if (!window.surface)
    {
        printf("L1Finishline Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    L1Finishline.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!L1Finishline.tex)
    {
        printf("L1Finishline Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(L1Finishline.tex, NULL, NULL, &L1Finishline.rect.w, &L1Finishline.rect.h);
    L1Finishline.rect.w = (int)200;
    L1Finishline.rect.h = (int)600;
    L1Finishline.rect.x = (int)L1FinishlinePos;
    L1Finishline.rect.y = (int)260;

    //initialInstruction load

    window.surface = IMG_Load("images/newcomponents/instruction.png");

    if (!window.surface)
    {
        printf("initial Instructions Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    initialInstructions.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!initialInstructions.tex)
    {
        printf("initial InstructionsTexture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(initialInstructions.tex, NULL, NULL, &initialInstructions.rect.w, &initialInstructions.rect.h);
    initialInstructions.rect.w = (int)WINDOW_WIDTH;
    initialInstructions.rect.h = (int)WINDOW_HEIGHT;
    initialInstructions.rect.x = (int)0;
    initialInstructions.rect.y = (int)0;

    //function calling to load rewards and obstacles and effects

    levelOneCoinsLoad();
    levelOneObstacleLoad();
    levelOneCoinsEffectLoad();
    levelOneLifeLoad();
    L1_LifeLossLoad();
    updateScore();
}
// function to destroy all the textures used
void levelOneWindowCleanUp()
{

    SDL_DestroyTexture(L1WindowSky.tex);
    SDL_DestroyTexture(L1WindowBuildings.tex);
    SDL_DestroyTexture(L1WindowUfo1.tex);
    SDL_DestroyTexture(L1WindowUfo2.tex);
    SDL_DestroyTexture(L1WindowClouds.tex);
    SDL_DestroyTexture(L1WindowTrack.tex);
    SDL_DestroyTexture(L1WindowChar.tex);
    SDL_DestroyTexture(initialInstructions.tex);
    SDL_DestroyTexture(levelOneWindowScore.tex);
    SDL_DestroyTexture(levelOneWindowHighScore.tex);
    SDL_DestroyTexture(L1Finishline.tex);
    SDL_DestroyTexture(L1WindowMoon.tex);
    IMG_Quit();
}
