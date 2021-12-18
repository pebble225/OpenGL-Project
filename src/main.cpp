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
	double tickns = 1.0 / (double)tps;

	double tickDelta = 0.0;

	uint64_t runtime = 0;

	double lastTick = glfwGetTime();//clock() returns different results between Linux and Windows!
	double performanceTimer = glfwGetTime();

	int fps = 0;//TODO: Add a frame limit

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		double nowTick = glfwGetTime();
		tickDelta += (double)(nowTick-lastTick) / tickns;
		lastTick = nowTick;

		while (tickDelta >= 1.0)
		{
			tickDelta -= 1.0;
			runtime++;

			fps++;

			g.Update(runtime);
		}

		glClear(GL_COLOR_BUFFER_BIT);

		g.Render();
		//fps++;

		glfwSwapBuffers(window);

		if (glfwGetTime()-performanceTimer > 1.0)
		{
			performanceTimer += 1.0;

			std::cout << "FPS: " << fps << std::endl;

			fps = 0;
		}
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
