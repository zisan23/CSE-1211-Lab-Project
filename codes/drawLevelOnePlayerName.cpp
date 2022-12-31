#include "drawLevelOnePlayerName.h"

void drawLevelOnePlayerNameFunction()
{

    SDL_RenderCopy(app.rend, startSky.tex, NULL, &startSky.rect);
    SDL_RenderCopy(app.rend, startGameTitle.tex, NULL, &startGameTitle.rect);
    SDL_RenderCopy(app.rend, back.tex, NULL, &back.rect);
    SDL_RenderCopy(app.rend, enterName.tex, NULL, &enterName.rect);
    SDL_RenderCopy(app.rend, playerNameBox.tex, NULL, &playerNameBox.rect);
    SDL_RenderCopy(app.rend, enterButton.tex, NULL, &enterButton.rect);
    SDL_RenderCopy(app.rend, enterCommand.tex, NULL, &enterCommand.rect);
}
