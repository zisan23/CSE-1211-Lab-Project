#include "drawLevelTwoCompleted.h"

void updateAnimationSpeedForLevelTwoCompleted()
{

    // adjusting the animation speeds for levelTwo sky, Track
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
}

void drawLevelTwoCompletedFunction()
{
    countLevelTwo++;

    if (variables.levelTwoCompleted == 1)
    {
        updateAnimationSpeedForLevelTwoCompleted();
    }
    if (variables.levelTwoCompleted == 1 && countLevelTwo == 1)
    {
        updateLevelTwoScore();
    }

    L2_WindowSky.rect.x = L2_SkyAnimSpeed;

    L2_WindowTrack.rect.x = L2_TrackAnimSpeed;

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

    SDL_RenderCopy(app.rend, L2_CompletedOverlay.tex, NULL, &L2_CompletedOverlay.rect);
    SDL_RenderCopy(app.rend, L2_CompletedMsg.tex, NULL, &L2_CompletedMsg.rect);

    SDL_RenderCopy(app.rend, back.tex, NULL, &back.rect);
}
