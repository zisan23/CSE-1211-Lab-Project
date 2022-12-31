#include "initiateScoreBoardHub.h"

void LegendsWindowLoad(void) // creating scoreboards button options for players
{
    // level 1 Button

    window.surface = IMG_Load("images/buttons/Level1_Button.png");

    if (!window.surface)
    {
        printf("L1_ScoreButton Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    L1_ScoreButton.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!L1_ScoreButton.tex)
    {
        printf("L1_ScoreButton  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(L1_ScoreButton.tex, NULL, NULL, &L1_ScoreButton.rect.w, &L1_ScoreButton.rect.h);
    L1_ScoreButton.rect.w = (int)532;
    L1_ScoreButton.rect.h = (int)77;
    L1_ScoreButton.rect.x = (int)WINDOW_WIDTH / 2 - 266;
    L1_ScoreButton.rect.y = (int)WINDOW_HEIGHT / 2 - 200;

    // level 2 Button

    window.surface = IMG_Load("images/buttons/Level2_Button.png");

    if (!window.surface)
    {
        printf("L2_ScoreButtonn Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    L2_ScoreButtonn.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!L2_ScoreButtonn.tex)
    {
        printf("L2_ScoreButtonn  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(L2_ScoreButtonn.tex, NULL, NULL, &L2_ScoreButtonn.rect.w, &L2_ScoreButtonn.rect.h);
    L2_ScoreButtonn.rect.w = (int)532;
    L2_ScoreButtonn.rect.h = (int)77;
    L2_ScoreButtonn.rect.x = (int)WINDOW_WIDTH / 2 - 266;
    L2_ScoreButtonn.rect.y = (int)WINDOW_HEIGHT / 2 - 100;
}

void LegendsWindowCleanUp()
{

    SDL_DestroyTexture(L1_ScoreButton.tex);
    SDL_DestroyTexture(L2_ScoreButtonn.tex);
    IMG_Quit();
}
