#ifndef _CONGAME_PROPERTY
#define _CONGAME_PROPERTY

namespace Congame {
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
}

#endif // !_CONGAME_PROPERTY
