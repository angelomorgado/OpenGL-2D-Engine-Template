#include <Scenes/StandardScene.hpp>
#include <SceneManager.hpp>

StandardScene::StandardScene() {
    INIReader reader("Config.ini");
    screen_width = reader.GetInteger("Window", "width", 800);
    screen_height = reader.GetInteger("Window", "height", 600);
    
    window = Setup::complete_setup("LearnOpenGL", screen_width, screen_height);

    vertices = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    }; 

}

void StandardScene::load() {
    // Load shaders
    standardShader.load("Shaders/standard.vert", "Shaders/standard.frag");

    // Load objects on the GPU
    // 1: Triangle
    // Generate and bind Vertex Array Object (VAO)
    glGenVertexArrays(1, &VAO);  // Generate VAO
    glBindVertexArray(VAO);      // Bind VAO
    // Generate and bind Vertex Buffer Object (VBO)
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // Copy our vertices array into the buffer for OpenGL to use
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), GL_STATIC_DRAW);
    // Set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // Unbind VAO and VBO for safety
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void StandardScene::update() {
    // input
    Callbacks::processInput(window);

    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void StandardScene::render() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    standardShader.use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

int StandardScene::clean() {
    glfwTerminate();
    return 0;
}

GLFWwindow* StandardScene::getWindow() {
    return window;
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
