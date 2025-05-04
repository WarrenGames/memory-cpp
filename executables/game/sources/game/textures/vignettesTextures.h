#ifndef MEMORY_CPP_VIGNETTES_TEXTURES_H
#define MEMORY_CPP_VIGNETTES_TEXTURES_H

/*
	This class load a textures theme list

*/

#include "advancedDrawing/texturesLoading/fileTexturesList.h"
#include "advancedDrawing/texturesDrawing/constAnimationDrawing.h"
#include "fileSystem/fileSystem.h"

struct AppLogFiles;
namespace sdl2{ class RendererWindow; }

class VignettesTextures
{
private:
	TexturesFilesList loadedTextures;
	ConstAnimDraw sprites;

public:
	explicit VignettesTextures(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const fs::path& listFile);
	~VignettesTextures() = default;
	VignettesTextures( const VignettesTextures& ) = delete;
	VignettesTextures& operator= ( const VignettesTextures& ) = delete;
	VignettesTextures( VignettesTextures&& ) = default;
	VignettesTextures& operator= ( VignettesTextures&& ) = default;
	
	bool wasLoadingPerfect() const;
	
	std::size_t size() const;
	
	void drawTexture(sdl2::RendererWindow& rndWnd, int xpos, int ypos, std::size_t textureIndex);
	
};

#endif //MEMORY_CPP_TEXTURES_SHAKER_H