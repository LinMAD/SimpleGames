#pragma once

#include <SFML/Audio.hpp>
#include "AbstractCharacter.h"
#include "Level.h"

namespace characters {
    class Player : public AbstractCharacter {
    private:
        SoundBuffer _bufferAudioJump;
        Sound _audioJump;

        SoundBuffer _bufferAudioBump;
        Sound _audioBump;

        SoundBuffer _bufferAudioBreak;
        Sound _audioBreak;

        SoundBuffer _bufferAudioCoin;
        Sound _audioCollectCoin;

        SoundBuffer _bufferAudioDie;
        SoundBuffer _bufferAudioKick;

        int _sprintMutator = 0;
    protected:
        void UpdateOrderLogic(float deltaTime) override;

        void HandleInput(float deltaTime) override;

        void HandleAnimation(float deltaTime) override;

        void HandleCollisionOn(bool isCoordinateX) override;

    public:
        Sound audioKick;
        Sound audioDie;

        Player(Texture &tileSet, float *camOffseX, float *camOffseY)
                :
                AbstractCharacter(tileSet, camOffseX, camOffseY) {
            _bufferAudioJump.loadFromFile("assets/sfx/mario_jump.wav");
            _audioJump.setBuffer(_bufferAudioJump);

            _bufferAudioBump.loadFromFile("assets/sfx/mario_bump.wav");
            _audioBump.setBuffer(_bufferAudioBump);

            _bufferAudioBreak.loadFromFile("assets/sfx/mario_breakblock.wav");
            _audioBreak.setBuffer(_bufferAudioBreak);

            _bufferAudioCoin.loadFromFile("assets/sfx/coin.wav");
            _audioCollectCoin.setBuffer(_bufferAudioCoin);

            _bufferAudioDie.loadFromFile("assets/sfx/mario_die.wav");
            audioDie.setBuffer(_bufferAudioDie);

            _bufferAudioKick.loadFromFile("assets/sfx/kick.wav");
            audioKick.setBuffer(_bufferAudioKick);

            sprite.setTexture(tileSet);

            // Put player collider at beginning of level
            rect = FloatRect(DEFAULT_TILE_SIZE, DEFAULT_GROUND_Y, DEFAULT_TILE_SIZE, DEFAULT_TILE_SIZE);

            movmentHorizontal = movmentVertical = 0.1;
            currentAnimationFrame = 0;
        }
    };
}