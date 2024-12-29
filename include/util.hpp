#include <mutex>
#include <optional>
#include <variant>

using namespace std;

namespace Alchemy {

namespace Util {

/// @brief A class representing a result that can be either an ok value or an error.
/// @tparam T The type of the ok value.
/// @tparam E The type of the error.
template <typename T, typename E> class Result : public variant<T, E> {

  public:
	/// @brief  Constructor for the ok variant.
	/// @param value The value to store in the ok variant.
	Result(T value) : variant<T, E>(value) {}

	/// @brief Constructor for the error variant.
	/// @param error  The error to store in the error variant.
	Result(E error) : variant<T, E>(error) {}

	/// @brief Returns true if the result is ok.
	/// @return
	bool is_ok();

	/// @brief Returns true if the result is an error.
	/// @return True if the result is an error.
	bool is_err();

	/// @brief Unwraps the result, or throws an exception if the result is an error.
	/// @return The ok value.
	T unwrap();

	/// @brief Unwraps the result, or throws an exception if the result is an ok value.
	/// @return The error.
	E unwrap_err();

	/// @brief Unwraps the result, or throws an exception with the given message if the result is an error.
	/// @param message The message to include in the exception.
	/// @return
	T expect(string message);

	/// @brief Unwraps the result, or throws an exception with the given message if the result is an ok value.
	/// @param message The message to include in the exception.
	/// @return The error.
	E expect_err(string message);

	/// @brief Unwraps the result, or returns the default value if the result is an error.
	/// @param default_value  The value to return if the result is an error.
	/// @return The ok value or the default value.
	T unwrap_or(T default_value);

	/// @brief Unwraps the result, or returns the result of the given function if the result is an error.
	/// @param f The function to call if the result is an error.
	/// @return The ok value or the result of the function.
	T unwrap_or_else(function<T(E)> f);

	/// @brief Maps the ok value to a new value using the given function.
	/// @param default_value The value to return if the result is an error.
	/// @return The new value.
	E unwrap_err_or(E default_value);

	/// @brief Maps the error to a new value using the given function.
	/// @param f The function to call if the result is an error.
	/// @return The new value.
	E unwrap_err_or_else(function<E(T)> f);

	/// @brief Maps the ok value to a new value using the given function.
	/// @param f The function to call if the result is an ok value.
	/// @return The new value.
	T map(function<T(E)> f);

	/// @brief Maps the error to a new value using the given function.
	/// @param f The function to call if the result is an error.
	/// @return The new value.
	E map_err(function<E(T)> f);

	/// @brief Maps the ok value to a new value using the given function, or returns the default value if the result is
	/// an error.
	/// @param default_value The value to return if the result is an error.
	/// @param f The function to call if the result is an ok value.
	/// @return The new value.
	T map_or(T default_value, function<T(E)> f);

	/// @brief Maps the ok value to a new value using the given function, or returns the result of the given function if
	/// @param f The function to call if the result is an ok value.
	/// @param g The function to call if the result is an error.
	/// @return The new value.
	T map_or_else(function<T(E)> f, function<T(E)> g);
};

const int BTREE_DEFAULT_ORDER = 4;
const int BTREE_DEFAULT_ITEMS = BTREE_DEFAULT_ORDER - 1;

template <typename K, typename V> class BTree {
  public:
	BTree(int order = BTREE_DEFAULT_ORDER);
	~BTree();

	/// @brief Inserts a key-value pair into the BTree.
	/// @param key The key to insert.
	/// @param value The value to insert.
	void insert(K key, V value);

	/// @brief Removes a key-value pair from the BTree.
	/// @param key The key to remove.
	void remove(K key);

	/// @brief Gets the value associated with the given key.
	/// @param key The key to search for.
	/// @return The value associated with the key.
	optional<V> get(K key);

	/// @brief Gets the value associated with the given key, or returns the default value if the key is not found.
	/// @param key The key to search for.
	/// @param default_value The value to return if the key is not found.
	/// @return The value associated with the key, or the default value.
	V get_or(K key, V default_value);

	/// @brief Gets the value associated with the given key, or returns the result of the given function if the key is
	/// not found.
	/// @param key The key to search for.
	/// @param f The function to call if the key is not found.
	/// @return The value associated with the key, or the result of the function.
	V get_or_else(K key, function<V(K)> f);

  private:
	int order;
	K *keys;
	V *values;
	BTree<K, V> *children;
};

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

} // namespace Util

} // namespace Alchemy
