#include <mutex>
#include <util/mutex.hpp>

namespace Alchemy {

namespace Util {

using namespace std;

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
