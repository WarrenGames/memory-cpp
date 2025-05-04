#ifndef MEMORY_CPP_OPTIONS_MENU_LANGUAGE_CHOICE_H
#define MEMORY_CPP_OPTIONS_MENU_LANGUAGE_CHOICE_H

#include "optionsMenu/languagesList.h"
#include "widgets/buttons/textButtonWidget.h"
#include "text/sdl2ttf_font.h"
#include "texturing/texturePosition.h"
#include "texts/textLoader.h"

struct Essentials;
namespace sdl2{ class RendererWindow; }

class LanguageChoiceInterface
{
private:
	InterfaceLanguagesList languagesList;
	TextsBlocks interfaceTexts;
	TextsBlocks quitText;
	sdl2::Font font;
	sdl2::Font smallFont;
	std::vector< TextButton > languagesButtons;
	std::vector< TextureCombo > interfaceTextsTextures;
	TextButton quitMenuButton;
	TexturePosition selectedLanguagePosition;
	TextureCombo currentLanguage;
	bool displayRestartHint;

public:
	explicit LanguageChoiceInterface(Essentials& essentials);
	~LanguageChoiceInterface() = default;
	LanguageChoiceInterface( const LanguageChoiceInterface& ) = delete;
	LanguageChoiceInterface& operator= ( const LanguageChoiceInterface& ) = delete;
	LanguageChoiceInterface( LanguageChoiceInterface&& ) = default;
	LanguageChoiceInterface& operator= ( LanguageChoiceInterface&& ) = default;
	
	void drawEverything(sdl2::RendererWindow& rndWnd) const;
	void updateInterface(Essentials& essentials);
	bool quitMenuButtonClicked() const;
	void changeLanguageWithButtons(Essentials& essentials);

private:
	void createButtons(Essentials& essentials);
	void createInterfaceTexts(Essentials& essentials);
	void drawInterfaceTexts(sdl2::RendererWindow& rndWnd) const;
	void drawButtons(sdl2::RendererWindow& rndWnd) const;
	void drawRestartHint(sdl2::RendererWindow& rndWnd) const;
	void updateLanguagesButtons(Essentials& essentials);
};

#endif //MEMORY_CPP_OPTIONS_MENU_LANGUAGE_CHOICE_H