#include "commonHeaders.h"

App app;
component
    // starting window Components

    startSky,
    welcomeWindowBirds,
    startMountain,
    startTrees,
    startGameTitle,
    start_StartButton,
    startCreditButton,
    startScoreBoardButton,
    startExitButton,

    // newgame Window Components

    LevelChoiceWindowlevel_1_Button,
    LevelChoiceWindowlevel_2_Button,

    // level One Components

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
    L1Completed_Overlay,
    levelOneCompletedMessage,
    L1Finishline, initialInstructions,
    L1WindowCoins[5],
    L1WindowObs[3],
    L1WindowLife[6],
    L1WindowCoins_Effect[5],
    L1_LifeLoss[3],

    window,
    enterName,
    enterButton,
    playerNameBox,
    enterCommand,

    // Level Two Components

    L2_WindowSky,
    L2_WindowTrack,
    charFramePos,
    levelTwoWindowScoreText,
    levelTwoWindowHighScoreText,
    levelTwoLifeScoreText,
    L2_WindowCoins[7],
    L2_WindowChar,
    L2_WindowCharPosition,
    levelTwoInvisibleBorder[2],
    levelTwoTrack[2],
    levelTwoRotatingCoin,
    levelTwoCoinPointPopUp,
    L2_Missile,
    L2_BossUFO,
    L2_BossUFO_Pos,
    L2_Explosion,
    levelTwoHeart,
    L2_Finishline,
    levelTwoRotatingHeart,
    levelTwoLifeBonusPopUp,
    levelTwoLifeScoreDisplay,
    levelTwoHeartDisplay,
    L2_CompletedOverlay,
    L2_CompletedMsg,
    L2_EnterName,
    L2_EnterButton,
    L2_PlayerName_Box,
    L2_Enter_Command,

    // score Board Components for both levels

    scoreBoard,
    scoreBoardPlayerScore[5],
    scoreBoardPlayerName[5],
    levelTwoScoreBoard,
    levelTwoScoreBoardPlayerScore[5],
    levelTwoScoreBoardPlayerName[5],

    // Components for game Over (used for both levels)

    levelOneGameOverOverlay,
    L1_GameOverMessage,

    // Scoreboard window Components

    L1_ScoreButton,
    L2_ScoreButtonn,

    // credit Window Components
    CreditList,

    // Back button
    back;

Variables variables;

extern void cleanup(void);
extern void initSDL(void);
extern void prepareScene(void);
extern void presentScene(void);
extern void doInput(void);
