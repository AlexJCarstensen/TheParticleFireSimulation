#include <iostream>
#include <SDL2/SDL.h>

#include "Screen.h"

using namespace std;
using namespace ParticleFireSimulation;
int main()
{

    Screen screen;

    if(screen.init() == false)
        cout << "Error initializing SDL." << endl;

    while(true)
    {

        int elapsed = SDL_GetTicks();
        unsigned char green = (1 + sin(elapsed * 0.001)) *  128;
        unsigned char red = (1 + sin(elapsed * 0.002)) *  128;
        unsigned char blue = (1 + sin(elapsed * 0.003)) *  128;


        for (int y = 0; y < Screen::SCREEN_HEIGHT; y++)
        {
            for (int x = 0; x < Screen::SCREEN_WIDTH; x++)
            {
                screen.setPixel(x, y, red, green, blue);
            }
        }

        screen.setPixel(400, 300, 255, 255 ,255);

        screen.update();

        if (screen.processEvents() == false)
            break;
    }

    screen.close();
    return 0;
}