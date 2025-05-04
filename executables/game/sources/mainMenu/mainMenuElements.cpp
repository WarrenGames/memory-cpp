#include "mainMenu/mainMenuElements.h"
#include "crossLevel/essentials.h"
#include "filesSetup/getFilesPaths.h"
#include "texturing/texturePosition.h"
#include "consts/filesConsts.h"
#include "consts/globalConsts.h"
#include "consts/colors.h"
#include "consts/fontsSizes.h"

enum{ TitleText, TitleMax };

MainMenuElements::MainMenuElements(Essentials& essentials):
	vignettesAnimDisplay{ essentials.logs, essentials.rndWnd },
	skillButtons{ essentials },
	titleText{ essentials.logs.error, path::getLanguageFile(essentials.selectedLanguage, files::TitleText), TitleMax },
	font{ essentials.logs.error, GameFontPath, BigFontSize },
	title{ essentials.logs, essentials.rndWnd, font, titleText[TitleText], WhiteColor, TexturePosition{ GameScreenWidth / 2, SquareSize, true, true } },
	themesInterface{ essentials },
	optionsMenuButton{ essentials }
{
	
}

void MainMenuElements::update(Essentials& essentials)
{
	vignettesAnimDisplay.update();
	skillButtons.updateButtons(essentials.inputs.getMousePosition(), essentials.inputs.getMouseLeftButton() );
	optionsMenuButton.update(essentials);
	themesInterface.update(essentials.inputs.getMousePosition(), essentials.inputs.getMouseLeftButton() );
	themesInterface.actWithButtons();
}
	
void MainMenuElements::drawEverything(sdl2::RendererWindow& rndWnd) const
{
	vignettesAnimDisplay.drawVignettes(rndWnd);
	skillButtons.drawButtons(rndWnd);
	optionsMenuButton.draw(rndWnd);
	title.draw(rndWnd);
	themesInterface.drawEverything(rndWnd);
}
	