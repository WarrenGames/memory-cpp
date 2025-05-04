#ifndef MEMORY_CPP_FILES_SETUP_H
#define MEMORY_CPP_FILES_SETUP_H

#include "fileSystem/fileSystem.h"

struct AppLogFiles;
class PrefPathFinder;

void setupFiles(AppLogFiles& logs, const PrefPathFinder& prefPath);

void installSelectedLanguageFile(AppLogFiles& logs, const PrefPathFinder& prefPath, const fs::path& selectedLanguageFile);

std::string fetchSelectedLanguage(AppLogFiles& logs, const PrefPathFinder& prefPath, const fs::path& selectedLanguageFile);

void writeDefaultThemeFile(AppLogFiles& logs, const PrefPathFinder& prefPath, const fs::path& defaultThemeFile);

#endif //MEMORY_CPP_FILES_SETUP_H