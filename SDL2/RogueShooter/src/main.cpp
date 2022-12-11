#include "Core/WindowManager.h"
#include "Core/AssetManager.h"
#include "Charaters/BaseActor.h"

#include <iostream>
#include <SDL2/SDL.h>

bool isGameRunning = true;

int main(int argc, char* argv[])
{
    WindowManager windowManager("Rogue Shooter");
    windowManager.Init();

    AssetManager assetManager(windowManager.GetRenderer());
    assetManager.AddTexture("player", "assets/characters/player.bmp", SDL_FPoint{ 18, 25 });

    BaseActor playerActor(&assetManager, "player");

    while (isGameRunning)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // Check if the user has closed the window
            if (event.type == SDL_QUIT)
            {
                isGameRunning = false;
            }
        }

        // Update the game state
        SDL_RenderClear(windowManager.GetRenderer());
        playerActor.Update();

        // Draw the game
        playerActor.Draw(windowManager.GetRenderer());

        //SDL_Texture* tPlayer = assetManager.GetTexture("player");
        //SDL_FPoint* tPlayerSize = assetManager.GetTextureSize("player");
        //SDL_Rect tPlayerBox{ 10, 10, tPlayerSize->x, tPlayerSize->y };
        //SDL_RenderCopy(windowManager.GetRenderer(), tPlayer, NULL, &tPlayerBox);

        // Update the screen
        SDL_RenderPresent(windowManager.GetRenderer());
    }

    return 0;
}
