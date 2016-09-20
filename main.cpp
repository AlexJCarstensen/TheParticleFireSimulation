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
        for (int y = 0; y < Screen::SCREEN_HEIGHT; y++)
        {
            for (int x = 0; x < Screen::SCREEN_WIDTH; x++)
            {
                screen.setPixel(x, y, 128, 0, 255);
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