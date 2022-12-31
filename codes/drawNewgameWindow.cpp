#include "drawNewgameWindow.h"

void drawNewgameWindowFunction()
{

    SDL_RenderCopy(app.rend, startSky.tex, NULL, &startSky.rect);

    SDL_RenderCopy(app.rend, startGameTitle.tex, NULL, &startGameTitle.rect);
    SDL_RenderCopy(app.rend, LevelChoiceWindowlevel_1_Button.tex, NULL, &LevelChoiceWindowlevel_1_Button.rect);
    SDL_RenderCopy(app.rend, LevelChoiceWindowlevel_2_Button.tex, NULL, &LevelChoiceWindowlevel_2_Button.rect);
    SDL_RenderCopy(app.rend, back.tex, NULL, &back.rect);
}
