#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class MapLoader {
private:
    // TODO Move this to camera class
    float _camTileOffsetX = 0;
    float _camTileOffsetY = 0;
protected:
    Texture texTileSet;
    Sprite tileSet;
public:
    MapLoader(Texture &tileMap) : texTileSet(tileMap) {
        tileSet.setTexture(texTileSet);
    }

    void Draw(RenderWindow &window);

    float *GetOffsetX() {
        return &_camTileOffsetX;
    };

    float *GetOffsetY() {
        return &_camTileOffsetY;
    }
};

