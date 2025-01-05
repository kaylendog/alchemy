#include <memory>
#include <vector>

namespace Alchemy {

namespace ECS {

/// @brief A component.
class Component {};

class ComponentStore {
  public:
	/// @brief Constructor.
	ComponentStore() {}

	/// @brief Destructor.
	~ComponentStore() {}

	/// @brief Adds a component to the store.
	/// @param component The component to add.
	void add_component(std::shared_ptr<Component> component) {
		this->components.push_back(component);
	}

  private:
	std::vector<std::shared_ptr<Component>> components;
};

} // namespace ECS

} // namespace Alchemy
