#include "Input.h"

bool engine::Input::isQuit() {
    SDL_Event event;

    if (!SDL_WaitEventTimeout(&event, engine::Input::EVENT_TIMEOUT)) {
        return false;
    }

    return event.type == SDL_QUIT;
}

void engine::Input::handle(component::Figure *fig) {
    SDL_Event event;

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
