#include "drawLevelOneWindow.h"

// funtion to add the animation effects
void updateAnimationSpeedForLevelOneWindow()
{
    // getting the current time
    L1CharPrevtime = L1CharCurrentime;
    L1CharCurrentime = SDL_GetTicks();
    L1CharDeltatime = (L1CharCurrentime - L1CharPrevtime) / 220.0f;

    // setting the frame rate according to device fps

    L1CharJumpPrevtime = L1CharJumpCurrenttime;
    L1CharJumpCurrenttime = SDL_GetTicks();
    L1CharJumpDeltatime = (L1CharJumpCurrenttime - L1CharJumpPrevtime) / 20.0f;

    L1BG_Prevtime = L1BG_Currenttime;
    L1BG_Currenttime = SDL_GetTicks();
    L1BG_Deltatime = (L1BG_Currenttime - L1BG_Prevtime) / 20.0f;

    // character sprite movement
    L1CharFrametime += L1CharDeltatime;
    if (L1CharFrametime >= (0.25f))
    {
        L1CharFrametime = 0.0;
        L1WindowChar.rect.x += L1CharFramewidth;

        if (L1WindowChar.rect.x >= L1CharTexturewidth)
        {
            L1WindowChar.rect.x = 0;
            L1CurrentScore += 5;
        }
    }

    // when the character reaches the end
    if (charFramePos.rect.x >= L1Finishline.rect.x + 100)
    {
        variables.levelOneCompleted = 1;
        variables.levelOne = 0;
        variables.saveScore = 1;
    }
    L1BG_Frametime += L1BG_Deltatime;
    if (L1BG_Frametime >= (0.25f))
    {
        L1BG_Frametime = 0.0;

        L1MountainAnimSpeed -= 1.625;
        if (L1MountainAnimSpeed < -L1WindowBuildings.rect.w)
        {
            L1MountainAnimSpeed = 0;
        }
        // setting the movement speed for treeshade
        L1Ufo1AnimSpeed -= 3.125;
        if (L1Ufo1AnimSpeed < -WINDOW_WIDTH + 100)
        {
            L1Ufo1AnimSpeed = WINDOW_WIDTH + 100;
            L1WindowUfo1.rect.w = (int)100;
            L1WindowUfo1.rect.h = (int)100;
        }
        // setting the movement speed for trees
        L1Ufo2AnimSpeed -= 4.25;
        if (L1Ufo2AnimSpeed < -WINDOW_WIDTH + 200)
        {
            L1Ufo2AnimSpeed = WINDOW_WIDTH + 200;
            L1WindowUfo2.rect.w = (int)100;
            L1WindowUfo2.rect.h = (int)80;
        }
        // setting the movement speed for track
        L1TrackAnimSpeed -= 1.625;
        if (L1TrackAnimSpeed < -L1WindowTrack.rect.w)
        {
            L1TrackAnimSpeed = 0;
        }
    }
    // resetting the character position
    if (L1CharYpos <= 40)
    {
        L1CharYpos = 40;
    }
    if (L1CharXpos >= 1100)
    {
        L1CharXpos = 1100;
    }
    if (L1CharYpos >= 665)
    {
        L1CharYpos = 665;
    }
    if (L1CharXpos < 50)
    {
        L1CharXpos = 50;
    }
    charFramePos.rect.x = L1CharXpos; // WINDOW_WIDTH / 2 - 100;
    charFramePos.rect.y = L1CharYpos;

    // setting the jump effect
    L1CharJumpFrametime += L1CharJumpDeltatime;

    if (L1CharJumpFrametime >= (0.25f))
    {
        L1CharJumpFrametime = 0.0f;
        if (L1CharYpos < 665)
        {
            L1CharYpos += SCROLL_SPEED / 70;
        }
    }

    // setting what happens after life becomes zero
    if (lifeSize == 0)
    {
        variables.levelOne = 0;
        variables.levelOnegameOver = 1;
        Mix_PlayChannel(-1, gameOver, 0);
    }
    L1FinishlinePos -= 3;
}
// funtion to load all the animations
void drawLevelOneWindowFunction()
{

    if (variables.levelOne == 1 && space == 1)
    {
        updateAnimationSpeedForLevelOneWindow();
        updateScore();
    }
    // setting the clouds animation speed
    lL1CloudsAnimSpeed -= 0.812;
    if (lL1CloudsAnimSpeed < -L1WindowClouds.rect.w)
    {
        lL1CloudsAnimSpeed = 0;
    }

    L1WindowSky.rect.x = L1SkyAnimSpeed;
    L1WindowBuildings.rect.x = L1MountainAnimSpeed;
    L1WindowUfo1.rect.x = L1Ufo1AnimSpeed;
    L1WindowUfo2.rect.x = L1Ufo2AnimSpeed;
    L1WindowClouds.rect.x = lL1CloudsAnimSpeed;
    L1WindowTrack.rect.x = L1TrackAnimSpeed;
    L1Finishline.rect.x = L1FinishlinePos;

    // rendering all the objects
    SDL_RenderClear(app.rend);

    // rendering the elements everytime new window comes
    SDL_RenderCopy(app.rend, L1WindowSky.tex, NULL, &L1WindowSky.rect);
    L1WindowSky.rect.x = L1SkyAnimSpeed + L1WindowSky.rect.w;
    SDL_RenderCopy(app.rend, L1WindowSky.tex, NULL, &L1WindowSky.rect);

    SDL_RenderCopy(app.rend, L1WindowMoon.tex, NULL, &L1WindowMoon.rect);

    SDL_RenderCopy(app.rend, L1WindowClouds.tex, NULL, &L1WindowClouds.rect);
    L1WindowClouds.rect.x = lL1CloudsAnimSpeed + L1WindowClouds.rect.w;
    SDL_RenderCopy(app.rend, L1WindowClouds.tex, NULL, &L1WindowClouds.rect);

    SDL_RenderCopy(app.rend, L1WindowBuildings.tex, NULL, &L1WindowBuildings.rect);
    L1WindowBuildings.rect.x = L1MountainAnimSpeed + L1WindowBuildings.rect.w;
    SDL_RenderCopy(app.rend, L1WindowBuildings.tex, NULL, &L1WindowBuildings.rect);

    SDL_RenderCopy(app.rend, L1WindowUfo1.tex, NULL, &L1WindowUfo1.rect);
    L1WindowUfo1.rect.x = L1Ufo1AnimSpeed + L1WindowUfo1.rect.w;

    SDL_RenderCopy(app.rend, L1WindowUfo2.tex, NULL, &L1WindowUfo2.rect);
    L1WindowUfo2.rect.x = L1Ufo2AnimSpeed + L1WindowUfo2.rect.w;

    SDL_RenderCopy(app.rend, L1WindowTrack.tex, NULL, &L1WindowTrack.rect);
    L1WindowTrack.rect.x = L1TrackAnimSpeed + L1WindowTrack.rect.w;
    SDL_RenderCopy(app.rend, L1WindowTrack.tex, NULL, &L1WindowTrack.rect);

    SDL_RenderCopy(app.rend, levelOneWindowScore.tex, NULL, &levelOneWindowScore.rect);
    SDL_RenderCopy(app.rend, levelOneWindowHighScore.tex, NULL, &levelOneWindowHighScore.rect);
    SDL_RenderCopy(app.rend, levelOneWindowScoreText.tex, NULL, &levelOneWindowScoreText.rect);
    SDL_RenderCopy(app.rend, levelOneWindowHighScoreText.tex, NULL, &levelOneWindowHighScoreText.rect);
    if (variables.levelOne == 1 && space == 0)
        SDL_RenderCopy(app.rend, initialInstructions.tex, NULL, &initialInstructions.rect);

    if (variables.levelOne == 1 && space == 1)
    {
        SDL_RenderCopy(app.rend, L1WindowChar.tex, &L1WindowChar.rect, &charFramePos.rect);
    }

    SDL_RenderCopy(app.rend, back.tex, NULL, &back.rect);

    // calling the functions for showing rewards and obstacles
    if (variables.levelOne == 1 && space == 1)
    {
        drawCoinsFunction();
        levelOneDrawObstacleFunction();

        // calling the funtion to detect collision
        collision();
        drawCoinsEffectFunction();
        levelOneDrawLifeFunction();
        levelOneDrawLifeLossFunction();
    }
    SDL_RenderCopy(app.rend, L1Finishline.tex, NULL, &L1Finishline.rect);
}
