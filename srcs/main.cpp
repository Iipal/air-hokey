#include "air_hokey.hpp"

int	main(void)
{
    AirHokey    ah("Air Hokey", 1280, 600);
    bool        quit = false;

    while (!quit)
    {
        while (0 < SDL_PollEvent(ah.sdl->get_event_addr()))
            if (SDL_QUIT == ah.sdl->get_event_type())
                quit = true;
            else if (SDL_KEYDOWN == ah.sdl->get_event_type()
                && SDLK_ESCAPE == ah.sdl->get_keycode())
                quit = true;
        // ah.rendering();
    }
}
