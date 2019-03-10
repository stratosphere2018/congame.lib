#ifndef _CONGAME_SCREEN
#define _CONGAME_SCREEN

#include <Windows.h>

namespace Congame {
	// inits the buffer size (mainly erases scroll bar)
	void SizeInit();
	//void SizeInit(int x, int y);

	// fullscreen mode
	void FullScreenMode();
	void FullScreenMode(bool fullscreen);

	// set the position of the cursor
	void SetPos(int x, int y);

	// set the cursors visibility
	void SetCursorVisible(bool visible);
}

#endif // !_CONGAME_SCREEN
