#include <iostream>
#include <spdlog/spdlog.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

int main(int argc, char const *argv[]) {
    
    spdlog::info("Multipling a glm::vec4 by a glm::mat4");
    glm::mat4 matrix;
    glm::vec4 vec;
    auto test = matrix * vec;

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    spdlog::info("Vulkan extension count: {}", extensionCount);

    spdlog::info("Creating a GLFW window with Vulkan support");
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
    spdlog::info("Exiting GLFW event loop due to window close");
    glfwDestroyWindow(window);
    glfwTerminate();

    spdlog::info("All done, exiting program");
    return 0;
}
