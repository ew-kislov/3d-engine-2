#include <glm/glm.hpp>

class GameSettings {
    public:
        void setViewport(int width, int height);
        void setMouseSensitivity(int mouseSensitivity);

    private:
        int width = 800;
        int height = 600;
        int mouseSensitivity = 5;

        glm::mat4 projectionMatrix;
};
