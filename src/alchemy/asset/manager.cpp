#include <alchemy/asset/manager.hpp>

namespace Alchemy {

namespace Asset {

Manager::Manager() {
	this->loaders = std::vector<Loader<Asset>>();
	// register loaders
	this->loaders.push_back(JpegLoader());
	this->loaders.push_back(PngLoader());
}

} // namespace Asset

} // namespace Alchemy
