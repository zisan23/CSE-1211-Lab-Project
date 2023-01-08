#include <SDL2/SDL_mixer.h>
extern float startSkyAnimSpeed;
extern float startMountainAnimSpeed;


extern float L1SkyAnimSpeed, L1MountainAnimSpeed,
    L1Ufo1AnimSpeed, L1Ufo2AnimSpeed,
    L1TrackAnimSpeed, lL1CloudsAnimSpeed;

extern int L1CharFramewidth, L1CharFrameheight,
    L1CharTexturewidth, L1CharTextureheight;

extern float L1CharFrametime;
extern int L1CharPrevtime;
extern int L1CharCurrentime;
extern float L1CharDeltatime;


extern float L1MovementSpeed;

extern int L1Highscore;
extern char L1ScoreString[10], L1HighscoreString[10],
    scoreBoardPlayerNameString[100][10], scoreBoardPlayerScoreString[100][10];

extern int space;
extern int L1CurrentScore;

extern float L1CharXpos,
    L1CharYpos;

extern int L1CharJumpCurrenttime, L1CharJumpPrevtime;
extern float L1CharJumpDeltatime, L1CharJumpFrametime;

extern int L1BG_Currenttime, L1BG_Prevtime;
extern float L1BG_Deltatime, L1BG_Frametime;

extern char playerName[100];
extern char playerNameList[100][100], showPlayerNameList[10000][100];
extern int scoreList[100], L1PointEffAnimSpeed[5],
    L1PointAnimSpeed[5], L1ObstacleAnimSpeed[3], L1LifeAnimSpeed[3];

extern int L1FinishlinePos;
extern int count;
extern int lifeSize;
extern Mix_Music *background_music, *IndianaJones;
extern Mix_Chunk *levelOneCoingain,  *hitLevelOne, *gameOver, *click;
