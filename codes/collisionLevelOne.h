#include "commonHeaders.h"

extern App app;
extern component

    L1WindowChar,

    charFramePos,

    L1WindowCoins[5],
    L1WindowCoins_Effect[5],

    L1WindowObs[3],

    L1WindowLife[6],
    L1_LifeLoss[3];

extern Variables variables;

extern void updateScore(void);
extern void drawCoinsFunction(void);
extern void drawCoinsEffectFunction(void);
extern void coineffectdelay();
extern void obstacleeffectdelay();

extern void coinsupdateanimation(void);
extern void collision(void);
extern void endlife(void);
