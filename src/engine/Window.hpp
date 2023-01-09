#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>

enum EInputKey {
    ESCAPE = GLFW_KEY_ESCAPE
};

class Window {
    public:
        static void open(int width, int height, std::string title);
        static void prepareCurrentFrame();
        static void prepareNextFrame();
        static void close();

        static void setShouldClose();
        static bool shouldClose();

        static bool isKeyDown(EInputKey key);
        static bool isKeyUp(EInputKey key);
        static bool isKeyPressed(EInputKey key);

        static glm::vec2 getMouseMovement();

    private:
        static GLFWwindow* window;
};
