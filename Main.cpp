#include <iostream>
#include <memory>
#include <INIReader.h>
#include <SceneManager.hpp>
#include <Scenes/StandardScene.hpp>

int main() {
    SceneManager& sceneManager = SceneManager::getInstance();

    // Register scenes
    sceneManager.registerScene("StandardScene", []() { return std::make_shared<StandardScene>(); });
    // sceneManager.registerScene("GameScene", []() { return std::make_shared<GameScene>(); });

    // Load a scene by name
    INIReader reader("Config/Config.ini");
    std::string sceneName = reader.Get("Scene", "active_scene", "StandardScene");
    // std::string sceneName = "StandardScene"; // Alternatively, you can hardcode the scene name
    std::cout << "Loading scene: " << sceneName << std::endl;
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