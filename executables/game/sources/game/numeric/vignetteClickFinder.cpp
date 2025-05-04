#include "game/numeric/vignetteClickFinder.h"
#include "customTypes/positionTypes.h"
#include "arithmetic/customArithmetic.h"
#include "consts/gameConsts.h"
#include "consts/globalConsts.h"

bool isCardPicked(const Offset& mousePosition, int width, int height)
{
	return width == ( mousePosition.x - Margin ) / ( SquareSize + IntersticeCards )
		&& width + 1 > ( mousePosition.x + IntersticeCards - Margin ) / ( SquareSize + IntersticeCards )
		&& height == ( mousePosition.y - Margin ) / ( SquareSize + IntersticeCards )
		&& height + 1 > ( mousePosition.y + IntersticeCards - Margin ) / ( SquareSize + IntersticeCards );
}

std::size_t getMatrixHeightFromPairNumber(std::size_t pairNumber)
{
	return static_cast<std::size_t>( getCeilInteger( static_cast<int>(pairNumber * 2), CardsByRow ) );
}

int getCardXPos(int width)
{
	return Margin + width * (SquareSize + IntersticeCards);
}

int getCardYPos(int height)
{
	return Margin + height * ( SquareSize + IntersticeCards );
}

std::size_t getRealPairNumber(std::size_t mainMenuPairNumber, std::size_t loadedPairNumber)
{
	if( mainMenuPairNumber > loadedPairNumber )
	{
		return loadedPairNumber;
	}
	else{
		return mainMenuPairNumber;
	}
}