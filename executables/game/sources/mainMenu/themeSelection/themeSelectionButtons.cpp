#include "mainMenu/themeSelection/themeSelectionButtons.h"
#include "crossLevel/essentials.h"
#include "texturing/texturePosition.h"
#include "customTypes/positionTypes.h"
#include "consts/globalConsts.h"

constexpr char PreviousButtonTexturePath[] = "textures/gameGUI/previousTheme.png";
constexpr char NextButtonTexturePath[] = "textures/gameGUI/nextTheme.png";

ThemeSelectionButtons::ThemeSelectionButtons(Essentials& essentials):
	previousTheme{ essentials.logs, essentials.rndWnd, PreviousButtonTexturePath, TexturePosition{ SquareSize * 4, GameScreenHeight - SquareSize, true, true} },
	nextTheme{ essentials.logs, essentials.rndWnd, NextButtonTexturePath, TexturePosition{ GameScreenWidth - SquareSize * 4, GameScreenHeight - SquareSize, true, true} }
{
	
}

void ThemeSelectionButtons::update(const Offset& mousePosition, bool mouseButtonState)
{
	previousTheme.updateButton(mousePosition, mouseButtonState);
	nextTheme.updateButton(mousePosition, mouseButtonState);
}

void ThemeSelectionButtons::draw(sdl2::RendererWindow& rndWnd) const
{
	previousTheme.drawButton(rndWnd);
	nextTheme.drawButton(rndWnd);
}