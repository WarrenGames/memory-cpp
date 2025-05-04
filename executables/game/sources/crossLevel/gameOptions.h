#ifndef MEMORY_CPP_GAME_OPTIONS_H
#define MEMORY_CPP_GAME_OPTIONS_H

#include "fileSystem/fileSystem.h"
#include <cstdlib>

struct GameOptions
{
	fs::path specificThemeDirectory;
	std::size_t pairNumber;
	std::size_t maxPairNumber;
	
	GameOptions(const fs::path& themeDir, std::size_t pairNum, std::size_t pairMax);
	~GameOptions() = default;
	GameOptions( const GameOptions& ) = default;
	GameOptions& operator= ( const GameOptions& ) = default;
	GameOptions( GameOptions&& ) = default;
	GameOptions& operator= ( GameOptions&& ) = default;
};

#endif //MEMORY_CPP_GAME_OPTIONS_H