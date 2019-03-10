/*
congame.h/congame.lib
コンソールゲーム開発用スタティックライブラリ

制作：Stratosphere
(https://github.com/stratosphere2018)
gitリポジトリ：https://github.com/stratosphere2018/congame.lib
バージョン：0.1.2
*/

#ifndef _CONGAME
#define _CONGAME

#include <Windows.h>

namespace Congame {

#ifdef _DEBUG
#pragma comment(lib,"../lib/v0.1_d.lib")
#else
#pragma comment(lib,"../lib/v0.1.lib")
#endif // _DEBUG

#ifndef _CONGAME_INPUT	// include guard
#define _CONGAME_INPUT

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

#endif // !_CONGAME_INPUT

#ifndef _CONGAME_PROPERTY
#define _CONGAME_PROPERTY

	// something like a property in c#
	template<class T> struct Property {
		operator T() {
			return get();
		}
		T operator =(T v) {
			r = set(v);
			return r;
		}

		Property(T(*getter)(), T(*setter)(T)) {
			constructor(getter, setter);
		}
		Property(T(*getter)()) {
			constructor(getter, DefaultSetter);
		}
		Property(T(*setter)(T)) {
			constructor(DefaultGetter, setter);
		}
		Property() {
			constructor(DefaultGetter, DefaultSetter);
		}
		void constructor(T(*getter)(), T(*setter)(T)) {
			*get = *getter;
			*set = *setter;
		}

	private:
		T& r;
		T(*get)();
		T(*set)(T v);

		T DefaultGetter() {
			return r;
		}
		T DefaultSetter(T val) {
			return val;
		}
	};

	// a readonly property
	template<class T> struct ReadOnly {
		operator T() {
			return get();
		}

		ReadOnly(T(*func)()) {
			*get = *func;
		}
		ReadOnly() {
			*get = DefaultGetter;
		}

	private:
		T& r;
		T(*get)();
		T DefaultGetter() {
			return r;
		}
	};

#endif // !_CONGAME_PROPERTY

#ifndef _CONGAME_RANDOM	// include guard
#define _CONGAME_RANDOM

	// randomize by seed
	void InitRnd(unsigned int seed);
	// randomize by msec
	void InitRnd();

	// returns random integer max to 'max'
	int RndInt(int max);
	// returns random integer from 'min' to 'max'
	int RndInt(int max, int min);

	// returns random float which 0 <= n < 1
	float RndFloat();
	// returns random double which 0 <= n < 1
	double RndDouble();

#endif // !_CONGAME_RANDOM

#ifndef _CONGAME_SCREEN
#define _CONGAME_SCREEN

#include <Windows.h>

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

#endif // !_CONGAME_SCREEN

#ifndef _CONGAME_VECTOR2
#define _CONGAME_VECTOR2

	typedef struct Vector2 {
		float X;
		float Y;
		struct _magnitude {
			Vector2& r;
			operator float();
		}magnitude{ *this };

		struct _normalized {
			Vector2& r;
			operator Vector2();
		}normalized{ *this };

		operator float();
		Vector2 operator =(Vector2 vector);
		Vector2 operator +(Vector2 vector);
		Vector2 operator +=(Vector2 vector);
		Vector2 operator -(Vector2 vector);
		Vector2 operator -=(Vector2 vector);
		Vector2 operator *(float val);
		Vector2 operator *=(float val);
		Vector2 operator /(float val);
		Vector2 operator /=(float val);
		Vector2 operator %(float val);
		Vector2 operator %=(int val);
		float operator &(Vector2 vector);
		float operator |(Vector2 vector);
		float operator *(Vector2 vector);
		bool operator <(Vector2 vector);
		bool operator >(Vector2 vector);
		bool operator <=(Vector2 vector);
		bool operator >=(Vector2 vector);
		bool operator ==(Vector2 vector);

		Vector2 Normalize();
		float Angle(Vector2 vector);
	}*pVector2;

	typedef struct Point2 {
		float X;
		float Y;

		float Distance(Point2 p, Vector2 vector);
	}*pPoint;

#endif // !_CONGAME_VECTOR2

}

#endif // !_CONGAME
