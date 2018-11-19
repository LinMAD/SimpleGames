#ifndef PLAINTETRIS_GAME_H
#define PLAINTETRIS_GAME_H

#include <time.h>
#include "Component/Tetromino.h"
#include "Component/Settings.h"
#include "Field.h"
#include "IO.h"

/**
 * Game represent a handler for all workflow of the tetris:
 * Init new game, draw, store
 * and handel tetromiono aka pieces
 * or generate new one
 */
class Game {
private:
    int screenHeight_;
    // Tetromino variables for next one
    int nextTetroPosOnX_, nextTetroPosOnY_;
    TetrominoType nextTetroType_;
    TetrominoRotation nextTetroRotation_;

    Field *field_;
    Tetromino *tetromino_;
    IO *io_;

    /**
     * Init game state with all prepared settings
     */
    void InitGame();

    /**
     * Draws given figure on screen
     *
     * @param x
     * @param y
     * @param type
     * @param rotation
     */
    void DrawPiece(int x, int y, TetrominoType type, TetrominoRotation rotation);

    /**
     * Draw will delimit board, like:
     * |  . |
     * |    |
     * |____|
     */
    void DrawBoard();

    /**
     * Generate random number between:
     * @param from
     * @param to
     *
     * @return random number
     */
    int GenRandomFrom(int from, int to);

public:
    /**
     * Constructor
     *
     * @param field
     * @param tetromino
     * @param screenHeight
     */
    Game(Field *field, Tetromino *tetromino, IO *io, int screenHeight);

    /**
     * Render scene
     */
    void DrawScene();

    /**
     * Generate one piece
     * (in same time can be only one falling down)
     */
    void GenerateTetromino();

    // Tetromino variables
    int tetroPosOnX_, tetroPosOnY_;
    TetrominoType tetroType_;
    TetrominoRotation tetroRotation_;

};

#endif //PLAINTETRIS_GAME_H
