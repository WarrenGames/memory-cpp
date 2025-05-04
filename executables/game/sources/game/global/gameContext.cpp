#include "game/global/gameContext.h"
#include "game/global/globalGameObject.h"
#include "crossLevel/essentials.h"
#include "game/replayMenu/replayButton.h"
#include "crossLevel/gameOptions.h"
#include "consts/colors.h"
#include <cassert>

void game::newGameContext(Essentials& essentials, const GameOptions& gameOptions)
{
	GlobalGameObject gameObject{ essentials, gameOptions };
	bool quitGame{false };
	essentials.inputs.setMouseLeftButtonToFalse();
	
	while( false == quitGame && gameObject )
	{
		essentials.inputs.updateEvents();
		game::quitGameWithInputs(essentials, quitGame);
		gameObject.update(essentials);
		game::quitGameInCaseOfSuccess(gameObject, quitGame);
		game::drawEverything(essentials, gameObject);
	}
	sum::drawGameSum(essentials, gameObject);
}

void game::quitGameWithInputs(Essentials& essentials, bool& quitGame)
{
	if( essentials.inputs.getSdlQuit() || essentials.inputs.getKeycodeState(SDLK_ESCAPE) )
	{
		quitGame = true;
	}
}

void game::drawEverything(Essentials& essentials, GlobalGameObject& gameObject)
{
	if( essentials.drawDelay.hasTimeElapsed( std::chrono::milliseconds{ 16 } ) )
	{
		essentials.drawDelay.joinTimePoints();
		essentials.rndWnd.clearScreen( DullGreen );
		gameObject.drawEverything(essentials.rndWnd);
		
		essentials.rndWnd.displayRenderer();
	}
}

void game::quitGameInCaseOfSuccess(const GlobalGameObject& gameObject, bool& quitGame)
{
	if( gameObject.isGameFinished() )
	{
		quitGame = true;
	}
}

void sum::drawGameSum(Essentials& essentials, const GlobalGameObject& gameObject)
{
	bool quitSum{false};
	ReplayButton replayButton{essentials};
	
	while( false == quitSum && gameObject.isGameFinished() )
	{
		essentials.inputs.updateEvents();
		game::quitGameWithInputs(essentials, quitSum);
		sum::replayGame(replayButton, quitSum);
		replayButton.update(essentials.inputs.getMousePosition(), essentials.inputs.getMouseLeftButton() );
		sum::drawEverything(essentials, gameObject, replayButton);
	}
	essentials.inputs.setMouseLeftButtonToFalse();
	essentials.inputs.setKeycodeStateToFalse(SDLK_ESCAPE);
}

void sum::drawEverything(Essentials& essentials, const GlobalGameObject& gameObject, const ReplayButton& replayButton)
{
	if( essentials.drawDelay.hasTimeElapsed( std::chrono::milliseconds{ 16 } ) )
	{
		essentials.drawDelay.joinTimePoints();
		essentials.rndWnd.clearScreen( DullGreen );
		gameObject.drawCardsPickingText(essentials.rndWnd);
		replayButton.drawButton(essentials.rndWnd);
		essentials.rndWnd.displayRenderer();
	}
}

void sum::replayGame(const ReplayButton& replayButton, bool& quitSum)
{
	if( replayButton.isClicked() )
	{
		quitSum = true;
	}
}