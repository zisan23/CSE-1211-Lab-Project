#include "drawScoreBoardHub.h"

void drawLegendsWindowFunction()
{
   
    SDL_RenderCopy(app.rend, startSky.tex, NULL, &startSky.rect);
    SDL_RenderCopy(app.rend, startGameTitle.tex, NULL, &startGameTitle.rect);
    SDL_RenderCopy(app.rend, L1_ScoreButton.tex, NULL, &L1_ScoreButton.rect);
    SDL_RenderCopy(app.rend, L2_ScoreButtonn.tex, NULL, &L2_ScoreButtonn.rect);
    SDL_RenderCopy(app.rend, back.tex, NULL, &back.rect);
}
