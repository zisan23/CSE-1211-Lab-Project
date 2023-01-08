#include "drawlevelTwoTracks.h"


void JumpingEffectCharacter()
{    
    SDL_bool collisionBetweenCharacterandTrackOne =  SDL_HasIntersection(&levelTwoTrack[0].rect , &L2_WindowCharPosition.rect);
    SDL_bool collisionBetweenCharacterandTrackTwo =  SDL_HasIntersection(&levelTwoTrack[1].rect , &L2_WindowCharPosition.rect);
    SDL_bool collisionBetweenCharacterandInvisibleBorderOne =  SDL_HasIntersection(&levelTwoInvisibleBorder[0].rect , &L2_WindowCharPosition.rect);
    SDL_bool collisionBetweenCharacterandInvisibleBorderTwo =  SDL_HasIntersection(&levelTwoInvisibleBorder[1].rect , &L2_WindowCharPosition.rect);
    
    // keeping the character below the tracks
    if(collisionBetweenCharacterandInvisibleBorderOne)
    {
        L2_Char_Y_pos  +=5;
        Down_pressed = 0;
    }
    else if(collisionBetweenCharacterandInvisibleBorderTwo)
    {
        L2_Char_Y_pos   +=5;
        Down_pressed = 0;
    }
    // enabling the character walking on the tracks 
    else if(collisionBetweenCharacterandTrackOne && Up_Pressed ==0)
    {
        Down_pressed = 0;
        L2_Char_Y_pos =  levelTwoTrack[0].rect.y - L2_WindowChar.rect.w -5 ;
    }
    else if(collisionBetweenCharacterandTrackTwo  && Up_Pressed ==0)
    {
        Down_pressed = 0;
        L2_Char_Y_pos =  levelTwoTrack[1].rect.y - L2_WindowChar.rect.w - 5 ;
    }
    // if the character is not colliding with the tracks or invisible borders then it falls automatically 
    if((!collisionBetweenCharacterandTrackOne && !collisionBetweenCharacterandTrackTwo ) || abs(levelTwoTrack[1].rect.y  -  L2_Char_Y_pos - L2_WindowChar.rect.w)>=6 ||  abs(levelTwoTrack[0].rect.y  -  L2_Char_Y_pos - L2_WindowChar.rect.w)>=6 )
    {
        if (L2_Char_Y_pos != WINDOW_HEIGHT)
        {
            L2_Char_Y_pos += 3;
        }

        if (L2_Char_Y_pos >= WINDOW_HEIGHT - 250)
        {
            L2_Char_Y_pos = WINDOW_HEIGHT - 250;
        }
    }
    if(Up_Pressed ==1)
    {
        Up_Pressed =0;
    }

    if(Down_pressed==1 && L2_Char_Y_pos <= WINDOW_HEIGHT - 260  )
    {
        L2_Char_Y_pos  +=70;
        Down_pressed=0;
    }

}
void levelTwoTrackmotion()
{    
    L1CharPrevtime = L1CharCurrentime;  
    L1CharCurrentime = SDL_GetTicks();
    L1CharDeltatime = (L1CharCurrentime - L1CharPrevtime) / 280.0f;

    L2_Track_X_pos1 -= MovementSpeed_L2 / 3 * L1CharDeltatime;
    L2_Track_X_pos2 -= MovementSpeed_L2 / 3 * L1CharDeltatime;

        if (L2_Track_X_pos1 + levelTwoTrack[0].rect.w <=0)
        {

            L2_Track_X_pos1 = WINDOW_WIDTH;
            levelTwoTrack[0].rect.y = rand() % WINDOW_HEIGHT;
            updateCoinsPosition();
        }

        if (L2_Track_X_pos2 + levelTwoTrack[0].rect.w <=0)
        {

            L2_Track_X_pos2 = L2_Track_X_pos1 + 900 ;
            levelTwoTrack[1].rect.y = levelTwoTrack[0].rect.y -100;
        }

        levelTwoInvisibleBorder[0].rect.y = levelTwoTrack[0].rect.y + levelTwoTrack[0].rect.h; 
        levelTwoInvisibleBorder[0].rect.x = L2_Track_X_pos1;
        levelTwoInvisibleBorder[1].rect.y = levelTwoTrack[1].rect.y + levelTwoTrack[0].rect.h; 
        levelTwoInvisibleBorder[1].rect.x = L2_Track_X_pos2;

        levelTwoTrack[0].rect.x =L2_Track_X_pos1;
        levelTwoTrack[1].rect.x =L2_Track_X_pos2;
        
 
        JumpingEffectCharacter();
     
}
void drawLevelTwoTrackFunction()
{
    
    SDL_RenderCopy(app.rend, levelTwoTrack[0].tex, NULL, &levelTwoTrack[0].rect);
    levelTwoTrack[0].rect.x = L2_Track_X_pos1 + levelTwoTrack[0].rect.w ;
    SDL_RenderCopy(app.rend, levelTwoTrack[1].tex, NULL, &levelTwoTrack[1].rect);
    levelTwoTrack[1].rect.x = L2_Track_X_pos2 + levelTwoTrack[1].rect.w ;
}

