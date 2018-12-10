#ifndef SOVIETTETRIS_FIGURE_H
#define SOVIETTETRIS_FIGURE_H

#include "AbstractVisualObject.h"
#include "Model/FigureType.h"

namespace component {
    /**
     * Figure represent a playable object
     */
    class Figure : public AbstractVisualObject {
        /**
         * Current angele (how it's rotated max 360==0)
         */
        int angle_;

        /**
         * Type of piece
         */
        model::FigureType type_;

        /**
         * Color of piece
         */
        model::Color color_;
    public:
        /**
         * Current coordinates in axis
         */
        int cX_, cY_;

        explicit Figure(model::FigureType type);

        /**
         * Render figure
         */
        void render(SDL_Renderer *renderer) override;

        /**
         * @return color of current figure
         */
        model::Color getFigureColor();

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
