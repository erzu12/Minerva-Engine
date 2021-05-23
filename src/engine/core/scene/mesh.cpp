#include "mesh.h"

#include <iostream>
#include <fstream>

VkVertexInputBindingDescription Vertex::getBindingDescription() {
	VkVertexInputBindingDescription bindingDescription{};
	bindingDescription.binding = 0;
	bindingDescription.stride = sizeof(Vertex);
	bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

	return bindingDescription;
}

std::array<VkVertexInputAttributeDescription, 4> Vertex::getAttributeDescriptions() {
	std::array<VkVertexInputAttributeDescription, 4> attributeDescriptions{};

	attributeDescriptions[0].binding = 0;
	attributeDescriptions[0].location = 0;
	attributeDescriptions[0].format = VK_FORMAT_R32G32B32_SFLOAT;
	attributeDescriptions[0].offset = offsetof(Vertex, pos);

	attributeDescriptions[1].binding = 0;
	attributeDescriptions[1].location = 1;
	attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
	attributeDescriptions[1].offset = offsetof(Vertex, color);

	attributeDescriptions[2].binding = 0;
	attributeDescriptions[2].location = 2;
	attributeDescriptions[2].format = VK_FORMAT_R32G32_SFLOAT;
	attributeDescriptions[2].offset = offsetof(Vertex, texCoord);

	attributeDescriptions[3].binding = 0;
	attributeDescriptions[3].location = 3;
	attributeDescriptions[3].format = VK_FORMAT_R32G32B32_SFLOAT;
	attributeDescriptions[3].offset = offsetof(Vertex, normal);

	return attributeDescriptions;
}

void Mesh::Write(std::ofstream& file) {
	int namelength = name.length();
	int vertlength = vertices.size();
	int indlenght = indices.size();

	file.write((char*)&moduleIndex, sizeof(int));

	file.write((char*)&namelength, sizeof(int));
	file.write(name.data(), name.length() * sizeof(char));

	file.write((char*)&vertlength, sizeof(int));
	file.write((char*)vertices.data(), vertlength * sizeof(Vertex));

	std::cout << file.tellp() << std::endl;
	file.write((char*)&indlenght, sizeof(int));
	file.write((char*)indices.data(), indlenght * sizeof(uint32_t));
}

void Mesh::Read(std::ifstream& file) {
	int namelength;
	int vertlength;
	int indlength;

	file.read((char*)&namelength, sizeof(int));
	name.resize(namelength);
	file.read(name.data(), namelength * sizeof(char));

	file.read((char*)&vertlength, sizeof(int));
	vertices.resize(vertlength);
	file.read((char*)vertices.data(), vertlength * sizeof(Vertex));

	std::cout << file.tellg() << std::endl;
	file.read((char*)&indlength, sizeof(int));
	indices.resize(indlength);
	file.read((char*)indices.data(), indlength * sizeof(uint32_t));
}
