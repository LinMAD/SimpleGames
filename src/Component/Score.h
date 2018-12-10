#ifndef SIMPLETETRIS_SCORE_H
#define SIMPLETETRIS_SCORE_H

#include <iostream>
#include "AbstractVisualObject.h"

namespace component {

    /**
     * Score represent game score object
     */
    class Score : public AbstractVisualObject {
    public:
        explicit Score(std::string current);

        /**
         * Score string which must be rendered
         */
        std::string score_;

        /**
         * Render score
         *
         * @param renderer
         */
        void render(SDL_Renderer *renderer) override;

        /**
         * Checking is block exist
         *
         * @param number
         * @param x
         * @param y
         * @return
         */
        bool isBlock(int number, int x, int y) const;

        /**
         * @return int size of figure
         */
        int getObjectScale() override;
    };
}

#endif //SIMPLETETRIS_SCORE_H
