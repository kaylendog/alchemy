#include <functional>

namespace Alchemy {

namespace ECS {

/// @brief  A class representing a system.
/// @tparam R The return type of the system.
/// @tparam ...Args The argument types of the system.
template <class... Args> class System : std::function<void(Args...)> {
  public:
	/// @brief Constructor.
	System() : std::function<void(Args...)>() {}

	/// @brief Destructor.
	~System() {}
};

} // namespace ECS

} // namespace Alchemy
