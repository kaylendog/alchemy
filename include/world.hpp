#include <cstdint>
#include <mutex>

namespace Alchemy {

class World {
  public:
	/// @brief  Constructor.
	World();
	/// @brief Destructor.
	~World();

  private:
	/// @brief The entity ID counter.
	std::mutex entity_id_counter_mutex;
};

} // namespace Alchemy