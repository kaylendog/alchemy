
#include <alchemy/asset/texture.hpp>
#include <string>

namespace Alchemy {

namespace Asset {

template <typename T> class Loader {
  public:
	virtual ~Loader() = default;

	/// @brief Load an asset from the given path.
	/// @param path
	/// @return
	virtual T load(std::string path);

	/// @brief Check if this loader can load the given path.
	/// @param path
	/// @return
	virtual bool is_loadable(std::string path);
};

/// @brief A loader for JPEG images.
class JpegLoader : public Loader<Texture2D> {
  public:
	bool is_loadable(std::string path) override;
};

/// @brief A loader for PNG images.
class PngLoader : public Loader<Texture2D> {
  public:
	bool is_loadable(std::string path) override;
};

} // namespace Asset

} // namespace Alchemy
