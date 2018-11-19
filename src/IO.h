#ifndef PLAINTETRIS_IO_H
#define PLAINTETRIS_IO_H

#include <SDL2/SDL.h>

enum IOColor {
    IO_C_BLACK, IO_C_RED, IO_C_GREEN, IO_C_BLUE, IO_C_CYAN, IO_C_MAGENTA, IO_C_YELLOW, IO_C_WHITE, IO_C_COLOR_MAX
};

/**
 * IO - input and output
 * Represent class to control and handle user input and screen output
 */
class IO {
private:
    SDL_Window *window_;
    SDL_Renderer *render_;
    SDL_Texture *texture_;
    Uint32 *buffer_;
public:
    const static int SCREEN_WIDTH = 640;
    const static int SCREEN_HEIGHT = 480;

    const static int SCREEN_RESOLUTION = SCREEN_WIDTH * SCREEN_HEIGHT;

    /**
     * Default constructor
     */
    IO();

    /**
     * Initialize graphical library
     *
     * @return int result code
     */
    int InitGraph();

    /**
     * Draw on screen a rectangle with given params
     *
     * @param x1
     * @param y1
     * @param x2
     * @param y2
     * @param color
     */
    void DrawRectangle(int x1, int y1, int x2, int y2, enum IOColor color);

    /**
     * Clears current screen state
     */
    void ClearScreen();

    /**
     * Method updates screen and all objects
     */
    void UpdateScreen();



    /**
     * @return int height of screen
     */
    int GetScreenHeight();

    /**
     * Handle input key events
     *
     * @return int result code
     */
    int HandleEventKeyPoll();

    /**
     * Get pressed key
     *
     * @return code
     */
    int GetKey();

    /**
     * Check if specific keys pressed
     *
     * @param key
     * @return
     */
    int IsKeyDown(int key);

};


#endif //PLAINTETRIS_IO_H
