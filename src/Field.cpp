#include "Field.h"

/**
 * Private methods
 */

void Field::NewField() {
    for (int x = 0; x < FieldWidth; x++) {
        for (int y = 0; y < FieldHeight; y++) {
            field_[x][y] = LocationFree;
        }
    }
}

void Field::DeleteLine(int y) {
    for (int from = y; from > 0; from--) {
        for (int x = 0; x < FieldWidth; x++) {
            field_[x][from] = field_[x][from - 1];
        }
    }
}

/**
 *  Public methods
 */

Field::Field(Tetromino *tetromino, int screenHeight) : tetromino_(nullptr), screenHeight_(0) {
    tetromino_ = tetromino;
    screenHeight_ = screenHeight;
    NewField();
}

void Field::StoreBlock(int x, int y, TetrominoType type, TetrominoRotation rotation) {
    // Go throw given x,y with all number of figures (tetromino) and collect if no spaces
    for (int iX1 = x, iX2 = 0; iX1 < x + TetrominoCount; iX1++, iX2++) {

        for (int iY1 = y, iY2 = 0; iY1 < y + TetrominoCount; iY1++, iY2++) {
            if (tetromino_->GetBlock(type, rotation, iY2, iX2) != 0) {
                field_[iX1][iY1] = LocationTaken;
            }

        }
    }
}

bool Field::IsGameOver() {
    // look up row if it's not free then game over
    for (auto &x : field_) {
        if (x[0] == LocationTaken) {
            return true;
        }
    }

    return false;
}

void Field::DeleteAvailableLines() {
    for (int y = 0; y < FieldHeight; y++) {
        // Store pass x coordinates to delete potentially all lines
        int x = 0;
        while (x < FieldWidth) {
            if (field_[x][y] != LocationTaken) {
                break;
            }
            x++;
        }

        if (x == FieldWidth) {
            DeleteLine(y);
        }
    }
}

bool Field::IsFreeBlock(int x, int y) {
    return field_[x][y] == LocationFree;
}

int Field::GetXInPix(int pos) {
    return ((FieldCenter - (TetrominoSize * (FieldWidth / 2))) + (pos * TetrominoSize));
}

int Field::GetYInPix(int pos) {
    return ((FieldHeight - (TetrominoSize * FieldHeight)) + (pos * TetrominoSize));
}

bool Field::IsCollide(int x, int y, TetrominoType type, TetrominoRotation rotation) {
    for (int x1 = x, x2 = 0; x1 < x + TetrominoCount; x1++, x2++) {
        for (int y1 = y, y2 = 0; y1 < y + TetrominoCount; y1++, y2++) {
            if (x1 < 0 || x1 > FieldWidth - 1 || y > FieldHeight - 1) {
                if (tetromino_->GetBlock(type, rotation, x2, y2) != 0) {
                    return false;
                }
            }

            if (y1 >= 0) {
                if (tetromino_->GetBlock(type, rotation, x2, y2) != 0 && IsFreeBlock(x1, y1)) {
                    return false;
                }
            }
        }
    }

    return true;
}

