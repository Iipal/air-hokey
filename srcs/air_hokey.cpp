#include "air_hokey.hpp"

AirHokey::AirHokey()
{
}

void AirHokey::sdl_init(const std::string title,
                        const int32_t w,
                        const int32_t h)
{
    this->sdl = new Sdl(title, w, h);
}

AirHokey::~AirHokey()
{
    delete this->sdl;
}
