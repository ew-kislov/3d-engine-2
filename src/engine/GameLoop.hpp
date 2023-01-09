#pragma once

#include <string>
#include <set>
#include <memory>

#include "GameSettings.hpp"

class GameLoop {
    public:
        GameLoop(int width, int height, std::string title):
            width(width),
            height(height),
            title(title),
            gameSettings(GameSettings()) {};

        void start();

    private:
        int width;
        int height;
        std::string title;

        GameSettings gameSettings;

        std::set<std::shared_ptr<GameObject> > gameObjects;

        bool shouldRunGame();
        void handleGameInput();
};
