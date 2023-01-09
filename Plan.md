# Igra

Window
    static open(width, height);
    static close();


IGameObject
    private:
        vao, vbo, Shaders
        ~IGameObject() {
            // clear buffers
        }

    public:
        abstract init(), draw()


Input
    isKeyDown(key): bool;
    getMouseMovement(): ...;


Camera
    private:
        static viewMatrix;
        static changeView(deltaVector) {
            // set uniforms
        }

    public:
        static update() {
            мониторим мышь и wasd
            получаем по ним deltaVector 
            this->changeView(deltaVector)
        }


GameSettings
    private:
        static mouseSensitivity;
        static projectionMatrix;

    public:
        static setViewport(width, height);


Game
    private:
        gameObjects: IGameObject[];

        updateCamera();

    public:
        start() {
            const width = 1;
            const height = 1;

            Window::open(width, height);
            GameSettings::setViewport(width, height);

            gameObjects.forEach(g => g.init());

            while (!Input.isKeyDown('escape')) {
                Window::update();

                Camera::update();
                
                gameObjects.forEach(g => g.draw());

                Window::prepareForNextFrame();

            }

            Window::close();
        }

------------------

Sun implements IGameObject
