#include "optionsMenu/languagesList.h"
#include "logging/logsStruct.h"
#include "consts/filesConsts.h"
#include <cassert>

InterfaceLanguagesList::InterfaceLanguagesList(AppLogFiles& logs)
{
	loadList(logs);
}

std::vector< std::string >::const_iterator InterfaceLanguagesList::begin() const
{
	return std::cbegin( list );
}

std::vector< std::string >::const_iterator InterfaceLanguagesList::end() const
{
	return std::cend( list );
}

std::size_t InterfaceLanguagesList::size() const
{
	return list.size();
}

const std::string& InterfaceLanguagesList::getString(std::size_t index) const
{
	assert( index < list.size() );
	return list[index];
}

void InterfaceLanguagesList::loadList(AppLogFiles& logs)
{
	if( std::ifstream listFile{ files::LanguagesListFilePath } )
	{
		std::string fileLine;
		while( std::getline( listFile, fileLine ) )
		{
			list.emplace_back( fileLine );
		}
	}
	else{
		logs.error << "Error: couldn open '" << files::LanguagesListFilePath << "' in order to load languages list.\n";
	}
}