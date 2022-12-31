#include "commonHeaders.h"
extern App app;
extern component
    L2_WindowSky,
    L2_WindowTrack,
    L2_WindowChar,
    L2_WindowCharPosition,
    levelTwoRotatingCoin,
    levelTwoRotatingHeart,
    characterFramePosition,
    levelTwoWindowScoreText,
    levelTwoLifeScoreText,
    levelTwoWindowHighScoreText,
    levelOneWindowScore,
    levelOneWindowHighScore,
    L2_BossUFO,
    L2_Finishline,
    initialInstructions,
    back;

extern Variables variables;
extern void drawLevelTwoTrackFunction(void);
extern void levelTwoTrackmotion(void);
extern void drawLevelTwoCoinsFunction(void);
extern void drawLevelTwoCoinsPopupFunction(void);
extern void drawBossUFOFunction(void);
extern void collisionsLevelTwo(void);
extern void updateLevelTwoScore(void);
extern void updateLevelTwoLifeBonusPopupFunction(void);
extern void drawLevelTwoLifeText(void);
extern void drawLevelTwoLifeFunction(void);
extern void LevelTwoLifeTextCleanUp(void);
extern void updateHeartPosition(void);
extern void lifeatstakeaftereffect(void);
extern void drawLevelTwoHeartFunction(void);
extern void drawLevelTwoHeartPopupFunction(void);
