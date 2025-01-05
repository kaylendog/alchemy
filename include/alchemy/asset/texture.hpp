#include <alchemy/asset/asset.hpp>
#include <cstdint>

namespace Alchemy {

namespace Asset {

/// @brief A 2D texture.
class Texture2D : public Asset {
  public:
	Texture2D();
	~Texture2D();

  private:
	/// @brief The width of the texture.
	uint32_t width;

	/// @brief The height of the texture.
	uint32_t height;

	/// @brief The number of channels in the texture.
	uint32_t channels;

	/// @brief The data in the texture.
	uint8_t *data;
};

/// @brief A 3D texture.
class Texture3D : public Asset {};

class TextureAtlas : public Asset {};

} // namespace Asset

} // namespace Alchemy
