#include <GLFW/glfw3.h>

#include <iostream>
#include <bitset>
#include <string>
#include <vector>



int main()
{
	int status = glfwInit();

	std::cout << status << std::endl;

	glfwTerminate();

	return 0;
}
