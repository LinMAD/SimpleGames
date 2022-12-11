#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Settings.h"
#include "MapLoader.h"
#include "Player.h"
#include "EnemyGoomba.h"
#include "Level.h"

using namespace std;
using namespace sf;
using namespace characters;

int main() {
    bool isGameOver = false;

    Clock deltaClock;
    RenderWindow window(VideoMode(WINDOW_HEIGHT, WINDOW_WIDTH), "Super Mario Bros.");
    window.setFramerateLimit(60);

    // Load gloabl resources
    Texture texTileSet;
    SoundBuffer bufferAudioBgTheme;
    Sound audioBgTheme;

    if (!texTileSet.loadFromFile("assets/tile_set.png"))
        return 1;
    if (!bufferAudioBgTheme.loadFromFile("assets/music/Above_Ground_BGM.ogg"))
        return 1;

    audioBgTheme.setBuffer(bufferAudioBgTheme);
    audioBgTheme.setLoop(true);
    audioBgTheme.play();

    MapLoader gameWorldLoader(texTileSet);
    Player player(texTileSet, gameWorldLoader.GetOffsetX(), gameWorldLoader.GetOffsetY());

    std::vector <EnemyGoomba> enemies;
    for (int y = 0; y < LEVEL_MAP_HEIGHT; y++) {
        for (int x = 0; x < LEVEL_MAP_WIDTH; x++) {
            if (LEVEL_MAP[y][x] == ENEMY_GOOMBA) {
                EnemyGoomba goomba(texTileSet, gameWorldLoader.GetOffsetX(), gameWorldLoader.GetOffsetY());
                goomba.Spawn(x * DEFAULT_TILE_SIZE, DEFAULT_GROUND_Y);

                enemies.push_back(goomba);
            }
        }
    }

    while (!isGameOver) {
        // Keep always same speed of the game
        float deltaTime = deltaClock.getElapsedTime().asMicroseconds();
        deltaClock.restart();

        if (deltaTime /= 500 > 20) deltaTime = 20;

        Event event;
        while (window.pollEvent(event))
            if (event.type == Event::Closed)
                window.close();

        gameWorldLoader.Draw(window); // World must be as first layer

        // TODO This could be more elegant if delegate to game manager
        // Update all enemies and draw them
        for (AbstractCharacter &enemy : enemies) {
            if (enemy.isDead) continue;

            if (player.rect.intersects(enemy.rect)) {
                if (player.movmentVertical > 0) {
                    enemy.movmentVertical = 0;
                    player.movmentVertical = -0.2;
                    enemy.isDead = true;
                    player.audioKick.play();
                } else {
                    // Patient prognosis is dead!
                    isGameOver = true;
                    player.audioDie.play();
                    player.isDead = true;
                    player.movmentVertical = -0.3;
                }
            }

            enemy.UpdateFrame(deltaTime);
            window.draw(enemy.sprite);
        }

        player.UpdateFrame(deltaTime);

        window.draw(player.sprite);
        window.display();
    }

    return 0;
}
