#include "crossLevel/inputs.h"
#include <cassert>

KeyEvent::KeyEvent(SDL_Keycode keycodeParam):
	keycode{ keycodeParam },
	isPushed{ false }
{

}

MouseEvents::MouseEvents():
	mousePosition{ 0, 0 },
	leftButtonState{ false },
	rightButtonState{ false }
{
	
}

UserInputs::UserInputs(const std::vector< SDL_Keycode >& neededKeys):
	sdlQuit{ false }
{
	loadKeycodes(neededKeys);
}

void UserInputs::updateEvents()
{
	while( SDL_PollEvent(&event) )
	{
		switch( event.type )
		{
			case SDL_QUIT:
				sdlQuit = true;
				break;
			case SDL_KEYDOWN:
				actWithKeycodeEvent( event.key.keysym.sym, true );
				break;
			case SDL_KEYUP:
				actWithKeycodeEvent( event.key.keysym.sym, false );
				break;
			case SDL_MOUSEMOTION:
				actWithMouseMotion( event.motion.x, event.motion.y );
				break;
			case SDL_MOUSEBUTTONDOWN:
				actWithMouseButton( static_cast<unsigned>(event.button.button), true );
				break;
			case SDL_MOUSEBUTTONUP:
				actWithMouseButton( static_cast<unsigned>(event.button.button), false );
				break;
		}
	}
}

const Offset& UserInputs::getMousePosition() const
{
	return mouseEvents.mousePosition;
}

bool UserInputs::getMouseLeftButton() const
{
	return mouseEvents.leftButtonState;
}

bool UserInputs::getMouseRightButton() const
{
	return mouseEvents.rightButtonState;
}

bool UserInputs::getKeycodeState(SDL_Keycode keycode) const
{
	for( auto const &data : keysEvents )
	{
		if( data.keycode == keycode )
		{
			return data.isPushed;
		}
	}
	assert( false && "Error: bad keycode value !" );
	return false;
}

bool UserInputs::getSdlQuit() const
{
	return sdlQuit;
}

void UserInputs::setMouseLeftButtonToFalse()
{
	mouseEvents.leftButtonState = false;
}

void UserInputs::setMouseRightButtonToFalse()
{
	mouseEvents.rightButtonState = false;
}

void UserInputs::setKeycodeStateToFalse(SDL_Keycode keycode)
{
	for( auto &data : keysEvents )
	{
		if( data.keycode == keycode )
		{
			data.isPushed = false;
		}
	}
}

void UserInputs::loadKeycodes(const std::vector< SDL_Keycode >& neededKeys)
{
	for( auto const &data : neededKeys )
	{
		keysEvents.emplace_back( KeyEvent{ data } );
	}
}

void UserInputs::actWithMouseMotion(int xPos, int yPos)
{
	mouseEvents.mousePosition.x = xPos;
	mouseEvents.mousePosition.y = yPos;
}

void UserInputs::actWithKeycodeEvent(SDL_Keycode keycode, bool valueToSet)
{
	for( auto &data : keysEvents )
	{
		if( keycode == data.keycode )
		{
			data.isPushed = valueToSet;
		}
	}
}

void UserInputs::actWithMouseButton(unsigned buttonNumber, bool valueToSet)
{
	switch( buttonNumber )
	{
		case SDL_BUTTON_LEFT:
			mouseEvents.leftButtonState = valueToSet;
			break;
		case SDL_BUTTON_RIGHT:
			mouseEvents.rightButtonState = valueToSet;
			break;
	}
}