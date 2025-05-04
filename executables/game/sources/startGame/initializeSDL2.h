#ifndef MEMORY_CPP_INITIALIZE_SDL2_MODULES_H
#define MEMORY_CPP_INITIALIZE_SDL2_MODULES_H

class PrefPathFinder;
struct AppLogFiles;

void initializeSDL2_Modules(const PrefPathFinder& prefPathFinder, AppLogFiles& logs);

#endif //MEMORY_CPP_INITIALIZE_SDL2_MODULES_H