#include "initiateScoreBoard.h"

void scoreboard(void) //Creating scoreboard layouts and player name and scoreList
{

    // level 1 ScoreBoard Layout

    window.surface = IMG_Load("./images/newcomponents/ScoreBoard.png");
    if (!window.surface)
    {
        printf("scoreBoard Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
    scoreBoard.tex = SDL_CreateTextureFromSurface(app.rend, window.surface);
    SDL_FreeSurface(window.surface);

    if (!scoreBoard.tex)
    {
        printf(" scoreBoard  level 1 Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    SDL_QueryTexture(scoreBoard.tex, NULL, NULL, &scoreBoard.rect.w, &scoreBoard.rect.h);
    scoreBoard.rect.w = (int)WINDOW_WIDTH;
    scoreBoard.rect.h = (int)WINDOW_HEIGHT;
    scoreBoard.rect.x = 0;
    scoreBoard.rect.y = 0;

    // level 1 ScoreBoard Player Name List

    for (int i = 0; i < 5; i++)
    {

        LoadScoreFile();
        if (showPlayerNameList[scoreList[i]])
            sprintf(scoreBoardPlayerNameString[i], "%s", showPlayerNameList[scoreList[i]]);

        scoreBoardPlayerName[i].surface = TTF_RenderText_Solid(variables.font, scoreBoardPlayerNameString[i], variables.color);

        if (!window.surface)
        {
            printf("scoreBoardPlayerName Error: %s\n", IMG_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }

        scoreBoardPlayerName[i].tex = SDL_CreateTextureFromSurface(app.rend, scoreBoardPlayerName[i].surface);
        if (!scoreBoardPlayerName[i].tex)
        {
            printf("scoreBoardPlayerName Texture %s\n", SDL_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }
        SDL_QueryTexture(scoreBoardPlayerName[i].tex, NULL, NULL, &scoreBoardPlayerName[i].rect.w, &scoreBoardPlayerName[i].rect.h);
        scoreBoardPlayerName[i].rect.w = (int)150;
        scoreBoardPlayerName[i].rect.h = (int)100;
        scoreBoardPlayerName[i].rect.x = (int)200;
        scoreBoardPlayerName[i].rect.y = (int)250 + i * 150;

        LoadScoreFile();
        if (scoreList[i])
            sprintf(scoreBoardPlayerScoreString[i], "%d", scoreList[i]);
        else
            sprintf(scoreBoardPlayerScoreString[i], "%d", 0);

        scoreBoardPlayerScore[i].surface = TTF_RenderText_Solid(variables.font, scoreBoardPlayerScoreString[i], variables.color);

        if (!scoreBoardPlayerScore[i].surface)
        {
            printf("scoreBoardPlayerScore Error: %s\n", IMG_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }

        scoreBoardPlayerScore[i].tex = SDL_CreateTextureFromSurface(app.rend, scoreBoardPlayerScore[i].surface);
        if (!scoreBoardPlayerScore[i].tex)
        {
            printf("scoreBoardPlayerScore Texture %s\n", SDL_GetError());
            SDL_DestroyRenderer(app.rend);
            SDL_DestroyWindow(app.window);
            SDL_Quit();
            exit(1);
        }
        SDL_QueryTexture(scoreBoardPlayerScore[i].tex, NULL, NULL, &scoreBoardPlayerScore[i].rect.w, &scoreBoardPlayerScore[i].rect.h);
        scoreBoardPlayerScore[i].rect.w = (int)150;
        scoreBoardPlayerScore[i].rect.h = (int)100;scoreBoardPlayerScore[i].surface->h - 10;
        scoreBoardPlayerScore[i].rect.x = (int)800;
        scoreBoardPlayerScore[i].rect.y = (int)250 + i * 150;
    }
}
void levelOneScoreboardCleanUp() //cleanig up
{
    SDL_DestroyTexture(scoreBoard.tex);
    for (int i = 0; i < 5; i++)
    {
        SDL_DestroyTexture(scoreBoardPlayerName[i].tex);
        SDL_DestroyTexture(scoreBoardPlayerScore[i].tex);
        SDL_FreeSurface(scoreBoardPlayerName[i].surface);
        SDL_FreeSurface(scoreBoardPlayerScore[i].surface);
    }
}
