#ifndef GAMETXT_H
#define GAMETXT_H
#include "Game.h"
class GameTXT :
    public Game
{
public:
    GameTXT();
    GameTXT(int, int);
    ~GameTXT();
    virtual void View();
};

#endif //GAMETXT_H
