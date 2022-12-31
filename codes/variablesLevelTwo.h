#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "preprocessors.h"

extern int L2_CharFrameWidth,
    L2_CharFrameHeight,
    L2_CharTextureWidth,
    L2_CharTextureHeight,

    L2_CoinTextureHeight,
    L2_CoinTextureWidth,
    L2_Coin_FrameHeight,
    L2_Coin_FrameWidth,

    L2_HeartTextureWidth,
    L2_HeartTextureHeight,
    L2_Heart_FrameHeight,
    L2_Heart_FrameWidth,

    L2_BossUfo_Framewidth,
    L2_BossUfo_Frameheight,
    L2_BossUfoTexturewidth,
    L2_BossUfoTextureheight,

    randomGenerator,
    delayCountForPointPopUp,
    delayCountForHearts,
    delayCountForLifeRectChange,
    delayCountForExplosion,
    delayCountForCharacterCollisionEffect,

    currentLife,
    lifePercentage,
    highScore,
    currentScore,
    scoreUpdate,
    levelTwoScoreList[100],
    spaceL2,
    iflifeatstake,
    turningLeft_pressed,
    turningRight_pressed,
    Down_pressed,
    Up_Pressed,
    countLevelTwo,
    finishlineForLevelTwo;

extern float L2_Char_Frametime,
    L2_CharPrevtime,
    L2_CharCurrentime,
    L2_Char_Deltatime,
    MovementSpeed_L2,
    L2_Char_X_pos,
    L2_Char_Y_pos,

    L2_RotatingCoin_Frametime,
    L2_RotatingCoinPrevtime,
    L2_RotatingCoinCurrtime,
    L2_RotatingCoin_Deltatime,

    L2_RotatingHeart_Frametime,
    L2_RotatingHeartPrevtime,
    L2_RotatingHeartCurrtime,
    L2_RotatingHeart_Deltatime,

    L2_BossUfo_Frametime,
    L2_BossUfoPrevtime,
    L2_BossUfoCurrentime,
    L2_BossUfo_Deltatime,

    L2_SkyAnimSpeed,
    L2_TrackAnimSpeed,
    L2_Track_X_pos1,
    L2_Track_Y_pos1,
    L2_Track_X_pos2,
    L2_Track_Y_pos2;

extern char lifeString[256],
    scoreString[256],
    highScoreString[256],
    L2_ScoreBoardPlayerNameString[100][10],
    levelTwoScoreBoardPlayerScoreString[100][10],
    L2_PlayerNameList[100][100],
    show_L2_PlayerNameList[10000][100],
    L2_HighScoreString[10],
    levelTwoPlayerName[100];

extern Mix_Music *doom_ost;
extern Mix_Chunk *coingain,
    *explosionsound,
    *jumpsound,
    *pointgainsound;

extern int L2_CharJumpCurrtime, level2CharacterJumpPrevtime;
extern float level2CharacterJumpDeltatime, level2CharacterJumpFrametime;
