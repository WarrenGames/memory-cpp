#include "filesSetup/setupFiles.h"
#include "filesSetup/getFilesPaths.h"
#include "logging/logsStruct.h"
#include "fileSystem/fileSystem.h"
#include "consts/filesConsts.h"
#include "consts/globalConsts.h"
#include <fstream>

void setupFiles(AppLogFiles& logs, const PrefPathFinder& prefPath)
{
	installSelectedLanguageFile(logs, prefPath, files::SelectedLanguageFile);
	writeDefaultThemeFile(logs, prefPath, files::DefaultThemeFile);
}

void installSelectedLanguageFile(AppLogFiles& logs, const PrefPathFinder& prefPath, const fs::path& selectedLanguageFileName)
{
	if( false == fs::exists( path::getOptionFile(prefPath, selectedLanguageFileName) ) )
	{
		if( std::ofstream languageFile{ path::getOptionFile(prefPath, selectedLanguageFileName) } )
		{
			languageFile << DefaultGameLanguage;
		}
		else{
			logs.error << "Error: couldn't open '" << path::getOptionFile(prefPath, selectedLanguageFileName).string() << "' file in order to write default game language.\n";
		}
	}
}

std::string fetchSelectedLanguage(AppLogFiles& logs, const PrefPathFinder& prefPath, const fs::path& selectedLanguageFileName)
{
	if( std::ifstream file{ path::getOptionFile(prefPath, selectedLanguageFileName) } )
	{
		std::string text;
		if( file >> text )
		{
			return text;
		}
		else{
			logs.error << "Error: couldn't read '" << path::getOptionFile(prefPath, selectedLanguageFileName) << "' file in order to load selected language.\n";
		}
	}
	else{
		logs.error << "Error: couldn't open '" << path::getOptionFile(prefPath, selectedLanguageFileName) << "' file in order to load selected language.\n";
	}
	return DefaultGameLanguage;
}

void writeDefaultThemeFile(AppLogFiles& logs, const PrefPathFinder& prefPath, const fs::path& defaultThemeFile)
{
	if( false == fs::exists( path::getOptionFile(prefPath, defaultThemeFile) ) )
	{
		if( std::ofstream file{ path::getOptionFile(prefPath, defaultThemeFile) } )
		{
			file << "0";
		}
		else{
			logs.error << "Error: couldn't open '" << path::getOptionFile(prefPath, defaultThemeFile).string() << "' file in order to write default theme index.\n";
		}
	}
}