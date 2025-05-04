#ifndef MEMORY_CPP_MAIN_MENU_SKILL_BUTTONS_H
#define MEMORY_CPP_MAIN_MENU_SKILL_BUTTONS_H

#include "widgets/buttons/buttonFlatWidget.h"
#include "text/sdl2ttf_font.h"
#include "texts/textLoader.h"

struct Essentials;
struct Offset;
namespace sdl2{ class RendererWindow; }

struct MainMenuButtons
{
	TextsBlocks buttonsTexts;
	sdl2::Font font;
	std::vector< TextureCombo > skillsTexts;
	std::vector< ButtonFlat > skillButtons;
	
	explicit MainMenuButtons(Essentials& essentials);
	~MainMenuButtons() = default;
	MainMenuButtons( const MainMenuButtons& ) = delete;
	MainMenuButtons& operator= ( const MainMenuButtons& ) = delete;
	MainMenuButtons( MainMenuButtons&& ) = default;
	MainMenuButtons& operator= ( MainMenuButtons&& ) = default;
	
	void updateButtons(const Offset& mousePosition, bool mouseButtonState);
	void drawButtons(sdl2::RendererWindow& rndWnd) const;

private:
	void createTexts(Essentials& essentials);
	void loadButtonsTextures(Essentials& essentials);
	void drawFlatButtons(sdl2::RendererWindow& rndWnd) const;
	void drawButtonsTexts(sdl2::RendererWindow& rndWnd) const;
};

#endif //MEMORY_CPP_MAIN_MENU_SKILL_BUTTONS_H