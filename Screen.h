//
// Created by plex on 9/20/16.
//

#ifndef THEPARTICLEFIRESIMULATION_SCREEN_H
#define THEPARTICLEFIRESIMULATION_SCREEN_H

#include <iostream>
#include <SDL2/SDL.h>


using namespace std;

namespace ParticleFireSimulation
{

    class Screen
    {
    public:
        const int static SCREEN_WIDTH = 800;
        const int static SCREEN_HEIGHT = 600;
    public:
        Screen() : _window(NULL), _renderer(NULL), _texture(NULL), _buffer(NULL)
        {}
        bool init()
        {
            if (SDL_Init(SDL_INIT_VIDEO) < 0)
            {
                cout << "SDL init failed." << endl;
                return false;
            }

            cout << "SDL init succeeded" << endl;

            _window = SDL_CreateWindow(
                    "Particle Fire Explosion",
                    SDL_WINDOWPOS_UNDEFINED,
                    SDL_WINDOWPOS_UNDEFINED,
                    SCREEN_WIDTH,
                    SCREEN_HEIGHT,
                    SDL_WINDOW_SHOWN);

            if (_window == NULL)
            {
                SDL_Quit();
                return false;
            }

            _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);
            if (_renderer == NULL)
            {
                cout << "Could not create renderer" << endl;
                SDL_DestroyWindow(_window);
                SDL_Quit();
                return false;
            }

            _texture = SDL_CreateTexture(_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH,
                                         SCREEN_HEIGHT);

            if (_texture == NULL)
            {
                cout << "Could not create renderer" << endl;
                SDL_DestroyRenderer(_renderer);
                SDL_DestroyWindow(_window);
                SDL_Quit();
                return false;
            }

            _buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
            //setting the color
            memset(_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

            //setting pixel color
            for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++)
            {
                _buffer[i] = 0xFF0000FF;
            }


            return true;
        }

        bool processEvents()
        {
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                    return false;
            }
            return true;
        }

        void update()
        {
            SDL_UpdateTexture(_texture, NULL, _buffer, SCREEN_WIDTH * sizeof(Uint32));
            SDL_RenderClear(_renderer);
            SDL_RenderCopy(_renderer, _texture, NULL, NULL);
            SDL_RenderPresent(_renderer);
        }
        void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
        {
            Uint32 color = 0;

            color += red;
            color <<= 8;
            color += green;
            color <<= 8;
            color += blue;
            color <<= 8;
            color += 0xFF;

            _buffer[(y * SCREEN_WIDTH) + x] = color;

        }
        void close()
        {
            delete[] _buffer;

            SDL_DestroyRenderer(_renderer);
            SDL_DestroyTexture(_texture);
            SDL_DestroyWindow(_window);
            SDL_Quit();
        }

    private:
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        SDL_Texture *_texture;
        Uint32 *_buffer;

    };

}
#endif //THEPARTICLEFIRESIMULATION_SCREEN_H
