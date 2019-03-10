#pragma once
#ifndef _CONGAME_PROPERTY
#define _CONGAME_PROPERTY

namespace Congame {
	template<class T> struct Property {
		T& r;

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
			get = getter;
			set = setter;
		}

	private:
		T(*get)();
		T(*set)(T v);

		T DefaultGetter() {
			return r;
		}
		T DefaultSetter(T val) {
			return val;
		}
	};
	template<class T> struct ReadOnly {
		T& r;

		operator T() {
			return get();
		}

		ReadOnly(T(*func)()) {
			*get = *func;
		}

	private:
		T(*get)();
	};
}

#endif // !_CONGAME_PROPERTY
