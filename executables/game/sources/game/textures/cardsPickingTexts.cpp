#include "game/textures/cardsPickingTexts.h"
#include "crossLevel/essentials.h"
#include "filesSetup/getFilesPaths.h"
#include "texturing/texturePosition.h"
#include "consts/gameConsts.h"
#include "consts/colors.h"
#include "consts/globalConsts.h"
#include "consts/filesConsts.h"
#include "consts/fontsSizes.h"

enum : unsigned{ PickedCards, PickedCardsMax };

CardsPickingText::CardsPickingText(Essentials& essentials):
	languageText{ essentials.logs.error, path::getLanguageFile(essentials.selectedLanguage, files::CardsPickingText), PickedCardsMax },
	font{ essentials.logs.error, GameFontPath, MediumFontSize }
{
	
}

void CardsPickingText::updateText(Essentials& essentials, unsigned pickedCardsNumber)
{
	pickText.texture.loadBlendedText( essentials.logs, essentials.rndWnd, font, languageText[PickedCards] + std::to_string( pickedCardsNumber ), WhiteColor );
	pickText.resetSpritePosition( TexturePosition{ SquareSize, SquareSize / 2, false, true } );
}

void CardsPickingText::drawText(sdl2::RendererWindow& rndWnd) const
{
	pickText.draw(rndWnd);
}