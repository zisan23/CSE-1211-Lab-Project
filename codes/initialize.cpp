#include "initialize.h"

void initSDL(void)
{

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO) < 0)
    {
        printf("video and timer: %s\n", SDL_GetError());
    }
    if (TTF_Init() < 0)
    {
        printf("Text: Can't laod %s\n", SDL_GetError());
    }
    if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)))
        printf("image: %s\n", SDL_GetError());

    app.window = SDL_CreateWindow("R . I. O . T .", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE); /*SDL_WINDOW_RESIZABLE = makes the window compitable with the monitor  */

    if (!app.window)
    {
        printf("window: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    app.rend = SDL_CreateRenderer(app.window, -1, render_flags);

    if (!app.rend)
    {
        printf("renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
    // loading fonts and setting colors

    variables.font = TTF_OpenFont("TTF_FONT.otf", 30); // opening fonts
    variables.color = {255, 0, 0};
    variables.levelTwofont = TTF_OpenFont("TTF_FONT.otf", 30);
    variables.levelTwocolor = {255, 0, 0};

    // loading All musics for all levels

    Mix_OpenAudioDevice(44100, MIX_DEFAULT_FORMAT, 2, 2048, NULL, SDL_AUDIO_ALLOW_FREQUENCY_CHANGE | SDL_AUDIO_ALLOW_CHANNELS_CHANGE);
    background_music = Mix_LoadMUS("audio/narutosong.mp3");             // initial background music
    doom_ost = Mix_LoadMUS("audio/doom_theOnlyThingTheyFearIsYou.mp3"); // BG MUSIC FOR LV 2
    IndianaJones = Mix_LoadMUS("audio/IndianaJones.mp3");               // during game background music FOR LV 1
    coingain = Mix_LoadWAV("audio/coingain.wav");
    explosionsound = Mix_LoadWAV("audio/explosionsound.wav");
    jumpsound = Mix_LoadWAV("audio/jump.wav");
    pointgainsound = Mix_LoadWAV("audio/pointgain.wav");
    hitLevelOne = Mix_LoadWAV("audio/hitLevelOne.wav");
    levelOneCoingain = Mix_LoadWAV("audio/levelOneCoinGain.wav");

    gameOver = Mix_LoadWAV("audio/game_over_sound.wav");
    click = Mix_LoadWAV("audio/click.wav");

    // Back button initialization

    window.surface = IMG_Load("images/back.png"); /* the back button the level choosing page */

    if (!window.surface)
    {
        printf("Back Button Error Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    back.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!back.tex)
    {
        printf("Back Button Error  Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(back.tex, NULL, NULL, &back.rect.w, &back.rect.h);
    back.rect.w = (int)70;
    back.rect.h = (int)60;
    back.rect.x = (int)45;
    back.rect.y = (int)25;

    // function calls to load other game windows

    SDL_StartTextInput();

    welcomeWindowLoad();

    newgameWindowLoad();

    updatePlayerName();
    updateLevelTwoPlayerName();

    levelOneWindowLoad();

    levelTwoWindowLoad();

    levelOneCompletedLoad();
    levelTwoCompletedLoad();

    levelOneGameOverLoad();

    scoreboard();
    levelTwoScoreboard();

    LegendsWindowLoad();

    CreditWindowLoad();
}
void cleanup(void) // cleaning up all the components at exit
{

    welcomeWindowCleanUp();

    newGameWindowCleanUp();

    levelOneWindowCleanUp();
    levelOneScoreCleanUp();
    levelTwoScoreCleanUp();
    levelOnePlayerNameCleanUp();
    levelOneScoreboardCleanUp();
    levelOneObstacleCleanUp();
    L1_LifeLossCleanUp();
    levelOneLifeCleanUp();
    levelOneCoinsEffectCleanUp();
    levelOneCoinsCleanUp();
    levelOneGameOverCleanUp();
    levelTwoCompletedCleanUp();

    LegendsWindowCleanUp();
    levelTwoWindowCleanUp();
    levelTwoScoreboardCleanUp();
    CreditWindowCleanUp();

    SDL_DestroyRenderer(app.rend);
    SDL_DestroyWindow(app.window);
    SDL_DestroyTexture(back.tex);
    SDL_StopTextInput();
    TTF_CloseFont(variables.font);
    TTF_Quit();
    Mix_FreeMusic(background_music);
    Mix_FreeChunk(coingain);
    Mix_FreeChunk(explosionsound);
    Mix_FreeChunk(jumpsound);
    Mix_FreeChunk(pointgainsound);
    Mix_CloseAudio();
    IMG_Quit();
    SDL_Quit();
}
