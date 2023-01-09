#include <stdexcept>

#include "Window.hpp"

GLFWwindow* Window::window = nullptr;

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void Window::open(int width, int height, std::string title) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    Window::window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

    if (Window::window == NULL) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(Window::window);
    glfwSetFramebufferSizeCallback(Window::window, framebufferSizeCallback);

    glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		throw std::runtime_error("Window: Failed to initialize GLEW");
	}  
}

void Window::prepareCurrentFrame() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::prepareNextFrame() {
    glfwSwapBuffers(Window::window);
    glfwPollEvents();
}

void Window::close() {
    glfwTerminate();
}

void Window::setShouldClose() {
    glfwSetWindowShouldClose(Window::window, true);
}

bool Window::shouldClose() {
    return glfwWindowShouldClose(Window::window);
}

bool Window::isKeyDown(EInputKey key) {
    return glfwGetKey(Window::window, key) == GLFW_PRESS;
}

bool Window::isKeyUp(EInputKey key) {
    return glfwGetKey(Window::window, key) == GLFW_RELEASE;
}

bool Window::isKeyPressed(EInputKey key) {
    return glfwGetKey(Window::window, key) == GLFW_REPEAT;
}

glm::vec2 Window::getMouseMovement() {
    return glm::vec2(1.0);
}