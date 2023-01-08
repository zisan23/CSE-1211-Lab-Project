#include "updateLevelTwoPlayerName.h"

void updateLevelTwoPlayerName()
{

    //Player Name

    L2_EnterName.surface = TTF_RenderText_Solid(variables.font, levelTwoPlayerName, variables.color);

    if (!L2_EnterName.surface)
    {
        printf("level 2 Enter Name Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
    L2_EnterName.tex = SDL_CreateTextureFromSurface(app.rend, L2_EnterName.surface);

    if (!L2_EnterName.tex)
    {
        printf("L2_EnterName  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(L2_EnterName.tex, NULL, NULL, &L2_EnterName.rect.w, &L2_EnterName.rect.h);
    L2_EnterName.rect.w = (int)L2_EnterName.surface->w;
    L2_EnterName.rect.h = (int)L2_EnterName.surface->h;
    L2_EnterName.rect.x = (int)WINDOW_WIDTH / 2 - 55;
    L2_EnterName.rect.y = (int)405;

    // Keeping name in frame for larger names

    if (strlen(levelTwoPlayerName) > 7)
    {
        L2_EnterName.rect.x -= 25;
    }

    //Box to enter Player Name

    window.surface = IMG_Load("images/buttons/name_square.png");

    if (!window.surface)
    {
        printf("L2_PlayerName_Box Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    L2_PlayerName_Box.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);

    SDL_FreeSurface(window.surface);

    if (!L2_PlayerName_Box.tex)
    {
        printf("L2_PlayerName_Box  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(L2_PlayerName_Box.tex, NULL, NULL, &L2_PlayerName_Box.rect.w, &L2_PlayerName_Box.rect.h);
    L2_PlayerName_Box.rect.w = (int)374;
    L2_PlayerName_Box.rect.h = (int)66;
    L2_PlayerName_Box.rect.x = (int)WINDOW_WIDTH / 2 - 187;
    L2_PlayerName_Box.rect.y = (int)385;

    //Level 2 Players Name Enter Button

    window.surface = IMG_Load("images/buttons/EnterButton.png");

    if (!window.surface)
    {
        printf("L2_EnterButton Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    L2_EnterButton.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!L2_EnterButton.tex)
    {
        printf("L2_EnterButton  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(L2_EnterButton.tex, NULL, NULL, &L2_EnterButton.rect.w, &L2_EnterButton.rect.h);
    L2_EnterButton.rect.w = (int)238;
    L2_EnterButton.rect.h = (int)69;
    L2_EnterButton.rect.x = (int)WINDOW_WIDTH / 2 - 119;
    L2_EnterButton.rect.y = (int)WINDOW_HEIGHT / 2;

    //Level 2 PlayerS name Enter button Command

    window.surface = IMG_Load("images/enterYourName.png");

    if (!window.surface)
    {
        printf("L2_EnterButtonBUTTON Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    L2_Enter_Command.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!L2_Enter_Command.tex)
    {
        printf("L2_Enter_Command  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
    L2_Enter_Command.rect;
    SDL_QueryTexture(L2_Enter_Command.tex, NULL, NULL, &L2_Enter_Command.rect.w, &L2_Enter_Command.rect.h);
    L2_Enter_Command.rect.w = (int)384;
    L2_Enter_Command.rect.h = (int)73;
    L2_Enter_Command.rect.x = (int)WINDOW_WIDTH / 2 - 192;
    L2_Enter_Command.rect.y = (int)WINDOW_HEIGHT / 2 - 200;
}

void levelTwoPlayerNameCleanUp() //function to freeup the textures of updating player name
{
    SDL_DestroyTexture(L2_EnterName.tex);
    SDL_DestroyTexture(L2_EnterButton.tex);
    SDL_DestroyTexture(L2_PlayerName_Box.tex);
    SDL_DestroyTexture(L2_Enter_Command.tex);
    SDL_FreeSurface(L2_EnterName.surface);
}
