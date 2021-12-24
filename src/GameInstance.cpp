#include "Core/GameInstance.h"

GLuint vao, vbo, ibo;

ShaderProgram sp;

GameInstance::GameInstance()
{
	
}

void GameInstance::init()
{
	//The code involve in initialize vbos, vaos and VAPs is extremely vague and online tutorials are not helping at all.


	glGenVertexArrays(1, &vao);//At what point in this code is vbo or ibo associated with the vao? It isn't clear and none of the resources explain it.
	glBindVertexArray(vao);//Does this create a new scope where buffering the vbos will automatically add references to the vao?

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(basicTriangle::vertices), basicTriangle::vertices, GL_STATIC_DRAW);//does this simply push data to the buffer in the GPU or is this linking to the VAO?

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(basicTriangle::indices), basicTriangle::indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);//what exactly does this mean? Pointer to the vbo, but where is this pointer being stored? Why does this not exist for the ibo?
	glEnableVertexAttribArray(0);//What does index 0 refer to??? What does it mean for this to be enabled???

	sp.initBasicShaderProgram("res/shaders/default.vertex.glsl", "res/shaders/default.fragment.glsl");
}

void GameInstance::Update(uint64_t runtime)
{
	
}

void GameInstance::Render()
{
	sp.use();
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

GameInstance::~GameInstance()
{

}