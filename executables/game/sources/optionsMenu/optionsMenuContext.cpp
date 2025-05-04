#include "optionsMenu/optionsMenuContext.h"
#include "crossLevel/essentials.h"
#include "optionsMenu/languageChoice.h"
#include "filesSetup/getFilesPaths.h"
#include "consts/colors.h"
#include "consts/filesConsts.h"

void optionsMenu::mainContext(Essentials& essentials)
{
	bool quitMenu{false};
	LanguageChoiceInterface languageChoiceInterface{ essentials };
	essentials.inputs.setMouseLeftButtonToFalse();
	while( false == quitMenu )
	{
		essentials.inputs.updateEvents();
		languageChoiceInterface.updateInterface(essentials);
		optionsMenu::quitMenu(essentials, languageChoiceInterface, quitMenu);
		languageChoiceInterface.changeLanguageWithButtons(essentials);
		optionsMenu::drawEverything(essentials, languageChoiceInterface);
		essentials.inputs.setMouseLeftButtonToFalse();
	}
	essentials.inputs.setKeycodeStateToFalse(SDLK_ESCAPE);
	essentials.inputs.setMouseLeftButtonToFalse();
	optionsMenu::recordSelectedLanguage(essentials);
}

void optionsMenu::drawEverything(Essentials& essentials, const LanguageChoiceInterface& languageChoiceInterface)
{
	if( essentials.drawDelay.hasTimeElapsed( std::chrono::milliseconds{ 16 } ) )
	{
		essentials.drawDelay.joinTimePoints();
		essentials.rndWnd.clearScreen( DullGreen );
		languageChoiceInterface.drawEverything(essentials.rndWnd);
		essentials.rndWnd.displayRenderer();
	}
}

void optionsMenu::quitMenu(Essentials& essentials, const LanguageChoiceInterface& languageChoiceInterface, bool& quitMenu)
{
	if( essentials.inputs.getSdlQuit() || essentials.inputs.getKeycodeState(SDLK_ESCAPE) || languageChoiceInterface.quitMenuButtonClicked() )
	{
		quitMenu = true;
		essentials.inputs.setKeycodeStateToFalse(SDLK_ESCAPE);
	}
}

void optionsMenu::recordSelectedLanguage(Essentials& essentials)
{
	if( std::ofstream languageFile{ path::getOptionFile(essentials.prefPath, files::SelectedLanguageFile) } )
	{
		languageFile << essentials.selectedLanguage;
	}
	else{
		essentials.logs.error << "Error: couldn't open '" << path::getOptionFile(essentials.prefPath, files::SelectedLanguageFile).string() << "' to write selected language.\n";
	}
}