#include "Core/GameInstance.h"

namespace testingMesh
{
	const float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f
	};

	const float indices[] = {
		0, 1, 2
	};
}

GLuint vao, vbo, ibo;

ShaderProgram sp;



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

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(testingMesh::indices), testingMesh::indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), NULL);
	glEnableVertexAttribArray(0);

	sp.initBasicShaderProgram("res/shaders/default.vertex.glsl", "res/shaders/default.fragment.glsl");
}

void GameInstance::Update(uint64_t runtime)
{
	
}

void GameInstance::Render()
{
	sp.use();
	glBindVertexArray(vao);

	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);//this isn't working for some reason.....
}

GameInstance::~GameInstance()
{

}