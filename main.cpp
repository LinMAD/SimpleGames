#include <iostream>
#include "src/Game.cpp"

using namespace std;

int main() {
    try {
        Game newGame;

        while(newGame.tick()){
            cout << "Tick " << endl;
        }
    } catch (const runtime_error& e) {
        cout << "Fatal error: " << e.what() << endl;

        return 1;
    }

    return 0;
}