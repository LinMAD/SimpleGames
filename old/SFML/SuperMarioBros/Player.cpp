#include "Player.h"
#include "Props.h"
#include <iostream>

namespace characters {
    void Player::UpdateOrderLogic(float deltaTime) {
        HandleInput(deltaTime);

        //  Simulate gravity and animation
        rect.left += movmentHorizontal * deltaTime;

        HandleCollisionOn(true); // x axis

        if (!isOnGround) movmentVertical += 0.0005 * deltaTime; // gravity

        rect.top += movmentVertical * deltaTime;
        isOnGround = false;

        HandleCollisionOn(false); // y axis

        HandleAnimation(deltaTime);

        sprite.setPosition(rect.left - *camOffsetX, rect.top - *camOffsetY);

        movmentHorizontal = 0;

        if (rect.left > 200) *camOffsetX = rect.left - 200;

        //std::cout << "Player X: " << rect.left << " Y: " << rect.top << "\n";
    }

    void Player::HandleCollisionOn(bool isCoordinateX) {
        for (int i = rect.top / DEFAULT_TILE_SIZE; i < (rect.top + rect.height) / DEFAULT_TILE_SIZE; i++) {
            for (int j = rect.left / DEFAULT_TILE_SIZE; j < (rect.left + rect.width) / DEFAULT_TILE_SIZE; j++) {
                if (LEVEL_MAP[i][j] != GROUND && LEVEL_MAP[i][j] != WALL && LEVEL_MAP[i][j] != BOX_SECRET &&
                    LEVEL_MAP[i][j] != BOX_WALL && LEVEL_MAP[i][j] != BOX_IRON && LEVEL_MAP[i][j] != PIPE)
                    continue;

                if (!isCoordinateX && movmentVertical < 0) {
                    if (LEVEL_MAP[i][j] == BOX_SECRET) {
                        // TODO Add coint sprite IntRect(56, 176, 10, 14)
                        // TODO Replace box sprite
                        _audioBump.play();

                        if (rand() % 2 == 0)
                            _audioCollectCoin.play();
                    }

                    if (LEVEL_MAP[i][j] == BOX_WALL) {
                        // TODO Remove block
                        _audioBreak.play();
                    }
                }

                if (movmentVertical > 0 && !isCoordinateX) {
                    rect.top = i * DEFAULT_TILE_SIZE - rect.height;
                    movmentVertical = 0;
                    isOnGround = true;
                }

                if (movmentVertical < 0 && !isCoordinateX) {
                    rect.top = i * DEFAULT_TILE_SIZE + DEFAULT_TILE_SIZE;
                    movmentVertical = 0;
                }

                if (movmentHorizontal > 0 && isCoordinateX) {
                    rect.left = j * DEFAULT_TILE_SIZE - rect.width;
                }

                if (movmentHorizontal < 0 && isCoordinateX) {
                    rect.left = j * DEFAULT_TILE_SIZE + DEFAULT_TILE_SIZE;
                }
            }
        }
    }

    void Player::HandleInput(float deltaTime) {
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            _sprintMutator -= 0.1;
            movmentHorizontal = -0.1 + _sprintMutator;
        }

        if (Keyboard::isKeyPressed(Keyboard::D)) {
            _sprintMutator += 0.1;
            movmentHorizontal = 0.1 + _sprintMutator;
        }

        if (Keyboard::isKeyPressed(Keyboard::Space) && isOnGround) {
            movmentVertical = -0.27;
            isOnGround = false;
            _audioJump.play();
        }
    }

    void Player::HandleAnimation(float deltaTime) {
        if (isDead) {
            sprite.setTextureRect(IntRect(62, 152, 14, 14));

            return;
        }

        currentAnimationFrame += deltaTime * 0.005;
        if (currentAnimationFrame > 3)
            currentAnimationFrame -= 3;

        // Move and jump sprite
        if (movmentHorizontal == 0) {
            //sprite.setTextureRect(IntRect(6, 108, DEFAULT_TILE_SIZE, DEFAULT_TILE_SIZE));
        } else if (movmentHorizontal > 0) {
            sprite.setTextureRect(IntRect(22 + DEFAULT_TILE_SIZE * int(currentAnimationFrame), 108, DEFAULT_TILE_SIZE,
                                          DEFAULT_TILE_SIZE));
        } else if (movmentHorizontal < 0) {
            sprite.setTextureRect(IntRect(22 + DEFAULT_TILE_SIZE * int(currentAnimationFrame) + DEFAULT_TILE_SIZE, 108,
                                          -DEFAULT_TILE_SIZE, DEFAULT_TILE_SIZE));
        }

        if (movmentVertical < 0)
            sprite.setTextureRect(IntRect(89 + DEFAULT_TILE_SIZE, 108, -DEFAULT_TILE_SIZE, DEFAULT_TILE_SIZE));
        if (movmentVertical < 0)
            sprite.setTextureRect(IntRect(89, 108, DEFAULT_TILE_SIZE, DEFAULT_TILE_SIZE));
    }
}