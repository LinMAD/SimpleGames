#include <iostream>
#include "src/GameHandler.cpp"

using namespace std;
using namespace engine;

int main() {
    try {
        GameHandler newGame(640, 480);
        while(newGame.tick()){}
    } catch (const runtime_error& e) {
        cout << "Fatal error: " << e.what() << endl;

        return 1;
    }

    return 0;
}