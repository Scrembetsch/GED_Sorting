#pragma once
#include <random>

std::mt19937 rng(177013);

int Random(int min, int max)
{
    // Mersenne-Twister
    double r = (double)max - (double)min + 1;
    return min + (int)(r * rng() / (std::mt19937::max() + 1.0));
}
