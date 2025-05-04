#ifndef MEMORY_CPP_MAIN_MENU_VIGNETTE_INFOS_H
#define MEMORY_CPP_MAIN_MENU_VIGNETTE_INFOS_H

#include "customTypes/positionTypes.h"
#include <cstdlib>

class AccurateTimeDelay;

class VignetteInfos
{
private:
	Offset position;
	unsigned phase;
	unsigned side;
	int width;

public:
	explicit VignetteInfos(const Offset& pos);
	~VignetteInfos() = default;
	VignetteInfos( const VignetteInfos& ) = default;
	VignetteInfos& operator= ( const VignetteInfos& ) = default;
	
	int getWidth() const;
	const Offset& getPosition() const;
	unsigned getSide() const;
	
	void update(AccurateTimeDelay& animDelay, std::size_t& currentVignette, std::size_t size);

private:
	void hideCurrentVignette(AccurateTimeDelay& animDelay, std::size_t& currentVignette, std::size_t size);
	void changeSideToVersoIfAny();
	void changeSideToRectoIfAny();
	void updateIfRevealFinished(std::size_t& currentVignette, std::size_t size);
	void updateIfHidingFinished(std::size_t& currentVignette, std::size_t size);
	void showCurrentVignette(AccurateTimeDelay& animDelay, std::size_t& currentVignette, std::size_t size);
};

void gotoNextVignette(std::size_t& currentVignette, std::size_t size);

#endif //MEMORY_CPP_MAIN_MENU_VIGNETTE_INFOS_H