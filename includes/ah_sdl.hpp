#pragma once

#include <iostream>
#include <SDL2/SDL.h>

struct  Sdl
{
    Sdl(const std::string title, const size_t w, const size_t h);
    ~Sdl();

    inline void
    pixelput(const size_t x, const size_t y, Uint32 color) {
        if (y < this->get_win_h() && x < this->get_win_w())
            ((Uint32*)this->winSurface->pixels)[y * this->get_win_h() + x] = color;
    }

    inline SDL_Event* __attribute__((__always_inline__,__artificial__))
    get_event_addr() { return &this->events; }

    inline Uint32 __attribute__((__always_inline__,__artificial__))
    get_event_type() { return this->events.type; }

    inline size_t __attribute__((__always_inline__,__artificial__))
    get_win_h() { return this->winSurface->h; }
    inline size_t __attribute__((__always_inline__,__artificial__))
    get_win_w() { return this->winSurface->w; }
    inline SDL_Window* __attribute__((__always_inline__,__artificial__))
    get_win() { return this->win; }

    inline SDL_Keycode __attribute__((__always_inline__,__artificial__))
    get_keycode() { return this->events.key.keysym.sym; }

    private:
        SDL_Window  *win;
        SDL_Surface *winSurface;
        SDL_Event   events;
};
