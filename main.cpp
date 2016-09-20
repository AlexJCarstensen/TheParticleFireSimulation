#include <iostream>
#include <SDL2/SDL.h>

#include "Screen.h"
#include "Swarm.h"


using namespace std;
using namespace ParticleFireSimulation;

int main()
{

    Screen screen;

    screen.init();

    Swarm swarm;

    while(true)
    {
        int elapsed = SDL_GetTicks();

        unsigned char green = (1 + sin(elapsed * 0.001)) *  128;
        unsigned char red = (1 + sin(elapsed * 0.002)) *  128;
        unsigned char blue = (1 + sin(elapsed * 0.003)) *  128;

        const Particle * const particles = swarm.getParticles();
        for (int i = 0; i < Swarm::NParticles; i++)
        {
            Particle particle = particles[i];

            int x = (particle.getX() + 1) * Screen::SCREEN_WIDTH/2;
            int y = (particle.getY() + 1) * Screen::SCREEN_HEIGHT/2;
            screen.setPixel(x,y,red, green, blue);
        }



//
//        for (int y = 0; y < Screen::SCREEN_HEIGHT; y++)
//        {
//            for (int x = 0; x < Screen::SCREEN_WIDTH; x++)
//            {
//                screen.setPixel(x, y, red, green, blue);
//            }
//        }
//
//        screen.setPixel(400, 300, 255, 255 ,255);

        screen.update();

        if (screen.processEvents() == false)
            break;
    }

    screen.close();
    return 0;
}