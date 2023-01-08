#include "drawLevelTwoPlayerName.h"


void drawLevelTwoPlayerNameFunction()
{
    SDL_RenderCopy(app.rend, startSky.tex, NULL, &startSky.rect);
    SDL_RenderCopy(app.rend, startGameTitle.tex, NULL, &startGameTitle.rect);
    SDL_RenderCopy(app.rend, back.tex, NULL, &back.rect);
    SDL_RenderCopy(app.rend, L2_EnterName.tex, NULL, &L2_EnterName.rect);
    SDL_RenderCopy(app.rend, L2_PlayerName_Box.tex, NULL, &L2_PlayerName_Box.rect);
    SDL_RenderCopy(app.rend, L2_EnterButton.tex, NULL, &L2_EnterButton.rect);
    SDL_RenderCopy(app.rend, L2_Enter_Command.tex, NULL, &L2_Enter_Command.rect);
}
