#ifndef OPENGLPROJECT_INCLUDE_CORE_GAMEINSTANCE_H_
#define OPENGLPROJECT_INCLUDE_CORE_GAMEINSTANCE_H_

class GameInstance
{
public:
	GameInstance();

	void init();
	void Update();
	void Render();

	~GameInstance();
};

#endif