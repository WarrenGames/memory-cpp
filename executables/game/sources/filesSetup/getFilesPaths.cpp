#include "filesSetup/getFilesPaths.h"
#include "prefPath/prefPathFinder.h"

fs::path path::getOptionFile(const PrefPathFinder& prefPath, const fs::path& subFilePath)
{
	return prefPath.getFsPath() / subFilePath;
}

fs::path path::getLanguageFile(const fs::path& selectedLanguage, const fs::path& subFilePath)
{
	fs::path languageFilePath{ "data/languages" / selectedLanguage / subFilePath };
	return languageFilePath;
}