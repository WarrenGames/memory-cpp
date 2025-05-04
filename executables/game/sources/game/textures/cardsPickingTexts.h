#ifndef MEMORY_CPP_CARDS_PICKING_NUMBER_H
#define MEMORY_CPP_CARDS_PICKING_NUMBER_H

#include "texturing/texturesCombo.h"
#include "text/sdl2ttf_font.h"
#include "texts/textLoader.h"

struct Essentials;
namespace sdl2{ class RendererWindow; }

class CardsPickingText
{
private:
	TextsBlocks languageText;
	sdl2::Font font;
	TextureCombo pickText;
	
public:
	explicit CardsPickingText(Essentials& essentials);
	~CardsPickingText() = default;
	CardsPickingText( const CardsPickingText& ) = delete;
	CardsPickingText& operator= ( const CardsPickingText& ) = delete;
	CardsPickingText( CardsPickingText&& ) = default;
	CardsPickingText& operator= ( CardsPickingText&& ) = default;
	
	void updateText(Essentials& essentials, unsigned pickedCardsNumber);
	void drawText(sdl2::RendererWindow& rndWnd) const;
};

#endif //MEMORY_CPP_CARDS_PICKING_NUMBER_H