#include <functional>
#include <stdexcept>
#include <string>

#include <util.hpp>

using namespace std;

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

template <typename K, typename V> BTree<K, V>::BTree(int order) {
	this->order = order;
	// alloc
	this->keys = new K[order - 1];
	this->values = new V[order - 1];
	this->children = new BTree<K, V> *[order];
}

template <typename K, typename V> BTree<K, V>::~BTree() {
	// dealloc
	delete[] this->keys;
	delete[] this->values;
	delete[] this->children;
}

template <typename K, typename V> void BTree<K, V>::insert(K key, V value) {
	// for each key
	for (int i = 0; i < this->order - 1; i++) {
		if (this->keys[i] <= key) {
			this->values[i] = value;
			return;
		}
	}
}

template <typename T> Mutex<T>::Mutex(T value) {
	this->mutex = new std::mutex();
	this->value = value;
}

template <typename T> Mutex<T>::~Mutex() {
	delete this->mutex;
	delete this->value;
}

template <typename T> MutexGuard<T> Mutex<T>::lock() {
	this->mutex->lock();
	return MutexGuard(this);
}

template <typename T> MutexGuard<T>::MutexGuard(Mutex<T> *mutex) {
	this->mutex = mutex;
}

template <typename T> MutexGuard<T>::~MutexGuard() {
	this->mutex->mutex->unlock();
}

} // namespace Util

} // namespace Alchemy
