#include "startGame/initializeLogFiles.h"
#include "startGame/initializeSDL2.h"
#include "filesSetup/setupFiles.h"
#include "prefPath/prefPathFinder.h"
#include "logging/logsStruct.h"
#include <iostream>

constexpr char ErrorFileName[] = "gameErrors.txt";

constexpr char WarningFileName[] = "gameWarnings.txt";

void openLogFiles(const PrefPathFinder& prefPathFinder)
{
	if( AppLogFiles logs{ prefPathFinder.getFsPath(), ErrorFileName, WarningFileName } )
	{
		setupFiles(logs, prefPathFinder);
		initializeSDL2_Modules(prefPathFinder, logs);
	}
	else{
		std::cout << "Pref path was found: '" << prefPathFinder.getPath() << "' but open logs files (error and warning) failed.\n";
	}
}