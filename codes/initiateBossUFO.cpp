#include "initiateBossUFO.h"
void BossUFOLoad()
{
    // MISSILE load
    window.surface = IMG_Load("images/level2obstacles/missile.png");

    if (!window.surface)
    {
        printf("missile Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    L2_Missile.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!L2_Missile.tex)
    {
        printf("missile Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(L2_Missile.tex, NULL, NULL, &L2_Missile.rect.w, &L2_Missile.rect.h);

    L2_Missile.rect.w = (int)100;
    L2_Missile.rect.h = (int)100; // ekhane ektu dekhte hobe

    L2_Missile.rect.x = (int)-150;
    L2_Missile.rect.y = (int)WINDOW_HEIGHT + 10;

    // Boss UFO load
    window.surface = IMG_Load("images/level2obstacles/UFO_Sprite.png");

    if (!window.surface)
    {
        printf("boss ufo Sprite Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    L2_BossUFO.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);
    if (!L2_BossUFO.tex)
    {
        printf("boss ufo Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(L2_BossUFO.tex, NULL, NULL, &L2_BossUfoTexturewidth, &L2_BossUfoTextureheight);

    // variables for animating the dragonSprite
    L2_BossUfo_Framewidth = L2_BossUfoTexturewidth / 5 + 1;
    L2_BossUfo_Frameheight = L2_BossUfoTextureheight / 2;
    L2_BossUFO.rect.w = L2_BossUfo_Framewidth;
    L2_BossUFO.rect.h = L2_BossUfo_Frameheight;
    L2_BossUFO.rect.x = 0;
    L2_BossUFO.rect.y = 0;
    L2_BossUFO_Pos.rect.w = L2_BossUfo_Framewidth;
    L2_BossUFO_Pos.rect.h = L2_BossUfo_Frameheight;
    L2_BossUFO_Pos.rect.x = WINDOW_WIDTH + 10;
    L2_BossUFO_Pos.rect.y = 30;

    // explosion load
    window.surface = IMG_Load("images/level2obstacles/explosion.png");

    if (!window.surface)
    {
        printf("explosion error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    L2_Explosion.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!L2_Explosion.tex)
    {
        printf("explosion Texture error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(L2_Explosion.tex, NULL, NULL, &L2_Explosion.rect.w, &L2_Explosion.rect.h);

    L2_Explosion.rect.w = (int)0;
    L2_Explosion.rect.h = (int)0;
    L2_Explosion.rect.x = (int)WINDOW_WIDTH - 150;
    L2_Explosion.rect.y = (int)L2_BossUFO_Pos.rect.y;
}
void BossUFOCleanUp()
{
    SDL_DestroyTexture(L2_BossUFO.tex);
    SDL_DestroyTexture(L2_Missile.tex);
    SDL_DestroyTexture(L2_Explosion.tex);
    IMG_Quit();
}
