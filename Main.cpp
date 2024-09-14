#include <iostream>
#include <memory>
#include "SceneManager.hpp"
#include "Scenes/StandardScene.hpp"

int main() {
    SceneManager& sceneManager = SceneManager::getInstance();

    // Register scenes
    sceneManager.registerScene("StandardScene", []() { return std::make_shared<StandardScene>(); });
    // sceneManager.registerScene("GameScene", []() { return std::make_shared<GameScene>(); });

    // Load a scene by name
    std::string sceneName = "StandardScene";
    auto scene = sceneManager.loadScene(sceneName);

    if (scene) {
        scene->load();
        while(!glfwWindowShouldClose(scene->getWindow())) {
            scene->update();
            scene->render();
        }
        scene->clean();
    } else {
        std::cout << "Scene not found!\n";
    }

    return 0;
}