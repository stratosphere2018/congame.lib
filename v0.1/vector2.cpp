#include "vector2.h"

#include <math.h>

namespace Congame {
	float Point2::Distance(Point2 p, Vector2 vector) {
		Vector2 diff;
		diff.X = X - p.X;
		diff.Y = Y - p.Y;
		return fabsf(vector | diff)*diff.magnitude;
	}

	Vector2::_magnitude::operator float() {
		return sqrtf(powf(r.X, 2.0f) + powf(r.Y, 2.0f));
	}
	Vector2::_normalized::operator Vector2() {
		return r % 1;
	}

	Vector2::operator float() {
		return (float)magnitude;
	}
	Vector2 Vector2::operator =(Vector2 vector) {
		X = vector.X;
		Y = vector.Y;
		return *this;
	}
	Vector2 Vector2::operator +(Vector2 vector) {
		Vector2 rtn;
		rtn.X = X + vector.X;
		rtn.Y = Y + vector.Y;
		return rtn;
	}
	Vector2 Vector2::operator +=(Vector2 vector) {
		return (*this = *this + vector);
	}
	Vector2 Vector2::operator -(Vector2 vector) {
		Vector2 rtn;
		rtn.X = X - vector.X;
		rtn.Y = Y - vector.Y;
		return rtn;
	}
	Vector2 Vector2::operator -=(Vector2 vector) {
		return (*this = *this - vector);
	}
	Vector2 Vector2::operator *(float val) {
		Vector2 rtn;
		rtn.X = X * val;
		rtn.Y = Y * val;
		return rtn;
	}
	Vector2 Vector2::operator *=(float val) {
		return (*this = *this * val);
	}
	Vector2 Vector2::operator /(float val) {
		Vector2 rtn;
		rtn.X = X / val;
		rtn.Y = Y / val;
		return rtn;
	}
	Vector2 Vector2::operator /=(float val) {
		return (*this = *this / val);
	}
	Vector2 Vector2::operator %(float val) {
		return (Vector2)normalized * val;
	}
	Vector2 Vector2::operator %=(int val) {
		return (*this = *this % val);
	}
	float Vector2::operator &(Vector2 vector) {
		return X * vector.X + Y * vector.Y;
	}
	float Vector2::operator |(Vector2 vector) {
		return X * vector.Y - Y * vector.X;
	}
	float Vector2::operator *(Vector2 vector) {
		return (*this & vector) / (magnitude * vector.magnitude);
	}
	bool Vector2::operator <(Vector2 vector) {
		return magnitude < vector.magnitude;
	}
	bool Vector2::operator >(Vector2 vector) {
		return magnitude > vector.magnitude;
	}
	bool Vector2::operator <=(Vector2 vector) {
		return magnitude <= vector.magnitude;
	}
	bool Vector2::operator >=(Vector2 vector) {
		return magnitude >= vector.magnitude;
	}
	bool Vector2::operator ==(Vector2 vector) {
		return X == vector.X && Y == vector.Y;
	}

	Vector2 Vector2::Normalize() {
		return (*this %= 1);
	}
	float Vector2::Angle(Vector2 vector) {
		return acos(*this * vector);
	}
}