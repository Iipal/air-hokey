#pragma once

#include <iostream>
#include <SDL2/SDL.h>

struct  Sdl
{
    Sdl(const std::string title, const int32_t w, const int32_t h);
    ~Sdl();

    void        sdl_pixelput(SDL_Surface *surf,
                            const int32_t x,
                            const int32_t y,
                            const Uint32 color);
    SDL_Event   *sdl_get_event_addr(void);
    Uint32      sdl_get_event_type(void);

    private:
        SDL_Window  *win;
        SDL_Surface *winSurface;
        SDL_Event   events;
};
