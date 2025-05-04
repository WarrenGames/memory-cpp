#ifndef MEMORY_CPP_MAIN_MENU_CONTEXT_H
#define MEMORY_CPP_MAIN_MENU_CONTEXT_H

#include "fileSystem/fileSystem.h"

struct Essentials;
struct MainMenuElements;
class ButtonFlat;
class ThemesInterface;
class OptionsMenuButton;

void mainMenuContext(Essentials& essentials);

void quitMainMenu(Essentials& essentials, bool& quitGame);

void drawMainMenu(Essentials& essentials, const MainMenuElements& mainMenuElements);

void runGame(Essentials& essentials, const MainMenuElements& mainMenuElements);

void runEasyGame(Essentials& essentials, const ButtonFlat& easyButton, const ThemesInterface& themesInterface);

void runMediumGame(Essentials& essentials, const ButtonFlat& mediumButton, const ThemesInterface& themesInterface);

void runHardGame(Essentials& essentials, const ButtonFlat& hardButton, const ThemesInterface& themesInterface);

void goToOptionsMenu(Essentials& essentials, const OptionsMenuButton& optionsMenuButton);

void writeDefaultThemeFile(Essentials& essentials, MainMenuElements& mainMenuElements, const fs::path& fileName);

#endif //MEMORY_CPP_MAIN_MENU_CONTEXT_H