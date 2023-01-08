#include <glm/glm.hpp>

class GameSettings {
    public:
        void setViewport(int width, int height);
        void setMouseSensitivity(int mouseSensitivity);

    private:
        int width;
        int height;
        int mouseSensitivity;

        glm::mat4 projectionMatrix;
};
