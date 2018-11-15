#include <iostream>
#include "src/Components/Tetromino.cpp"

using namespace std;

int main() {
    // TODO Add game loop

    Tetromino tetromino;

    int block;
    block = tetromino.GetBlock(L, Left, 0, 1);

    cout << block << endl;
    cout << "\nDump blocks" << endl;
    cout << blocks << endl;
    cout << "\nDump blocks init pos" << endl;
    cout << blocksInitialPosition << endl;

    return 0;
}