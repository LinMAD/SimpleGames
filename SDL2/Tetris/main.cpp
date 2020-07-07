#include <iostream>
#include "src/GameHandler.cpp"

using namespace std;
using namespace engine;

int main() {
    GameHandler tetrisGame;

    try {
        tetrisGame.init();
    } catch (const runtime_error& e) {
        cout << "Fatal error: " << e.what() << endl;
        return 1;
    }

    while(!tetrisGame.isGameEnd()) {
        tetrisGame.input();
        tetrisGame.update();
        tetrisGame.render();
    }

    return 0;
}
