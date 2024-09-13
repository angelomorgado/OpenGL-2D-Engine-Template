#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <vector>

#include <Callbacks.hpp>
#include <Setup.hpp>
#include <INIReader.h>

int main()
{
    INIReader reader("Config/Config.ini");
    int screen_width = reader.GetInteger("Window", "width", 800);
    int screen_height = reader.GetInteger("Window", "height", 600);
    
    GLFWwindow* window = Setup::complete_setup("LearnOpenGL", screen_width, screen_height);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        Callbacks::processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}
