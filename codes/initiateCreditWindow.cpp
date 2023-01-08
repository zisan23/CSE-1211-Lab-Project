#include "initiateCreditWindow.h"

void CreditWindowLoad(void)
{

    window.surface = IMG_Load("images/newcomponents/Credit.png");

    if (!window.surface)
    {
        printf("CreditList Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    CreditList.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!CreditList.tex)
    {
        printf("CreditList  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
    SDL_QueryTexture(CreditList.tex, NULL, NULL, &CreditList.rect.w, &CreditList.rect.h);
    CreditList.rect.w = (int)WINDOW_WIDTH;
    CreditList.rect.h = (int)WINDOW_HEIGHT;
    CreditList.rect.x = (int)0;
    CreditList.rect.y = (int)0;
}
void CreditWindowCleanUp()
{

    SDL_DestroyTexture(CreditList.tex);
    IMG_Quit();
}
