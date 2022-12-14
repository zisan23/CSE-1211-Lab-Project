#include "drawLevelOneCompleted.h"

//funtion to control the speeds of the levelOne completed window elements
void updateAnimationSpeedForLevelOneCompleted()
{   
    //getting the current time
    L1BG_Prevtime = L1BG_Currenttime;
    L1BG_Currenttime = SDL_GetTicks();
    L1BG_Deltatime = (L1BG_Currenttime - L1BG_Prevtime) / 20.0f;

    L1BG_Frametime += L1BG_Deltatime;
    if (L1BG_Frametime >= (0.25f))
    {
        L1BG_Frametime = 0.0;

        L1SkyAnimSpeed -= 0.412;
        if (L1SkyAnimSpeed < -L1WindowSky.rect.w)
        {
            L1SkyAnimSpeed = 0;
        }
        lL1CloudsAnimSpeed -= 0.812;
        if (lL1CloudsAnimSpeed < -L1WindowClouds.rect.w)
        {
            lL1CloudsAnimSpeed = 0;
        }
        L1MountainAnimSpeed -= 1.625;
        if (L1MountainAnimSpeed < -L1WindowBuildings.rect.w)
        {
            L1MountainAnimSpeed = 0;
        }

        L1Ufo1AnimSpeed -= 2.125;
        if (L1Ufo1AnimSpeed < -L1WindowUfo1.rect.w)
        {
            L1Ufo1AnimSpeed = 0;
        }

        L1Ufo2AnimSpeed -= 4.25;
        if (L1Ufo2AnimSpeed < -L1WindowUfo2.rect.w)
        {
            L1Ufo2AnimSpeed = 0;
        }

        L1TrackAnimSpeed -= 5.5;
        if (L1TrackAnimSpeed < -L1WindowTrack.rect.w)
        {
            L1TrackAnimSpeed = 0;
        }
    }
}
//funtion to render the components of levelOne completed window
void drawLevelOneCompletedFunction()
{   
    //when game ends count increases
    count++;
    
    //writes the score in files
    if (variables.saveScore == 1)
    {
        updateAnimationSpeedForLevelOneCompleted();
    }
    //count is used to make sure score is written only once for one player
    if (variables.saveScore == 1 && count == 1)
    {
        updateScore();
    }
    L1WindowSky.rect.x = L1SkyAnimSpeed;
    L1WindowBuildings.rect.x = L1MountainAnimSpeed;
    L1WindowUfo1.rect.x = L1Ufo1AnimSpeed;
    L1WindowUfo2.rect.x = L1Ufo2AnimSpeed;
    L1WindowClouds.rect.x = lL1CloudsAnimSpeed;
    L1WindowTrack.rect.x = L1TrackAnimSpeed;
    SDL_RenderClear(app.rend);

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
    SDL_RenderCopy(app.rend, L1WindowUfo1.tex, NULL, &L1WindowUfo1.rect);

    SDL_RenderCopy(app.rend, L1WindowUfo2.tex, NULL, &L1WindowUfo2.rect);
    L1WindowUfo2.rect.x = L1Ufo2AnimSpeed + L1WindowUfo2.rect.w;
    SDL_RenderCopy(app.rend, L1WindowUfo2.tex, NULL, &L1WindowUfo2.rect);

    SDL_RenderCopy(app.rend, L1WindowTrack.tex, NULL, &L1WindowTrack.rect);
    L1WindowTrack.rect.x = L1TrackAnimSpeed + L1WindowTrack.rect.w;
    SDL_RenderCopy(app.rend, L1WindowTrack.tex, NULL, &L1WindowTrack.rect);

    SDL_RenderCopy(app.rend, levelOneWindowScore.tex, NULL, &levelOneWindowScore.rect);
    SDL_RenderCopy(app.rend, levelOneWindowHighScore.tex, NULL, &levelOneWindowHighScore.rect);
    SDL_RenderCopy(app.rend, levelOneWindowScoreText.tex, NULL, &levelOneWindowScoreText.rect);
    SDL_RenderCopy(app.rend, levelOneWindowHighScoreText.tex, NULL, &levelOneWindowHighScoreText.rect);
    //rendering the levelOne completed message
    SDL_RenderCopy(app.rend, L1Completed_Overlay.tex, NULL, &L1Completed_Overlay.rect);
    SDL_RenderCopy(app.rend, levelOneCompletedMessage.tex, NULL, &levelOneCompletedMessage.rect);
    SDL_RenderCopy(app.rend, back.tex, NULL, &back.rect);
}
