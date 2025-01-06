
#include <alchemy/ecs/system.hpp>

namespace Alchemy {

namespace ECS {

/// @brief A node in the schedule.
class ScheduleNode {
  public:
	ScheduleNode();
	~ScheduleNode();

  private:
	std::vector<ScheduleNode *> after;
};

/// @brief A schedule is an acyclic directed graph of systems encoding the constraints between systems.
class Schedule {
  public:
	Schedule();
	~Schedule();

  private:
	/// @brief The nodes in the schedule.
	std::vector<ScheduleNode> nodes;

	/// @brief The root node of the schedule.
	ScheduleNode *root;
};

} // namespace ECS

} // namespace Alchemy
