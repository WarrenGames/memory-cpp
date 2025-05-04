#include "game/global/globalGameObject.h"
#include "game/numeric/vignetteClickFinder.h"
#include "crossLevel/gameOptions.h"
#include "crossLevel/essentials.h"
#include "consts/gameConsts.h"
#include "consts/globalConsts.h"

GlobalGameObject::GlobalGameObject(Essentials& essentials, const GameOptions& gameOptions):
	texturesPackage{ essentials, gameOptions.specificThemeDirectory },
	numericData{ gameOptions.pairNumber, texturesPackage.vignettesTextures.size() }
{
	
}

GlobalGameObject::operator bool() const
{
	return texturesPackage.wasLoadingPerfect();
}

void GlobalGameObject::update(Essentials& essentials)
{
	numericData.drawCardsWithMouse(essentials.inputs);
	updateCardsPickNumber(essentials);
}

void GlobalGameObject::updateCardsPickNumber(Essentials& essentials)
{
	if( numericData.canUpdateTriesNumber() )
	{
		texturesPackage.cardsPickingText.updateText(essentials, numericData.triesNumber);
		numericData.triesNumberUpdateDone();
	}
}

void GlobalGameObject::drawEverything(sdl2::RendererWindow& rndWnd)
{
	drawCards(rndWnd);
	drawComment(rndWnd);
	drawCardsPickingText(rndWnd);
	drawHintsToTurnBackRevealedCards(rndWnd);
}

void GlobalGameObject::drawCardsPickingText(sdl2::RendererWindow& rndWnd) const
{
	texturesPackage.cardsPickingText.drawText(rndWnd);
}

bool GlobalGameObject::isGameFinished() const
{
	return numericData.isGameFinished();
}

void GlobalGameObject::drawCards(sdl2::RendererWindow& rndWnd)
{
	for( int width{0} ; width < static_cast<int>( numericData.cardsIndexesArray.width() ); ++width )
	{
		for( int height{0} ; height < static_cast<int>( numericData.cardsIndexesArray.height() ) ; ++height )
		{
			drawSingleCard(rndWnd, numericData.cardsIndexesArray(width, height), width, height);
		}
	}
}

void GlobalGameObject::drawSingleCard(sdl2::RendererWindow& rndWnd, const CardInfos& cardInfos, int width, int height)
{
	if( cardInfos.status != CardPairFound )
	{
		if( areCoordsOneOfTheSelectedCards(width, height, Card1) || areCoordsOneOfTheSelectedCards(width, height, Card2) )
		{
			texturesPackage.vignettesTextures.drawTexture(rndWnd, getCardXPos(width), getCardYPos(height), cardInfos.index); 
		}
		else{
			texturesPackage.cardsBackTexture.draw(rndWnd, getCardXPos(width), getCardYPos(height) );
		}
	}
}

void GlobalGameObject::drawComment(sdl2::RendererWindow& rndWnd) const
{
	if( numericData.whichTextToDisplay < DisplayMax )
	{
		texturesPackage.commentsTexts.drawText(rndWnd, numericData.whichTextToDisplay);
	}
}

bool GlobalGameObject::areCoordsOneOfTheSelectedCards(int width, int height, std::size_t selectedCardIndex) const
{
	return coords::are2DCoordsTheSame( numericData.selectedCards[selectedCardIndex], Coord2D{static_cast<std::size_t>(width), static_cast<std::size_t>(height) } );
}

void GlobalGameObject::drawHintsToTurnBackRevealedCards(sdl2::RendererWindow& rndWnd) const
{
	if( numericData.currentStep == TestIfCardsTwin )
	{
		texturesPackage.commentsTexts.drawText(rndWnd, PushSpace );
	}
}