#include "mainMenu/vignettesAnimation/vignettesGraphics.h"
#include "texturing/rendererWindow.h"
#include "texturing/texturePosition.h"
#include "logging/logsStruct.h"
#include "mainMenu/mainMenuConsts.h"
#include <string>
#include <cassert>

constexpr char VignTexFilePath[] = "data/mainMenu/vignettesTextures.txt";

VignettesAnimDisplay::VignettesAnimDisplay(AppLogFiles& logs, sdl2::RendererWindow& rndWnd):
	backTextureSprites( VignetteMax )
{
	loadTextures(logs, rndWnd);
}

void VignettesAnimDisplay::update()
{
	vignettesAnimation.update();
	updateActiveSprite();
}

void VignettesAnimDisplay::updateActiveSprite()
{
	for( std::size_t i{0} ; i < vignettesAnimation.size() && i < vignettesTextures.size() ; ++i )
	{
		switch( vignettesAnimation.getSide(i) )
		{
			case VignetteSideRecto:
				vignettesTextures[i].sprite.setWidth(vignettesAnimation.getWidth(i) );
				vignettesTextures[i].sprite.setTexturePosition( TexturePosition{ vignettesAnimation.getPosition(i), true, true } );
				break;
			case VignetteSideVerso:
				backTextureSprites[i].setWidth(vignettesAnimation.getWidth(i) );
				backTextureSprites[i].setTexturePosition( TexturePosition{ vignettesAnimation.getPosition(i), true, true } );
				break;
		}
	}
}

void VignettesAnimDisplay::drawVignettes(sdl2::RendererWindow& rndWnd) const
{
	assert( vignettesAnimation.size() == vignettesTextures.size() );
	for( std::size_t i{0} ; i < vignettesAnimation.size() && i < vignettesTextures.size() ; ++i )
	{
		switch( vignettesAnimation.getSide(i) )
		{
			case VignetteSideRecto:
				//vignettesTextures[i].sprite.setWidth(vignettesAnimation.getWidth(i) );
				//vignettesTextures[i].draw(rndWnd, TexturePosition{ vignettesAnimation.getPosition(i), true, true } );
				vignettesTextures[i].draw(rndWnd);
				break;
			case VignetteSideVerso:
				//backTexture.sprite.setWidth(vignettesAnimation.getWidth(i) );
				//backTexture.draw(rndWnd, TexturePosition{ vignettesAnimation.getPosition(i), true, true } );
				backTextureSprites[i].draw(rndWnd);
				break;
		}
	}
}

void VignettesAnimDisplay::loadTextures(AppLogFiles& logs, sdl2::RendererWindow& rndWnd)
{
	if( std::ifstream file{ VignTexFilePath } )
	{
		loadRectoTextures(logs, rndWnd, file);
		loadVersoTexture(logs, rndWnd, file);
	}
	else{
		logs.error << "Error: couldn't open '" << VignTexFilePath << "' file in order to load main menu vignettes animation.\n";
	}
}

void VignettesAnimDisplay::loadRectoTextures(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, std::ifstream& file)
{
	std::string fileLine;
	for( std::size_t i{0} ; i < vignettesAnimation.size() ; ++i )
	{
		if( std::getline( file, fileLine ) )
		{
			vignettesTextures.emplace_back( TextureCombo{ logs, rndWnd, fileLine } );
		}
		else{
			logs.error << "Error: couldn't read line in '" << VignTexFilePath << "' file in order to load textures for main menu vignettes animation.\n";
		}
	}
}

void VignettesAnimDisplay::loadVersoTexture(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, std::ifstream& file)
{
	std::string fileLine;
	if( std::getline( file, fileLine ) )
	{
		backTexture.loadTextureFile(logs, rndWnd, fileLine);
		if( backTexture )
		{
			for( auto &sprite : backTextureSprites )
			{
				sprite.setTexture(backTexture);
				sprite.resetDimensions();
				sprite.resetSourceRect();
			}
			for( std::size_t i{0} ; i < vignettesAnimation.size() ; ++i )
			{
				backTextureSprites[i].setTexturePosition( vignettesAnimation.getPosition(i), true, true );
			}
		}
		//backTexture.catchTexture();
		//backTexture.sprite.resetDimensions();
		//backTexture.sprite.resetSourceRect();
	}
	else{
		logs.error << "Error: couldn't read verso/back texture in '" << VignTexFilePath << "' file for main menu vignettes animation.\n";
	}
}