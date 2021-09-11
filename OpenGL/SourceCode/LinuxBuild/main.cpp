#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <array>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

#include "Dependencies/draw.h"
#include "Dependencies/tools.h"
#include "Dependencies/Sound.h"

using namespace std;

const char* name = "OpenGL";
int width = 600;
int height = 600;

double mouse_x;
double mouse_y;
int mouse_state;
int mouse_button;


static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	mouse_x = map(-1, 1, 0, width, xpos);
	mouse_y = map(1, -1, 0, height, ypos);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	mouse_button = button;
	mouse_state = action;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

}

int main(void)
{
	if (!glfwInit()) { error("could not initialize glfw"); return -1;}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	GLFWwindow* window = glfwCreateWindow(width, height, name, NULL, NULL);
	
	if (!window)
	{
		glfwTerminate();
		error("could not create window");
		return -1;
	}
	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetKeyCallback(window, key_callback);
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) { error("could not initialize glew"); return -1; }

	Shader shader("shaders/basic.shader");
	shader.useShader();

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);	
		
		polygon(shader, { {-0.9, -0.9}, {-0.75, 0.25}, {0, 0.9}, {0.75, 0.25}, {0.9, -0.9} }, {1,1,1,1}, true);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	shader.deleteShader();
	glfwTerminate();
}
