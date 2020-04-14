#include <cmath>
#include <cstdlib>
#include <iostream>

#include "Coordinate.hpp"
#include "Vector.hpp"

namespace util {
    template <typename T>
    T getRandomNumber(T min, T max) {
        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
        return static_cast<T>(rand() * fraction * (max - min + 1) + min);
    }
}

template <typename T>
Vector getPseudoRandomGradientVector(const Coordinate<T> &C) {
    std::srand(0);

    const int rNum = util::getRandomNumber(0, 3);

    switch(rNum) {
        case 0: { return Vector(1, 0, 0, 1); } break;
        case 1: { return Vector(-1, 0, 0, 1); } break;
        case 2: { return Vector(0, 1, 0, 1); } break;
        case 3: { return Vector(0, -1, 0, 1); } break;
    }
}

double perlinNoise(Coordinate<double> C) {
    const Coordinate<unsigned> topLeftCoords = Coordinate<unsigned>(std::floor(C.x), std::floor(C.y), 0);

    const Coordinate<double> centerCoords = Coordinate<double>(C - topLeftCoords);

    const Vector topLeftGradient = getPseudoRandomGradientVector(topLeftCoords);
    const Coordinate<int> topRightCoords(topLeftCoords.getX() + 1, topLeftCoords.getY(), topLeftCoords.getZ());
    const Vector topRightGradient = getPseudoRandomGradientVector(topRightCoords);
    const Coordinate<int> botLeftCoords(topLeftCoords.getX(), topLeftCoords.getY() + 1, topLeftCoords.getZ());
    const Vector botLeftGradient = getPseudoRandomGradientVector(botLeftCoords);
    const Coordinate<int> botRightCoords(topLeftCoords.getX() + 1, topLeftCoords.getY() + 1, topLeftCoords.getZ());
    const Vector botRightGradient = getPseudoRandomGradientVector(botRightCoords);
}

int main(int argc, char **argv) {

    return 0;
}