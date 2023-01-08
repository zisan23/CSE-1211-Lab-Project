#include "loadScoreFile.h"

FILE *fp;

void LoadScoreFile() //lodaing Score from files
{
    int i = 0, j;

    // Loading Level One Score

    fp = fopen("score.txt", "r"); // Opening file to read

    while (fscanf(fp, "%s %d\n", &playerNameList[i], &scoreList[i]) != EOF)
    {
        sprintf(showPlayerNameList[scoreList[i]], "%s", playerNameList[i]); //mapping the score for players
        i++;
    }
    int tmp;
    // sorting the score list
    for (i = 0; scoreList[i]; i++)
    {
        for (j = i + 1; scoreList[j]; j++)
        {
            if (scoreList[i] <= scoreList[j])
            {
                tmp = scoreList[j];
                scoreList[j] = scoreList[i];
                scoreList[i] = tmp;
            }
        }
        sprintf(scoreBoardPlayerNameString[i], "%s", playerNameList[i]);
    }
    fclose(fp);
    sprintf(L1HighscoreString, "%i", scoreList[0]);

    //Loading Level Two Scores

    fp = fopen("scoreleveltwo.txt", "r"); //  Opening file to read
    i = 0;
    while (fscanf(fp, "%s %d\n", &L2_PlayerNameList[i], &levelTwoScoreList[i]) != EOF)
    {
        sprintf(show_L2_PlayerNameList[levelTwoScoreList[i]], "%s", L2_PlayerNameList[i]); //mapping the score for players
        i++;
    }
    // sorting the score list

    for (i = 0; levelTwoScoreList[i]; i++)
    {
        for (j = i + 1; levelTwoScoreList[j]; j++)
        {
            if (levelTwoScoreList[i] <= levelTwoScoreList[j])
            {
                tmp = levelTwoScoreList[j];
                levelTwoScoreList[j] = levelTwoScoreList[i];
                levelTwoScoreList[i] = tmp;
            }
        }

        sprintf(L2_ScoreBoardPlayerNameString[i], "%s", L2_PlayerNameList[i]);
    }
    fclose(fp);

    sprintf(L2_HighScoreString, "%i", levelTwoScoreList[0]);
}

void updateHighScoreOnFile() //if player completes the level then score is saved
{
    L1Highscore = L1CurrentScore;

    fp = fopen("score.txt", "a");
    if (variables.newScore == 1 && variables.saveScore == 1 && L1Highscore > 0)
    {

        fprintf(fp, "%s ", playerName);
        fprintf(fp, "%d\n", L1Highscore);
    }

    sprintf(L1HighscoreString, "%i", L1Highscore);
    fclose(fp);
}

void updateLevelTwoHighScoreOnFile() //if player completes the level then score is saved
{
    highScore = currentScore;
    fp = fopen("scoreleveltwo.txt", "a");

    if (variables.newLevelTwoScore == 1 && variables.levelTwoCompleted == 1 && highScore > 0)
    {
        fprintf(fp, "%s ", levelTwoPlayerName);
        fprintf(fp, "%d\n", highScore);
    }

    sprintf(L2_HighScoreString, "%i", highScore);
    fclose(fp);
}
