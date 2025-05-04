#include "game/textures/commentsTexts.h"
#include "crossLevel/essentials.h"
#include "filesSetup/getFilesPaths.h"
#include "texturing/texturePosition.h"
#include "consts/gameConsts.h"
#include "consts/colors.h"
#include "consts/globalConsts.h"
#include "consts/filesConsts.h"
#include "consts/fontsSizes.h"
#include <cassert>

CommentsTexts::CommentsTexts(Essentials& essentials):
	languagesTexts{ essentials.logs.error, path::getLanguageFile(essentials.selectedLanguage, files::CommentsTexts), DisplayMax },
	font{ essentials.logs.error, GameFontPath, MediumFontSize }
{
	loadTexts(essentials);
}

void CommentsTexts::drawText(sdl2::RendererWindow& rndWnd, std::size_t textIndex) const
{
	assert( textIndex < texts.size() );
	texts[textIndex].draw(rndWnd);
}

void CommentsTexts::loadTexts(Essentials& essentials)
{
	for( auto const &text : languagesTexts )
	{
		texts.emplace_back( TextureCombo{ essentials.logs, essentials.rndWnd, font, text, WhiteColor, 
								TexturePosition{ GameScreenWidth / 2, SquareSize / 2, false, true } } );
	}
	texts[ PushSpace ].resetSpritePosition( TexturePosition{ SquareSize, GameScreenHeight - SquareSize / 2, false, true } );
}