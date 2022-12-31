#include "drawWelcomeWindow.h"

void drawWelcomeWindowFunction()

{
    SDL_RenderCopy(app.rend, startSky.tex, NULL, &startSky.rect);
    SDL_RenderCopy(app.rend, startGameTitle.tex, NULL, &startGameTitle.rect);
    SDL_RenderCopy(app.rend, start_StartButton.tex, NULL, &start_StartButton.rect);
    SDL_RenderCopy(app.rend, startCreditButton.tex, NULL, &startCreditButton.rect);
    SDL_RenderCopy(app.rend, startScoreBoardButton.tex, NULL, &startScoreBoardButton.rect);
    SDL_RenderCopy(app.rend, startExitButton.tex, NULL, &startExitButton.rect);
}
