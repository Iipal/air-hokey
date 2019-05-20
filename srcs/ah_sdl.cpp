#include "ah_sdl.hpp"

Sdl::Sdl(const std::string title, const int32_t w, const int32_t h) {
    if (0 > SDL_Init(SDL_INIT_EVERYTHING)) {
        std::cout << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
    this->win = SDL_CreateWindow(title.c_str(),
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        w, h, SDL_WINDOW_SHOWN);
    if (!this->win) {
        std::cout << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
    this->winSurface = SDL_GetWindowSurface(this->win);
    if (!this->winSurface)
    {
        std::cout << SDL_GetError() << std::endl;
        SDL_DestroyWindow(this->win);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
}

inline void Sdl::sdl_pixelput(SDL_Surface *surf,
                            const int32_t x,
                            const int32_t y,
                            const Uint32 color)
{
    if (0 <= x && 0 <= y && y < surf->h && y < surf->w)
        ((Uint32*)surf->pixels)[y * surf->h + x] = color;
}

inline SDL_Event    *Sdl::sdl_get_event_addr(void)
{
    return &this->events;
}

inline Uint32   Sdl::sdl_get_event_type(void)
{
    return this->events.type;
}


Sdl::~Sdl() {
    if (this->win)
        SDL_DestroyWindow(this->win);
    SDL_Quit();
}
