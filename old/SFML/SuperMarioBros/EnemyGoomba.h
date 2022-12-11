#pragma once

#include <SFML/Audio.hpp>
#include "AbstractCharacter.h"
#include "Level.h"
#include "Props.h"

namespace characters {
    class EnemyGoomba : public AbstractCharacter {
    protected:
        void UpdateOrderLogic(float deltaTime) override;

        void HandleAnimation(float deltaTime) override;

        void HandleCollisionOn(bool isCoordinateX) override;

    public:
        EnemyGoomba(Texture &tileSet, float *camOffseX, float *camOffseY)
                :
                AbstractCharacter(tileSet, camOffseX, camOffseY) {
            sprite.setTexture(tileSet);

            isDead = false;
            movmentHorizontal = 0.05;
            currentAnimationFrame = 0;
        }

        void Spawn(int x, int y) override;
    };
}
