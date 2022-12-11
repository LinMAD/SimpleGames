#include "BaseActor.h"

BaseActor::BaseActor(AssetManager* assetManager, std::string name)
{
    m_asset_manager = assetManager;
    m_actor_name = name;
}

void BaseActor::Update()
{
    // Update the current frame of animation for the player character
    m_currentFrame = (m_currentFrame + 1) % 3;
}

void BaseActor::Draw(SDL_Renderer* renderer)
{
    // Determine the source and destination rectangles for the player character's
    // current frame of animation
    SDL_Rect srcRect, destRect;
    int frameWidth = 18;
    int frameHeight = 25;
    srcRect.x = m_currentFrame * frameWidth;
    srcRect.y = 0;
    srcRect.w = frameWidth;
    srcRect.h = frameHeight;
    destRect.x = 14;
    destRect.y = 31;
    destRect.w = frameWidth;
    destRect.h = frameHeight;

    // Draw the player character to the screen
    SDL_RenderCopy(renderer, m_asset_manager->GetTexture(m_actor_name), &srcRect, &destRect);
}