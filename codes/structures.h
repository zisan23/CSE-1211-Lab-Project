typedef struct
{
    SDL_Renderer *rend;
    SDL_Window *window;
} App; // for creating the window

typedef struct
{
    SDL_Surface *surface;
    SDL_Texture *tex;
    SDL_Rect rect;
} component; // this structure is used to create all the elements of the game

typedef struct
{
    int chooseLevel, gameWindowBegin = 1, levelOne = 0, levelTwo = 0,
                     levelOneCompleted = 0, levelOnePlayerName = 0, levelTwoPlayerName = 0,
                     newScore = 0, ScoreBoard = 0, saveScore = 0, levelOnegameOver = 0,
                     levelTwoCompleted = 0, levelTwoScoreBoard = 0, chooselevelWindow = 0,
                     newLevelTwoScore = 0, creditWindow = 0, levelTwoGameOver = 0;
    TTF_Font *font;
    SDL_Color color;
    TTF_Font *levelTwofont;
    SDL_Color levelTwocolor;

} Variables; //for creating variables for window creating and destroying
