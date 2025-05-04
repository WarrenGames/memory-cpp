#include "mainMenu/themeSelection/themesInterface.h"
#include "filesSetup/getFilesPaths.h"
#include "crossLevel/essentials.h"
#include "texturing/texturePosition.h"
#include "consts/colors.h"
#include "consts/filesConsts.h"
#include "consts/globalConsts.h"
#include "consts/fontsSizes.h"
#include <fstream>
#include <string>
#include <cassert>

enum{
	ThemeLanguageText,
	ThameLanguageMax
};

ThemesStrings::ThemesStrings(Essentials& essentials, const sdl2::Font& font, const fs::path& newThemeDirectory):
	themeDirectory{ newThemeDirectory },
	themeText{ essentials.logs, essentials.rndWnd, font, newThemeDirectory.string(), WhiteColor, TexturePosition{ GameScreenWidth / 2, GameScreenHeight - SquareSize, false, true } }
{
	
}

ThemesInterface::ThemesInterface(Essentials& essentials):
	texts{ essentials.logs.error, path::getLanguageFile(essentials.selectedLanguage, files::ThemeGUILanguageFile), ThameLanguageMax },
	font{ essentials.logs.error, GameFontPath, SmallFontSize },
	buttons{ essentials },
	themeIndex{ 0 },
	themeLanguageText{ essentials.logs, essentials.rndWnd, font, texts[ThemeLanguageText], WhiteColor, TexturePosition{ SquareSize * 5, GameScreenHeight - SquareSize, false, true } }
{
	createThemesTexts(essentials);
	fetchDefaultThemeIndexValueInFile(essentials);
}

void ThemesInterface::drawEverything(sdl2::RendererWindow& rndWnd) const
{
	drawSelectedTheme(rndWnd);
	buttons.draw(rndWnd);
	themeLanguageText.draw(rndWnd);
}

void ThemesInterface::drawSelectedTheme(sdl2::RendererWindow& rndWnd) const
{
	if( loadedThemes.empty() == false )
	{
		assert( themeIndex < loadedThemes.size() );
		loadedThemes[themeIndex].themeText.draw(rndWnd);
	}
}

void ThemesInterface::update(const Offset& mousePosition, bool mouseButtonState)
{
	buttons.update(mousePosition, mouseButtonState);
}

void ThemesInterface::actWithButtons()
{
	browsePreviousTheme();
	browseNextTheme();
}

void ThemesInterface::browseNextTheme()
{
	if( buttons.nextTheme.buttonClicked() && themeIndex + 1 < loadedThemes.size() )
	{
		themeIndex = themeIndex + 1;
	}
}

void ThemesInterface::browsePreviousTheme()
{
	if( buttons.previousTheme.buttonClicked() && themeIndex > 0 )
	{
		themeIndex--;
	}
}

void ThemesInterface::createThemesTexts(Essentials& essentials)
{
	if( std::ifstream file{ files::ThemesListFilePath } )
	{
		std::string fileLine;
		while( std::getline( file, fileLine ) )
		{
			loadedThemes.emplace_back( ThemesStrings{essentials, font, fileLine} );
		}
	}
	else{
		essentials.logs.error << "Error: couldn't open '" << files::ThemesListFilePath << "' file in order to load the themes.\n";
	}
}

const fs::path& ThemesInterface::getSelectedTheme() const
{
	assert( loadedThemes.empty() == false );
	assert( themeIndex < loadedThemes.size() );
	return loadedThemes[themeIndex].themeDirectory;
}

std::size_t ThemesInterface::getIndex() const
{
	return themeIndex;
}

void ThemesInterface::fetchDefaultThemeIndexValueInFile(Essentials& essentials)
{
	if( std::ifstream file{ path::getOptionFile(essentials.prefPath, files::DefaultThemeFile) } )
	{
		if( !( file >> themeIndex ) )
		{
			essentials.logs.error << "Error: the file '" << path::getOptionFile(essentials.prefPath, files::DefaultThemeFile).string() << "' was opened but reading failed.\n";
		}
	}
	else{
		essentials.logs.error << "Error: couldn't open '" << path::getOptionFile(essentials.prefPath, files::DefaultThemeFile).string() 
								<< "' file in order to read default theme index.\n";
	}
}