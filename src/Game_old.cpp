#include <random>
#include "Game_old.h"

/**
 * Private methods
 */

void Game::InitGame() {
    tetroType_ = TetrominoType(GenRandomFrom(0, 6));
    tetroRotation_ = TetrominoRotation(GenRandomFrom(0, 3));
    tetroPosOnX_ = (FieldWidth / 2) + tetromino_->GetXInitPos(tetroType_, tetroRotation_);
    tetroPosOnY_ = tetromino_->GetYInitPos(tetroType_, tetroRotation_);

    nextTetroType_ = TetrominoType(GenRandomFrom(0, 6));
    nextTetroRotation_ = TetrominoRotation(GenRandomFrom(0, 3));
    nextTetroPosOnX_ = FieldWidth + 5;
    nextTetroPosOnY_ = 5;
}

void Game::DrawPiece(int x, int y, TetrominoType type, TetrominoRotation rotation) {
    IOColor tetrominoColor; // TODO Add color generation
    int pixelX = field_->GetXInPix(x);
    int pixelY = field_->GetYInPix(y);

    for (int i = 0; i < TetrominoCount; i++) {
        for (int j = 0; j < TetrominoCount; j++) {
            int tetroBlock = tetromino_->GetBlock(type, rotation, j, i);

            tetrominoColor = IOColor(GenRandomFrom(0, IO_C_COLOR_MAX));

            if (tetroBlock != 0) {
                io_->DrawRectangle(
                        pixelX + i * TetrominoSize,
                        pixelY + j * TetrominoSize,
                        (pixelX + i * TetrominoSize) + TetrominoSize - 1,
                        (pixelY + j * TetrominoSize) + TetrominoSize - 1,
                        tetrominoColor
                );
            }
        }
    }
}

int Game::GenRandomFrom(int from, int to) {
    std::random_device randD;
    std::mt19937 generator(randD());
    std::uniform_int_distribution<> distribute(from, to);

    return distribute(generator);
}

/**
 * Public methods
 */

Game::Game(Field *field, Tetromino *tetromino, IO *io, int screenHeight) : screenHeight_(0) {
    field_ = field;
    tetromino_ = tetromino;
    io_ = io;
    screenHeight_ = screenHeight;
}

void Game::GenerateTetromino() {
    tetroType_ = nextTetroType_;
    tetroRotation_ = nextTetroRotation_;
    tetroPosOnX_ = (FieldWidth / 2) + tetromino_->GetXInitPos(tetroType_, tetroRotation_);
    tetroPosOnY_ = tetromino_->GetYInitPos(tetroType_, tetroRotation_);

    nextTetroType_ = TetrominoType(GenRandomFrom(0, 6));
    nextTetroRotation_ = TetrominoRotation(GenRandomFrom(0, 3));
}

void Game::DrawBoard() {
    IOColor colorOfLine = IOColor(IO_C_YELLOW);
    IOColor colorOfStoredBlock = IOColor(IO_C_WHITE);

    // Get limits
    int xLimit = FieldCenter - (TetrominoSize * (FieldWidth / 2)) - 1;
    int x2Limit = FieldCenter + (TetrominoSize * (FieldWidth / 2));
    int yLimit = screenHeight_ - (TetrominoSize * FieldHeight);


    io_->DrawRectangle(xLimit - FieldLineWidth, yLimit, xLimit, screenHeight_ - 1, colorOfLine);
    io_->DrawRectangle(x2Limit, yLimit, x2Limit + FieldLineWidth, screenHeight_ - 1, colorOfLine);

    // Draw all stored Tetromino's
    //xLimit += 1;
    for (int x = 0; x < FieldWidth; x++) {
        for (int y = 0; y < FieldWidth; y++) {
            if (!field_->IsFreeBlock(x, y))
                io_->DrawRectangle(
                        xLimit + x * TetrominoSize,
                        yLimit + y * TetrominoSize,
                        (xLimit + x * TetrominoSize) + TetrominoSize - 1,
                        (yLimit + y * TetrominoSize) + TetrominoSize - 1,
                        colorOfStoredBlock
                );
        }
    }
}

void Game::DrawScene() {
    DrawBoard ();
    DrawPiece(tetroPosOnX_, tetroPosOnY_, tetroType_, tetroRotation_);
    DrawPiece(nextTetroPosOnX_, nextTetroPosOnY_, nextTetroType_, nextTetroRotation_);
}

