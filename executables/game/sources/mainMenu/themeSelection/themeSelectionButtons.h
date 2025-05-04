#ifndef MEMORY_CPP_THEME_SELECTION_BUTTON_H
#define MEMORY_CPP_THEME_SELECTION_BUTTON_H

#include "widgets/buttons/buttonFlatWidget.h"

struct Essentials;
struct Offset;

struct ThemeSelectionButtons
{
	ButtonFlat previousTheme;
	ButtonFlat nextTheme;
	
	explicit ThemeSelectionButtons(Essentials& essentials);
	~ThemeSelectionButtons() = default;
	ThemeSelectionButtons( const ThemeSelectionButtons& ) = delete;
	ThemeSelectionButtons& operator= ( const ThemeSelectionButtons& ) = delete;
	ThemeSelectionButtons( ThemeSelectionButtons&& ) = default;
	ThemeSelectionButtons& operator= ( ThemeSelectionButtons&& ) = default;
	
	void update(const Offset& mousePosition, bool mouseButtonState);
	void draw(sdl2::RendererWindow& rndWnd) const;
};

#endif //MEMORY_CPP_THEME_SELECTION_BUTTON_H