#pragma once
#include <vulkan/vulkan.h>
#include <glm/glm.hpp>
#include <vector>
#include <array>

#include "config.h"
#include "module.h"

struct Vertex {
	glm::vec3 pos;
	glm::vec3 color;
	glm::vec2 texCoord;
	glm::vec3 normal;

	static VkVertexInputBindingDescription getBindingDescription();

	static std::array<VkVertexInputAttributeDescription, 4> getAttributeDescriptions();

	bool operator==(const Vertex& other) const {
		return pos == other.pos && color == other.color && texCoord == other.texCoord;
	}
};


class Mesh : public Module {
private:
	int moduleIndex = 0;
public:
	glm::vec3 pos;

    std::vector<Vertex> vertices;
	std::vector<uint32_t> indices;

	int GetModuleIndex() override;

	void Write(std::ofstream& file) override;
	void Read(std::ifstream& file) override;
};