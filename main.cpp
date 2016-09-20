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
        if (screen.processEvents() == false)
            break;
    }

    //screen.close();
    return 0;
}