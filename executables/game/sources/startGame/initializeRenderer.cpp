#include "startGame/initializeRenderer.h"
#include "crossLevel/essentials.h"
#include "mainMenu/mainMenuContext.h"
#include "consts/globalConsts.h"
#include "SDL_timer.h"

constexpr char IconPath[] = "textures/themes/70sGame/5.png";

void initializeRenderer(const PrefPathFinder& prefPathFinder, AppLogFiles& logs)
{
	if( sdl2::RendererWindow rndWnd{ logs.error, GameScreenWidth, GameScreenHeight, "Memory game", IconPath} )
	{
		Essentials essentials{ logs, rndWnd, prefPathFinder };
		
		mainMenuContext(essentials);
	}
	else{
		logs.error << "Error: couldn't initialize SDL2 Window and/or Renderer.\n";
	}
}