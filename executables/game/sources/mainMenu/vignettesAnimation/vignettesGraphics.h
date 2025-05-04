#ifndef MEMORY_CPP_MAIN_MENU_VIGNETTES_GRAPHISMS_H
#define MEMORY_CPP_MAIN_MENU_VIGNETTES_GRAPHISMS_H

#include "mainMenu/vignettesAnimation/vignettesAnimation.h"
#include "texturing/texturesCombo.h"
#include <iosfwd>

struct AppLogFiles;
namespace sdl2{ class RendererWindow; }

class VignettesAnimDisplay
{
private:
	VignettesAnimation vignettesAnimation;
	std::vector< TextureCombo > vignettesTextures;
	sdl2::TextureLoader backTexture;
	std::vector< sdl2::Sprite > backTextureSprites;

public:
	explicit VignettesAnimDisplay(AppLogFiles& logs, sdl2::RendererWindow& rndWnd);
	~VignettesAnimDisplay() = default;
	VignettesAnimDisplay( const VignettesAnimDisplay& ) = delete;
	VignettesAnimDisplay& operator= ( const VignettesAnimDisplay& ) = delete;
	VignettesAnimDisplay( VignettesAnimDisplay&& ) = default;
	VignettesAnimDisplay& operator= ( VignettesAnimDisplay&& ) = default;
	
	void update();
	void drawVignettes(sdl2::RendererWindow& rndWnd) const;

private:
	void updateActiveSprite();
	void loadTextures(AppLogFiles& logs, sdl2::RendererWindow& rndWnd);
	void loadRectoTextures(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, std::ifstream& file);
	void loadVersoTexture(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, std::ifstream& file);
};

#endif //MEMORY_CPP_MAIN_MENU_VIGNETTES_GRAPHISMS_H