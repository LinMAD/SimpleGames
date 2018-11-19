#include <iostream>
#include "src/Component/Tetromino.cpp"
#include "src/Field.cpp"
#include "src/Game.cpp"
#include "src/IO.cpp"

using namespace std;

int main() {
    // TODO Add game loop
    IO *io;
    Tetromino *tetromino;
    Field *field = new Field(tetromino, 100);
    Game *game = new Game(field, tetromino, io, 200);

    game->GenerateTetromino();
    game->DrawScene();


    cout << field->IsGameOver() << endl;
    cout << field->IsFreeBlock(10, 10) << endl;

    return 0;
}