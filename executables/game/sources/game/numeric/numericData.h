#ifndef MEMORY_CPP_NUMERIC_DATA_H
#define MEMORY_CPP_NUMERIC_DATA_H

#include "game/numeric/vignettesRandomSelector.h"
#include "matrices/matrix2D.h"

class UserInputs;

struct CardInfos
{
	std::size_t index;
	unsigned status;
	
	CardInfos();
	~CardInfos() = default;
	CardInfos( const CardInfos& ) = default;
	CardInfos& operator= ( const CardInfos& ) = default;
};

struct NumericData
{
	VignettesRandomSelector vignettesRandomSelector;
	unsigned currentStep;
	MatrixTemp2D< CardInfos > cardsIndexesArray;
	std::vector< Coord2D > selectedCards;
	bool areCardsTwin;
	std::size_t whichTextToDisplay;
	unsigned triesNumber;
	bool canUpdateTriesNumberText;
	
	explicit NumericData(std::size_t pairNumber, std::size_t maxPairNumber);
	~NumericData() = default;
	NumericData( const NumericData& ) = delete;
	NumericData& operator= ( const NumericData& ) = delete;
	NumericData( NumericData&& ) = default;
	NumericData& operator= ( NumericData&& ) = default;
	
	bool isGameFinished() const;
	void triesNumberUpdateDone();
	bool canUpdateTriesNumber();
	
	void drawCardsWithMouse(UserInputs& inputs);
	
private:
	void waitForFirstCardToBeClicked(UserInputs& inputs);
	void determineSelectedCardIndex(UserInputs& inputs, std::size_t selectedCardNumber);
	void switchToSecondCardPicking();
	void waitForSecondCardToBeClicked(UserInputs& inputs);
	void testIfRevealedCardsAreTwins(UserInputs& inputs);
	void turnBackCardsWithSpaceBar(UserInputs& inputs);
	void displayTextAccordinglyOfPickedCards();
	void removeCardsFromBoardBecauseTheyAreTwin();
	
	void copyIndexes();
	void shuffleBoardCardsIndexes(std::size_t pairNumber);
	void abortOutsideCards(std::size_t pairNumber);
};

#endif //MEMORY_CPP_NUMERIC_DATA_H