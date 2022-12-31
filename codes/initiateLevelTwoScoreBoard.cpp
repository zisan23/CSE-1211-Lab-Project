#include "initiateLevelTwoScoreBoard.h"

void levelTwoScoreboard(void)
{
    // level 2 ScoreBoard Layouts

    window.surface = IMG_Load("./images/newcomponents/ScoreBoard.png");
    if (!window.surface)
    {
        printf("scoreBoard Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
    levelTwoScoreBoard.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!levelTwoScoreBoard.tex)
    {
        printf("levelTwoScoreBoard Texture Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(levelTwoScoreBoard.tex, NULL, NULL, &levelTwoScoreBoard.rect.w, &levelTwoScoreBoard.rect.h);
    levelTwoScoreBoard.rect.w = (int)WINDOW_WIDTH;
    levelTwoScoreBoard.rect.h = (int)WINDOW_HEIGHT;
    levelTwoScoreBoard.rect.x = 0;
    levelTwoScoreBoard.rect.y = 0;

    // Level 2 score board
    for (int i = 0; i < 5; i++)
    {
        LoadScoreFile();
        if (show_L2_PlayerNameList[levelTwoScoreList[i]])
        {
            sprintf(L2_ScoreBoardPlayerNameString[i], "%s", show_L2_PlayerNameList[levelTwoScoreList[i]]);
        }
        else
        {
            sprintf(L2_ScoreBoardPlayerNameString[i], "%s", "000");
        }

        levelTwoScoreBoardPlayerName[i].surface = TTF_RenderText_Solid(variables.font, L2_ScoreBoardPlayerNameString[i], variables.color);
        if (!levelTwoScoreBoardPlayerName[i].surface)
        {
            printf("playername Error: %s\n", IMG_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }

        levelTwoScoreBoardPlayerName[i].tex = SDL_CreateTextureFromSurface(app.rend, levelTwoScoreBoardPlayerName[i].surface);
        if (!levelTwoScoreBoardPlayerName[i].tex)
        {
            printf("scoreText Texture Error: %s\n", SDL_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }
        SDL_QueryTexture(levelTwoScoreBoardPlayerName[i].tex, NULL, NULL, &levelTwoScoreBoardPlayerName[i].rect.w, &levelTwoScoreBoardPlayerName[i].rect.h);
        levelTwoScoreBoardPlayerName[i].rect.w = (int)150;
        levelTwoScoreBoardPlayerName[i].rect.h = (int)100;
        levelTwoScoreBoardPlayerName[i].rect.x = (int)200;
        levelTwoScoreBoardPlayerName[i].rect.y = (int)250 + i * 150;

        // Level 2 ScoreBoard Player Score List
        LoadScoreFile();
        if (levelTwoScoreList[i])
            sprintf(levelTwoScoreBoardPlayerScoreString[i], "%d", levelTwoScoreList[i]);
        else
            sprintf(levelTwoScoreBoardPlayerScoreString[i], "%d", 0);

        levelTwoScoreBoardPlayerScore[i].surface = TTF_RenderText_Solid(variables.font, levelTwoScoreBoardPlayerScoreString[i], variables.color);

        if (!levelTwoScoreBoardPlayerScore[i].surface)
        {
            printf("scorestring Error: %s\n", IMG_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }

        levelTwoScoreBoardPlayerScore[i].tex = SDL_CreateTextureFromSurface(app.rend, levelTwoScoreBoardPlayerScore[i].surface);
        if (!levelTwoScoreBoardPlayerScore[i].tex)
        {
            printf("scoreText Texture Error: %s\n", SDL_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }
        SDL_QueryTexture(levelTwoScoreBoardPlayerScore[i].tex, NULL, NULL, &levelTwoScoreBoardPlayerScore[i].rect.w, &levelTwoScoreBoardPlayerScore[i].rect.h);
        levelTwoScoreBoardPlayerScore[i].rect.w = (int)150;
        levelTwoScoreBoardPlayerScore[i].rect.h = (int)100;
        levelTwoScoreBoardPlayerScore[i].rect.x = (int)800;
        levelTwoScoreBoardPlayerScore[i].rect.y = (int)250 + i * 150;
    }
}
void levelTwoScoreboardCleanUp()
{
    SDL_DestroyTexture(levelTwoScoreBoard.tex);
    for (int i = 0; i < 5; i++)
    {
        SDL_DestroyTexture(levelTwoScoreBoardPlayerName[i].tex);
        SDL_DestroyTexture(levelTwoScoreBoardPlayerScore[i].tex);
        SDL_FreeSurface(levelTwoScoreBoardPlayerName[i].surface);
        SDL_FreeSurface(levelTwoScoreBoardPlayerScore[i].surface);
    }
}
