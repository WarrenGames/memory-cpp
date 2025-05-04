#include "mainMenu/mainMenuContext.h"
#include "mainMenu/mainMenuElements.h"
#include "crossLevel/essentials.h"
#include "filesSetup/getFilesPaths.h"
#include "consts/filesConsts.h"
#include "game/global/gameContext.h"
#include "optionsMenu/optionsMenuContext.h"
#include "crossLevel/gameOptions.h"
#include "consts/colors.h"
#include "consts/globalConsts.h"
#include "consts/gameConsts.h"
#include "consts/themesConsts.h"
#include <cassert>
#include <fstream>

void mainMenuContext(Essentials& essentials)
{
	bool quitGame{ false };
	MainMenuElements mainMenuElements{ essentials };
	
	while( false == quitGame )
	{
		essentials.inputs.updateEvents();
		quitMainMenu(essentials, quitGame);
		mainMenuElements.update(essentials);
		runGame(essentials, mainMenuElements);
		goToOptionsMenu(essentials, mainMenuElements.optionsMenuButton);
		drawMainMenu(essentials, mainMenuElements);
		essentials.inputs.setMouseLeftButtonToFalse();
	}
	writeDefaultThemeFile(essentials, mainMenuElements, files::DefaultThemeFile);
}

void quitMainMenu(Essentials& essentials, bool& quitGame)
{
	if( essentials.inputs.getSdlQuit() || essentials.inputs.getKeycodeState(SDLK_ESCAPE) )
	{
		quitGame = true;
	}
}

void drawMainMenu(Essentials& essentials, const MainMenuElements& mainMenuElements)
{
	if( essentials.drawDelay.hasTimeElapsed( std::chrono::milliseconds{ 16 } ) )
	{
		essentials.drawDelay.joinTimePoints();
		essentials.rndWnd.clearScreen( DullGreen );
		mainMenuElements.drawEverything(essentials.rndWnd);
		essentials.rndWnd.displayRenderer();
	}
}

void runGame(Essentials& essentials, const MainMenuElements& mainMenuElements)
{
	assert( mainMenuElements.skillButtons.skillButtons.size() == SkillMax );
	runEasyGame(essentials, mainMenuElements.skillButtons.skillButtons[EasySkill], mainMenuElements.themesInterface );
	runMediumGame(essentials, mainMenuElements.skillButtons.skillButtons[MediumSkill], mainMenuElements.themesInterface );
	runHardGame(essentials, mainMenuElements.skillButtons.skillButtons[HardSkill], mainMenuElements.themesInterface );
}

void runEasyGame(Essentials& essentials, const ButtonFlat& easyButton, const ThemesInterface& themesInterface)
{
	if( easyButton.buttonClicked() )
	{
		game::newGameContext(essentials, GameOptions{themesInterface.getSelectedTheme(), EasyPairNumber, HardPairNumber} );
	}
}

void runMediumGame(Essentials& essentials, const ButtonFlat& mediumButton, const ThemesInterface& themesInterface)
{
	if( mediumButton.buttonClicked() )
	{
		game::newGameContext(essentials, GameOptions{themesInterface.getSelectedTheme(), MediumPairNumber, HardPairNumber});
	}
}

void runHardGame(Essentials& essentials, const ButtonFlat& hardButton, const ThemesInterface& themesInterface)
{
	if( hardButton.buttonClicked() )
	{
		game::newGameContext(essentials, GameOptions{themesInterface.getSelectedTheme(), HardPairNumber, HardPairNumber});
	}
}

void goToOptionsMenu(Essentials& essentials, const OptionsMenuButton& optionsMenuButton)
{
	if( optionsMenuButton.buttonClicked() )
	{
		optionsMenu::mainContext(essentials);
	}
}

void writeDefaultThemeFile(Essentials& essentials, MainMenuElements& mainMenuElements, const fs::path& fileName)
{
	if( std::ofstream file{ path::getOptionFile(essentials.prefPath, fileName) } )
	{
		file << mainMenuElements.themesInterface.getIndex();
	}
	else{
		essentials.logs.error << "Error: couldn't open '" << fileName.string() << "' file in order to save default theme index.\n";
	}
}