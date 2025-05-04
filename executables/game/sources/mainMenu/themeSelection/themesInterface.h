#ifndef MEMORY_CPP_THEMES_INTERFACE_H
#define MEMORY_CPP_THEMES_INTERFACE_H

#include "mainMenu/themeSelection/themeSelectionButtons.h"
#include "text/sdl2ttf_font.h"
#include "texts/textLoader.h"
#include "fileSystem/fileSystem.h"
#include <vector>

struct Essentials;
namespace sdl2{ class RendererWindow; }

struct ThemesStrings
{
	fs::path themeDirectory;
	TextureCombo themeText;
	
	explicit ThemesStrings(Essentials& essentials, const sdl2::Font& font, const fs::path& newThemeDirectory);
	~ThemesStrings() = default;
	ThemesStrings( const ThemesStrings& ) = default;
	ThemesStrings& operator= ( const ThemesStrings& ) = default;
	ThemesStrings( ThemesStrings&& ) = default;
	ThemesStrings& operator= ( ThemesStrings&& ) = default;
};

class ThemesInterface
{
private:
	TextsBlocks texts;
	sdl2::Font font;
	ThemeSelectionButtons buttons;
	std::vector< ThemesStrings > loadedThemes;
	std::size_t themeIndex;
	TextureCombo themeLanguageText;

public:
	explicit ThemesInterface(Essentials& essentials);
	~ThemesInterface() = default;
	ThemesInterface( const ThemesInterface& ) = delete;
	ThemesInterface& operator= ( const ThemesInterface& ) = delete;
	ThemesInterface( ThemesInterface&& ) = default;
	ThemesInterface& operator= ( ThemesInterface&& ) = default;
	
	void drawEverything(sdl2::RendererWindow& rndWnd) const;
	void drawSelectedTheme(sdl2::RendererWindow& rndWnd) const;
	
	void update(const Offset& mousePosition, bool mouseButtonState);
	void actWithButtons();
	void browseNextTheme();
	void browsePreviousTheme();
	
	void createThemesTexts(Essentials& essentials);
	
	const fs::path& getSelectedTheme() const;
	std::size_t getIndex() const;
	void fetchDefaultThemeIndexValueInFile(Essentials& essentials);
};

#endif //MEMORY_CPP_THEMES_INTERFACE_H