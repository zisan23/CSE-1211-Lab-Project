#include "initiateLevelOneCompleted.h"

// funtion to load levelOne completed message
void levelOneCompletedLoad(void)
{
    // overlay load

    window.surface = IMG_Load("images/levelone/overlay-min.png");

    if (!window.surface)
    {
        printf("L1Completed_Overlay Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    L1Completed_Overlay.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!L1Completed_Overlay.tex)
    {
        printf("L1Completed_Overlay  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(L1Completed_Overlay.tex, NULL, NULL, &L1Completed_Overlay.rect.w, &L1Completed_Overlay.rect.h);
    L1Completed_Overlay.rect.w = (int)WINDOW_WIDTH;
    L1Completed_Overlay.rect.h = (int)WINDOW_HEIGHT;
    L1Completed_Overlay.rect.x = (int)0;
    L1Completed_Overlay.rect.y = (int)0;

    // texture load  when the finishline is reached
    window.surface = IMG_Load("images/newcomponents/trophy.png");

    if (!window.surface)
    {
        printf("levelOneCompletedMessage Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelOneCompletedMessage.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!levelOneCompletedMessage.tex)
    {
        printf("levelOneCompletedMessage  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(levelOneCompletedMessage.tex, NULL, NULL, &levelOneCompletedMessage.rect.w, &levelOneCompletedMessage.rect.h);
    levelOneCompletedMessage.rect.w = (int)460;
    levelOneCompletedMessage.rect.h = (int)406;
    levelOneCompletedMessage.rect.x = WINDOW_WIDTH / 2 - 230;
    levelOneCompletedMessage.rect.y = WINDOW_HEIGHT / 2 - 203;
}
// funtion to destroy textures of levelOne completed
void levelOneCompletedCleanUp()
{

    SDL_DestroyTexture(L1Completed_Overlay.tex);
    SDL_DestroyTexture(levelOneCompletedMessage.tex);
    IMG_Quit();
}
