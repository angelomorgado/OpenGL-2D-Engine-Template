/*
Initialization.hpp
    - Deals with the setup of the window, OpenGL, etc.
*/

#ifndef SETUP_HPP
#define SETUP_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>

#include <Callbacks.hpp>

class Setup{
    public:
        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
        static void glfw_setup();
        static void window_setup(GLFWwindow* window);
        static void glad_setup();
        static void printGPUinfo();
        static GLFWwindow* setupWindow(const char* title);
};

#endif