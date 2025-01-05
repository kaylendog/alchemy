#include <alchemy/render/mesh.hpp>

namespace Alchemy {

namespace Render {

Mesh::Mesh() {
	this->vertices = std::vector<glm::vec3>();
	this->indices = std::vector<uint32_t>();
	this->normals = std::vector<glm::vec3>();
	this->tex_coords = std::vector<glm::vec2>();
}

Mesh::~Mesh() {}

uint32_t Mesh::get_vertex_count() const {
	return this->vertices.size();
}

void Mesh::set_vertices(glm::vec3 *vertices) {
	this->vertices = std::vector<glm::vec3>(vertices, vertices + this->get_vertex_count());
}

} // namespace Render

} // namespace Alchemy
