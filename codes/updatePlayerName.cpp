#include "updatePlayerName.h"

void updatePlayerName()
{

    // Player Name

    enterName.surface = TTF_RenderText_Solid(variables.font, playerName, variables.color);

    if (!enterName.surface)
    {
        printf("playername Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    enterName.tex = SDL_CreateTextureFromSurface(app.rend, enterName.surface);
    if (!enterName.tex)
    {
        printf("playername  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(enterName.tex, NULL, NULL, &enterName.rect.w, &enterName.rect.h);
    enterName.rect.w = (int)enterName.surface->w;
    enterName.rect.h = (int)enterName.surface->h;
    enterName.rect.x = (int)WINDOW_WIDTH / 2 - 55;
    enterName.rect.y = (int)405;

    // Keeping name in frame for larger names

    if (strlen(playerName) > 7)
    {
        enterName.rect.x -= 25;
    }

    // Box for typing Playername

    window.surface = IMG_Load("images/buttons/name_square.png");

    if (!window.surface)
    {
        printf("playerNameBox Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    playerNameBox.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!playerNameBox.tex)
    {
        printf("playerNameBox  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(playerNameBox.tex, NULL, NULL, &playerNameBox.rect.w, &playerNameBox.rect.h);
    playerNameBox.rect.w = (int)374;
    playerNameBox.rect.h = (int)66;
    playerNameBox.rect.x = (int)WINDOW_WIDTH / 2 - 187;
    playerNameBox.rect.y = (int)385;

    // Enter button

    window.surface = IMG_Load("images/buttons/EnterButton.png");

    if (!window.surface)
    {
        printf("enterButton Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    enterButton.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!enterButton.tex)
    {
        printf("enterButton  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
    enterButton.rect;
    SDL_QueryTexture(enterButton.tex, NULL, NULL, &enterButton.rect.w, &enterButton.rect.h);
    enterButton.rect.w = (int)238;
    enterButton.rect.h = (int)69;
    enterButton.rect.x = (int)WINDOW_WIDTH / 2 - 119;
    enterButton.rect.y = (int)WINDOW_HEIGHT / 2;

    // Enter Command

    window.surface = IMG_Load("images/enterYourName.png");

    if (!window.surface)
    {
        printf("enterCommand Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    enterCommand.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!enterCommand.tex)
    {
        printf("enterCommand  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
    enterCommand.rect;
    SDL_QueryTexture(enterCommand.tex, NULL, NULL, &enterCommand.rect.w, &enterCommand.rect.h);
    enterCommand.rect.w = (int)384;
    enterCommand.rect.h = (int)73;
    enterCommand.rect.x = (int)WINDOW_WIDTH / 2 - 192;
    enterCommand.rect.y = (int)WINDOW_HEIGHT / 2 - 200;
}
void levelOnePlayerNameCleanUp() // cleaning up Components surface and texture
{
    SDL_DestroyTexture(enterName.tex);
    SDL_DestroyTexture(enterButton.tex);
    SDL_DestroyTexture(playerNameBox.tex);
    SDL_DestroyTexture(enterCommand.tex);
    SDL_FreeSurface(enterName.surface);
}
