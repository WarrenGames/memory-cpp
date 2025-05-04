#include "crossLevel/gameOptions.h"

GameOptions::GameOptions(const fs::path& themeDir, std::size_t pairNum, std::size_t pairMax):
	specificThemeDirectory{ themeDir },
	pairNumber{ pairNum },
	maxPairNumber{ pairMax }
{
	
}