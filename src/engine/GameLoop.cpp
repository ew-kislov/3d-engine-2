#include "GameLoop.hpp"

#include "Window.hpp"

void GameLoop::start() {
    Window::open(this->width, this->height, this->title);
    this->gameSettings.setViewport(this->width, this->height);
    for (const auto& gameObject: this->gameObjects) {
        gameObject->init();
    }

    while (this->shouldRunGame()) {
        this->handleGameInput();

        Window::prepareCurrentFrame();

        for (const auto& gameObject: this->gameObjects) {
            gameObject->update();
        }

        Window::prepareNextFrame();
    }

    Window::close();
}

bool GameLoop::shouldRunGame() {
    return Window::shouldClose();
}

void GameLoop::handleGameInput() {
    if (Window::isKeyDown(EInputKey::ESCAPE)) {
        Window::setShouldClose();
    }
}
