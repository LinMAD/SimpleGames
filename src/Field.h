#ifndef PLAINTETRIS_FIELD_H
#define PLAINTETRIS_FIELD_H

#include "Component/Settings.h"
#include "Component/Tetromino.h"

/**
 * Field represent game field
 */
class Field {
private:
    // Flags to controlling locations
    enum {
        LocationFree, LocationTaken
    };

    Tetromino *tetromino_;

    // Field matrix with flags
    int field_[FieldWidth][FieldHeight];
    int screenHeight_;

    /**
     * Must create new field with free locations
     */
    void NewField();

    /**
     * Delete one line from up to down
     *
     * @param y
     */
    void DeleteLine(int y);

public:
    /**
     * Constructor
     * @param tetromino
     * @param screenHeight
     */
    Field(Tetromino *tetromino, int screenHeight);

    /**
     * Return pixel representation of given position
     * X axis (horizontal)
     *
     * @param pos
     * @return int coordinate
     */
    int GetXInPix(int pos);

    /**
     * Return pixel representation of given position
     * Y axis (vertical)
     *
     * @param pos
     * @return int coordinate
     */
    int GetYInPix(int pos);

    /**
     * @param x
     * @param y
     *
     * @return bool
     */
    bool IsFreeBlock(int x, int y);

    /**
     * Checks if object colliding with something
     * @param x
     * @param y
     * @param block
     * @param rotation
     *
     * @return bool
     */
    bool IsCollide(int x, int y, TetrominoType type, TetrominoRotation rotation);

    /**
     * Collect block without holes
     *
     * @param x
     * @param y
     * @param block type
     * @param rotation
     */
    void StoreBlock(int x, int y, TetrominoType type, TetrominoRotation rotation);

    /**
     * Handel deleting line with filled blocks
     */
    void DeleteAvailableLines();

    /**
     * Game will be over if blocks on top of game field
     *
     * @return bool is still can play
     */
    bool IsGameOver();
};


#endif //PLAINTETRIS_FIELD_H
