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
        static GLFWwindow* window_setup(const char* title, int width, int height);
        static void glad_setup();
        static void printInfo();
        static GLFWwindow* complete_setup(const char* title, int width, int height);
};

#endif