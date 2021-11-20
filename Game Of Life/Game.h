#ifndef GAME_H
#define GAME_H
#include "Engine.h"

class Game : public Engine
{
public:
	Game();
	Game(int, int);
	Game(const Game&);
	virtual ~Game() {}

	virtual void View() = 0;
};

#endif //GAME_H

