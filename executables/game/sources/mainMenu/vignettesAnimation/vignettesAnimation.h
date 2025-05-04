#ifndef MEMORY_CPP_MAIN_MENU_VIGNETTES_ANIMATION_H
#define MEMORY_CPP_MAIN_MENU_VIGNETTES_ANIMATION_H

#include "mainMenu/vignettesAnimation/vignetteInfos.h"
#include "time/accurateTime.h"
#include <vector>

class VignettesAnimation
{
private:
	std::vector< VignetteInfos > vignettes;
	std::size_t currentVignette;
	AccurateTimeDelay animDelay;

public:
	VignettesAnimation();
	~VignettesAnimation() = default;
	VignettesAnimation( const VignettesAnimation& ) = delete;
	VignettesAnimation& operator= ( const VignettesAnimation& ) = delete;
	VignettesAnimation( VignettesAnimation&& ) = default;
	VignettesAnimation& operator= ( VignettesAnimation&& ) = default;
	
	void update();
	int getWidth(std::size_t vignetteIndex) const;
	const Offset& getPosition(std::size_t vignetteIndex) const;
	unsigned getSide(std::size_t vignetteIndex) const;
	std::size_t size() const;
	
private:
	void createVignettesData();
	
};

#endif //MEMORY_CPP_MAIN_MENU_VIGNETTES_ANIMATION_H