#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

struct  Sdl
{
    Sdl(const std::string title, const size_t w, const size_t h);
    ~Sdl();

    inline SDL_Surface* __attribute__((__always_inline__,__artificial__))
    load_texture(const std::string path)
    {
        SDL_Surface *temp = NULL;
        SDL_Surface *optimize_out = NULL;
        SDL_assert_always(temp = IMG_Load(path.c_str()));
        SDL_assert_always(optimize_out = SDL_ConvertSurface(temp, this->winSurface->format, 0));
        return optimize_out;
    }

    inline void __attribute__((__always_inline__,__artificial__))
    pixelput(const size_t x, const size_t y, Uint32 color, const size_t w, const size_t h) {
        if (y < h && x < w)
            static_cast<Uint32*>(this->winSurface->pixels)[y * w + x] = color;
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
        SDL_Surface *bg;
        SDL_Event   events;
};
