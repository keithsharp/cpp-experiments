#include <iostream>
#include <stdexcept>

#include <vulkan/vulkan.h>

void printVulkanVersion() {
    std::cout << "\tGetting Vulkan version...";
    uint32_t version;
    if (vkEnumerateInstanceVersion(&version) != VK_SUCCESS) {
        std::cout << "failed." << std::endl;
        throw std::runtime_error("Could not query Vulkan version.");
    } else {
        std::cout << " " << VK_API_VERSION_MAJOR(version) << "."
                         << VK_API_VERSION_MINOR(version) << "."
                         << VK_API_VERSION_PATCH(version)
                         << std::endl;
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

    VkInstance instance;
    std::cout << "\tCreating VkInstance...";
    if (vkCreateInstance(&instanceInfo, nullptr, &instance) != VK_SUCCESS) {
        std::cout << " failed." << std::endl;
        throw std::runtime_error("Could not create VkInstance.");
    }
    std::cout << " success." << std::endl;
    return instance;
}

int main(int argc, char const *argv[])
{
    std::cout << "Starting Vulkan tests:" << std::endl;

    printVulkanVersion();
    VkInstance instance = createVkInstance();

    std::cout << "Tests completed successfully." << std::endl;

    std::cout << "Cleaning up Vulkan resources...";
    vkDestroyInstance(instance, nullptr);
    std::cout << " done." << std::endl;

    return 0;
}

