#ifndef MEMORY_CPP_ESSENTIALS_H
#define MEMORY_CPP_ESSENTIALS_H

#include "crossLevel/inputs.h"
#include "texturing/rendererWindow.h"
#include "prefPath/prefPathFinder.h"
#include "logging/logsStruct.h"
#include "time/accurateTime.h"

struct Essentials
{
	AppLogFiles& logs;
	sdl2::RendererWindow& rndWnd;
	const PrefPathFinder& prefPath;
	UserInputs inputs;
	AccurateTimeDelay drawDelay;
	std::string selectedLanguage;
	
	explicit Essentials(AppLogFiles& logs_, sdl2::RendererWindow& rndWnd_, const PrefPathFinder& prefPathFinder_);
	~Essentials() = default;
	Essentials( const Essentials& ) = delete;
	Essentials& operator= ( const Essentials& ) = delete;
	//Essentials( Essentials&& ) = default;
	//Essentials& operator = ( Essentials&& ) = default;
};

#endif //MEMORY_CPP_ESSENTIALS_H