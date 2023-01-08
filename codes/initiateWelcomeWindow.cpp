#include "initiateWelcomeWindow.h"

void welcomeWindowLoad(void)
{
    // Starting Window Backgroud Sky

    window.surface = IMG_Load("./images/frontbackground/bg.png");
    if (!window.surface)
    {
        printf("Welcome window sky Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
    startSky.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!startSky.tex)
    {
        printf("Welcome window sky Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(startSky.tex, NULL, NULL, &startSky.rect.w, &startSky.rect.h);
    startSky.rect.w = (int)WINDOW_WIDTH;
    startSky.rect.h = (int)WINDOW_HEIGHT;
    startSky.rect.x = 0;
    startSky.rect.y = 0;
    

   

    // Starting Window Game Logo

    window.surface = IMG_Load("images/riotlogo.png");

    if (!window.surface)
    {
        printf("startGameTitle Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    startGameTitle.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!startGameTitle.tex)
    {
        printf("startGameTitle  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
    SDL_QueryTexture(startGameTitle.tex, NULL, NULL, &startGameTitle.rect.w, &startGameTitle.rect.h);
    
    startGameTitle.rect.w = (int)241;
    startGameTitle.rect.h = (int)181;
    startGameTitle.rect.x = (int)WINDOW_WIDTH / 2 - 120;
    startGameTitle.rect.y = (int)WINDOW_HEIGHT / 2 - 460;
    
    
    

     ///Start game button

    window.surface = IMG_Load("images/buttons/StartButton.png");

    if (!window.surface)
    {
        printf("start_StartButton Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    start_StartButton.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!start_StartButton.tex)
    {
        printf("start_StartButton  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(start_StartButton.tex, NULL, NULL, &start_StartButton.rect.w, &start_StartButton.rect.h);
    start_StartButton.rect.w = (int)310;
    start_StartButton.rect.h = (int)150;
    start_StartButton.rect.x = (int)WINDOW_WIDTH / 2 + 180;
    start_StartButton.rect.y = (int)WINDOW_HEIGHT / 2 - 100;

    // Starting Window ScoreBoard  Button

    window.surface = IMG_Load("images/buttons/ScoreBoard.png");

    if (!window.surface)
    {
        printf("startScoreBoardButton Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    startScoreBoardButton.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!startScoreBoardButton.tex)
    {
        printf("startScoreBoardButton  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(startScoreBoardButton.tex, NULL, NULL, &startScoreBoardButton.rect.w, &startScoreBoardButton.rect.h);
    startScoreBoardButton.rect.w = (int)250;
    startScoreBoardButton.rect.h = (int)70;
    startScoreBoardButton.rect.x = (int)700;
    startScoreBoardButton.rect.y = (int)850;

    // Starting Window Credit  Button

    window.surface = IMG_Load("images/buttons/CreditButton.png");

    if (!window.surface)
    {
        printf("startCreditButton Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    startCreditButton.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!startCreditButton.tex)
    {
        printf("startCreditButton  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(startCreditButton.tex, NULL, NULL, &startCreditButton.rect.w, &startCreditButton.rect.h);
    startCreditButton.rect.w = (int)250;
    startCreditButton.rect.h = (int)70;
    startCreditButton.rect.x = (int)1000;
    startCreditButton.rect.y = (int)850;

    //Starting Window Exit Button

    window.surface = IMG_Load("images/buttons/ExitButton.png");

    if (!window.surface)
    {
        printf("startExitButton Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    startExitButton.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!startExitButton.tex)
    {
        printf("startExitButton  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(startExitButton.tex, NULL, NULL, &startExitButton.rect.w, &startExitButton.rect.h);
    startExitButton.rect.w = (int)250;
    startExitButton.rect.h = (int)70;
    startExitButton.rect.x = (int)20;
    startExitButton.rect.y = (int)850;
}

void welcomeWindowCleanUp() // cleaning up components textures and surfaces
{

    SDL_DestroyTexture(startSky.tex);  
    SDL_DestroyTexture(startMountain.tex);
    SDL_DestroyTexture(startTrees.tex);
    SDL_DestroyTexture(startGameTitle.tex);
    SDL_DestroyTexture(start_StartButton.tex);
    SDL_DestroyTexture(startScoreBoardButton.tex);
    SDL_DestroyTexture(startCreditButton.tex);
    SDL_DestroyTexture(startExitButton.tex);
    IMG_Quit();
}
