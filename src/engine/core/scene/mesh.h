#pragma once
#include <vulkan/vulkan.h>
#include <glm/glm.hpp>
#include <vector>
#include <array>


struct Vertex2 {
	glm::vec3 pos;
	glm::vec3 color;
	glm::vec2 texCoord;
	glm::vec3 normal;

	static VkVertexInputBindingDescription getBindingDescription();

	static std::array<VkVertexInputAttributeDescription, 4> getAttributeDescriptions();

	bool operator==(const Vertex2& other) const {
		return pos == other.pos && color == other.color && texCoord == other.texCoord;
	}
};

struct Mesh {
public:
    std::vector<Vertex2> vertices;
	std::vector<uint32_t> indices;
};