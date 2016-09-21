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
        Screen() : window_(NULL), renderer_(NULL), texture_(NULL), buffer_(NULL), buffer2_(NULL)
        {}

        bool init()
        {
            if (SDL_Init(SDL_INIT_VIDEO) < 0)
                return false;

            window_ = SDL_CreateWindow(
                    "Particle Fire Explosion",
                    SDL_WINDOWPOS_UNDEFINED,
                    SDL_WINDOWPOS_UNDEFINED,
                    SCREEN_WIDTH,
                    SCREEN_HEIGHT,
                    SDL_WINDOW_SHOWN);

            if (window_ == NULL)
            {
                SDL_Quit();
                return false;
            }

            renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_PRESENTVSYNC);
            if (renderer_ == NULL)
            {
                cout << "Could not create renderer" << endl;
                SDL_DestroyWindow(window_);
                SDL_Quit();
                return false;
            }

            texture_ = SDL_CreateTexture(renderer_, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH,
                                         SCREEN_HEIGHT);

            if (texture_ == NULL)
            {
                cout << "Could not create renderer" << endl;
                SDL_DestroyRenderer(renderer_);
                SDL_DestroyWindow(window_);
                SDL_Quit();
                return false;
            }

            buffer_ = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
            buffer2_ = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
            clear();

            return true;
        }

        void blur()
        {
            Uint32 *temp = buffer_;
            buffer_ = buffer2_;
            buffer2_ = temp;

            for (int y = 0; y < SCREEN_HEIGHT; y++)
            {
                for (int x = 0; x < SCREEN_WIDTH; x++)
                {
                    int redTotal = 0;
                    int greenTotal = 0;
                    int blueTotal = 0;

                    for (int row = -1; row <= 1; row++)
                    {
                        for (int col = -1; col <= 1; col++)
                        {
                            int currentX = x + col;
                            int currentY = y + row;

                            if (currentX >= 0 && currentX < SCREEN_WIDTH && currentY >= 0 && currentY < SCREEN_HEIGHT)
                            {
                                Uint32 color = buffer2_[currentY * SCREEN_WIDTH + currentX];
                                Uint8 red = color >> 24;
                                Uint8 green = color >> 16;
                                Uint8 blue = color >> 8;

                                redTotal += red;
                                greenTotal += green;
                                blueTotal += blue;
                            }
                        }
                    }
                    Uint8 red = redTotal / 9;
                    Uint8 green = greenTotal / 9;
                    Uint8 blue = blueTotal / 9;
                    setPixel(x,y,red,green, blue);
                }
            }
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
            SDL_UpdateTexture(texture_, NULL, buffer_, SCREEN_WIDTH * sizeof(Uint32));
            SDL_RenderClear(renderer_);
            SDL_RenderCopy(renderer_, texture_, NULL, NULL);
            SDL_RenderPresent(renderer_);

        }

        void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
        {
            if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
                return;

            Uint32 color = 0;

            color += red;
            color <<= 8;
            color += green;
            color <<= 8;
            color += blue;
            color <<= 8;
            color += 0xFF;

            buffer_[(y * SCREEN_WIDTH) + x] = color;

        }

        void clear()
        {
            memset(buffer_, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
            memset(buffer2_, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
        }

        void close()
        {
            delete[] buffer_;
            delete[] buffer2_;

            SDL_DestroyRenderer(renderer_);
            SDL_DestroyTexture(texture_);
            SDL_DestroyWindow(window_);
            SDL_Quit();
        }

    private:
        SDL_Window *window_;
        SDL_Renderer *renderer_;
        SDL_Texture *texture_;
        Uint32 *buffer_;
        Uint32 *buffer2_;

    };

}
#endif //THEPARTICLEFIRESIMULATION_SCREEN_H
