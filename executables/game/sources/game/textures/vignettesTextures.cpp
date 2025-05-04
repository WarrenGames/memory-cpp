#include "game/textures/vignettesTextures.h"
#include "texturing/rendererWindow.h"
#include "logging/logsStruct.h"
#include <cassert>

VignettesTextures::VignettesTextures(AppLogFiles& logs, sdl2::RendererWindow& rndWnd, const fs::path& listFile):
	loadedTextures{ logs, rndWnd, listFile.string() },
	sprites{ loadedTextures }
{
	
}

bool VignettesTextures::wasLoadingPerfect() const
{
	return loadedTextures.wasLoadingPerfect();
}

std::size_t VignettesTextures::size() const
{
	return loadedTextures.size();
}

void VignettesTextures::drawTexture(sdl2::RendererWindow& rndWnd, int xpos, int ypos, std::size_t textureIndex)
{
	assert( textureIndex < sprites.size() );
	sprites.draw(rndWnd, xpos, ypos, textureIndex);
}
