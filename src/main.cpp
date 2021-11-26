#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Core/GameInstance.h"

#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include <time.h>
#include <stdint.h>

GameInstance g;

int main()
{
	//setting up window and opengl

	if (!glfwInit())
	{
		std::cout << "GLFW failed to initialize." << std::endl;

		return -1;
	}

	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);
	
	if (window == NULL)
	{
		std::cout << "GLFW failed to create a window." << std::endl;

		return -1;
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "GLEW failed to initialize." << std::endl;
	}

	g.init();

	//setting up timing system

	int tps = 60;
	double tickns = 1000 / tps;

	double tickDelta = 0.0;

	uint64_t runtime = 0;

	time_t lastTick = clock();//open to changing this if there's a better option

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		double nowTick = clock();
		tickDelta += (double)(nowTick-lastTick) / tickns;
		lastTick = nowTick;

		while (tickDelta >= 1.0)
		{
			tickDelta -= 1.0;
			runtime++;

			g.Update(runtime);
		}

		glClear(GL_COLOR_BUFFER_BIT);

		g.Render();

		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
