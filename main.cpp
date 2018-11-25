#include <iostream>
#include "src/GameHandler.cpp"

using namespace std;
using namespace engine;

int main() {
    try {
        GameHandler newGame;

        while(!newGame.isGameEnd()) {
            newGame.input();
            newGame.update();
            newGame.render();
        }
    } catch (const runtime_error& e) {
        cout << "Fatal error: " << e.what() << endl;

        return 1;
    }

    return 0;
}
