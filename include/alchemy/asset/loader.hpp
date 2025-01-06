#pragma once

#include <string>

#include <alchemy/asset/asset.hpp>
#include <alchemy/asset/texture.hpp>
#include <alchemy/util/result.hpp>

using namespace Alchemy::Util;

namespace Alchemy {

namespace Asset {

/// @brief An error that can occur when loading an asset.
enum AssetLoadError {
	/// @brief No valid loader was found for the asset.
	UNSUPPORTED_FORMAT,
};

class Loader {
  public:
	virtual ~Loader() = default;

	/// @brief Load an asset from the given path.
	/// @param path
	/// @return
	virtual Result<Asset, AssetLoadError> load(std::string path);

	/// @brief Check if this loader can load the given path.
	/// @param path
	/// @return
	virtual bool is_loadable(std::string path);
};

/// @brief A loader for JPEG images.
class JpegLoader : public Loader {
  public:
	bool is_loadable(std::string path) override;
};

/// @brief A loader for PNG images.
class PngLoader : public Loader {
  public:
	bool is_loadable(std::string path) override;
};

} // namespace Asset

} // namespace Alchemy
