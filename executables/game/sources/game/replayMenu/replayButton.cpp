#include "game/replayMenu/replayButton.h"
#include "crossLevel/essentials.h"
#include "filesSetup/getFilesPaths.h"
#include "widgets/buttons/buttonFlatWidget.h"
#include "texturing/texturePosition.h"
#include "mainMenu/mainMenuConsts.h"
#include "consts/colors.h"
#include "consts/filesConsts.h"
#include "consts/fontsSizes.h"

enum{ ReplayText, ReplayMax };

constexpr char ReplayButtonPath[] = "textures/gameGUI/replayButton.png";

ReplayButton::ReplayButton(Essentials& essentials):
	texts{essentials.logs.error, path::getLanguageFile(essentials.selectedLanguage, files::ReplayContext), ReplayMax },
	font{ essentials.logs.error, GameFontPath, MenuFontSize },
	guiText{ essentials.logs, essentials.rndWnd, font, texts[ReplayText], WhiteColor, TexturePosition{ GameScreenWidth / 2, GameScreenHeight / 2, true, true } },
	replayButton{essentials.logs, essentials.rndWnd, ReplayButtonPath, TexturePosition{ GameScreenWidth / 2, GameScreenHeight / 2, true, true } }
{
	
}

void ReplayButton::update(const Offset& mousePosition, bool mouseButtonState)
{
	replayButton.updateButton(mousePosition, mouseButtonState);
}

bool ReplayButton::isClicked() const
{
	return replayButton.buttonClicked();
}

void ReplayButton::drawButton(sdl2::RendererWindow& rndWnd) const
{
	replayButton.drawButton(rndWnd);
	guiText.draw(rndWnd);
}