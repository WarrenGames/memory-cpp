#ifndef MEMORY_CPP_OPTIONS_MENU_LANGUAGE_LIST_H
#define MEMORY_CPP_OPTIONS_MENU_LANGUAGE_LIST_H

#include <string>
#include <vector>

struct AppLogFiles;

class InterfaceLanguagesList
{
private:
	std::vector< std::string > list;
	
public:
	InterfaceLanguagesList(AppLogFiles& logs);
	~InterfaceLanguagesList() = default;
	InterfaceLanguagesList( const InterfaceLanguagesList& ) = default;
	InterfaceLanguagesList& operator= ( const InterfaceLanguagesList& ) = default;
	InterfaceLanguagesList( InterfaceLanguagesList&& ) = default;
	InterfaceLanguagesList& operator= ( InterfaceLanguagesList&& ) = default;
	
	std::vector< std::string >::const_iterator begin() const;
	std::vector< std::string >::const_iterator end() const;
	std::size_t size() const;
	const std::string& getString(std::size_t index) const;

private:
	void loadList(AppLogFiles& logs);
};

#endif //MEMORY_CPP_OPTIONS_MENU_LANGUAGE_LIST_H