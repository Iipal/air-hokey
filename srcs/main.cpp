#include "air_hokey.hpp"

int	main(void)
{
    AirHokey    ah;
    bool        quit;

    ah.sdl_init("Air Hokey", 1000, 500);

    quit = false;
    while (!quit)
        while (0 < SDL_PollEvent(ah.sdl->sdl_get_event_addr()))
            if (SDL_QUIT == ah.sdl->sdl_get_event_type())
                quit = true;
            else if (SDL_KEYDOWN == ah.sdl->sdl_get_event_type())
                quit = true;
}
