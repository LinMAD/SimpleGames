#ifndef SOVIETTETRIS_GENERATOR_H
#define SOVIETTETRIS_GENERATOR_H

#include <random>

namespace util {
    /**
     * Generates random int in given range
     *
     * @param from
     * @param to
     *
     * @return generated int
     */
    int generateRandom(int from, int to) {
        std::random_device randD;
        std::mt19937 generator(randD());
        std::uniform_int_distribution<> distribute(from, to);

        return distribute(generator);
    }
}

#endif //SOVIETTETRIS_GENERATOR_H
