#ifndef ENGINE_H
#define ENGINE_H
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;
class Engine
{
protected:
	Engine();
	Engine(int, int);
	Engine(const Engine&);
	virtual ~Engine();
	void Analize();

	int getKolumny();
	int getWiersze();

	bool** Arr, ** temp;
	int kolumny,
		wiersze;

	int Analize_neighbor(int, int);
	void Init();


};
#endif //ENIGINE_H

