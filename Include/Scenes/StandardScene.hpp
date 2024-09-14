#ifndef STANDARDSCENE_HPP
#define STANDARDSCENE_HPP

#include <Scene.hpp>
#include <Callbacks.hpp>
#include <Setup.hpp>
#include <INIReader.h>

class StandardScene : public Scene {
public:
    StandardScene();
    void load() override;
    void update() override;
    void render() override;
    int clean() override;
    GLFWwindow* getWindow() override;
private:
    GLFWwindow* window;
    int screen_width;
    int screen_height;
};

#endif // STANDARDSCENE_HPP