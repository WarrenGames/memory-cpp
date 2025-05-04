#include "game/numeric/numericData.h"
#include "game/numeric/vignetteClickFinder.h"
#include "crossLevel/inputs.h"
#include "consts/gameConsts.h"
#include <random>
#include <algorithm>
#include <cassert>

CardInfos::CardInfos():
	index{ 0 },
	status{ CardHidden }
{
	
}

NumericData::NumericData(std::size_t mainMenuPairNumber, std::size_t loadedPairNumber):
	vignettesRandomSelector{ getRealPairNumber(mainMenuPairNumber, loadedPairNumber) },
	currentStep{ WaitCard1_Choice },
	cardsIndexesArray{ CardsByRow, getMatrixHeightFromPairNumber( getRealPairNumber(mainMenuPairNumber, loadedPairNumber) ) },
	selectedCards(2, Coord2D{ cardsIndexesArray.getCoordSize() } ),
	areCardsTwin{ false },
	whichTextToDisplay{ DisplayMax },
	triesNumber{ 0 },
	canUpdateTriesNumberText{ true }
{
	copyIndexes();
	shuffleBoardCardsIndexes( getRealPairNumber(mainMenuPairNumber, loadedPairNumber) );
	abortOutsideCards( getRealPairNumber(mainMenuPairNumber, loadedPairNumber) );
}

bool NumericData::isGameFinished() const
{
	return std::all_of( std::cbegin( cardsIndexesArray ), std::cend( cardsIndexesArray ), [](auto const& card){ return card.status == CardPairFound; } );
}

void NumericData::triesNumberUpdateDone()
{
	canUpdateTriesNumberText = false;
}

bool NumericData::canUpdateTriesNumber()
{
	return canUpdateTriesNumberText;
}

void NumericData::drawCardsWithMouse(UserInputs& inputs)
{
	switch( currentStep )
	{
		case WaitCard1_Choice:
			waitForFirstCardToBeClicked(inputs);
			break;
		case WaitCard2_Choice:
			waitForSecondCardToBeClicked(inputs);
			break;
		case TestIfCardsTwin:
			testIfRevealedCardsAreTwins(inputs);
			break;
	}
}

void NumericData::waitForFirstCardToBeClicked(UserInputs& inputs)
{
	if( inputs.getMouseLeftButton() )
	{
		determineSelectedCardIndex(inputs, Card1);
		switchToSecondCardPicking();
		inputs.setMouseLeftButtonToFalse();
	}
}

void NumericData::determineSelectedCardIndex(UserInputs& inputs, std::size_t selectedCardNumber)
{
	assert( selectedCardNumber < CardMax );
	selectedCards[selectedCardNumber] = cardsIndexesArray.getCoordSize();
	for( int width{0} ; width < static_cast<int>( cardsIndexesArray.width() ) ; ++width )
	{
		for( int height{0} ; height < static_cast<int>( cardsIndexesArray.height() ) ; ++height )
		{
			if( isCardPicked(inputs.getMousePosition(), width, height) && cardsIndexesArray(width, height).status == CardHidden )
			{
				selectedCards[selectedCardNumber].width = static_cast<std::size_t>(width);
				selectedCards[selectedCardNumber].height = static_cast<std::size_t>(height);
				cardsIndexesArray(width, height).status = CardReveal;
				break;
			}
		}
	}
}

void NumericData::switchToSecondCardPicking()
{
	if( false == coords::are2DCoordsTheSame(selectedCards[Card1], cardsIndexesArray.getCoordSize() ) )
	{
		currentStep = WaitCard2_Choice;
	}
}

void NumericData::waitForSecondCardToBeClicked(UserInputs& inputs)
{
	if( inputs.getMouseLeftButton() && false == inputs.getKeycodeState(SDLK_SPACE) )
	{
		determineSelectedCardIndex(inputs, Card2);
		if( false == coords::are2DCoordsTheSame(selectedCards[Card2], cardsIndexesArray.getCoordSize() ) 
			&& false == coords::are2DCoordsTheSame(selectedCards[Card1], selectedCards[Card2] ) )
		{
			currentStep = TestIfCardsTwin;
			triesNumber++;
			canUpdateTriesNumberText = true;
		}
		inputs.setMouseLeftButtonToFalse();
	}
}

void NumericData::testIfRevealedCardsAreTwins(UserInputs& inputs)
{
	displayTextAccordinglyOfPickedCards();
	turnBackCardsWithSpaceBar(inputs);
}

void NumericData::turnBackCardsWithSpaceBar(UserInputs& inputs)
{
	if( inputs.getKeycodeState(SDLK_SPACE) || inputs.getMouseRightButton() )
	{
		removeCardsFromBoardBecauseTheyAreTwin();
		selectedCards[Card1] = cardsIndexesArray.getCoordSize();
		selectedCards[Card2] = cardsIndexesArray.getCoordSize();
		currentStep = WaitCard1_Choice;
		inputs.setMouseRightButtonToFalse();
		inputs.setKeycodeStateToFalse(SDLK_SPACE);
	}
}

void NumericData::displayTextAccordinglyOfPickedCards()
{
	if( cardsIndexesArray(selectedCards[Card1]).index == cardsIndexesArray(selectedCards[Card2]).index )
	{
		areCardsTwin = true;
		whichTextToDisplay = WellDone;
	}
	else{
		whichTextToDisplay = WhatA_Pity;
	}
}

void NumericData::removeCardsFromBoardBecauseTheyAreTwin()
{
	if( areCardsTwin )
	{
		cardsIndexesArray(selectedCards[Card1]).status = CardPairFound;
		cardsIndexesArray(selectedCards[Card2]).status = CardPairFound;
		areCardsTwin = false;
	}
	else{
		cardsIndexesArray(selectedCards[Card1]).status = CardHidden;
		cardsIndexesArray(selectedCards[Card2]).status = CardHidden;
	}
}

void NumericData::copyIndexes()
{
	for( std::size_t i{0} ; i < vignettesRandomSelector.size() && i * CardMax < cardsIndexesArray.size() ; ++i )
	{
		cardsIndexesArray[i * CardMax + Card1].index = vignettesRandomSelector.getValidIndex(i);
		cardsIndexesArray[i * CardMax + Card2].index = vignettesRandomSelector.getValidIndex(i);
	}
}

void NumericData::shuffleBoardCardsIndexes(std::size_t pairNumber)
{
	std::random_device rd;
	std::mt19937 g{ rd() };
	auto customEndIt{ std::next(cardsIndexesArray.begin(), pairNumber * 2 ) };
	
	std::shuffle( cardsIndexesArray.begin(), customEndIt, g );
}

void NumericData::abortOutsideCards(std::size_t pairNumber)
{
	for( std::size_t i{pairNumber * 2} ; i < cardsIndexesArray.size() ; ++i )
	{
		cardsIndexesArray[i].status = CardPairFound;
	}
}