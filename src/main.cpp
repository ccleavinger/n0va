//
// Created by caleb on 11/26/2023.
//

#define GLFW_INCLUDE_VULKAN
#include <GLFW3/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <fast_io.h>
#include <flecs.h>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class HelloTriangleApplication {
public:
    void run() {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }

private:
    GLFWwindow* window;

    void initWindow() {
        glfwInit();

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(WIDTH, HEIGHT, "Hello World!", nullptr, nullptr);
    }

    void initVulkan() {

    }

    void mainLoop() {
        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents();
        }
    }

    void cleanup() {
        glfwDestroyWindow(window);

        glfwTerminate();
    }
};

void entityGreet(flecs::entity& e) {
    std::string p = "My name is ";
    p += e.name();
    p += e.is_alive() ? " and I'm alive!": " and I'm dead!";
    print(p);
}


int main() {

    flecs::world world;

    auto e = world.entity("Bob");

    entityGreet(e);

    e.destruct();

    entityGreet(e);


    e.destruct();
    print(e.is_alive());

    HelloTriangleApplication app{};

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}