#include "initiateLevelOneGameOver.h"

//funtion to load GameOver message
void levelOneGameOverLoad(void)
{

    window.surface = IMG_Load("images/levelone/gameover.png");

    if (!window.surface)
    {
        printf("L1_GameOverMessage Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
	SDL_SetColorKey(window.surface, SDL_TRUE, SDL_MapRGB(window.surface->format, 255, 255, 255));
	
    L1_GameOverMessage.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!L1_GameOverMessage.tex)
    {
        printf("L1_GameOverMessage  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(L1_GameOverMessage.tex, NULL, NULL, &L1_GameOverMessage.rect.w, &L1_GameOverMessage.rect.h);

    L1_GameOverMessage.rect.w = (int)400;
    L1_GameOverMessage.rect.h = (int)503;
    L1_GameOverMessage.rect.x = (int)WINDOW_WIDTH / 2 - 187;
    L1_GameOverMessage.rect.y = (int)WINDOW_HEIGHT / 2 -350;
}
//function to destroy texture of gameover message
void levelOneGameOverCleanUp()
{

    SDL_DestroyTexture(L1_GameOverMessage.tex);
    IMG_Quit();
}
