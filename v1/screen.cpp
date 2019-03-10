#include "Package\build\native\include\congame.h"

namespace Congame {
#define OUTPUT_HANDLE GetStdHandle(STD_OUTPUT_HANDLE)
	void SizeInit() {
		COORD size;
		SetConsoleDisplayMode(OUTPUT_HANDLE, CONSOLE_WINDOWED_MODE, &size);
		SetConsoleScreenBufferSize(OUTPUT_HANDLE, size);
	}
	void SizeInit(int x, int y) {
		SMALL_RECT winRect = { 0,0,(SHORT)x - 1,(SHORT)y - 1 };
		COORD size = { (SHORT)x,(SHORT)y };

		SetConsoleScreenBufferSize(OUTPUT_HANDLE, size);
		SetConsoleWindowInfo(OUTPUT_HANDLE, TRUE, &winRect);
	}


	void FullScreenMode() {
		FullScreenMode(true);
	}
	void FullScreenMode(bool fullscreen) {
		if (fullscreen) {
			COORD size;
			SetConsoleDisplayMode(OUTPUT_HANDLE, CONSOLE_FULLSCREEN_MODE, &size);
			SetConsoleScreenBufferSize(OUTPUT_HANDLE, size);
		}
		else {
			SizeInit();
		}
	}

	void SetPos(int x, int y) {
		COORD pos;
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(OUTPUT_HANDLE, &info);
		if (0 < x && x < info.dwSize.X)	pos.X = x;
		else if (x < 0)					pos.X = 0;
		else							pos.X = info.dwSize.X - 1;

		if (0 < y && y < info.dwSize.Y)	pos.Y = y;
		else if (y < 0)					pos.Y = 0;
		else							pos.Y = info.dwSize.Y - 1;

		SetConsoleCursorPosition(OUTPUT_HANDLE, pos);
	}

	void SetCursorVisible(bool visible) {
		CONSOLE_CURSOR_INFO cci;
		GetConsoleCursorInfo(OUTPUT_HANDLE, &cci);
		cci.bVisible = visible;
		SetConsoleCursorInfo(OUTPUT_HANDLE, &cci);
	}
}