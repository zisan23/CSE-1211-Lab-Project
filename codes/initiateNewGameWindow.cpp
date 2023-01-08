#include "initiateNewGameWindow.h"

void newgameWindowLoad(void)
{
    //Level 1 Button

    window.surface = IMG_Load("images/buttons/Level1_Button.png");

    if (!window.surface)
    {
        printf("LevelChoiceWindowlevel_1_Button Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    LevelChoiceWindowlevel_1_Button.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!LevelChoiceWindowlevel_1_Button.tex)
    {
        printf("LevelChoiceWindowlevel_1_Button  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(LevelChoiceWindowlevel_1_Button.tex, NULL, NULL, &LevelChoiceWindowlevel_1_Button.rect.w, &LevelChoiceWindowlevel_1_Button.rect.h);
    LevelChoiceWindowlevel_1_Button.rect.w = (int)200;
    LevelChoiceWindowlevel_1_Button.rect.h = (int)150;
    LevelChoiceWindowlevel_1_Button.rect.x = (int)390;
    LevelChoiceWindowlevel_1_Button.rect.y = (int)355;

    //Level 2 Button

    window.surface = IMG_Load("images/buttons/Level2_Button.png");

    if (!window.surface)
    {
        printf("LevelChoiceWindowlevel_2_Button Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    LevelChoiceWindowlevel_2_Button.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!LevelChoiceWindowlevel_2_Button.tex)
    {
        printf("LevelChoiceWindowlevel_2_Button  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(LevelChoiceWindowlevel_2_Button.tex, NULL, NULL, &LevelChoiceWindowlevel_2_Button.rect.w, &LevelChoiceWindowlevel_2_Button.rect.h);
    LevelChoiceWindowlevel_2_Button.rect.w = (int)200;
    LevelChoiceWindowlevel_2_Button.rect.h = (int)150;
    LevelChoiceWindowlevel_2_Button.rect.x = (int)690;
    LevelChoiceWindowlevel_2_Button.rect.y = (int)355;
}

void newGameWindowCleanUp()
{

    SDL_DestroyTexture(LevelChoiceWindowlevel_1_Button.tex);
    SDL_DestroyTexture(LevelChoiceWindowlevel_2_Button.tex);
    IMG_Quit();
}
