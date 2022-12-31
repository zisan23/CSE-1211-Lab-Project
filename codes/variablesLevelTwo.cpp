#include "variablesLevelTwo.h"

int L2_CharFrameWidth,
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

    L2_BossUfo_Framewidth = 0,
    L2_BossUfo_Frameheight = 0,
    L2_BossUfoTexturewidth = 0,
    L2_BossUfoTextureheight = 0,

    randomGenerator,
    delayCountForPointPopUp = 0,
    delayCountForHearts = 0,
    delayCountForLifeRectChange = 0,
    delayCountForExplosion = 0,
    delayCountForCharacterCollisionEffect = 0,

    currentLife = 100,
    lifePercentage = 0,
    highScore,
    currentScore = 0,
    scoreUpdate = 0,
    levelTwoScoreList[100],
    spaceL2 = 0,
    iflifeatstake = 0,
    turningLeft_pressed = 0,
    turningRight_pressed = 1,
    Down_pressed = 0,
    Up_Pressed = 0,
    countLevelTwo = 0,
    finishlineForLevelTwo = 10000;

float L2_Char_Frametime = 0,
      L2_CharCurrentime = 0,
      L2_CharPrevtime = 0,
      L2_Char_Deltatime = 0.0,
      MovementSpeed_L2 = 300.0f,
      L2_Char_X_pos = (float)100,
      L2_Char_Y_pos = (float)700,

      L2_RotatingCoin_Frametime = 0,
      L2_RotatingCoinPrevtime = 0,
      L2_RotatingCoinCurrtime = 0,
      L2_RotatingCoin_Deltatime = 0.0,

      L2_RotatingHeart_Frametime = 0,
      L2_RotatingHeartPrevtime = 0,
      L2_RotatingHeartCurrtime = 0,
      L2_RotatingHeart_Deltatime = 0.0,

      L2_BossUfo_Frametime = 0,
      L2_BossUfoPrevtime = 0,
      L2_BossUfoCurrentime = 0,
      L2_BossUfo_Deltatime = 0.0,

      L2_SkyAnimSpeed = 0,
      L2_TrackAnimSpeed = 0,
      L2_Track_X_pos1 = (float)WINDOW_WIDTH / 2 + 200,
      L2_Track_Y_pos1 = (float)WINDOW_HEIGHT / 2 - 200,
      L2_Track_X_pos2 = (float)WINDOW_WIDTH / 2 + 200,
      L2_Track_Y_pos2 = (float)WINDOW_HEIGHT / 2 - 200;

char lifeString[256] = " ",
     scoreString[256],
     highScoreString[256],
     L2_ScoreBoardPlayerNameString[100][10],
     levelTwoScoreBoardPlayerScoreString[100][10],
     L2_PlayerNameList[100][100],
     show_L2_PlayerNameList[10000][100],
     L2_HighScoreString[10],
     levelTwoPlayerName[100] = " ";

Mix_Music *doom_ost;
Mix_Chunk *coingain,
    *explosionsound,
    *jumpsound,
    *pointgainsound;

extern int L2_CharJumpCurrtime = 0, level2CharacterJumpPrevtime = 0;
extern float level2CharacterJumpDeltatime = 0, level2CharacterJumpFrametime = 0;
