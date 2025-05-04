#include "crossLevel/essentials.h"
#include "filesSetup/setupFiles.h"
#include "consts/filesConsts.h"

Essentials::Essentials(AppLogFiles& logs_, sdl2::RendererWindow& rndWnd_, const PrefPathFinder& prefPathFinder_):
	logs{ logs_ },
	rndWnd{ rndWnd_ },
	prefPath{ prefPathFinder_ },
	inputs{ std::vector<SDL_Keycode>{SDLK_ESCAPE, SDLK_SPACE} },
	selectedLanguage{ fetchSelectedLanguage(logs, prefPath, files::SelectedLanguageFile) }
{
	
}