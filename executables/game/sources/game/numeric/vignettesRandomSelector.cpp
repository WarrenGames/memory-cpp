#include "game/numeric/vignettesRandomSelector.h"
#include <random>
#include <algorithm>
#include <cassert>

VignettesRandomSelector::VignettesRandomSelector(std::size_t maximumPair):
	completeIndexes( maximumPair, 0 )
{
	fillFullCollection();
	shuffleFullCollection();
}

std::size_t VignettesRandomSelector::size() const
{
	return completeIndexes.size();
}
	
std::size_t VignettesRandomSelector::getValidIndex(std::size_t arrayIndex) const
{
	assert( arrayIndex < completeIndexes.size() );
	return completeIndexes[arrayIndex];
}

void VignettesRandomSelector::fillFullCollection()
{
	for( std::size_t i{0} ; i < completeIndexes.size() ; ++i )
	{
		completeIndexes[i] = i;
	}
}

void VignettesRandomSelector::shuffleFullCollection()
{
	std::random_device rd;
	std::mt19937 g{ rd() };
	
	std::shuffle( completeIndexes.begin(), completeIndexes.end(), g );
}
