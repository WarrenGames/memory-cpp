#ifndef MEMORY_CPP_GAME_REPLAY_BUTTON_H
#define MEMORY_CPP_GAME_REPLAY_BUTTON_H

#include "widgets/buttons/buttonFlatWidget.h"
#include "text/sdl2ttf_font.h"
#include "texts/textLoader.h"

struct Essentials;
struct Offset;
namespace sdl2{ class RendererWindow; }

class ReplayButton
{
private:
	TextsBlocks texts;
	sdl2::Font font;
	TextureCombo guiText;
	ButtonFlat replayButton;

public:
	explicit ReplayButton(Essentials& essentials);
	~ReplayButton() = default;
	ReplayButton( const ReplayButton& ) = delete;
	ReplayButton& operator= ( const ReplayButton& ) = delete;
	ReplayButton( ReplayButton&& ) = default;
	ReplayButton& operator= ( ReplayButton&& ) = default;
	
	void update(const Offset& mousePosition, bool mouseButtonState);
	bool isClicked() const;
	void drawButton(sdl2::RendererWindow& rndWnd) const;
};

#endif //MEMORY_CPP_GAME_REPLAY_BUTTON_H