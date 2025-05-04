#include "optionsMenu/languageChoice.h"
#include "crossLevel/essentials.h"
#include "filesSetup/getFilesPaths.h"
#include "consts/globalConsts.h"
#include "consts/colors.h"
#include "consts/filesConsts.h"
#include "consts/fontsSizes.h"
#include <cassert>

enum{
	OptionsMenu_Title,
	OptionsMenu_Available,
	OptionsMenu_Selected,
	OptionsMenu_RestartToChange,
	OptionsMenu_Max
};

constexpr int LangChoiceXPos = SquareSize * 2;

constexpr int SelectedXPos = GameScreenWidth / 2 + SquareSize * 2;

LanguageChoiceInterface::LanguageChoiceInterface(Essentials& essentials):
	languagesList{ essentials.logs },
	interfaceTexts{ essentials.logs.error, path::getLanguageFile( essentials.selectedLanguage, files::OptionsMenuInterfaceTexts ), OptionsMenu_Max },
	quitText{ essentials.logs.error, path::getLanguageFile( essentials.selectedLanguage, files::QuitTextFile ), QuitMax },
	font{ essentials.logs.error, GameFontPath, MediumFontSize },
	smallFont{ essentials.logs.error, GameFontPath, SmallFontSize },
	quitMenuButton{ essentials.logs, essentials.rndWnd, smallFont, quitText[QuitText], WhiteColor, MediumGray, TexturePosition{ SquareSize, SquareSize, false, true } },
	selectedLanguagePosition{ SelectedXPos, SquareSize * 5, false, true },
	currentLanguage{ essentials.logs, essentials.rndWnd, smallFont, essentials.selectedLanguage, WhiteColor, selectedLanguagePosition },
	displayRestartHint{ false }
{
	createButtons(essentials);
	createInterfaceTexts(essentials);
}

bool LanguageChoiceInterface::quitMenuButtonClicked() const
{
	return quitMenuButton.buttonClicked();
}

void LanguageChoiceInterface::changeLanguageWithButtons(Essentials& essentials)
{
	assert( languagesButtons.size() == languagesList.size() );
	for( std::size_t i{0} ; i < languagesButtons.size() ; ++i )
	{
		if( languagesButtons[i].buttonClicked() )
		{
			essentials.selectedLanguage = languagesList.getString(i);
			currentLanguage.texture.loadBlendedText(essentials.logs, essentials.rndWnd, smallFont, essentials.selectedLanguage, WhiteColor);
			currentLanguage.sprite.resetDimensions();
			currentLanguage.sprite.resetSourceRect();
			currentLanguage.sprite.setTexturePosition(selectedLanguagePosition); 
			displayRestartHint = true;
		}
	}
}

void LanguageChoiceInterface::updateInterface(Essentials& essentials)
{
	quitMenuButton.updateButton( essentials.inputs.getMousePosition(), essentials.inputs.getMouseLeftButton() );
	updateLanguagesButtons(essentials);
}

void LanguageChoiceInterface::updateLanguagesButtons(Essentials& essentials)
{
	for( auto &btn : languagesButtons )
	{
		btn.updateButton( essentials.inputs.getMousePosition(), essentials.inputs.getMouseLeftButton() );
	}
}

void LanguageChoiceInterface::drawEverything(sdl2::RendererWindow& rndWnd) const
{
	drawInterfaceTexts(rndWnd);
	drawButtons(rndWnd);
	quitMenuButton.drawButton(rndWnd);
	drawRestartHint(rndWnd);
	currentLanguage.draw(rndWnd);
}

void LanguageChoiceInterface::createButtons(Essentials& essentials)
{
	int yPos{ SquareSize * 5 };
	for( auto const &language : languagesList )
	{
		languagesButtons.emplace_back( TextButton{essentials.logs, essentials.rndWnd, smallFont, language, WhiteColor, MediumGray, 
											TexturePosition{ LangChoiceXPos, yPos, false, true } } );
		yPos += SquareSize;
	}
}

void LanguageChoiceInterface::createInterfaceTexts(Essentials& essentials)
{
	for( auto const &text : interfaceTexts )
	{
		interfaceTextsTextures.emplace_back( TextureCombo{ essentials.logs, essentials.rndWnd, font, text, WhiteColor, TexturePosition{} } );
	}
	assert( interfaceTextsTextures.size() == OptionsMenu_Max );
	interfaceTextsTextures[ OptionsMenu_Title ].sprite.setTexturePosition( TexturePosition{ GameScreenWidth / 2, SquareSize, true, true } );
	interfaceTextsTextures[ OptionsMenu_Available ].sprite.setTexturePosition( TexturePosition{ LangChoiceXPos, SquareSize * 4, false, true } );
	interfaceTextsTextures[ OptionsMenu_Selected ].sprite.setTexturePosition( TexturePosition{ SelectedXPos, SquareSize * 4, false, true } );
	interfaceTextsTextures[ OptionsMenu_RestartToChange ].sprite.setTexturePosition( TexturePosition{ SquareSize, GameScreenHeight - SquareSize, false, true } );
}

void LanguageChoiceInterface::drawInterfaceTexts(sdl2::RendererWindow& rndWnd) const
{
	interfaceTextsTextures[ OptionsMenu_Title ].draw(rndWnd);
	interfaceTextsTextures[ OptionsMenu_Available ].draw(rndWnd);
	interfaceTextsTextures[ OptionsMenu_Selected ].draw(rndWnd);
}

void LanguageChoiceInterface::drawButtons(sdl2::RendererWindow& rndWnd) const
{
	for( auto const &button : languagesButtons )
	{
		button.drawButton(rndWnd);
	}
}

void LanguageChoiceInterface::drawRestartHint(sdl2::RendererWindow& rndWnd) const
{
	if( displayRestartHint )
	{
		interfaceTextsTextures[ OptionsMenu_RestartToChange ].sprite.draw(rndWnd);
	}
}