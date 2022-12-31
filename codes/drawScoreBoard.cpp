#include "drawScoreBoard.h"

void drawScoreBoardFunction()
{

    SDL_RenderCopy(app.rend, scoreBoard.tex, NULL, &scoreBoard.rect);
    for (int i = 0; i < 5; i++)
    {
        SDL_RenderCopy(app.rend, scoreBoardPlayerName[i].tex, NULL, &scoreBoardPlayerName[i].rect);
        SDL_RenderCopy(app.rend, scoreBoardPlayerScore[i].tex, NULL, &scoreBoardPlayerScore[i].rect);
    }
    SDL_RenderCopy(app.rend, startGameTitle.tex, NULL, &startGameTitle.rect);
    SDL_RenderCopy(app.rend, back.tex, NULL, &back.rect);
}
