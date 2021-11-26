#include <GL/glew.h>

#include "Core/GameInstance.h"

namespace testingMesh
{
	const float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
		0.5f, 0.5f, 0.0f
	};

	const int indices[] = {
		0, 1, 2,
		1, 3, 2
	};
}

GLuint vao, vbo, ibo;

GameInstance::GameInstance()
{
	
}

void GameInstance::init()
{
	
}

void GameInstance::Update(uint64_t runtime)
{
	
}

void GameInstance::Render()
{
	
}

GameInstance::~GameInstance()
{

}