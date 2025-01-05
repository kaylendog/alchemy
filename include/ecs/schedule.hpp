
#include "system.hpp"

namespace Alchemy {

/// @brief A class representing a schedule of systems to run.
class Schedule {
  public:
	/// @brief Constructor.
	Schedule();

	/// @brief Destructor.
	~Schedule();

	/// @brief Adds a system to the schedule.
	/// @param system The system to add.
	template <class... Args> void add_system(SystemSet, System<Args...> *system);
};

/// @brief A class representing a set of systems.
class SystemSet {
  public:
	/// @brief Constructor.
	SystemSet();

	/// @brief Destructor.
	~SystemSet();
};

} // namespace Alchemy
