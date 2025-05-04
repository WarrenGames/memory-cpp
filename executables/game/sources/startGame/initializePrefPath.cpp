#include "startGame/initializePrefPath.h"
#include "startGame/initializeLogFiles.h"
#include "prefPath/prefPathFinder.h"
#include "consts/globalConsts.h"
#include <iostream>

void initializePrefPath()
{
	if( PrefPathFinder prefPathFinder{ OrganizationName, ApplicationName } )
	{
		openLogFiles(prefPathFinder);
	}
	else{
		std::cout << "Error: couldn't initialize pref path with '" << OrganizationName << "' and '" << ApplicationName << "' .\n";
	}
}