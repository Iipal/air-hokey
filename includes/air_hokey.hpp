#pragma once

#include <iostream>
#include <stdint.h>

#include "ah_sdl.hpp"

class AirHokey
{
public:
    AirHokey();
    AirHokey(const std::string title, const size_t w, const size_t h);

    void    rendering(void);

    ~AirHokey();

    Sdl *sdl;
};
