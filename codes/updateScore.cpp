#include "updateScore.h"
void updateScore() // for managin levelOne Score (sundarban)
{

    // loading the scores from file and updating them if necessary

    LoadScoreFile();
    sprintf(L1ScoreString, "%i", L1CurrentScore);

    if (variables.saveScore == 1 && count == 1)
    {
        updateHighScoreOnFile();
        scoreboard();
    }

    sprintf(L1HighscoreString, "%i", scoreList[0]);

    // level One Score Displaying Components Initialisation

    levelOneWindowScoreText.surface = TTF_RenderText_Solid(variables.font, L1ScoreString, variables.color);

    if (!levelOneWindowScoreText.surface)
    {
        printf("levelOneWindowScoreText Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelOneWindowScoreText.tex = SDL_CreateTextureFromSurface(app.rend, levelOneWindowScoreText.surface);
    if (!levelOneWindowScoreText.tex)
    {
        printf("levelOneWindowScoreText Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
    SDL_QueryTexture(levelOneWindowScoreText.tex, NULL, NULL, &levelOneWindowScoreText.rect.w, &levelOneWindowScoreText.rect.h);
    levelOneWindowScoreText.rect.w = (int)levelOneWindowScoreText.surface->w;
    levelOneWindowScoreText.rect.h = (int)levelOneWindowScoreText.surface->h;
    levelOneWindowScoreText.rect.x = (int)150;
    levelOneWindowScoreText.rect.y = (int)45;

    //level One High Score Displaying Components Initialisation

    levelOneWindowHighScoreText.surface = TTF_RenderText_Solid(variables.font, L1HighscoreString, variables.color);

    if (!levelOneWindowHighScoreText.surface)
    {
        printf("levelOneWindowHighScoreText Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelOneWindowHighScoreText.tex = SDL_CreateTextureFromSurface(app.rend, levelOneWindowHighScoreText.surface);
    if (!levelOneWindowHighScoreText.tex)
    {
        printf("levelOneWindowHighScoreText Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
    SDL_QueryTexture(levelOneWindowHighScoreText.tex, NULL, NULL, &levelOneWindowHighScoreText.rect.w, &levelOneWindowHighScoreText.rect.h);
    levelOneWindowHighScoreText.rect.w = (int)levelOneWindowHighScoreText.surface->w;
    levelOneWindowHighScoreText.rect.h = (int)levelOneWindowHighScoreText.surface->h;
    levelOneWindowHighScoreText.rect.x = (int)150;
    levelOneWindowHighScoreText.rect.y = (int)110;
}

void levelOneScoreCleanUp() //cleaing up the textures and surfaces
{
    SDL_DestroyTexture(levelOneWindowScoreText.tex);
    SDL_DestroyTexture(levelOneWindowHighScoreText.tex);
    SDL_FreeSurface(levelOneWindowScoreText.surface);
    SDL_FreeSurface(levelOneWindowHighScoreText.surface);
}

void updateLevelTwoScore() // for managing Score of Level Two
{

    //loading levelTwo Score and Updating if necessary
    LoadScoreFile();

    sprintf(scoreString, "%i", currentScore);

    if (variables.levelTwoCompleted == 1 && countLevelTwo == 1)
    {
        updateLevelTwoHighScoreOnFile();
        levelTwoScoreboard();
    }
    sprintf(L2_HighScoreString, "%i", levelTwoScoreList[0]);

    //leve Two  Score Displaying Components Initialisation

    levelTwoWindowScoreText.surface = TTF_RenderText_Solid(variables.levelTwofont, scoreString, variables.levelTwocolor);

    if (!levelTwoWindowScoreText.surface)
    {
        printf("levelTwoWindowScoreText Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelTwoWindowScoreText.tex = SDL_CreateTextureFromSurface(app.rend, levelTwoWindowScoreText.surface);
    if (!levelTwoWindowScoreText.tex)
    {
        printf("levelTwoWindowScoreText Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
    SDL_QueryTexture(levelTwoWindowScoreText.tex, NULL, NULL, &levelTwoWindowScoreText.rect.w, &levelTwoWindowScoreText.rect.h);
    levelTwoWindowScoreText.rect.w = (int)levelTwoWindowScoreText.surface->w;
    levelTwoWindowScoreText.rect.h = (int)levelTwoWindowScoreText.surface->h;
    levelTwoWindowScoreText.rect.x = (int)150;
    levelTwoWindowScoreText.rect.y = (int)45;

    //level Two High Score Displaying Components Initialisation

    levelTwoWindowHighScoreText.surface = TTF_RenderText_Solid(variables.levelTwofont, L2_HighScoreString, variables.levelTwocolor);

    if (!levelTwoWindowHighScoreText.surface)
    {
        printf("levelTwoWindowHighScoreText Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }

    levelTwoWindowHighScoreText.tex = SDL_CreateTextureFromSurface(app.rend, levelTwoWindowHighScoreText.surface);

    if (!levelTwoWindowHighScoreText.tex)
    {
        printf("levelTwoWindowHighScoreText Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(app.rend);
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
    SDL_QueryTexture(levelTwoWindowHighScoreText.tex, NULL, NULL, &levelTwoWindowHighScoreText.rect.w, &levelTwoWindowHighScoreText.rect.h);
    levelTwoWindowHighScoreText.rect.w = (int)levelTwoWindowHighScoreText.surface->w;
    levelTwoWindowHighScoreText.rect.h = (int)levelTwoWindowHighScoreText.surface->h;
    levelTwoWindowHighScoreText.rect.x = (int)150;
    levelTwoWindowHighScoreText.rect.y = (int)110;
}
void levelTwoScoreCleanUp() // cleaning up Level Two Score displaying surfaces and textures
{

    SDL_FreeSurface(levelTwoWindowScoreText.surface);
    SDL_FreeSurface(levelTwoWindowHighScoreText.surface);
    SDL_DestroyTexture(levelTwoWindowScoreText.tex);
    SDL_DestroyTexture(levelTwoWindowHighScoreText.tex);
}
