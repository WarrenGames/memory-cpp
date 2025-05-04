#ifndef MEMORY_CPP_VIGNETTE_FINDER_H
#define MEMORY_CPP_VIGNETTE_FINDER_H

#include <cstdlib>

struct Offset;

//Use this function to know if the mouse cursor is over a card with a given row (x coordinates) and a given column (y coordinates)
bool isCardPicked(const Offset& mousePosition, int width, int height);

std::size_t getMatrixHeightFromPairNumber(std::size_t pairNumber);

int getCardXPos(int width);

int getCardYPos(int height);

std::size_t getRealPairNumber(std::size_t mainMenuPairNumber, std::size_t loadedPairNumber);

#endif //MEMORY_CPP_VIGNETTE_FINDER_H