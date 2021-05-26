#pragma once

#include <glm/glm.hpp>

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <optional>
#include <cstring>
#include <string>
#include <chrono>

#include "config.h"
#include "events/events.h"
#include "events/inputEvents.h"

#include "scene/mesh.h"
#include "scene/scene.h"

struct QueueFamilyIndices {
	std::optional<uint32_t> graphicsFamily;
	std::optional<uint32_t> presentFamily;

	bool isComplete();
};

struct SwapChainSupportDetails {
	VkSurfaceCapabilitiesKHR capabilities;
	std::vector<VkSurfaceFormatKHR> formats;
	std::vector<VkPresentModeKHR> presentModes;
};

class Vulkan {
	public:
	Vulkan();

	void initVulkan(GLFWwindow* window, Scene *scene);

	void drawFrame();

	void cleanup();


	VkDevice device;

private:
	GLFWwindow *window;

	Scene* scene;

	VkInstance instance;
	VkDebugUtilsMessengerEXT debugMessenger;
	VkSurfaceKHR surface;

	static VkPhysicalDevice physicalDevice;
	
	VkQueue graphicsQueue;
	VkQueue presentQueue;

	VkSwapchainKHR swapChain;
	std::vector<VkImage> swapChainImages;
	VkFormat swapChainImageFormat;
	VkExtent2D swapChainExtent;
	std::vector<VkImageView> swapChainImageViews;
	std::vector<VkFramebuffer> swapChainFramebuffers;

	VkRenderPass renderPass;
	VkDescriptorSetLayout descriptorSetLayout;
	VkPipelineLayout pipelineLayout;
	VkPipeline graphicsPipeline;

	VkCommandPool commandPool;
	VkDescriptorPool descriptorPool;

	std::vector<VkDescriptorSet> descriptorSets;

	std::vector<std::vector<Vertex>*> vertices;
	std::vector<std::vector<uint32_t>*> indices;
	std::vector<VkBuffer> vertexBuffers;
	std::vector<VkDeviceMemory> vertexBufferMemorys;
	std::vector<VkBuffer> indexBuffers;
	std::vector<VkDeviceMemory> indexBufferMemorys;

	std::vector<VkBuffer> uniformBuffers;
	std::vector<VkDeviceMemory> uniformBuffersMemory;

	std::vector<VkCommandBuffer> commandBuffers;

	uint32_t mipLevels;
	VkImage textureImage;
	VkImageView textureImageView;
	VkSampler textureSampler;
	VkDeviceMemory textureImageMemory;

	VkImage depthImage;
	VkDeviceMemory depthImageMemory;
	VkImageView depthImageView;

	VkImage colorImage;
	VkDeviceMemory colorImageMemory;
	VkImageView colorImageView;
	VkSampleCountFlagBits msaaSamples = VK_SAMPLE_COUNT_1_BIT;

	std::vector<VkSemaphore> imageAvailableSemaphores;
	std::vector<VkSemaphore> renderFinishedSemaphores;
	std::vector<VkFence> inFlightFences;
	std::vector<VkFence> imagesInFlight;
	size_t currentFrame = 0;

	std::vector<glm::vec3> pos;

	int meshCount;

	std::chrono::steady_clock::time_point lastrender;

	static bool framebufferResized;

	void LoadGeometry(Object *co);

	void LoadMeshes();
	
	void createInstance();

	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

	void setupDebugMessenger();

	void createSurface();

	void pickPhysicalDevice();

	bool isDeviceSuitable(VkPhysicalDevice device);

	bool checkDeviceExtensionSupport(VkPhysicalDevice device);

	void createLogicalDevice();

	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

	void createSwapChain();

	void cleanupSwapChain();

	void recreateSwapChain();

	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);

	VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);

	VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
	
	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

	VkImageView createImageView(VkImage image, VkFormat format, VkImageAspectFlags aspectFlags, uint32_t mipLevels);

	void createImageViews();

	void createTextureImageView();

	void createTextureSampler();

	void createGraphicsPipeline();

	VkShaderModule createShaderModule(const std::vector<char>& code);

	void createRenderPass();

	void createFrameBuffers();

	void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);

	void createIndexBuffer();

	void createUniformBuffers();

	void updateUniformBuffers(uint32_t currentImage);

	void createVertexBuffer();

	void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);

	VkCommandBuffer beginSingleTimeCommands();

	void endSingleTimeCommands(VkCommandBuffer commandBuffer);

	uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);

	void createCommandPool();

	void createCommandBuffers();

	void createSyncObjects();

	void createDescriptorSetLayout();

	void createDescriptorSets();

	void createDescriptorPool();

	void createTextureImage();

	void createImage(uint32_t width, uint32_t height, uint32_t mipLevels, VkSampleCountFlagBits numSamples, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory);

	void transitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout, uint32_t mipLevels);

	void copyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);

	void generateMipmaps(VkImage image, VkFormat imageFormat, int32_t texWidth, int32_t texHeight, uint32_t mipLevels);

	void createDepthResources();

	VkFormat findDepthFormat();

	bool hasStencilComponent(VkFormat format);

	VkFormat findSupportedFormat(const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features);

	void loadModel();

	VkSampleCountFlagBits getMaxUsableSampleCount();

	void createColorResources();

	std::vector<const char*> getRequiredExtensions();

	static std::vector<char> readFile(const std::string& filename);

	bool checkValidationLayerSupport();

	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
		VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		VkDebugUtilsMessageTypeFlagsEXT messageType,
		const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData);
};