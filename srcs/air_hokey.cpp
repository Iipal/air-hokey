#include "air_hokey.hpp"

AirHokey::AirHokey()
{
}

AirHokey::AirHokey(const std::string title, const size_t w, const size_t h) {
    this->sdl = new Sdl(title, w, h);
}

void AirHokey::rendering()
{
    size_t y = ~0L, x;

    while (++y < this->sdl->get_win_h() && (x = ~0L))
        while (++x < this->sdl->get_win_w())
            this->sdl->pixelput(x, y, 0xffaffa, this->sdl->get_win_w(), this->sdl->get_win_h());
    SDL_UpdateWindowSurface(this->sdl->get_win());
}

AirHokey::~AirHokey()
{
    delete this->sdl;
}
