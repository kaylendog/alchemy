#include <alchemy/asset/manager.hpp>
#include <alchemy/util/result.hpp>

using namespace Alchemy::Util;

namespace Alchemy {

namespace Asset {

Manager::Manager() {
	// register loaders
	this->loaders = std::vector<Loader>();
	this->loaders.push_back(JpegLoader());
	this->loaders.push_back(PngLoader());
}

Result<Asset, AssetLoadError> Manager::load(std::string path) {
	for (Loader loader : this->loaders) {
		if (loader.is_loadable(path)) {
			return loader.load(path);
		}
	}
	return Result<Asset, AssetLoadError>(AssetLoadError::UNSUPPORTED_FORMAT);
}

} // namespace Asset

} // namespace Alchemy
