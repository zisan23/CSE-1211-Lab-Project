#include "drawLevelTwoLife.h"

void heartDisplayAndScoreDisplayCleanUp()
{
    SDL_DestroyTexture(levelTwoHeartDisplay.tex);
    SDL_DestroyTexture(levelTwoLifeScoreDisplay.tex);
}
void drawLevelTwoLifeFunction()
{
    SDL_RenderCopy(app.rend, levelTwoLifeScoreDisplay.tex, 0, &levelTwoLifeScoreDisplay.rect);
    SDL_RenderCopy(app.rend, levelTwoHeartDisplay.tex, 0, &levelTwoHeartDisplay.rect);
    SDL_RenderCopy(app.rend, levelTwoLifeScoreText.tex, 0, &levelTwoLifeScoreText.rect);
}

void drawLevelTwoHeartPopupFunction()
{
    SDL_RenderCopy(app.rend, levelTwoLifeBonusPopUp.tex, 0, &levelTwoLifeBonusPopUp.rect);
}

void popuppointcleanup()
{
    SDL_DestroyTexture(levelTwoLifeBonusPopUp.tex);
    heartDisplayAndScoreDisplayCleanUp();
}

void drawLevelTwoHeartFunction()
{
    SDL_RenderCopy(app.rend, levelTwoHeart.tex, &levelTwoRotatingHeart.rect, &levelTwoHeart.rect);
}
void updateLevelTwoLifeBonusPopupFunction()
{

    // implementing the life bonus popup motion to the right corner

    levelTwoLifeBonusPopUp.rect.x += (levelTwoLifeScoreText.rect.x - levelTwoLifeBonusPopUp.rect.x) / 30;
    levelTwoLifeBonusPopUp.rect.y += (levelTwoLifeScoreText.rect.y - levelTwoLifeBonusPopUp.rect.y) / 30;

    if (abs(levelTwoLifeBonusPopUp.rect.x - levelTwoLifeScoreText.rect.x) <= 30)
    {
        if (currentLife >= 95 && levelTwoLifeBonusPopUp.rect.w == 50)
        {
            lifePercentage = 0;
        }
        else if (levelTwoLifeBonusPopUp.rect.w == 50)
        {
            lifePercentage -= 100;
            Mix_PlayChannel(-1, pointgainsound, 0);
            variables.levelTwofont = TTF_OpenFont("Freshman.ttf", 40);
            levelTwoLifeScoreText.rect.x = 1154;
            levelTwoLifeScoreText.rect.y = 62;
            delayCountForLifeRectChange++;
        }

        levelTwoLifeBonusPopUp.rect.w = 0;
        levelTwoLifeBonusPopUp.rect.h = 0;
    }
    // delay the changing of life rect
    if (delayCountForLifeRectChange > 0)
    {
        delayCountForLifeRectChange++;
    }
    if (delayCountForLifeRectChange == 15)
    {
        delayCountForLifeRectChange = 0;
        variables.levelTwofont = TTF_OpenFont("Freshman.ttf", 30);
        levelTwoLifeScoreText.rect.x = (int)1163;
        levelTwoLifeScoreText.rect.y = (int)69;
    }
}

void updateHeartPosition()
{
    currentLife = 100 - (lifePercentage / 20);
    sprintf(lifeString, "%i", currentLife);

    // hearts start coming when currentLife is less than 95%
    if (currentLife <= 95)
    {
        if (delayCountForHearts == 0)
        {
            levelTwoHeart.rect.w = 0;
            levelTwoHeart.rect.h = 0;
        }

        // adjusting the interval after which another heart will come
        delayCountForHearts++;

        if (delayCountForHearts == 30)
        {
            levelTwoHeart.rect.w = 80;
            levelTwoHeart.rect.h = 80;
            levelTwoHeart.rect.x = rand() % (WINDOW_WIDTH - 150);
            levelTwoHeart.rect.y = rand() % WINDOW_HEIGHT;

            if (levelTwoHeart.rect.y < 150 || levelTwoHeart.rect.y > 750)
            {
                levelTwoHeart.rect.y = 500;
            }
        }
        if (delayCountForHearts == 300)
        {
            levelTwoHeart.rect.w = 0;
            levelTwoHeart.rect.h = 0;
        }
        if (delayCountForHearts == 500)
        {
            delayCountForHearts = 0;
        }
    }
    else
    {
        levelTwoHeart.rect.w = 0;
        levelTwoHeart.rect.h = 0;
    }
}

void drawLevelTwoLifeText()
{
    levelTwoLifeScoreText.surface = TTF_RenderText_Solid(variables.levelTwofont, lifeString, variables.levelTwocolor);
    levelTwoLifeScoreText.tex = SDL_CreateTextureFromSurface(app.rend, levelTwoLifeScoreText.surface);

    SDL_QueryTexture(levelTwoLifeScoreText.tex, NULL, NULL, &levelTwoLifeScoreText.rect.w, &levelTwoLifeScoreText.rect.h);
    levelTwoLifeScoreText.rect.w = (int)levelTwoLifeScoreText.surface->w;
    levelTwoLifeScoreText.rect.h = (int)levelTwoLifeScoreText.surface->h;
    levelTwoLifeScoreText.rect.x = (int)1163;
    levelTwoLifeScoreText.rect.y = (int)69;
}

void LevelTwoLifeTextCleanUp()
{
    SDL_DestroyTexture(levelTwoLifeScoreText.tex);
    SDL_DestroyTexture(levelTwoWindowScoreText.tex);
    SDL_DestroyTexture(levelTwoWindowHighScoreText.tex);
}
