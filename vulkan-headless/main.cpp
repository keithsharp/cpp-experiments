#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

#include <vulkan/vulkan.h>

std::string getVulkanVersion(uint32_t version) {
    uint32_t major = VK_API_VERSION_MAJOR(version);
    uint32_t minor = VK_API_VERSION_MINOR(version);
    uint32_t patch = VK_API_VERSION_PATCH(version);

    return std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch);
}

void printVulkanVersion() {
    std::cout << "\tGetting Vulkan version...";
    uint32_t version;
    if (vkEnumerateInstanceVersion(&version) != VK_SUCCESS) {
        std::cout << "failed." << std::endl;
        throw std::runtime_error("Could not query Vulkan version.");
    } else {
        std::cout << getVulkanVersion(version) << std::endl;
    }
}

VkInstance createVkInstance() {
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pNext = nullptr;
    appInfo.pApplicationName = "Vulkan Headless Test";
    appInfo.apiVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "Test Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_MAKE_VERSION(1, 0, 0);

    VkInstanceCreateInfo instanceInfo{};
    instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instanceInfo.pNext = nullptr;
    instanceInfo.flags = 0;
    instanceInfo.pApplicationInfo = &appInfo;
    instanceInfo.ppEnabledExtensionNames = nullptr;
    instanceInfo.enabledExtensionCount = 0;
    instanceInfo.ppEnabledLayerNames = nullptr;

    VkInstance instance{};
    std::cout << "\tCreating VkInstance...";
    if (vkCreateInstance(&instanceInfo, nullptr, &instance) != VK_SUCCESS) {
        std::cout << " failed." << std::endl;
        throw std::runtime_error("Could not create VkInstance.");
    }
    std::cout << " success." << std::endl;
    return instance;
}

void printDeviceProperties(const VkPhysicalDevice &device) {
    std::cout << "\tGetting device properties:" << std::endl;
    VkPhysicalDeviceProperties properties{};
    vkGetPhysicalDeviceProperties(device, &properties);
    VkPhysicalDeviceFeatures features{};
    vkGetPhysicalDeviceFeatures(device, &features);

    std::cout << "\t\tDevice name: " << properties.deviceName << std::endl;
    std::cout << "\t\tSupported Vulkan version: " << getVulkanVersion(properties.apiVersion) << std::endl;
    std::cout << "\t\tSupports Tesselation shader: " << (features.tessellationShader == VK_TRUE ? "true" : "false") << std::endl;
    std::cout << "\t\tSupports Geometry shader: " << (features.geometryShader == VK_TRUE ? "true" : "false") << std::endl;

    VkPhysicalDeviceMemoryProperties memoryProperties{};
    vkGetPhysicalDeviceMemoryProperties(device, &memoryProperties);
    for (auto heap : memoryProperties.memoryHeaps) {
        if (heap.flags & VK_MEMORY_HEAP_DEVICE_LOCAL_BIT) {
            std::cout << "\t\tDevice local memory: " << heap.size << std::endl;
        }
    }
}

void queryVkPhysicalDevice(const VkInstance &instance) {
    std::cout << "\tNumber of physical devices... ";
    uint32_t deviceCount = 0;
    if (vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr) != VK_SUCCESS) {
        std::cout << " failed to find any Vulkan enabled devices." << std::endl;
        throw std::runtime_error("Failed to find any Vulkan enabled physical devices.");
    }
    std::cout << deviceCount << std::endl;

    std::vector<VkPhysicalDevice> physicalDevices(deviceCount);
    if (vkEnumeratePhysicalDevices(instance, &deviceCount, physicalDevices.data()) != VK_SUCCESS) {
        std::cout << " failed to find any Vulkan enabled devices." << std::endl;
        throw std::runtime_error("Failed to find any Vulkan enabled physical devices.");
    }
    for (auto device : physicalDevices) {
        printDeviceProperties(device);
    }

}

int main(int argc, char const *argv[])
{
    std::cout << "Starting Vulkan tests:" << std::endl;

    printVulkanVersion();
    VkInstance instance = createVkInstance();
    queryVkPhysicalDevice(instance);

    std::cout << "Tests completed successfully." << std::endl;

    std::cout << "Cleaning up Vulkan resources...";
    vkDestroyInstance(instance, nullptr);
    std::cout << " done." << std::endl;

    return 0;
}

