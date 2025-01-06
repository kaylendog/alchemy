#include <cstdint>
#include <iterator>

#include <alchemy/asset/asset.hpp>

namespace Alchemy {

namespace Asset {

/// @brief A 2D texture.
class Texture2D : public Asset {
  public:
	Texture2D(uint32_t width, uint32_t height, uint32_t channels);
	Texture2D(uint32_t width, uint32_t height, uint32_t channels, uint8_t *data);
	~Texture2D();

	/// @brief Get the width of the texture.
	/// @return The width.
	uint32_t get_width() const;

	/// @brief Get the height of the texture.
	/// @return The height.
	uint32_t get_height() const;

	/// @brief Get the number of channels in the texture.
	/// @return The number of channels.
	uint32_t get_channels() const;

	/// @brief Get the data in the texture.
	/// @return The data.
	uint8_t *get_raw_data() const;

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
