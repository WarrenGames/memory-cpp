#include "mainMenu/buttons/skillButtons.h"
#include "crossLevel/essentials.h"
#include "filesSetup/getFilesPaths.h"
#include "texturing/texturePosition.h"
#include "mainMenu/mainMenuConsts.h"
#include "consts/globalConsts.h"
#include "consts/colors.h"
#include "consts/filesConsts.h"
#include "consts/fontsSizes.h"

constexpr char EasyBtnTexturePath[] = "textures/gameGUI/easyButton.png";
constexpr char MediumBtnTexturePath[] = "textures/gameGUI/mediumButton.png";
constexpr char HardBtnTexturePath[] = "textures/gameGUI/hardButton.png";

MainMenuButtons::MainMenuButtons(Essentials& essentials):
	buttonsTexts{ essentials.logs.error, path::getLanguageFile( essentials.selectedLanguage, files::SkillLevelsTexts ), SkillMax },
	font{ essentials.logs.error, GameFontPath, MenuFontSize }
{
	createTexts(essentials);
	loadButtonsTextures(essentials);
}

void MainMenuButtons::updateButtons(const Offset& mousePosition, bool mouseButtonState)
{
	for( auto &button : skillButtons )
	{
		button.updateButton(mousePosition, mouseButtonState);
	}
}

void MainMenuButtons::drawButtons(sdl2::RendererWindow& rndWnd) const
{
	drawFlatButtons(rndWnd);
	drawButtonsTexts(rndWnd);
}

void MainMenuButtons::createTexts(Essentials& essentials)
{
	int yPos{ SquareSize * 5 };
	for( auto const &text : buttonsTexts )
	{
		skillsTexts.emplace_back( TextureCombo{essentials.logs, essentials.rndWnd, font, text, WhiteColor, TexturePosition{ GameScreenWidth / 2, yPos, true, true } } );
		yPos += SquareSize * 2;
	}
}

void MainMenuButtons::loadButtonsTextures(Essentials& essentials)
{
	skillButtons.emplace_back( ButtonFlat{essentials.logs, essentials.rndWnd, EasyBtnTexturePath, TexturePosition{ GameScreenWidth / 2, SquareSize * 5, true, true } } );
	skillButtons.emplace_back( ButtonFlat{essentials.logs, essentials.rndWnd, MediumBtnTexturePath, TexturePosition{ GameScreenWidth / 2, SquareSize * 7, true, true } } );
	skillButtons.emplace_back( ButtonFlat{essentials.logs, essentials.rndWnd, HardBtnTexturePath, TexturePosition{ GameScreenWidth / 2, SquareSize * 9, true, true } } );
}

void MainMenuButtons::drawFlatButtons(sdl2::RendererWindow& rndWnd) const
{
	for( auto const &button : skillButtons )
	{
		button.drawButton(rndWnd);
	}
}

void MainMenuButtons::drawButtonsTexts(sdl2::RendererWindow& rndWnd) const
{
	for( auto const &text : skillsTexts )
	{
		text.draw(rndWnd);
	}
}