#include "Scenes/StandardScene.hpp"
#include "SceneManager.hpp"

StandardScene::StandardScene() {
    INIReader reader("Config.ini");
    this->screen_width = reader.GetInteger("Window", "width", 800);
    this->screen_height = reader.GetInteger("Window", "height", 600);
    
    this->window = Setup::complete_setup("LearnOpenGL", screen_width, screen_height);
}

void StandardScene::load() {
    // Load menu assets
}

void StandardScene::update() {
    // input
    Callbacks::processInput(this->window);
}

void StandardScene::render() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}

int StandardScene::clean() {
    glfwTerminate();
    return 0;
}

GLFWwindow* StandardScene::getWindow() {
    return this->window;
}

// Register this scene to the scene manager
namespace {
    bool isRegistered = []() {
        SceneManager::getInstance().registerScene("StandardScene", []() -> std::shared_ptr<Scene> {
            return std::make_shared<StandardScene>();
        });
        return true;
    }();
}
