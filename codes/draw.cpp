#include "draw.h"
void prepareScene(void) //Calling functions based on players command
{

    if (variables.gameWindowBegin == 1)
    {

        drawWelcomeWindowFunction();
    }

    if (variables.chooseLevel == 1)
    {
        drawNewgameWindowFunction();
    }

    if (variables.levelOne == 1)
    {
        drawLevelOneWindowFunction();
    }
    if (variables.levelOneCompleted == 1)
    {
        drawLevelOneCompletedFunction();
    }
    if (variables.levelTwo == 1)
    {
        drawLevelTwoWindowFunction();
    }
    if (variables.levelOnePlayerName == 1)
    {
        drawLevelOnePlayerNameFunction();
    }
    if (variables.ScoreBoard == 1)
    {
        drawScoreBoardFunction();
    }
    if (variables.levelOnegameOver == 1)
    {
        drawLevelOneGameOverFunction();
    }
    if (variables.levelTwoCompleted == 1)
    {
        drawLevelTwoCompletedFunction();
    }
    if (variables.levelTwoScoreBoard == 1)
    {
        drawLevelTwoScoreBoardFunction();
    }
    if (variables.chooselevelWindow == 1)
    {
        drawLegendsWindowFunction();
    }
    if (variables.levelTwoPlayerName == 1)
    {
        drawLevelTwoPlayerNameFunction();
    }
    if (variables.creditWindow == 1)
    {
        drawCreditWindowFunction();
    }
    if (variables.levelTwoGameOver == 1)
    {
        drawLevelTwoGameOverFunction();
    }
}

void presentScene(void) //Presenting the Window
{
    SDL_RenderPresent(app.rend);
}
