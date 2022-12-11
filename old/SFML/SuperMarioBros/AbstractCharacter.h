#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

namespace characters {
    class AbstractCharacter {
    protected:
        Texture texTileSet;

        // Camera offset on X and Y
        float *camOffsetX;
        float *camOffsetY;

        float currentAnimationFrame;

        bool isOnGround;

        // Here must be prepared character update logic order
        // inputs, stats update, animation etc.
        virtual void UpdateOrderLogic(float deltaTime) {};

        virtual void HandleInput(float deltaTime) {};

        virtual void HandleAnimation(float deltaTime) {};

        virtual void HandleCollisionOn(bool isCoordinateX) {};
    public:
        float movmentHorizontal, movmentVertical;
        bool isDead;

        FloatRect rect;
        Sprite sprite;

        AbstractCharacter(Texture &tileSet, float *camOffseX, float *camOffseY) :
                texTileSet(tileSet),
                camOffsetX(camOffseX),
                camOffsetY(camOffseY) {
            isDead = false;
        }

        // Call to update character per frame
        void UpdateFrame(float deltaTime) {
            UpdateOrderLogic(deltaTime);
        };

        virtual void Spawn(int x, int y) {};
    };
}
