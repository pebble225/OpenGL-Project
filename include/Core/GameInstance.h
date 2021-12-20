#ifndef OPENGLPROJECT_INCLUDE_CORE_GAMEINSTANCE_H_
#define OPENGLPROJECT_INCLUDE_CORE_GAMEINSTANCE_H_

#include <stdint.h>//can't get <cstdint> to work. C++ 11 compatibility issues
#include "GameGL/ShaderProgram.h"

class GameInstance
{
public:
	GameInstance();

	void init();
	void Update(uint64_t runtime);
	void Render();

	~GameInstance();
};

#endif