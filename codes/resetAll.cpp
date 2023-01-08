#include "resetAll.h"

void resetAll() // Resetting all the variables
{
    variables.gameWindowBegin = 1;
    variables.levelOne = 0;
    variables.levelTwo = 0;
    variables.chooseLevel = 0;
    variables.levelOneCompleted = 0;
    variables.levelOnePlayerName = 0;
    variables.newScore = 0;
    variables.ScoreBoard = 0;
    space = 0;
    variables.chooselevelWindow = 0;
    L1WindowTrack.rect.x = 0;
    L1CurrentScore = 0;
    variables.levelOnegameOver = 0;
    variables.levelTwoCompleted = 0;
    variables.creditWindow = 0;
    variables.levelTwoGameOver = 0;

    variables.levelTwoScoreBoard = 0;

    variables.levelTwoPlayerName = 0;
    variables.newLevelTwoScore = 0;

    lifeSize = 6;

    strcpy(playerName, " ");
    strcpy(levelTwoPlayerName, " ");
    updatePlayerName();
    updateLevelTwoPlayerName();
    updateScore();

    L1SkyAnimSpeed = 0;
    L1MountainAnimSpeed = 0;
    L1Ufo1AnimSpeed = 0;
    L1Ufo2AnimSpeed = 0;
    lL1CloudsAnimSpeed = 0;
    L1TrackAnimSpeed = 0;

    L1CharXpos = 200;
    L1CharYpos = 665;
    

    L2_SkyAnimSpeed = 0;
    L2_TrackAnimSpeed = 0;
    L2_Char_X_pos = 0;

    for (int i = 0; i < 5; i++)
    {
        L1PointEffAnimSpeed[i] = 0;
        L1PointAnimSpeed[i] = 0;
    }

    for (int i = 0; i < 3; i++)
    {
        L1ObstacleAnimSpeed[i] = 1380;
        L1LifeAnimSpeed[i] = 700;
        L1_LifeLoss[i].rect.w = (int)0;
        L1_LifeLoss[i].rect.h = (int)0;
    }
    L1FinishlinePos = 15000;
    count = 0;
    currentScore = 0;
    lifePercentage = 0;
    spaceL2 = 0;
    turningRight_pressed = 1;
    turningLeft_pressed = 0;
    levelTwoWindowLoad();

    countLevelTwo = 0;
    finishlineForLevelTwo = 10000;
    SDL_SetTextureColorMod(L1WindowChar.tex, 255, 255, 255);
}
