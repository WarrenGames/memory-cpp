#ifndef MEMORY_CPP_INPUTS_H
#define MEMORY_CPP_INPUTS_H

#include "customTypes/positionTypes.h"
#include "SDL_keycode.h"
#include "SDL_events.h"
#include <vector>

struct KeyEvent
{
	SDL_Keycode keycode;
	bool isPushed;
	
	explicit KeyEvent(SDL_Keycode keycodeParam);
	~KeyEvent() = default;
	KeyEvent( const KeyEvent& ) = default;
	KeyEvent& operator= ( const KeyEvent& ) = default;
	KeyEvent( KeyEvent&& ) = default;
	KeyEvent& operator= ( KeyEvent&& ) = default;
};

struct MouseEvents
{
	Offset mousePosition;
	bool leftButtonState;
	bool rightButtonState;
	
	MouseEvents();
	~MouseEvents() = default;
	MouseEvents( const MouseEvents& ) = default;
	MouseEvents& operator= ( const MouseEvents& ) = default;
	MouseEvents( MouseEvents&& ) = default;
	MouseEvents& operator= ( MouseEvents&& ) = default;
};

class UserInputs
{
private:
	SDL_Event event;
	MouseEvents mouseEvents;
	std::vector< KeyEvent > keysEvents;
	bool sdlQuit;
	
public:
	explicit UserInputs(const std::vector< SDL_Keycode >& neededKeys);
	~UserInputs() = default;
	UserInputs( const UserInputs& ) = default;
	UserInputs& operator= ( const UserInputs& ) = default;
	UserInputs( UserInputs&& ) = default;
	UserInputs& operator= ( UserInputs&& ) = default;
	
	void updateEvents();
	
	const Offset& getMousePosition() const;
	bool getMouseLeftButton() const;
	bool getMouseRightButton() const;
	bool getKeycodeState(SDL_Keycode keycode) const;
	bool getSdlQuit() const;
	void setMouseLeftButtonToFalse();
	void setMouseRightButtonToFalse();
	void setKeycodeStateToFalse(SDL_Keycode keycode);
	
private:
	void loadKeycodes(const std::vector< SDL_Keycode >& neededKeys);
	void actWithMouseMotion(int xPos, int yPos);
	void actWithKeycodeEvent(SDL_Keycode keycode, bool valueToSet);
	void actWithMouseButton(unsigned buttonNumber, bool valueToSet);
};

#endif //MEMORY_CPP_INPUTS_H