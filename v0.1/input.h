#pragma once
#ifndef _CONGAME_INPUT	// include guard
#define _CONGAME_INPUT

#include <Windows.h>

namespace Congame {
	// keycode enumerator
	enum KEYS {
		None = '\0',
		A = 'A', B = 'B', C = 'C', D = 'D',
		E = 'E', F = 'F', G = 'G', H = 'H',
		I = 'I', J = 'J', K = 'K', L = 'L',
		M = 'M', N = 'N', O = 'O', P = 'P',
		Q = 'Q', R = 'R', S = 'S', T = 'T',
		U = 'U', V = 'V', W = 'W', X = 'X',
		Y = 'Y', Z = 'Z',
		D0 = '0', D1 = '1', D2 = '2', D3 = '3',
		D4 = '4', D5 = '5', D6 = '6', D7 = '7',
		D8 = '8', D9 = '9',
		T0 = VK_NUMPAD0, T1 = VK_NUMPAD1, T2 = VK_NUMPAD2, T3 = VK_NUMPAD3,
		T4 = VK_NUMPAD4, T5 = VK_NUMPAD5, T6 = VK_NUMPAD6, T7 = VK_NUMPAD7,
		T8 = VK_NUMPAD8, T9 = VK_NUMPAD9,
		Comma = ',', Period = '.', At = '@', Caret = '^',
		Colon = ':', SemiColon = ';', LBracket = '[', RBracket = ']',
		Plus = '+', Minus = '-', Asterisc = '*', Slash = '/', BackSlash = '\\',
		Space = ' ', Back = '\b', Enter = VK_RETURN, Esc = VK_ESCAPE,
		Ctrl = VK_CONTROL, LCtrl = VK_LCONTROL, RCtrl = VK_RCONTROL,
		Shift = VK_SHIFT, LShift = VK_LSHIFT, RShift = VK_RSHIFT,
		Left = VK_LEFT, Up = VK_UP, Right = VK_RIGHT, Down = VK_DOWN,
		F1 = VK_F1, F2 = VK_F2, F3 = VK_F3, F4 = VK_F4,
		F5 = VK_F5, F6 = VK_F6, F7 = VK_F7, F8 = VK_F8,
		F9 = VK_F9, F10 = VK_F10, F11 = VK_F11, F12 = VK_F12,
		KEYS_MAX = 256
	};

	// key state enumerator
	enum KEY_STATE {
		KeyNone, KeyPress, KeyDown, KeyUp,
		KEYSTATE_MAX
	};

	// axis structure
	struct Axis :COORD {
		KEY_STATE Up;
		KEY_STATE Down;
		KEY_STATE Left;
		KEY_STATE Right;

		Axis() {
			X = Y = 0;
		}
	};

	// returns the state of the key
	KEY_STATE GetKey(KEYS keycode);

	// returns input axis
	Axis GetAxis();

#define GetLetter GetLetterA
	// returns input letter char
	char GetLetterA();

	// returns input letter wide char
	wchar_t GetLetterW();
}

#endif // !_CONGAME_INPUT
