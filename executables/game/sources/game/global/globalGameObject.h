#ifndef MEMORY_CPP_GLOBAL_GAME_OBJECT_H
#define MEMORY_CPP_GLOBAL_GAME_OBJECT_H

#include "game/textures/gameTextures.h"
#include "game/numeric/numericData.h"

struct Essentials;
namespace sdl2{ class RendererWindow; }
struct GameOptions;

class GlobalGameObject
{
private:
	TexturesPackage texturesPackage;
	NumericData numericData;

public:
	explicit GlobalGameObject(Essentials& essentials, const GameOptions& gameOptions);
	~GlobalGameObject() = default;
	GlobalGameObject( const GlobalGameObject& ) = delete;
	GlobalGameObject& operator= ( const GlobalGameObject& ) = delete;
	GlobalGameObject( GlobalGameObject&& ) = default;
	GlobalGameObject& operator= ( GlobalGameObject&& ) = default;
	
	operator bool() const;
	
	void update(Essentials& essentials);
	void drawEverything(sdl2::RendererWindow& rndWnd);
	void drawCardsPickingText(sdl2::RendererWindow& rndWnd) const;
	bool isGameFinished() const;

private:
	void updateCardsPickNumber(Essentials& essentials);
	
	void drawCards(sdl2::RendererWindow& rndWnd);
	void drawSingleCard(sdl2::RendererWindow& rndWnd, const CardInfos& cardInfos, int width, int height);
	void drawComment(sdl2::RendererWindow& rndWnd) const;
	
	bool areCoordsOneOfTheSelectedCards(int width, int height, std::size_t selectedCardIndex) const;
	void drawHintsToTurnBackRevealedCards(sdl2::RendererWindow& rndWnd) const;
};

#endif //MEMORY_CPP_GLOBAL_GAME_OBJECT_H