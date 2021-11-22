#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <bitset>
#include <string>
#include <vector>

int main()
{
	int status = glfwInit();

	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);
	
	glfwMakeContextCurrent(window);

	glewInit();

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
