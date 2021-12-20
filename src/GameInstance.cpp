#include <GL/glew.h>

#include "Core/GameInstance.h"

namespace testingMesh
{
	const float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f
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

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glDisableVertexAttribArray(0);
	//glBindBuffer(GL_ARRAY_BUFFER, 0);//is it necessary to rebind this buffer during render time?
	//glBindVertexArray(0);

	sp.initBasicShaderProgram("res/shaders/default.vertex.glsl", "res/shaders/default.fragment.glsl");
}

void GameInstance::Update(uint64_t runtime)
{
	
}

void GameInstance::Render()
{
	glEnableVertexAttribArray(0);
	sp.use();//Shader is throwing errors when compiling!

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(0);
}

GameInstance::~GameInstance()
{

}