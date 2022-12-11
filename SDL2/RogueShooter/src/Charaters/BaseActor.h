#pragma once
#include "../Core/AssetManager.h"
#include <SDL2/SDL.h>
#include <iostream>

class BaseActor
{
public:
    BaseActor(AssetManager* assetManager, std::string name);

    /// <summary>
    /// Updates the character's animation
    /// </summary>
    void Update();

    /// <summary>
    /// Draws the character to the screen
    /// </summary>
    /// <param name="renderer">SDL_Renderer</param>
    void Draw(SDL_Renderer* renderer);

private:
    // The name of actor that could be related to assets or other parts
    std::string m_actor_name;
    // The current frame of animation for the player character
    int m_currentFrame;

    AssetManager* m_asset_manager;
};

