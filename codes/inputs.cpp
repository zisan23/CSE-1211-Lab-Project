#include "inputs.h"

void doInput(void)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {

        if (event.type == SDL_QUIT)
        {
            exit(0);
        }
        // level one Key Events

        if (variables.levelOnePlayerName == 1 || variables.levelOne == 1)
        {
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_BACKSPACE && strlen(playerName) > 1)
                {
                    // deleteing player names character

                    playerName[strlen(playerName) - 1] = '\0';
                    updatePlayerName();
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_SPACE && variables.levelOne == 1)
                {
                    space = 1;
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_UP || event.key.keysym.scancode == SDL_SCANCODE_W)
                {
                    // if player jumps up  color and position are toggled

                    L1CharYpos -= L1MovementSpeed * L1CharDeltatime + 400;
                    SDL_SetTextureColorMod(L1WindowChar.tex, 255, 255, 255);
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_DOWN || event.key.keysym.scancode == SDL_SCANCODE_S)
                {
                    // if player jumps down  color and position are toggled

                    L1CharYpos += L1MovementSpeed * L1CharDeltatime + 400;
                    SDL_SetTextureColorMod(L1WindowChar.tex, 255, 255, 255);
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT || event.key.keysym.scancode == SDL_SCANCODE_D)
                {
                    // if player jumps up  color and position are toggled

                    L1CharXpos += 50; // L1MovementSpeed * L1CharDeltatime + 40;
                    SDL_SetTextureColorMod(L1WindowChar.tex, 255, 255, 255);
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_LEFT || event.key.keysym.scancode == SDL_SCANCODE_A)
                {
                    // if player jumps down  color and position are toggled

                    L1CharXpos -= 50; // L1MovementSpeed * L1CharDeltatime + 40;
                    SDL_SetTextureColorMod(L1WindowChar.tex, 255, 255, 255);
                }
            }
            else if (event.type == SDL_TEXTINPUT && variables.levelOnePlayerName == 1)
            {
                // Not allowing player to copy paste for username

                if (strlen(playerName) < 10 && !(SDL_GetModState() & KMOD_CTRL && (event.text.text[0] == ' ' || event.text.text[0] == 'c' || event.text.text[0] == 'C' || event.text.text[0] == 'v' || event.text.text[0] == 'V')))
                {
                    strcat(playerName, event.text.text);
                    updatePlayerName();
                }
            }
        }

        // level two key events

        if (event.type == SDL_KEYDOWN && variables.levelTwoPlayerName == 1)
        {
            if (event.key.keysym.sym == SDLK_BACKSPACE && strlen(levelTwoPlayerName) > 1)
            {
                // deleteing player names character

                levelTwoPlayerName[strlen(levelTwoPlayerName) - 1] = '\0';
                updateLevelTwoPlayerName();
            }
        }
        if (event.type == SDL_TEXTINPUT && variables.levelTwoPlayerName == 1)
        {
            // Not allowing player to copy paste for username

            if (strlen(levelTwoPlayerName) < 10 && !(SDL_GetModState() & KMOD_CTRL && (event.text.text[0] == ' ' || event.text.text[0] == 'c' || event.text.text[0] == 'C' || event.text.text[0] == 'v' || event.text.text[0] == 'V')))
            {
                strcat(levelTwoPlayerName, event.text.text);
                updateLevelTwoPlayerName();
            }
        }
        if (variables.levelTwo == 1) // level Two Key Events
        {

            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
                {
                    spaceL2 = 1;
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT || event.key.keysym.scancode == SDL_SCANCODE_D)
                {
                    turningLeft_pressed = 0;
                    turningRight_pressed = 1;
                    SDL_SetTextureColorMod(L2_WindowChar.tex, 255, 255, 255);
                    if (L2_Char_X_pos < WINDOW_WIDTH - 300)
                    {
                        L2_Char_X_pos += MovementSpeed_L2 * L2_Char_Deltatime + 5;
                    }
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_LEFT || event.key.keysym.scancode == SDL_SCANCODE_A)
                {
                    turningLeft_pressed = 1;
                    turningRight_pressed = 0;
                    SDL_SetTextureColorMod(L2_WindowChar.tex, 255, 255, 255);
                    L2_Char_X_pos -= MovementSpeed_L2 * L2_Char_Deltatime + 5;
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_UP || event.key.keysym.scancode == SDL_SCANCODE_W)
                {

                    SDL_SetTextureColorMod(L2_WindowChar.tex, 255, 255, 255);
                    // handling the collision between invisible borders & the character and implementing the jumping effect of the character

                    SDL_bool collisionBetweenCharacterandInvisibleBorderOne = SDL_HasIntersection(&levelTwoInvisibleBorder[0].rect, &L2_WindowCharPosition.rect);
                    SDL_bool collisionBetweenCharacterandInvisibleBorderTwo = SDL_HasIntersection(&levelTwoInvisibleBorder[1].rect, &L2_WindowCharPosition.rect);

                    if (collisionBetweenCharacterandInvisibleBorderOne)
                    {
                        L2_Char_Y_pos += 100;
                    }
                    else if (collisionBetweenCharacterandInvisibleBorderTwo)
                    {
                        L2_Char_Y_pos += 100;
                    }
                    else if (L2_Char_Y_pos > 250)
                    {
                        Up_Pressed = 1;
                        L2_Char_Y_pos -= 70;
                    }
                    L2_Char_Y_pos -= MovementSpeed_L2 * L2_Char_Deltatime + 100;
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_DOWN || event.key.keysym.scancode == SDL_SCANCODE_S)
                {
                    Down_pressed = 1;
                    SDL_SetTextureColorMod(L2_WindowChar.tex, 255, 255, 255);
                }
            }
        }
    }

    // mouse events for all levels

    int mousex, mousey;
    int buttons = SDL_GetMouseState(&mousex, &mousey);
    if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
    {
        if (variables.gameWindowBegin == 1 && (mousex >= start_StartButton.rect.x && mousex <= (start_StartButton.rect.x + start_StartButton.rect.w) && mousey >= start_StartButton.rect.y && mousey <= (start_StartButton.rect.y + start_StartButton.rect.h)))
        {
            variables.chooseLevel = 1;
            variables.levelOne = 0;
            variables.levelTwo = 0;
            variables.gameWindowBegin = 0;
            variables.levelOneCompleted = 0;
            variables.levelOnePlayerName = 0;
            variables.newScore = 0;
            variables.ScoreBoard = 0;
            variables.levelOnegameOver = 0;
            variables.levelTwoScoreBoard = 0;
            variables.chooselevelWindow = 0;
            variables.newLevelTwoScore = 0;
            variables.creditWindow = 0;
            variables.levelTwoGameOver = 0;
            Mix_PlayChannel(-1, click, 0);
        }
        if (variables.gameWindowBegin == 1 && (mousex >= startCreditButton.rect.x && mousex <= (startCreditButton.rect.x + startCreditButton.rect.w) && mousey >= startCreditButton.rect.y && mousey <= (startCreditButton.rect.y + startCreditButton.rect.h)))
        {
            variables.creditWindow = 1;
            variables.levelOne = 0;
            variables.levelTwo = 0;
            variables.chooseLevel = 0;
            variables.gameWindowBegin = 0;
            variables.levelOneCompleted = 0;
            variables.levelOnePlayerName = 0;
            variables.newScore = 0;
            variables.ScoreBoard = 0;
            variables.levelOnegameOver = 0;
            variables.levelTwoScoreBoard = 0;
            variables.chooselevelWindow = 0;
            variables.newLevelTwoScore = 0;
            variables.levelTwoGameOver = 0;
            Mix_PlayChannel(-1, click, 0);
        }
        if (variables.chooseLevel == 1 && (mousex >= LevelChoiceWindowlevel_1_Button.rect.x && mousex <= (LevelChoiceWindowlevel_1_Button.rect.x + LevelChoiceWindowlevel_1_Button.rect.w) && mousey >= LevelChoiceWindowlevel_1_Button.rect.y && mousey <= (LevelChoiceWindowlevel_1_Button.rect.y + LevelChoiceWindowlevel_1_Button.rect.h)))
        {
            variables.levelOnePlayerName = 1;
            variables.levelOne = 0;
            variables.levelTwo = 0;
            variables.chooseLevel = 0;
            variables.gameWindowBegin = 0;
            variables.levelOneCompleted = 0;
            variables.newScore = 0;
            variables.ScoreBoard = 0;
            variables.levelOnegameOver = 0;
            variables.levelTwoScoreBoard = 0;
            variables.chooselevelWindow = 0;
            variables.newLevelTwoScore = 0;
            variables.creditWindow = 0;
            variables.levelTwoGameOver = 0;
            Mix_PlayChannel(-1, click, 0);
        }

        if (variables.chooseLevel == 1 && (mousex >= LevelChoiceWindowlevel_2_Button.rect.x && mousex <= (LevelChoiceWindowlevel_2_Button.rect.x + LevelChoiceWindowlevel_2_Button.rect.w) && mousey >= LevelChoiceWindowlevel_2_Button.rect.y && mousey <= (LevelChoiceWindowlevel_2_Button.rect.y + LevelChoiceWindowlevel_2_Button.rect.h)))
        {
            variables.levelTwoPlayerName = 1;
            variables.levelOne = 0;
            variables.levelTwo = 0;
            variables.chooseLevel = 0;
            variables.gameWindowBegin = 0;
            variables.levelOneCompleted = 0;
            variables.levelOnePlayerName = 0;
            variables.newScore = 0;
            variables.ScoreBoard = 0;
            variables.levelOnegameOver = 0;
            variables.levelTwoScoreBoard = 0;
            variables.chooselevelWindow = 0;
            variables.newLevelTwoScore = 0;
            variables.creditWindow = 0;
            variables.levelTwoGameOver = 0;
            Mix_PlayChannel(-1, click, 0);
        }

        if (strlen(playerName) > 1 && variables.levelOnePlayerName == 1 && (mousex >= enterButton.rect.x && mousex <= (enterButton.rect.x + enterButton.rect.w) && mousey >= enterButton.rect.y && mousey <= (enterButton.rect.y + enterButton.rect.h)))
        {
            variables.levelOne = 1;
            variables.levelTwo = 0;
            variables.chooseLevel = 0;
            variables.gameWindowBegin = 0;
            variables.levelOneCompleted = 0;
            variables.levelOnePlayerName = 0;
            variables.newScore = 1;
            variables.ScoreBoard = 0;
            variables.levelOnegameOver = 0;
            variables.levelTwoScoreBoard = 0;
            variables.chooselevelWindow = 0;
            variables.levelTwoPlayerName = 0;
            variables.newLevelTwoScore = 0;
            variables.creditWindow = 0;
            variables.levelTwoGameOver = 0;
            Mix_VolumeMusic(30); // adjusting volume
            Mix_PlayMusic(IndianaJones, 0);
            Mix_PlayChannel(-1, click, 0);
        }

        if (strlen(levelTwoPlayerName) > 1 && variables.levelTwoPlayerName == 1 && (mousex >= L2_EnterButton.rect.x && mousex <= (L2_EnterButton.rect.x + L2_EnterButton.rect.w) && mousey >= L2_EnterButton.rect.y && mousey <= (L2_EnterButton.rect.y + L2_EnterButton.rect.h)))
        {
            variables.levelTwo = 1;
            variables.levelOne = 0;
            variables.chooseLevel = 0;
            variables.gameWindowBegin = 0;
            variables.levelOneCompleted = 0;
            variables.levelOnePlayerName = 0;
            variables.newScore = 0;
            variables.ScoreBoard = 0;
            variables.levelOnegameOver = 0;
            variables.levelTwoScoreBoard = 0;
            variables.chooselevelWindow = 0;
            variables.levelTwoPlayerName = 0;
            variables.newLevelTwoScore = 1;
            variables.creditWindow = 0;
            variables.levelTwoGameOver = 0;
            Mix_PlayMusic(doom_ost, 0);
            Mix_PlayChannel(-1, click, 0);
        }

        if (variables.gameWindowBegin == 1 && (mousex >= startScoreBoardButton.rect.x && mousex <= (startScoreBoardButton.rect.x + startScoreBoardButton.rect.w) && mousey >= startScoreBoardButton.rect.y && mousey <= (startScoreBoardButton.rect.y + startScoreBoardButton.rect.h)))
        {
            variables.chooselevelWindow = 1;
            variables.levelOne = 0;
            variables.levelTwo = 0;
            variables.chooseLevel = 0;
            variables.gameWindowBegin = 0;
            variables.levelOneCompleted = 0;
            variables.levelOnePlayerName = 0;
            variables.newScore = 0;
            variables.ScoreBoard = 0;
            variables.levelOnegameOver = 0;
            variables.levelTwoScoreBoard = 0;
            variables.levelTwoPlayerName = 0;
            variables.newLevelTwoScore = 0;
            variables.creditWindow = 0;
            variables.levelTwoGameOver = 0;
            Mix_PlayChannel(-1, click, 0);
        }
        if (variables.chooselevelWindow == 1 && (mousex >= L1_ScoreButton.rect.x && mousex <= (L1_ScoreButton.rect.x + L1_ScoreButton.rect.w) && mousey >= L1_ScoreButton.rect.y && mousey <= (L1_ScoreButton.rect.y + L1_ScoreButton.rect.h)))
        {
            variables.ScoreBoard = 1;
            variables.levelOne = 0;
            variables.levelTwo = 0;
            variables.chooseLevel = 0;
            variables.gameWindowBegin = 0;
            variables.levelOneCompleted = 0;
            variables.levelOnePlayerName = 0;
            variables.newScore = 0;
            variables.levelOnegameOver = 0;
            variables.levelTwoScoreBoard = 0;
            variables.chooselevelWindow = 0;
            variables.levelTwoPlayerName = 0;
            variables.newLevelTwoScore = 0;
            variables.creditWindow = 0;
            variables.levelTwoGameOver = 0;
            Mix_PlayChannel(-1, click, 0);
        }

        if (variables.chooselevelWindow == 1 && (mousex >= L2_ScoreButtonn.rect.x && mousex <= (L2_ScoreButtonn.rect.x + L2_ScoreButtonn.rect.w) && mousey >= L2_ScoreButtonn.rect.y && mousey <= (L2_ScoreButtonn.rect.y + L2_ScoreButtonn.rect.h)))
        {
            variables.levelTwoScoreBoard = 1;
            variables.levelOne = 0;
            variables.levelTwo = 0;
            variables.chooseLevel = 0;
            variables.gameWindowBegin = 0;
            variables.levelOneCompleted = 0;
            variables.levelOnePlayerName = 0;
            variables.newScore = 0;
            variables.ScoreBoard = 0;
            variables.levelOnegameOver = 0;
            variables.chooselevelWindow = 0;
            variables.levelTwoPlayerName = 0;
            variables.newLevelTwoScore = 0;
            variables.creditWindow = 0;
            variables.levelTwoGameOver = 0;
            Mix_PlayChannel(-1, click, 0);
        }

        if (variables.gameWindowBegin == 1 && (mousex >= startExitButton.rect.x && mousex <= (startExitButton.rect.x + startExitButton.rect.w) && mousey >= startExitButton.rect.y && mousey <= (startExitButton.rect.y + startExitButton.rect.h)))
        {
            exit(0);
        }
        if (mousex >= back.rect.x && mousex <= (back.rect.x + back.rect.w) && mousey >= back.rect.y && mousey <= (back.rect.y + back.rect.h))
        {

            if (variables.levelOneCompleted == 1 || variables.levelTwoCompleted == 1 || variables.levelOne == 1 || variables.levelTwo == 1 || variables.levelTwoGameOver == 1 || variables.levelOnegameOver == 1)
            {
                Mix_PlayMusic(background_music, -1);
            }
            // if player wants to go back reseting the windows

            resetAll();
        }
    }

    // Hover Effects for Buttons

    if (variables.gameWindowBegin == 1 && (mousex >= start_StartButton.rect.x && mousex <= (start_StartButton.rect.x + start_StartButton.rect.w) && mousey >= start_StartButton.rect.y && mousey <= (start_StartButton.rect.y + start_StartButton.rect.h)))
    {
        SDL_SetTextureColorMod(start_StartButton.tex, 100, 255, 255);
    }
    else
        SDL_SetTextureColorMod(start_StartButton.tex, 255, 255, 255);

    if (variables.gameWindowBegin == 1 && (mousex >= startCreditButton.rect.x && mousex <= (startCreditButton.rect.x + startCreditButton.rect.w) && mousey >= startCreditButton.rect.y && mousey <= (startCreditButton.rect.y + startCreditButton.rect.h)))
    {
        SDL_SetTextureColorMod(startCreditButton.tex, 100, 255, 255);
    }
    else
        SDL_SetTextureColorMod(startCreditButton.tex, 255, 255, 255);

    if (variables.chooseLevel == 1 && (mousex >= LevelChoiceWindowlevel_1_Button.rect.x && mousex <= (LevelChoiceWindowlevel_1_Button.rect.x + LevelChoiceWindowlevel_1_Button.rect.w) && mousey >= LevelChoiceWindowlevel_1_Button.rect.y && mousey <= (LevelChoiceWindowlevel_1_Button.rect.y + LevelChoiceWindowlevel_1_Button.rect.h)))
    {
        SDL_SetTextureColorMod(LevelChoiceWindowlevel_1_Button.tex, 100, 255, 255); // cyan on levelone button
    }
    else
        SDL_SetTextureColorMod(LevelChoiceWindowlevel_1_Button.tex, 255, 255, 255);

    if (variables.chooseLevel == 1 && (mousex >= LevelChoiceWindowlevel_2_Button.rect.x && mousex <= (LevelChoiceWindowlevel_2_Button.rect.x + LevelChoiceWindowlevel_2_Button.rect.w) && mousey >= LevelChoiceWindowlevel_2_Button.rect.y && mousey <= (LevelChoiceWindowlevel_2_Button.rect.y + LevelChoiceWindowlevel_2_Button.rect.h)))
    {
        SDL_SetTextureColorMod(LevelChoiceWindowlevel_2_Button.tex, 100, 255, 255);
    }
    else
        SDL_SetTextureColorMod(LevelChoiceWindowlevel_2_Button.tex, 255, 255, 255);

    if (strlen(playerName) > 1 && variables.levelOnePlayerName == 1 && (mousex >= enterButton.rect.x && mousex <= (enterButton.rect.x + enterButton.rect.w) && mousey >= enterButton.rect.y && mousey <= (enterButton.rect.y + enterButton.rect.h)))
    {
        SDL_SetTextureColorMod(enterButton.tex, 100, 255, 255);
    }
    else
        SDL_SetTextureColorMod(enterButton.tex, 255, 255, 255);

    if (strlen(levelTwoPlayerName) > 1 && variables.levelTwoPlayerName == 1 && (mousex >= L2_EnterButton.rect.x && mousex <= (L2_EnterButton.rect.x + L2_EnterButton.rect.w) && mousey >= L2_EnterButton.rect.y && mousey <= (L2_EnterButton.rect.y + L2_EnterButton.rect.h)))
    {
        SDL_SetTextureColorMod(L2_EnterButton.tex, 100, 255, 255);
    }
    else
        SDL_SetTextureColorMod(L2_EnterButton.tex, 255, 255, 255);

    if (variables.gameWindowBegin == 1 && (mousex >= startScoreBoardButton.rect.x && mousex <= (startScoreBoardButton.rect.x + startScoreBoardButton.rect.w) && mousey >= startScoreBoardButton.rect.y && mousey <= (startScoreBoardButton.rect.y + startScoreBoardButton.rect.h)))
    {
        SDL_SetTextureColorMod(startScoreBoardButton.tex, 100, 255, 255);
    }
    else
        SDL_SetTextureColorMod(startScoreBoardButton.tex, 255, 255, 255);
    if (variables.chooselevelWindow == 1 && (mousex >= L1_ScoreButton.rect.x && mousex <= (L1_ScoreButton.rect.x + L1_ScoreButton.rect.w) && mousey >= L1_ScoreButton.rect.y && mousey <= (L1_ScoreButton.rect.y + L1_ScoreButton.rect.h)))
    {
        SDL_SetTextureColorMod(L1_ScoreButton.tex, 100, 255, 255);
    }
    else
        SDL_SetTextureColorMod(L1_ScoreButton.tex, 255, 255, 255);
    if (variables.chooselevelWindow == 1 && (mousex >= L2_ScoreButtonn.rect.x && mousex <= (L2_ScoreButtonn.rect.x + L2_ScoreButtonn.rect.w) && mousey >= L2_ScoreButtonn.rect.y && mousey <= (L2_ScoreButtonn.rect.y + L2_ScoreButtonn.rect.h)))
    {
        SDL_SetTextureColorMod(L2_ScoreButtonn.tex, 100, 255, 255);
    }
    else
        SDL_SetTextureColorMod(L2_ScoreButtonn.tex, 255, 255, 255);

    if (variables.gameWindowBegin == 1 && (mousex >= startExitButton.rect.x && mousex <= (startExitButton.rect.x + startExitButton.rect.w) && mousey >= startExitButton.rect.y && mousey <= (startExitButton.rect.y + startExitButton.rect.h)))
    {
        SDL_SetTextureColorMod(startExitButton.tex, 100, 255, 255);
    }
    else
        SDL_SetTextureColorMod(startExitButton.tex, 255, 255, 255);
    if (mousex >= back.rect.x && mousex <= (back.rect.x + back.rect.w) && mousey >= back.rect.y && mousey <= (back.rect.y + back.rect.h))
    {
        SDL_SetTextureColorMod(back.tex, 100, 255, 255);
    }
    else
        SDL_SetTextureColorMod(back.tex, 255, 255, 255);
}
