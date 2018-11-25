#ifndef SOVIETTETRIS_FIGURE_H
#define SOVIETTETRIS_FIGURE_H

#include "AbstractVisualObject.h"
#include "FigureType.h"

namespace component {
    /**
     * Figure represent a playable object
     */
    class Figure : public AbstractVisualObject {
    private:
        /**
         * Current coordinates in axis
         */
        int cX_, cY_;

        /**
         * Current angele (how it's rotated max 360==0)
         */
        int angle_;

        /**
         * Type of piece
         */
        FigureType type_;
    public:
        explicit Figure(FigureType type);

        /**
         * Render figure
         */
        void render(SDL_Renderer *renderer) override;

        /**
         * Handle movement on next coordinates
         * @param nextX
         * @param nextY
         */
        void move(int nextX, int nextY);

        /**
         * Handel rotation of figure
         */
        void rotate();

        /**
         * @return int of current coordinate axis
         */
        int getX() const;

        /**
         * @return int of current coordinate axis
         */
        int getY() const;

        /**
         * Checking is block exist on
         * coordinates
         * @param x
         * @param y
         *
         * @return bool
         */
        bool isBlock(int x, int y) const;
    };
}

#endif //SOVIETTETRIS_FIGURE_H
