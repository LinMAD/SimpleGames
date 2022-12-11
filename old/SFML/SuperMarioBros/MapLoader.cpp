#include "MapLoader.h"
#include "Props.h"
#include "Level.h"

void MapLoader::Draw(RenderWindow &window) {
    window.clear(LEVEL_BG_COLOR);

    for (int y = 0; y < LEVEL_MAP_HEIGHT; y++) {
        for (int x = 0; x < LEVEL_MAP_WIDTH; x++) {
            bool isNeedToDraw = true;

            switch (LEVEL_MAP[y][x]) {
                case GROUND:
                    tileSet.setTextureRect(IntRect(57, 201, DEFAULT_TILE_SIZE, DEFAULT_TILE_SIZE));
                    break;
                case CLOUD:
                    tileSet.setTextureRect(IntRect(8, 195, 43, 32));
                    break;
                case HILL:
                    tileSet.setTextureRect(IntRect(5, 170, 48, 20));
                    break;
                case BUSH:
                    tileSet.setTextureRect(IntRect(9, 145, 42, 21));
                    break;
                case BOX_SECRET:
                    tileSet.setTextureRect(IntRect(88, 201, DEFAULT_TILE_SIZE, DEFAULT_TILE_SIZE));
                    break;
                case BOX_WALL:
                    tileSet.setTextureRect(IntRect(104, 201, DEFAULT_TILE_SIZE, DEFAULT_TILE_SIZE));
                    break;
                case BOX_IRON:
                    tileSet.setTextureRect(IntRect(72, 201, DEFAULT_TILE_SIZE, DEFAULT_TILE_SIZE));
                    break;
                case PIPE:
                    tileSet.setTextureRect(IntRect(88, 138, 32, 48));
                    break;
                default:
                    isNeedToDraw = false;
                    break;
            }

            if (isNeedToDraw) {
                tileSet.setPosition(x * DEFAULT_TILE_SIZE - *GetOffsetX(), y * DEFAULT_TILE_SIZE - *GetOffsetY());
                window.draw(tileSet);
            }
        }
    }
}
