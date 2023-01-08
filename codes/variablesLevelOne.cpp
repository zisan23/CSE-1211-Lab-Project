#include "variablesLevelOne.h"

// welcome window animation speed

float startSkyAnimSpeed = 0;
float startMountainAnimSpeed = 0;


float L1SkyAnimSpeed = 0, L1MountainAnimSpeed = 0,
      L1Ufo1AnimSpeed = 0, L1Ufo2AnimSpeed = 0,
      L1TrackAnimSpeed = 0, lL1CloudsAnimSpeed = 0;

int L1CharFramewidth = 0, L1CharFrameheight = 0,
    L1CharTexturewidth = 0, L1CharTextureheight = 0;

float L1CharFrametime = 0;
int L1CharPrevtime = 0;
int L1CharCurrentime = 0;
float L1CharDeltatime = 0;



float L1MovementSpeed = 0;

int L1Highscore = 0;
char L1ScoreString[10], L1HighscoreString[10],
    scoreBoardPlayerNameString[100][10], scoreBoardPlayerScoreString[100][10];

int space = 0;
int L1CurrentScore = 0;

float L1CharXpos = 200,
      L1CharYpos = 665;

int L1CharJumpCurrenttime = 0, L1CharJumpPrevtime = 0;
float L1CharJumpDeltatime = 0, L1CharJumpFrametime = 0;

int L1BG_Currenttime = 0, L1BG_Prevtime = 0;
float L1BG_Deltatime = 0, L1BG_Frametime = 0;

char playerName[100] = " ";

char playerNameList[100][100], showPlayerNameList[10000][100];
int scoreList[100];
int L1PointEffAnimSpeed[5];
int L1PointAnimSpeed[5];
int L1ObstacleAnimSpeed[3] = {1380, 1380, 1380};
int L1LifeAnimSpeed[3] = {700, 700, 700};
int L1FinishlinePos = 15000;
int count = 0;
int lifeSize = 6;

Mix_Music *background_music, *IndianaJones;
Mix_Chunk *levelOneCoingain, *hitLevelOne, *gameOver, *click;
