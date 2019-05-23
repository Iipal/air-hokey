#include "ah_sdl.hpp"

Sdl::Sdl(const std::string title, const size_t w, const size_t h) {
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

Sdl::~Sdl() {
    if (this->win)
        SDL_DestroyWindow(this->win);
    SDL_Quit();
}
