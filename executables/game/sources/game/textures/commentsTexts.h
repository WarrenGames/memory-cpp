#ifndef MEMORY_CPP_TEXTURES_COMMENTS_TEXTS_H
#define MEMORY_CPP_TEXTURES_COMMENTS_TEXTS_H

#include "texturing/texturesCombo.h"
#include "text/sdl2ttf_font.h"
#include "texts/textLoader.h"

struct Essentials;
namespace sdl2{ class RendererWindow; }

class CommentsTexts
{
private:
	TextsBlocks languagesTexts;
	sdl2::Font font;
	std::vector< TextureCombo > texts;

public:
	explicit CommentsTexts(Essentials& essentials);
	~CommentsTexts() = default;
	CommentsTexts( const CommentsTexts& ) = delete;
	CommentsTexts& operator= ( const CommentsTexts& ) = delete;
	CommentsTexts( CommentsTexts&& ) = default;
	CommentsTexts& operator= ( CommentsTexts&& ) = default;
	
	void drawText(sdl2::RendererWindow& rndWnd, std::size_t textIndex) const;

private:
	void loadTexts(Essentials& essentials);
};

#endif //MEMORY_CPP_TEXTURES_COMMENTS_TEXTS_H