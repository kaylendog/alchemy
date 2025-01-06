#pragma once

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <vector>

using namespace std;

namespace Alchemy {

namespace Render {

class Mesh {
  public:
	/// @brief Constructor.
	Mesh();

	/// @brief Destructor.
	~Mesh();

	/// @brief Gets the vertices of the mesh.
	/// @return The vertices.
	uint32_t get_vertex_count() const;

	/// @brief Sets the vertices of the mesh.
	/// @param vertices The vertices.
	void set_vertices(glm::vec3 *vertices);

	/// @brief Sets the indices of the mesh.
	/// @param indices The indices.
	void set_indices(uint32_t *indices);

	/// @brief Sets the normals of the mesh.
	/// @param normals The normals.
	void set_normals(glm::vec3 *normals);

	/// @brief Sets the texture coordinates of the mesh.
	/// @param texture_coordinates The texture coordinates.
	void set_tex_coords(glm::vec2 *texture_coordinates);

  private:
	std::vector<glm::vec3> vertices;
	std::vector<uint32_t> indices;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> tex_coords;
};

} // namespace Render

} // namespace Alchemy
