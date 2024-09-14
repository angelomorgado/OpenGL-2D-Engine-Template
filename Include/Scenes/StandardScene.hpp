#ifndef STANDARDSCENE_HPP
#define STANDARDSCENE_HPP

#include <array>

#include <Scene.hpp>
#include <Callbacks.hpp>
#include <Setup.hpp>
#include <INIReader.h>
#include <Shader.hpp>

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
    
    std::array<float, 9> vertices;
    unsigned int VBO, VAO;
    Shader standardShader;
};

#endif // STANDARDSCENE_HPP