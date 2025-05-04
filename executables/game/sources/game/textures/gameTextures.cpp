#include "game/textures/gameTextures.h"
#include "crossLevel/essentials.h"
#include "consts/gameConsts.h"

TexturesPackage::TexturesPackage(Essentials& essentials, const fs::path& specificThemeDirectory):
	themeDirectory{ ThemesDirectory },
	vignettesTextures{ essentials.logs, essentials.rndWnd, themeDirectory / specificThemeDirectory / VignettesThemeFile },
	cardsBackTexture{ essentials.logs, essentials.rndWnd, fetchCardBackTexture(essentials, themeDirectory / specificThemeDirectory / CardBackThemeFile).string() },
	commentsTexts{ essentials },
	cardsPickingText{ essentials }
{
	
}

bool TexturesPackage::wasLoadingPerfect() const
{
	return vignettesTextures.wasLoadingPerfect() && cardsBackTexture;
}

fs::path TexturesPackage::fetchCardBackTexture(Essentials& essentials, const fs::path& cardBackConfigFile) const
{
	if( std::ifstream file{ cardBackConfigFile } )
	{
		std::string fileLine;
		if( std::getline( file, fileLine ) )
		{
			return fs::path{ fileLine };
		}
		else{
			essentials.logs.error << "Error: the file '" << cardBackConfigFile.string() << "' was opened but read a first line was impossible.\n";
		}
	}
	else{
		essentials.logs.error << "Error: couldn't open '" << cardBackConfigFile.string() << "' file in order to read the cards back texture path.\n";
	}
	return fs::path{"path error"};
}