#ifndef MEMORY_CPP_GET_FILES_PATHS_H
#define MEMORY_CPP_GET_FILES_PATHS_H

#include "fileSystem/fileSystem.h"

class PrefPathFinder;

namespace path{

fs::path getOptionFile(const PrefPathFinder& prefPath, const fs::path& subFilePath);

fs::path getLanguageFile(const fs::path& selectedLanguage, const fs::path& subFilePath);

}

#endif //MEMORY_CPP_GET_FILES_PATHS_H