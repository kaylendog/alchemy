#include <map>
#include <string>

#include <alchemy/asset/asset.hpp>
#include <alchemy/asset/loader.hpp>

namespace Alchemy {

namespace Asset {

/// @brief A manager for assets.
class Manager {
  public:
	/// @brief Constructor.
	Manager();

	/// @brief Destructor.
	~Manager();

	/// @brief Loads an asset from the given path.
	/// @param path The path to the asset.
	/// @return The asset.
	Asset load(std::string path);

	/// @brief Unloads an asset.
	/// @param asset The asset to unload.
	void unload(Asset asset);

  private:
	std::map<std::string, Asset> assets;
	std::vector<Loader<Asset>> loaders;
};

} // namespace Asset

} // namespace Alchemy
