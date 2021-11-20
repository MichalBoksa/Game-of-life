#include "Game.h"

Game::Game() : Engine() {}

Game::Game(int xwiersze, int ykolumny) : Engine(xwiersze, ykolumny) {}

Game::Game(const Game& G) : Engine(G) {}
