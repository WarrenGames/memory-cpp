#ifndef MEMORY_CPP_FILES_CONSTS_H
#define MEMORY_CPP_FILES_CONSTS_H

namespace files{
	constexpr char SelectedLanguageFile[] = "selectedLanguage.txt";
	
	constexpr char SkillLevelsTexts[] = "skillLevelsButtons.txt";
	constexpr char TitleText[] = "title.txt";
	constexpr char CommentsTexts[] = "comments.txt";
	constexpr char CardsPickingText[] = "cardsPicking.txt";
	
	constexpr char ReplayContext[] = "replayContext.txt";
	
	constexpr char ThemesListFilePath[] = "data/themes/themesList.txt";

	constexpr char ThemeGUILanguageFile[] = "themesInterface.txt";
	
	constexpr char DefaultThemeFile[] = "defaultThemeFile.txt";
	
	constexpr char OptionsMenuText[] = "options.txt";
	
	constexpr char OptionsMenuInterfaceTexts[] = "optionsMenu.txt";
	
	constexpr char LanguagesListFilePath[] = "data/languages/availableLanguages.txt";
	
	constexpr char QuitTextFile[] = "quit.txt";
}

enum{
	QuitText,
	QuitMax
};

#endif //MEMORY_CPP_FILES_CONSTS_H