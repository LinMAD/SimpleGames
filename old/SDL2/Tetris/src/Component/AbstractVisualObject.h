#ifndef SIMPLETETRIS_ABSTRACTVISUALOBJECT_H
#define SIMPLETETRIS_ABSTRACTVISUALOBJECT_H

#include <SDL2/SDL.h>
#include "Setting/Properties.h"
#include "Model/Color.h"

namespace component {
    /**
     * Abstract class represent drawable object
     */
    class AbstractVisualObject {
    protected:
        /**
         * Wrapper to draw SDL filled rectangle
         *
         * @param renderer SDL renderer
         * @param color struct
         * // React properties
         * @param x
         * @param y
         * @param w
         * @param h
         */
        void drawRectangle(SDL_Renderer *renderer, model::Color color, int x, int y, int w, int h) {
            SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, color.alpha);
            SDL_Rect rect{x, y, w, h};
            SDL_RenderFillRect(renderer, &rect);
        }

    public:
        // SDL rect border pixel
        static const int RECT_BORDER = 1;

        /**
         * Assign object for render
         *
         * @param renderer
         */
        virtual void render(SDL_Renderer *renderer) = 0;

        virtual /**
         * @return int scaling based on screen
         */
        int getObjectScale() {
            return setting::HalfScreen / 10;
        }
    };
}

#endif //SIMPLETETRIS_ABSTRACTVISUALOBJECT_H
