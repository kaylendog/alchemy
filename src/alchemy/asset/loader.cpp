
#include <alchemy/asset/loader.hpp>

namespace Alchemy {

namespace Asset {

bool JpegLoader::is_loadable(std::string path) {
	return path.size() >= 4 && (path.substr(path.size() - 4) == ".jpg" || path.substr(path.size() - 5) == ".jpeg");
}

bool PngLoader::is_loadable(std::string path) {
	return path.size() >= 4 && path.substr(path.size() - 4) == ".png";
}

} // namespace Asset

} // namespace Alchemy
