#include <util/result.hpp>

namespace Alchemy {

namespace Util {

template <typename T, typename E> bool Result<T, E>::is_ok() {
	return holds_alternative<T>(*this);
}

template <typename T, typename E> bool Result<T, E>::is_err() {
	return holds_alternative<E>(*this);
}

template <typename T, typename E> T Result<T, E>::unwrap() {
	return get<T>(*this);
}

template <typename T, typename E> E Result<T, E>::unwrap_err() {
	return get<E>(*this);
}

template <typename T, typename E> T Result<T, E>::expect(string message) {
	if (is_ok()) {
		return unwrap();
	}
	else {
		throw runtime_error(message);
	}
}

template <typename T, typename E> E Result<T, E>::expect_err(string message) {
	if (is_err()) {
		return unwrap_err();
	}
	else {
		throw runtime_error(message);
	}
}

template <typename T, typename E> T Result<T, E>::unwrap_or(T default_value) {
	if (is_ok()) {
		return unwrap();
	}
	else {
		return default_value;
	}
}

template <typename T, typename E> T Result<T, E>::unwrap_or_else(function<T(E)> f) {
	if (is_ok()) {
		return unwrap();
	}
	else {
		return f(unwrap_err());
	}
}

template <typename T, typename E> E Result<T, E>::unwrap_err_or(E default_value) {
	if (is_err()) {
		return unwrap_err();
	}
	else {
		return default_value;
	}
}

template <typename T, typename E> E Result<T, E>::unwrap_err_or_else(function<E(T)> f) {
	if (is_err()) {
		return unwrap_err();
	}
	else {
		return f(unwrap());
	}
}

template <typename T, typename E> T Result<T, E>::map(function<T(E)> f) {
	if (is_ok()) {
		return f(unwrap());
	}
	else {
		return unwrap();
	}
}

template <typename T, typename E> E Result<T, E>::map_err(function<E(T)> f) {
	if (is_err()) {
		return f(unwrap_err());
	}
	else {
		return unwrap_err();
	}
}

template <typename T, typename E> T Result<T, E>::map_or(T default_value, function<T(E)> f) {
	if (is_ok()) {
		return f(unwrap());
	}
	else {
		return default_value;
	}
}

template <typename T, typename E> T Result<T, E>::map_or_else(function<T(E)> f, function<T(E)> g) {
	if (is_ok()) {
		return f(unwrap());
	}
	else {
		return g(unwrap_err());
	}
}

} // namespace Util

} // namespace Alchemy
