#include <GLFW/glfw3.h>

#include <iostream>

int main() {
    glfwInit();
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    GLFWwindow* window = glfwCreateWindow(800, 600, 
                                          "CMake Find Library GLFW", 
                                          nullptr, nullptr);
    
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}