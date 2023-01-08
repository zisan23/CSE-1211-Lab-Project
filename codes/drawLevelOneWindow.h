#include "commonHeaders.h"
extern App app;
extern component

    L1WindowSky,
    L1WindowMoon,
    L1WindowBuildings,
    L1WindowUfo1,
    L1WindowUfo2,
    L1WindowClouds,
    L1WindowTrack,
    L1WindowChar,
    levelOneWindowScore,
    levelOneWindowHighScore,
    levelOneWindowScoreText,
    levelOneWindowHighScoreText,
    L1Finishline, initialInstructions,

    charFramePos,
    

    levelOneWindowCoins[5],
    levelOneWindowObstacle[3],

    back;

extern Variables variables;

extern void updateScore(void);
extern void drawCoinsFunction(void);
extern void levelOneDrawObstacleFunction(void);
extern void levelOneDrawLifeFunction(void);
extern void levelOneDrawLifeLossFunction();

extern void collision(void);
extern void drawCoinsEffectFunction(void);
