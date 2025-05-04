#include "startGame/initializeSDL2.h"
#include "startGame/initializeRenderer.h"
#include "initialization/sdl2TTF_Init.h"
#include "initialization/sdl2ModuleInit.h"
#include "prefPath/prefPathFinder.h"
#include "logging/logsStruct.h"
#include "SDL.h"

void initializeSDL2_Modules(const PrefPathFinder& prefPathFinder, AppLogFiles& logs)
{
	if( const sdl2::ModuleInit sdl2_init{ SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER | SDL_INIT_HAPTIC, logs.error} )
	{
		if( const sdl2::TTFModule ttfInit{ logs.error } )
		{
			initializeRenderer(prefPathFinder, logs);
		}
		else{
			logs.error << "Error: SDL2 ttf initialization failed.\n";
		}
	}
	else{
		logs.error << "Error: SDL2 initialization failed.\n";
	}
}