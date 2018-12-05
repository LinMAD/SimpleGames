#include <iostream>
#include "Input.h"

void engine::Input::handle(component::Figure *fig) {
    SDL_Event event;

    if (!SDL_WaitEventTimeout(&event, engine::Input::EVENT_TIMEOUT)) {
        return;
    }

    if (event.type == SDL_QUIT) {
        throw std::runtime_error("Quit game");
    }

    if (event.type != SDL_KEYDOWN) {
        return;
    }

    switch (event.key.keysym.sym) {
        case SDLK_DOWN:
            fig->move(0, 1);
            break;
        case SDLK_RIGHT:
            fig->move(1, 0);
            break;
        case SDLK_LEFT:
            fig->move(-1, 0);
            break;
        case SDLK_UP:
            fig->rotate();
            break;
        default:
            break;
    }
}
