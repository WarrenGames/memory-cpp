#ifndef MEMORY_CPP_MAIN_MENU_ELEMENTS_H
#define MEMORY_CPP_MAIN_MENU_ELEMENTS_H

#include "mainMenu/vignettesAnimation/vignettesGraphics.h"
#include "mainMenu/buttons/skillButtons.h"
#include "mainMenu/themeSelection/themesInterface.h"
#include "mainMenu/buttons/optionsButton.h"

struct Essentials;

struct MainMenuElements
{
	VignettesAnimDisplay vignettesAnimDisplay;
	MainMenuButtons skillButtons;
	TextsBlocks titleText;
	sdl2::Font font;
	TextureCombo title;
	ThemesInterface themesInterface;
	OptionsMenuButton optionsMenuButton;
	
	explicit MainMenuElements(Essentials& essentials);
	~MainMenuElements() = default;
	MainMenuElements( const MainMenuElements& ) = delete;
	MainMenuElements& operator= ( const MainMenuElements& ) = delete;
	MainMenuElements( MainMenuElements&& ) = default;
	MainMenuElements& operator= ( MainMenuElements&& ) = default;
	
	void update(Essentials& essentials);
	
	void drawEverything(sdl2::RendererWindow& rndWnd) const;
};

#endif //MEMORY_CPP_MAIN_MENU_ELEMENTS_H