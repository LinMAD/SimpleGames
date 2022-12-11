#include <iostream>
#include <SFML/Audio.hpp>
#include "EnemyGoomba.h"

namespace characters {
    void EnemyGoomba::UpdateOrderLogic(float deltaTime) {
        rect.left += movmentHorizontal * deltaTime;

        HandleCollisionOn(true);
        HandleAnimation(deltaTime);

        sprite.setPosition(rect.left - *camOffsetX, rect.top - *camOffsetY);
        //std::cout << "Enemy X: " << rect.left << ", Y: " << rect.top << "\n";
    }

    void EnemyGoomba::HandleAnimation(float deltaTime) {
        currentAnimationFrame += deltaTime * 0.005;
        if (currentAnimationFrame > 2)
            currentAnimationFrame -= 2;

        if (isDead) {
            sprite.setTextureRect(IntRect(65, 133, DEFAULT_TILE_SIZE, 8));
        } else {
            sprite.setTextureRect(IntRect(
                    6 + DEFAULT_TILE_SIZE * int(currentAnimationFrame),
                    125,
                    DEFAULT_TILE_SIZE,
                    DEFAULT_TILE_SIZE
            ));
        }
    }

    void EnemyGoomba::HandleCollisionOn(bool isCoordinateX) {
        for (int i = rect.top / DEFAULT_TILE_SIZE; i < (rect.top + rect.height) / DEFAULT_TILE_SIZE; i++) {
            for (int j = rect.left / DEFAULT_TILE_SIZE; j < (rect.left + rect.width) / DEFAULT_TILE_SIZE; j++) {
                if (LEVEL_MAP[i][j] != GROUND && LEVEL_MAP[i][j] != WALL)
                    continue;

                if (movmentHorizontal > 0) {
                    rect.left = j * DEFAULT_TILE_SIZE - rect.width;
                    movmentHorizontal *= -1;
                } else if (movmentHorizontal < 0) {
                    rect.left = j * DEFAULT_TILE_SIZE + DEFAULT_TILE_SIZE;
                    movmentHorizontal *= -1;
                }
            }
        }
    }

    void EnemyGoomba::Spawn(int x, int y) {
        rect = FloatRect(x, y, DEFAULT_TILE_SIZE, DEFAULT_TILE_SIZE);
    }
}
