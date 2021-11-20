#ifndef GAMEAPI_H
#define GAMEAPI_H
#include "Game.h"
class GameAPI :
    public Game
{
public:
    GameAPI();
    GameAPI(int, int);
    ~GameAPI();
    virtual void View();
};
#endif //GAMEAPI_H
#pragma once
