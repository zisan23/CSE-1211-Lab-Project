#include "drawLevelTwoWindow.h"

void updateAnimationSpeedForLevelTwoWindow()
{
    
    // adjusting animation speed for L2_BossUFO 
    L2_BossUfoPrevtime = L2_BossUfoCurrentime;
    L2_BossUfoCurrentime = SDL_GetTicks();
    L2_BossUfo_Deltatime = (L2_BossUfoCurrentime - L2_BossUfoPrevtime) / 260.0f;
    
    //adjusting the animation speed for character jump
    level2CharacterJumpPrevtime = L2_CharJumpCurrtime;
    L2_CharJumpCurrtime = SDL_GetTicks();
    level2CharacterJumpDeltatime = (L2_CharJumpCurrtime - level2CharacterJumpPrevtime) / 20.0f;
    
    // updating the frame for animating L2_BossUFO Sprite 
    L2_BossUfo_Frametime += L2_BossUfo_Deltatime;
    if (L2_BossUfo_Frametime >= (0.25f))
    {
        L2_BossUfo_Frametime = 0.0;
        L2_BossUFO.rect.x += L2_BossUfo_Framewidth;

        if (L2_BossUFO.rect.x >= L2_BossUfoTexturewidth)
        {
            L2_BossUFO.rect.x = 0;
        }
    }
	// adjusting animation speed for levelTwoCharacter 
    L2_CharPrevtime = L2_CharCurrentime;
    L2_CharCurrentime = SDL_GetTicks();
    L2_Char_Deltatime = (L2_CharCurrentime - L2_CharPrevtime) / 280.0f;
    
    // updating the frame for animating level 2 CharacterSprite 
    L2_Char_Frametime += L2_Char_Deltatime;

    if (L2_Char_Frametime >= (0.25f))
    {
        L2_Char_Frametime = 0;
        L2_WindowChar.rect.x += L2_CharFrameWidth;
        if (L2_WindowChar.rect.x == L2_CharTextureWidth && L2_WindowChar.rect.y == L2_CharFrameHeight)
        {
            L2_WindowChar.rect.y = 0;
            L2_WindowChar.rect.x = 0;
        }
        else if (L2_WindowChar.rect.x == L2_CharTextureWidth)
        {
            L2_WindowChar.rect.x = 0;
            L2_WindowChar.rect.y = L2_CharFrameHeight;
        }
    }
    
    // adjusting animation speed for level 2 RotatingCoins
    L2_RotatingCoinPrevtime = L2_RotatingCoinCurrtime;
    L2_RotatingCoinCurrtime = SDL_GetTicks();
    L2_RotatingCoin_Deltatime = (L2_RotatingCoinCurrtime - L2_RotatingCoinPrevtime) / 280.0f;
    
    // updating the frame for animating levelTwoRotatingCoinSprite 
    L2_RotatingCoin_Frametime += L2_RotatingCoin_Deltatime;

    if (L2_RotatingCoin_Frametime >= (0.25f))
    {
        L2_RotatingCoin_Frametime = 0;
        levelTwoRotatingCoin.rect.x += L2_Coin_FrameWidth;
        if (levelTwoRotatingCoin.rect.x == L2_CoinTextureWidth && levelTwoRotatingCoin.rect.y == L2_Coin_FrameHeight)
        {
            levelTwoRotatingCoin.rect.y = 0;
            levelTwoRotatingCoin.rect.x = 0;
        }
        else if (levelTwoRotatingCoin.rect.x >= L2_CoinTextureWidth)
        {
            levelTwoRotatingCoin.rect.x = 0;
            levelTwoRotatingCoin.rect.y = L2_Coin_FrameHeight;
        }
    }

    // adjusting animation speed for levelTwoRotatingHearts
    L2_RotatingHeartPrevtime = L2_RotatingHeartCurrtime;
    L2_RotatingHeartCurrtime = SDL_GetTicks();
    L2_RotatingHeart_Deltatime = (L2_RotatingHeartCurrtime - L2_RotatingHeartPrevtime) / 280.0f;
    
    // updating the frame for animating levelTwoRotatingHeartSprite
    L2_RotatingHeart_Frametime += L2_RotatingHeart_Deltatime;

    if (L2_RotatingHeart_Frametime >= (0.25f))
    {
        L2_RotatingHeart_Frametime = 0;
        levelTwoRotatingHeart.rect.x += L2_Heart_FrameWidth;
        if (levelTwoRotatingHeart.rect.x == L2_HeartTextureWidth && levelTwoRotatingHeart.rect.y == L2_Heart_FrameHeight)
        {
            levelTwoRotatingHeart.rect.y = 0;
            levelTwoRotatingHeart.rect.x = 0;
        }
        else if (levelTwoRotatingHeart.rect.x >= L2_HeartTextureWidth)
        {
            levelTwoRotatingHeart.rect.x = 0;
            levelTwoRotatingHeart.rect.y = L2_Heart_FrameHeight;
        }
    }

    drawLevelTwoLifeText();
    levelTwoTrackmotion();
    updateHeartPosition();
    
    // update the score automatically while the character survives
    scoreUpdate++;
    if (scoreUpdate == 10)
    {
        scoreUpdate = 0;
        currentScore++;
    }

    collisionsLevelTwo();
    updateLevelTwoLifeBonusPopupFunction();
    
    updateLevelTwoScore();
    
    sprintf(lifeString, "%i", currentLife);
    
    
    
    
    // keeping levelTwoCharacter into the frame 
    if (L2_Char_Y_pos <= 40)
    {
        L2_Char_Y_pos = 40;
    }
    if (L2_Char_X_pos <= 40)
    {
        L2_Char_X_pos = 40;
    }
    if (L2_Char_Y_pos >= 800)
    {
        L2_Char_Y_pos = 800;
    }
    if (L2_Char_X_pos >= WINDOW_WIDTH)
    {
        L2_Char_X_pos = 0;
    }

    L2_WindowCharPosition.rect.x = L2_Char_X_pos;
    L2_WindowCharPosition.rect.y = L2_Char_Y_pos;
    
    //setting the jump effect
    level2CharacterJumpFrametime += level2CharacterJumpDeltatime;

    if (level2CharacterJumpFrametime >= (0.25f))
    {
        L1CharJumpFrametime = 0.0f;
        if (L2_Char_Y_pos < 665)
        {
            L2_Char_Y_pos += SCROLL_SPEED / 70;
            L2_Char_X_pos += SCROLL_SPEED / 150;
        }
    }
    
    // adjusting the animation speeds for levelTwo sky, mountains, treeShades, clouds, windowTrack 
    L2_SkyAnimSpeed -= 0.5;
    if (L2_SkyAnimSpeed < -L2_WindowSky.rect.w)
    {
        L2_SkyAnimSpeed = 0;
    }

    L2_TrackAnimSpeed -= 6;
    if (L2_TrackAnimSpeed < -L2_WindowTrack.rect.w)
    {
        L2_TrackAnimSpeed = 0;
    }
    // resetting variables if no life remains 
    if (currentLife <= 0)
    {
        spaceL2 = 0;
        SDL_DestroyTexture(levelTwoLifeScoreText.tex);
        variables.levelTwo = 0;
        variables.levelTwoGameOver = 1;
        Mix_PlayChannel(-1, gameOver, 0);
    }
    
    // reaching the finishing line
    finishlineForLevelTwo -= 2;

    if (L2_WindowCharPosition.rect.x >= L2_Finishline.rect.x)
    {
        variables.levelTwo = 0;
        variables.levelTwoCompleted = 1;
    }
}
void drawLevelTwoWindowFunction()
{

    if (spaceL2 == 1 && variables.levelTwo == 1)
    {
        updateAnimationSpeedForLevelTwoWindow();
        updateLevelTwoScore();
    }

    L2_WindowSky.rect.x = L2_SkyAnimSpeed;
    L2_WindowTrack.rect.x = L2_TrackAnimSpeed;

    L2_Finishline.rect.x = finishlineForLevelTwo;
    SDL_RenderClear(app.rend);

    SDL_RenderCopy(app.rend, L2_WindowSky.tex, NULL, &L2_WindowSky.rect);
    L2_WindowSky.rect.x = L2_SkyAnimSpeed + L2_WindowSky.rect.w;
    SDL_RenderCopy(app.rend, L2_WindowSky.tex, NULL, &L2_WindowSky.rect);
    
    SDL_RenderCopy(app.rend, L2_WindowTrack.tex, NULL, &L2_WindowTrack.rect);
    L2_WindowTrack.rect.x = L2_TrackAnimSpeed + L2_WindowTrack.rect.w;
    SDL_RenderCopy(app.rend, L2_WindowTrack.tex, NULL, &L2_WindowTrack.rect);
    
    SDL_RenderCopy(app.rend, levelOneWindowScore.tex, NULL, &levelOneWindowScore.rect);
    SDL_RenderCopy(app.rend, levelOneWindowHighScore.tex, NULL, &levelOneWindowHighScore.rect);
    SDL_RenderCopy(app.rend, levelTwoWindowScoreText.tex, NULL, &levelTwoWindowScoreText.rect);
    SDL_RenderCopy(app.rend, levelTwoWindowHighScoreText.tex, NULL, &levelTwoWindowHighScoreText.rect);


    if (spaceL2 == 0)
        SDL_RenderCopy(app.rend, L2_WindowChar.tex, &L2_WindowChar.rect, &L2_WindowCharPosition.rect);
    drawLevelTwoLifeFunction();
    if (variables.levelTwo == 1 && spaceL2 == 0)
        SDL_RenderCopy(app.rend, initialInstructions.tex, NULL, &initialInstructions.rect);

    if (spaceL2 == 1 && variables.levelTwo == 1)
    {
        drawLevelTwoTrackFunction();
        drawLevelTwoCoinsFunction();
        drawBossUFOFunction();

        LevelTwoLifeTextCleanUp();
        drawLevelTwoHeartFunction();
        drawLevelTwoHeartPopupFunction();
        
        // left-right flipping of the character 
        if (turningLeft_pressed == 1)
        {
            SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
            SDL_RenderCopyEx(app.rend, L2_WindowChar.tex, &L2_WindowChar.rect, &L2_WindowCharPosition.rect, 0, NULL, flip);
        }
        else if (turningRight_pressed == 1)
        {
            SDL_RenderCopy(app.rend, L2_WindowChar.tex, &L2_WindowChar.rect, &L2_WindowCharPosition.rect);
        }
    }
    SDL_RenderCopy(app.rend, L2_Finishline.tex, NULL, &L2_Finishline.rect);

    SDL_RenderCopy(app.rend, back.tex, NULL, &back.rect);
}
