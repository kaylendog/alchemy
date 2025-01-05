#include <mutex>

namespace Alchemy {

namespace Async {

template <typename T> class MutexGuard;

/// A wrapper around `std::mutex` providing a mutex-protected smart pointer.
template <typename T> class Mutex {
  public:
	/// @brief Construct a new Mutex object
	/// @param value The value to protect.
	Mutex(T value);

	/// @brief Destroy the Mutex object
	~Mutex();

	/// @brief Lock the mutex.
	MutexGuard<T> lock();

  private:
	std::mutex mutex;
	T value;
};

/// @brief A smart pointer that unlocks its mutex when it goes out of scope.
/// @tparam T The type of the value.
template <typename T> class MutexGuard {
  public:
	/// @brief Construct a new Mutex Guard object
	/// @param mutex The mutex to guard.
	MutexGuard(Mutex<T> *mutex);

	/// @brief Destroy the Mutex Guard object
	~MutexGuard();

  private:
	Mutex<T> *mutex;
};

} // namespace Async

} // namespace Alchemy
