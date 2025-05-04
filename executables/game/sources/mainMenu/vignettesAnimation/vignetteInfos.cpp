#include "mainMenu/vignettesAnimation/vignetteInfos.h"
#include "time/accurateTime.h"
#include "mainMenu/mainMenuConsts.h"
#include "consts/globalConsts.h"

VignetteInfos::VignetteInfos(const Offset& pos):
	position{ pos },
	phase{ VignettePhaseShowReal },
	side{ VignetteSideRecto },
	width{ SquareSize }
{
	
}

int VignetteInfos::getWidth() const
{
	return width;
}

const Offset& VignetteInfos::getPosition() const
{
	return position;
}

unsigned VignetteInfos::getSide() const
{
	return side;
}

void VignetteInfos::update(AccurateTimeDelay& animDelay, std::size_t& currentVignette, std::size_t size)
{
	switch( phase )
	{
		case VignettePhaseShowReal:
			phase = VignettePhaseHide;
			break;
		case VignettePhaseHide:
			hideCurrentVignette(animDelay, currentVignette, size);
			break;
		case VignettePhaseShowHidden:
			phase = VignettePhaseReveal;
			break;
		case VignettePhaseReveal:
			showCurrentVignette(animDelay, currentVignette, size);
			break;
	}
}

void VignetteInfos::hideCurrentVignette(AccurateTimeDelay& animDelay, std::size_t& currentVignette, std::size_t size)
{
	if( animDelay.hasTimeElapsed( std::chrono::milliseconds{ VignettesAnimationDelay } ) )
	{
		animDelay.joinTimePoints();
		if( side == VignetteSideRecto )
		{
			width--;
			changeSideToVersoIfAny();
		}
		else if( side == VignetteSideVerso )
		{
			width++;
			updateIfHidingFinished(currentVignette, size);
		}
	}
}

void VignetteInfos::changeSideToVersoIfAny()
{
	if( width == 0 && side == VignetteSideRecto )
	{
		side = VignetteSideVerso;
	}
}

void VignetteInfos::changeSideToRectoIfAny()
{
	if( width == 0 && side == VignetteSideVerso )
	{
		side = VignetteSideRecto;
	}
}

void VignetteInfos::updateIfRevealFinished(std::size_t& currentVignette, std::size_t size)
{
	if( phase == VignettePhaseReveal && width == SquareSize && side == VignetteSideRecto )
	{
		phase = VignettePhaseShowReal;
		gotoNextVignette(currentVignette, size);
	}
}

void VignetteInfos::updateIfHidingFinished(std::size_t& currentVignette, std::size_t size)
{
	if( phase == VignettePhaseHide && width == SquareSize && side == VignetteSideVerso )
	{
		phase = VignettePhaseShowHidden;
		gotoNextVignette(currentVignette, size);
	}
}

void VignetteInfos::showCurrentVignette(AccurateTimeDelay& animDelay, std::size_t& currentVignette, std::size_t size)
{
	if( animDelay.hasTimeElapsed( std::chrono::milliseconds{ VignettesAnimationDelay } ) )
	{
		animDelay.joinTimePoints();
		if( side == VignetteSideRecto )
		{
			width++;
			updateIfRevealFinished(currentVignette, size);
		}
		else if( side == VignetteSideVerso )
		{
			width--;
			changeSideToRectoIfAny();
		}
	}
}

void gotoNextVignette(std::size_t& currentVignette, std::size_t size)
{
	if( currentVignette + 1 < size )
	{
		currentVignette++;
	}
	else{
		currentVignette = 0;
	}
}
