#include "initiateLevelTwoCompleted.h"

void levelTwoCompletedLoad(void) // if player completes the game , overlay with a message apears
{
    // Overlay Load

    window.surface = IMG_Load("images/levelone/overlay-min.png");

    if (!window.surface)
    {
        printf("L2_CompletedOverlay Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    L2_CompletedOverlay.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!L2_CompletedOverlay.tex)
    {
        printf("L2_CompletedOverlay Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(L2_CompletedOverlay.tex, NULL, NULL, &L2_CompletedOverlay.rect.w, &L2_CompletedOverlay.rect.h);
    L2_CompletedOverlay.rect.w = (int)WINDOW_WIDTH;
    L2_CompletedOverlay.rect.h = (int)WINDOW_HEIGHT;
    L2_CompletedOverlay.rect.x = (int)0;
    L2_CompletedOverlay.rect.y = (int)0;

     //level two completed message
    window.surface = IMG_Load("images/newcomponents/trophy.png");

    if (!window.surface)
    {
        printf("L2_CompletedMsg Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    L2_CompletedMsg.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!L2_CompletedMsg.tex)
    {
        printf("L2_CompletedMsg Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(L2_CompletedMsg.tex, NULL, NULL, &L2_CompletedMsg.rect.w, &L2_CompletedMsg.rect.h);
    L2_CompletedMsg.rect.w = (int)460;
    L2_CompletedMsg.rect.h = (int)406;
    L2_CompletedMsg.rect.x = WINDOW_WIDTH / 2 - 230;
    L2_CompletedMsg.rect.y = WINDOW_HEIGHT / 2 - 203;
}

void levelTwoCompletedCleanUp()
{
    SDL_DestroyTexture(L2_CompletedOverlay.tex);
    SDL_DestroyTexture(L2_CompletedMsg.tex);
    IMG_Quit();
}
