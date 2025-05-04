#ifndef MEMORY_CPP_MAIN_MENU_OPTIONS_BUTTON_H
#define MEMORY_CPP_MAIN_MENU_OPTIONS_BUTTON_H

#include "widgets/buttons/buttonFlatWidget.h"
#include "text/sdl2ttf_font.h"
#include "texts/textLoader.h"

struct Essentials;
namespace sdl2{ class RendererWindow; }

class OptionsMenuButton
{
private:
	TextsBlocks optionText;
	sdl2::Font font;
	TextureCombo optionsTextTexture;
	ButtonFlat optionsMenuButton;

public:
	explicit OptionsMenuButton(Essentials& essentials);
	~OptionsMenuButton() = default;
	OptionsMenuButton( const OptionsMenuButton& ) = delete;
	OptionsMenuButton& operator= ( const OptionsMenuButton& ) = delete;
	OptionsMenuButton( OptionsMenuButton&& ) = default;
	OptionsMenuButton& operator= ( OptionsMenuButton&& ) = default;
	
	void update(Essentials& essentials);
	void draw(sdl2::RendererWindow& rndWnd) const;
	bool buttonClicked() const;
};

#endif //MEMORY_CPP_MAIN_MENU_OPTIONS_BUTTON_H