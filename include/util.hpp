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

} // namespace Util

} // namespace Alchemy
