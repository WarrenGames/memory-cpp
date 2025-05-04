#ifndef MEMORY_CPP_OPTIONS_MENU_CONTEXT_H
#define MEMORY_CPP_OPTIONS_MENU_CONTEXT_H

struct Essentials;
class LanguageChoiceInterface;

namespace optionsMenu{
	void mainContext(Essentials& essentials);
	
	void drawEverything(Essentials& essentials, const LanguageChoiceInterface& languageChoiceInterface);
	
	void quitMenu(Essentials& essentials, const LanguageChoiceInterface& languageChoiceInterface, bool& quitMenu);
	
	void recordSelectedLanguage(Essentials& essentials);
}

#endif //MEMORY_CPP_OPTIONS_MENU_CONTEXT_H