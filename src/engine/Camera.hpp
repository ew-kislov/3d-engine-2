#pragma once

#include <glm/glm.hpp>

class Camera {
    public:
        Camera(glm::vec3 position, glm::vec3 lookAt);

        /**
         * мониторим мышь и wasd
         * получаем по ним deltaVector 
         * this->changeView(deltaVector)
        */
        void update();

    private:
        glm::vec3 position;
        glm::vec3 lookAt;
        glm::mat4 viewMatrix;
        
        void changeView(glm::vec2 deltaVector);
};
