#include "mainMenu/vignettesAnimation/vignettesAnimation.h"
#include "consts/globalConsts.h"
#include <cassert>

VignettesAnimation::VignettesAnimation():
	currentVignette{ 0 }
{
	createVignettesData();
}

void VignettesAnimation::update()
{
	assert( currentVignette < vignettes.size() );
	vignettes[currentVignette].update(animDelay, currentVignette, vignettes.size() );
}

int VignettesAnimation::getWidth(std::size_t vignetteIndex) const
{
	assert( vignetteIndex < vignettes.size() );
	return vignettes[vignetteIndex].getWidth();
}

const Offset& VignettesAnimation::getPosition(std::size_t vignetteIndex) const
{
	assert( vignetteIndex < vignettes.size() );
	return vignettes[vignetteIndex].getPosition();
}

unsigned VignettesAnimation::getSide(std::size_t vignetteIndex) const
{
	assert( vignetteIndex < vignettes.size() );
	return vignettes[vignetteIndex].getSide();
}

std::size_t VignettesAnimation::size() const
{
	return vignettes.size();
}

void VignettesAnimation::createVignettesData()
{
	vignettes.emplace_back( VignetteInfos{ Offset{ SquareSize * 2, SquareSize * 2 } } );
	vignettes.emplace_back( VignetteInfos{ Offset{ GameScreenWidth - SquareSize * 2, SquareSize * 2 } } );
	vignettes.emplace_back( VignetteInfos{ Offset{ SquareSize * 2, GameScreenHeight - SquareSize * 2 } } );
	vignettes.emplace_back( VignetteInfos{ Offset{ GameScreenWidth - SquareSize * 2, GameScreenHeight - SquareSize * 2 } } );
}

