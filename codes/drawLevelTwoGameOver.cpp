#include "drawLevelTwoGameOver.h"

void updateAnimationSpeedForLevelTwoGameOver()
{

    L2_SkyAnimSpeed = 0;
 
    
}
void drawLevelTwoGameOverFunction()
{

    if (variables.levelTwoGameOver == 1)
    {
        updateAnimationSpeedForLevelTwoGameOver();
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

 	//rendering level one components here
    SDL_RenderCopy(app.rend, levelOneWindowScore.tex, NULL, &levelOneWindowScore.rect);
    SDL_RenderCopy(app.rend, levelOneWindowHighScore.tex, NULL, &levelOneWindowHighScore.rect);
    SDL_RenderCopy(app.rend, levelTwoWindowScoreText.tex, NULL, &levelTwoWindowScoreText.rect);
    SDL_RenderCopy(app.rend, levelTwoWindowHighScoreText.tex, NULL, &levelTwoWindowHighScoreText.rect);

    SDL_RenderCopy(app.rend, L1Completed_Overlay.tex, NULL, &L1Completed_Overlay.rect);
    SDL_RenderCopy(app.rend, L1_GameOverMessage.tex, NULL, &L1_GameOverMessage.rect);

    SDL_RenderCopy(app.rend, back.tex, NULL, &back.rect);
}
