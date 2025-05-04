#ifndef MEMORY_CPP_TEXTURES_PACKAGE_H
#define MEMORY_CPP_TEXTURES_PACKAGE_H

#include "game/textures/vignettesTextures.h"
#include "texturing/texturesCombo.h"
#include "game/textures/commentsTexts.h"
#include "game/textures/cardsPickingTexts.h"
#include "fileSystem/fileSystem.h"

struct Essentials;

struct TexturesPackage
{
	fs::path themeDirectory;
	VignettesTextures vignettesTextures;
	TextureCombo cardsBackTexture;
	CommentsTexts commentsTexts;
	CardsPickingText cardsPickingText;
	
	explicit TexturesPackage(Essentials& essentials, const fs::path& specificThemeDirectory);
	~TexturesPackage() = default;
	TexturesPackage( const TexturesPackage& ) = default;
	TexturesPackage& operator= ( const TexturesPackage& ) = default;
	TexturesPackage( TexturesPackage&& ) = default;
	TexturesPackage& operator= ( TexturesPackage&& ) = default;
	
	bool wasLoadingPerfect() const;
	
	fs::path fetchCardBackTexture(Essentials& essentials, const fs::path& cardBackConfigFile) const;
};

#endif //MEMORY_CPP_TEXTURES_PACKAGE_H