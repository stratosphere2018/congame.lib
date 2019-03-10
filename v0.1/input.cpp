#include "Package\build\native\include\congame.h"

#include <stdio.h>

namespace Congame {
	static KEY_STATE keyState[256] = {
		KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,
		KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,
		KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,
		KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,
		KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,
		KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,
		KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,
		KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,
		KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,
		KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,
		KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,
		KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,
		KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,
		KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,
		KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,
		KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone,KeyNone
	};

	KEY_STATE GetKey(KEYS keycode) {
		int code = (int)keycode;
		int state = GetAsyncKeyState(code);

		KEY_STATE rtn;
		if (HIWORD(state) && keyState[code] == KeyNone) {
			keyState[code] = KeyDown;
			rtn = KeyPress;
		}
		else if (HIWORD(state)) {
			keyState[code] = KeyDown;
			rtn = KeyDown;
		}
		else if (keyState[code] == KeyDown) {
			keyState[code] = KeyNone;
			rtn = KeyUp;
		}
		else {
			keyState[code] = KeyNone;
			rtn = KeyNone;
		}
		fflush(stdin);
		return rtn;
	}

	Axis GetAxis() {
		Axis rtn;
		rtn.Up = GetKey(Up);
		rtn.Down = GetKey(Down);
		rtn.Left = GetKey(Left);
		rtn.Right = GetKey(Right);
		if (rtn.Up == KeyPress || rtn.Up == KeyDown) {
			rtn.Y--;
		}if (rtn.Down == KeyPress || rtn.Down == KeyDown) {
			rtn.Y++;
		}if (rtn.Left == KeyPress || rtn.Left == KeyDown) {
			rtn.X--;
		}if (rtn.Right == KeyPress || rtn.Right == KeyDown) {
			rtn.X++;
		}
		return rtn;
	}

	char GetLetterA() {
		if (GetKey(A) == KeyPress) return 'A';
		if (GetKey(B) == KeyPress) return 'B';
		if (GetKey(C) == KeyPress) return 'C';
		if (GetKey(D) == KeyPress) return 'D';
		if (GetKey(E) == KeyPress) return 'E';
		if (GetKey(F) == KeyPress) return 'F';
		if (GetKey(G) == KeyPress) return 'G';
		if (GetKey(H) == KeyPress) return 'H';
		if (GetKey(I) == KeyPress) return 'I';
		if (GetKey(J) == KeyPress) return 'J';
		if (GetKey(K) == KeyPress) return 'K';
		if (GetKey(L) == KeyPress) return 'L';
		if (GetKey(M) == KeyPress) return 'M';
		if (GetKey(N) == KeyPress) return 'N';
		if (GetKey(O) == KeyPress) return 'O';
		if (GetKey(P) == KeyPress) return 'P';
		if (GetKey(Q) == KeyPress) return 'Q';
		if (GetKey(R) == KeyPress) return 'R';
		if (GetKey(S) == KeyPress) return 'S';
		if (GetKey(T) == KeyPress) return 'T';
		if (GetKey(U) == KeyPress) return 'U';
		if (GetKey(V) == KeyPress) return 'V';
		if (GetKey(W) == KeyPress) return 'W';
		if (GetKey(X) == KeyPress) return 'X';
		if (GetKey(Y) == KeyPress) return 'Y';
		if (GetKey(Z) == KeyPress) return 'Z';
		if (GetKey(D0) == KeyPress) return '0';
		if (GetKey(D1) == KeyPress) return '1';
		if (GetKey(D2) == KeyPress) return '2';
		if (GetKey(D3) == KeyPress) return '3';
		if (GetKey(D4) == KeyPress) return '4';
		if (GetKey(D5) == KeyPress) return '5';
		if (GetKey(D6) == KeyPress) return '6';
		if (GetKey(D7) == KeyPress) return '7';
		if (GetKey(D8) == KeyPress) return '8';
		if (GetKey(D9) == KeyPress) return '9';
		return '\0';
	}

	wchar_t GetLetterW() {
		if (GetKey(A) == KeyPress) return L'A';
		if (GetKey(B) == KeyPress) return L'B';
		if (GetKey(C) == KeyPress) return L'C';
		if (GetKey(D) == KeyPress) return L'D';
		if (GetKey(E) == KeyPress) return L'E';
		if (GetKey(F) == KeyPress) return L'F';
		if (GetKey(G) == KeyPress) return L'G';
		if (GetKey(H) == KeyPress) return L'H';
		if (GetKey(I) == KeyPress) return L'I';
		if (GetKey(J) == KeyPress) return L'J';
		if (GetKey(K) == KeyPress) return L'K';
		if (GetKey(L) == KeyPress) return L'L';
		if (GetKey(M) == KeyPress) return L'M';
		if (GetKey(N) == KeyPress) return L'N';
		if (GetKey(O) == KeyPress) return L'O';
		if (GetKey(P) == KeyPress) return L'P';
		if (GetKey(Q) == KeyPress) return L'Q';
		if (GetKey(R) == KeyPress) return L'R';
		if (GetKey(S) == KeyPress) return L'S';
		if (GetKey(T) == KeyPress) return L'T';
		if (GetKey(U) == KeyPress) return L'U';
		if (GetKey(V) == KeyPress) return L'V';
		if (GetKey(W) == KeyPress) return L'W';
		if (GetKey(X) == KeyPress) return L'X';
		if (GetKey(Y) == KeyPress) return L'Y';
		if (GetKey(Z) == KeyPress) return L'Z';
		if (GetKey(D0) == KeyPress) return L'0';
		if (GetKey(D1) == KeyPress) return L'1';
		if (GetKey(D2) == KeyPress) return L'2';
		if (GetKey(D3) == KeyPress) return L'3';
		if (GetKey(D4) == KeyPress) return L'4';
		if (GetKey(D5) == KeyPress) return L'5';
		if (GetKey(D6) == KeyPress) return L'6';
		if (GetKey(D7) == KeyPress) return L'7';
		if (GetKey(D8) == KeyPress) return L'8';
		if (GetKey(D9) == KeyPress) return L'9';
		return L'\0';
	}
}