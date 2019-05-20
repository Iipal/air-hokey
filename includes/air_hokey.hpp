#pragma once

#include <iostream>
#include <stdint.h>

#include "ah_sdl.hpp"

class AirHokey
{
public:
    AirHokey();
    ~AirHokey();

    void    sdl_init(const std::string title, const int32_t w, const int32_t h);

    Sdl *sdl;
};
