#include <iostream>
#include <SDL2/SDL.h>

using namespace std;
int main()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL init failed." << endl;
        return -1;

    }

    std::cout << "SDL init succeeded" << std::endl;

    SDL_Quit();
    return 0;
}