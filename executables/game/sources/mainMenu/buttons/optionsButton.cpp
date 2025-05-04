#include "mainMenu/buttons/optionsButton.h"
#include "crossLevel/essentials.h"
#include "filesSetup/getFilesPaths.h"
#include "texturing/texturePosition.h"
#include "mainMenu/mainMenuConsts.h"
#include "consts/globalConsts.h"
#include "consts/colors.h"
#include "consts/filesConsts.h"
#include "consts/fontsSizes.h"

enum{ OptionsMenuText, OptionsMenuMax };

constexpr int OptionButtonYCenterPos = 3 * SquareSize;

constexpr char OptionsMenuButtonTexturePath[] = "textures/gameGUI/optionsMenuButton.png";

OptionsMenuButton::OptionsMenuButton(Essentials& essentials):
	optionText{ essentials.logs.error, path::getLanguageFile(essentials.selectedLanguage, files::OptionsMenuText), OptionsMenuMax },
	font{ essentials.logs.error, GameFontPath, MenuFontSize },
	optionsTextTexture{ essentials.logs, essentials.rndWnd, font, optionText[OptionsMenuText], WhiteColor, TexturePosition{ GameScreenWidth / 2, OptionButtonYCenterPos, true, true } },
	optionsMenuButton{ essentials.logs, essentials.rndWnd, OptionsMenuButtonTexturePath, TexturePosition{ GameScreenWidth / 2, OptionButtonYCenterPos, true, true } }
{
	
}

void OptionsMenuButton::update(Essentials& essentials)
{
	optionsMenuButton.updateButton( essentials.inputs.getMousePosition(), essentials.inputs.getMouseLeftButton() );
}

void OptionsMenuButton::draw(sdl2::RendererWindow& rndWnd) const
{
	optionsMenuButton.drawButton(rndWnd);
	optionsTextTexture.draw(rndWnd);
}

bool OptionsMenuButton::buttonClicked() const
{
	return optionsMenuButton.buttonClicked();
}