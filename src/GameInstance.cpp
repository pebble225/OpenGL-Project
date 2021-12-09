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
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(testingMesh::vertices), testingMesh::vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glDisableVertexAttribArray(0);
}

void GameInstance::Update(uint64_t runtime)
{
	
}

void GameInstance::Render()
{
	glEnableVertexAttribArray(0);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(0);
}

GameInstance::~GameInstance()
{

}