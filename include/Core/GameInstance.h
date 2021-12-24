#include <GL/glew.h>
#include <GLFW/glfw3.h>

#ifndef OPENGLPROJECT_INCLUDE_CORE_GAMEINSTANCE_H_
#define OPENGLPROJECT_INCLUDE_CORE_GAMEINSTANCE_H_

#include <stdint.h>//can't get <cstdint> to work. C++ 11 compatibility issues
#include "GameGL/ShaderProgram.h"
#include "GameGL/meshData.h"
#include <glm.hpp>

class GameInstance
{
public:
	GameInstance();

	void APIENTRY openglcatcherror(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const char* message, const void* userparam);

	void init();
	void Update(uint64_t runtime);
	void Render();

	~GameInstance();
};

#endif