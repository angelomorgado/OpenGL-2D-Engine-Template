/*
    Callbacks.hpp :

        - Deals with the callbacks of the window, e.g. resizing, input, etc.
*/
#ifndef CALLBACKS_HPP
#define CALLBACKS_HPP

#include <iostream>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

class Callbacks
{
    public:
        static void processInput(GLFWwindow *window);
        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
        static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
};

#endif