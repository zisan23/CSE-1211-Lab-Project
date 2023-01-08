#include "drawCreditWindow.h"

void drawCreditWindowFunction()
{
    
    SDL_RenderCopy(app.rend, CreditList.tex, NULL, &CreditList.rect);

    SDL_RenderCopy(app.rend, back.tex, NULL, &back.rect);
}
