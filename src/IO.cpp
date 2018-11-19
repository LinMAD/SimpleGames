#include <iostream>
#include "IO.h"

using namespace std;

static SDL_Surface *sdlScreen_;
static Uint32 ioColors_[IO_C_COLOR_MAX] = {
        0x000000ff, 0xff0000ff, 0x00ff00ff, 0x0000ffff,
        0x00ffffff, 0xff00ffff, 0xffff00ff, 0xffffffff
};

IO::IO() {
    InitGraph();
}

int IO::InitGraph() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Unable initialize SDL library" << SDL_GetError() << endl;

        return 1;
    }

    window_ = SDL_CreateWindow(
            "SovietTetris",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN
    );
    if (window_ == nullptr) {
        cout << "Unable to set video(640x480) mode" << SDL_GetError() << endl;

        return 1;
    }

    render_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_PRESENTVSYNC);
    if (render_ == nullptr) {
        return 1;
    }

    texture_ = SDL_CreateTexture(
            render_,
            SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_STATIC,
            SCREEN_WIDTH,
            SCREEN_HEIGHT
    );
    if (texture_ == nullptr) {
        return 1;
    }

    buffer_ = new Uint32[SCREEN_RESOLUTION];
    ClearScreen();

    return 0;
}

void IO::ClearScreen() {
    int memsetSize = SCREEN_RESOLUTION * sizeof(Uint32);

    memset(buffer_, 0, static_cast<size_t>(memsetSize));
}

void IO::UpdateScreen() {
    SDL_UpdateTexture(texture_, nullptr, buffer_, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(render_);
    SDL_RenderCopy(render_, texture_, nullptr, nullptr);
    SDL_RenderPresent(render_);
}

void IO::DrawRectangle(int x1, int y1, int x2, int y2, enum IOColor color) {

}

int IO::GetScreenHeight() {
    return sdlScreen_->h;
}

int IO::HandleEventKeyPoll() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
                return event.key.keysym.sym;
            case SDL_QUIT:
                exit(0);
        }
    }

    return 1;
}


