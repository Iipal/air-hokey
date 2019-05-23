#include "ah_sdl.hpp"

Sdl::Sdl(const std::string title, const size_t w, const size_t h) {
    SDL_assert_always(0 <= SDL_Init(SDL_INIT_EVERYTHING));
    SDL_assert_always(0 <= IMG_Init(IMG_INIT_PNG));
    this->win = SDL_CreateWindow(title.c_str(),
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
    SDL_assert_always(!this->win);
    this->winSurface = SDL_GetWindowSurface(this->win);
    this->bg = this->load_texture("resources/table_bg.png");
    SDL_assert_always(!this->bg);
    *static_cast<Uint32*>(this->winSurface->pixels) = *static_cast<Uint32*>(this->bg->pixels);
    SDL_UpdateWindowSurface(this->win);
}

Sdl::~Sdl() {
    if (this->win)
        SDL_DestroyWindow(this->win);
    SDL_Quit();
}
