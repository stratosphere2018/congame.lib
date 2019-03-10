#pragma once
#ifndef _CONGAME_VECTOR2
#define _CONGAME_VECTOR2

namespace Congame {

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
}

#endif // !_CONGAME_VECTOR2
