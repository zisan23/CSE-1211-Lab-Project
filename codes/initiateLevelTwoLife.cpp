#include "initiateLevelTwoLife.h"
void LevelTwoLifeLoad()
{   
    // hearts load
    window.surface = IMG_Load("images/level2obstacles/redgreenheartsprite.png");

    if (!window.surface)
    {
        printf("levelTwoHeart Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelTwoHeart.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!levelTwoHeart.tex)
    {
        printf("levelTwoHeart Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(levelTwoHeart.tex, NULL, NULL, &levelTwoHeart.rect.w, &levelTwoHeart.rect.h);

    levelTwoHeart.rect.w = (int)50;
    levelTwoHeart.rect.h = (int)50;
    levelTwoHeart.rect.x = (int)levelTwoTrack[0].rect.x + 50;
    levelTwoHeart.rect.y = (int)levelTwoTrack[0].rect.y - 70;

    // variables for animating the rotatingHeartSprite
    SDL_QueryTexture(levelTwoHeart.tex, NULL, NULL, &L2_HeartTextureHeight, &L2_HeartTextureWidth);

    L2_Heart_FrameWidth = L2_HeartTextureWidth / 2;
    L2_Heart_FrameHeight = L2_HeartTextureHeight / 2;

    levelTwoRotatingHeart.rect.w = (int)L2_Heart_FrameWidth;
    levelTwoRotatingHeart.rect.h = (int)L2_Heart_FrameHeight;
    levelTwoRotatingHeart.rect.x = (int)0;
    levelTwoRotatingHeart.rect.y = (int)0;

    // lifeBonus Load 
    window.surface = IMG_Load("images/level2obstacles/5p.png");

    if (!window.surface)
    {
        printf("lifeBonus Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelTwoLifeBonusPopUp.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!levelTwoLifeBonusPopUp.tex)
    {
        printf("lifeBonus Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(levelTwoLifeBonusPopUp.tex, NULL, NULL, &levelTwoLifeBonusPopUp.rect.w, &levelTwoLifeBonusPopUp.rect.h);

    levelTwoLifeBonusPopUp.rect.w = (int)0;
    levelTwoLifeBonusPopUp.rect.h = (int)0;
    levelTwoLifeBonusPopUp.rect.x = (int)WINDOW_WIDTH / 2;
    levelTwoLifeBonusPopUp.rect.y = (int)WINDOW_HEIGHT / 2;

    
    // lifeScore load 
    window.surface = IMG_Load("images/level2obstacles/lifescore.png");

    if (!window.surface)
    {
        printf("lifeScoreDisplay Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelTwoLifeScoreDisplay.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!levelTwoLifeScoreDisplay.tex)
    {
        printf("lifeScoreDisplay Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(levelTwoLifeScoreDisplay.tex, NULL, NULL, &levelTwoLifeScoreDisplay.rect.w, &levelTwoLifeScoreDisplay.rect.h);

    levelTwoLifeScoreDisplay.rect.w = (int)125;
    levelTwoLifeScoreDisplay.rect.h = (int)39;
    levelTwoLifeScoreDisplay.rect.x = (int)1110;
    levelTwoLifeScoreDisplay.rect.y = (int)63;
    
    //life heart display load 
    window.surface = IMG_Load("images/level2obstacles/life.png");

    if (!window.surface)
    {
        printf("lifeHeartDisplay Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelTwoHeartDisplay.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!levelTwoHeartDisplay.tex)
    {
        printf("lifeHeartDisplay Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(levelTwoHeartDisplay.tex, NULL, NULL, &levelTwoHeartDisplay.rect.w, &levelTwoHeartDisplay.rect.h);

    levelTwoHeartDisplay.rect.w = (int)90;
    levelTwoHeartDisplay.rect.h = (int)72;
    levelTwoHeartDisplay.rect.x = (int)1078;
    levelTwoHeartDisplay.rect.y = (int)31;
}

void HeartCleanUp()
{
    SDL_DestroyTexture(levelTwoHeart.tex);
    SDL_DestroyTexture(levelTwoRotatingHeart.tex);
    SDL_DestroyTexture(levelTwoLifeBonusPopUp.tex);
    SDL_DestroyTexture(levelTwoHeartDisplay.tex);
    SDL_DestroyTexture(levelTwoLifeScoreDisplay.tex);
    IMG_Quit();
}
