#include "drawLevelTwoScoreBoard.h"


void drawLevelTwoScoreBoardFunction()
{
    SDL_RenderCopy(app.rend, levelTwoScoreBoard.tex, NULL, &levelTwoScoreBoard.rect);
    for (int i = 0; i < 5; i++)
    {
        SDL_RenderCopy(app.rend, levelTwoScoreBoardPlayerName[i].tex, NULL, &levelTwoScoreBoardPlayerName[i].rect);
        SDL_RenderCopy(app.rend, levelTwoScoreBoardPlayerScore[i].tex, NULL, &levelTwoScoreBoardPlayerScore[i].rect);
    }
    SDL_RenderCopy(app.rend, startGameTitle.tex, NULL, &startGameTitle.rect);
    SDL_RenderCopy(app.rend, back.tex, NULL, &back.rect);
}
