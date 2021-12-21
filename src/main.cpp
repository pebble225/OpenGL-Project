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

void APIENTRY openglcatcherror(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const char* message, const void* userparam)
{
	std::cout << "===================================\nOPENGL ERROR:\nSource: " << source << "\nType: 0x" << type << "\nId: " << id << "\nSeverity: " << severity << "\n\n> ";
	std::cout << message << "\n\n";
	
	exit(-1);
}

void enableglDebugFlag()
{
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
}

void enableglDebug()
{
	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageCallback(openglcatcherror, NULL);
}

int main()
{
	//setting up window and opengl

	if (!glfwInit())
	{
		std::cout << "GLFW failed to initialize." << std::endl;

		return -1;
	}

	enableglDebugFlag();

	GLFWwindow* window = glfwCreateWindow(1600, 900, "Untitled RPG Game", NULL, NULL);
	
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

	enableglDebug();

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

			g.Update(runtime);
		}

		glClear(GL_COLOR_BUFFER_BIT);

		g.Render();
		fps++;

		glfwSwapBuffers(window);

		if (glfwGetTime()-performanceTimer > 1.0)
		{
			performanceTimer += 1.0;

			//std::cout << "FPS: " << fps << std::endl;

			fps = 0;
		}
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
