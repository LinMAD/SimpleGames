#ifndef SOVIETTETRIS_BOARD_H
#define SOVIETTETRIS_BOARD_H

#include "AbstractVisualObject.h"
#include "Setting/Properties.h"
#include "Component/Tetromino.h"

namespace component {

    /**
     * Board represent a game field
     */
    class Board : public AbstractVisualObject {
    private:
        bool boardMatrix[setting::FieldWidth][setting::FieldHeight];
    public:
        Board();

        /**
         * Provide game field
         * @param renderer
         */
        void render(SDL_Renderer *renderer) override;

        bool isColliding(Tetromino &tetromino);
    };
}

#endif //SOVIETTETRIS_BOARD_H
