#include "main.h"
int main(int argc, char *argv[])
{
    printf("WELCOME TO\n");

    printf("RRRRR   IIIII   OOOOO   TTTTT  \n");
    printf("R   R     I     O   O     T    \n");
    printf("RRRRR     I     O   O     T    \n");
    printf("R  R      I     O   O     T    \n");
    printf("R  RR . IIIII . OOOOO .   T   .\n");

    printf("    Game Started Successfully !!!\n");
    printf("            Enjoy the Game!!!\n");

    memset(&app, 0, sizeof(App));
    initSDL(); // in init.cpp file
    atexit(cleanup);
    Mix_PlayMusic(background_music, -1); // playing background music on start
    while (1)
    {
        prepareScene(); // in draw.cpp file
        doInput();      // in input.cpp file
        presentScene(); // in draw.cpp file
    }
    return 0;
}
