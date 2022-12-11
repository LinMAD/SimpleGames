#include <SFML/Graphics.hpp>
#include "EventHandler.h"

using namespace sf;

void EventHandler::Handle(RenderWindow& window)
{
    Event e;

    while (window.pollEvent(e))
    {
        if (e.type == Event::Closed)
            window.close();

        if (e.type != Event::KeyPressed)
            continue;

        switch (e.key.code) {
            case Keyboard::Space:
            case Keyboard::W:
            case Keyboard::Up:
                 *_inputRotation = true;
                 break;
            case Keyboard::A:
            case Keyboard::Left:
                 *_inputHorizontal = -1;
                 break;
             case Keyboard::D:
             case Keyboard::Right:
                 *_inputHorizontal = 1;
                 break;
             case Keyboard::S:
             case Keyboard::Down:
                 *_inputVertical = 0.05f;
                 break;
            default:
                break;
        }
    }
}
