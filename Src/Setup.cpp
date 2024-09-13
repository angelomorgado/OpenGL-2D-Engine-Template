#include <Setup.hpp>

void Setup::glfw_setup() {
	
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE); // Resisable window?

	#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	#endif
}

GLFWwindow* Setup::window_setup(const char* title, int width, int height) {
    GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		exit(-1);
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, Callbacks::framebuffer_size_callback);
	// glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); // Enabled Cursor? 
	//glfwSetCursorPosCallback(window, mouse_callback); // Call mouse callback

    return window;
}

void Setup::glad_setup() {
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		exit(-1);
	}
}

// prints all the relevant info
void Setup::printInfo() {
	std::cout << "=======================================================================\n";
	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
	std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "=======================================================================\n";
}

// It automatically sets up everything and returns the window
GLFWwindow* Setup::complete_setup(const char* title, int width, int height)
{
    glfw_setup();
    GLFWwindow* window = window_setup(title, width, height);
    glad_setup();
	printInfo();

    // Z buffer (depth buffer)
	glEnable(GL_DEPTH_TEST);

	return window;
}