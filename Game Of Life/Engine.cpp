#include "Engine.h"


Engine::Engine() : wiersze(20), kolumny(30)
{
	temp = new bool* [wiersze];
	if (temp) {

		for (int i = 0; i < wiersze; i++)
		{
			temp[i] = new bool[kolumny];
		}
	}

	Arr = new bool* [wiersze];
	if (Arr) {
		for (int i = 0; i < wiersze; i++)
		{
			Arr[i] = new bool[kolumny];
		}
	}



	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
		{
			Arr[i][j] = 0;
		}
	}

	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
		{
			temp[i][j] = 0;
		}
	}

	Init();
}


Engine::Engine(int xwiersze, int ykolumny) : wiersze(xwiersze), kolumny(ykolumny)
{
	Arr = new bool* [wiersze];
	if (Arr) {
		for (int i = 0; i < wiersze; i++)
		{
			Arr[i] = new bool[kolumny];
		}
	}


	temp = new bool* [wiersze];
	if (temp) {
		for (int i = 0; i < wiersze; i++)
		{
			temp[i] = new bool[kolumny];
		}
	}


	Init();
}


Engine::Engine(const Engine& E) : wiersze(E.wiersze), kolumny(E.kolumny)
{
	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
		{
			this->Arr[i][j] = E.Arr[i][j];
		}
	}

	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
		{
			this->temp[i][j] = E.temp[i][j];
		}
	}
}


void Engine::Init()
{
	srand(time(NULL));
	int temp = (getWiersze() * getKolumny()) / 2,
		tempx,
		tempy;

	for (int i = 0; i < temp; i++)
	{
		tempx = rand() % getWiersze();
		tempy = rand() % getKolumny();
		Arr[tempx][tempy] = 1;
	}
	//Arr[2][1] = 1;
	//Arr[2][2] = 1;
	//Arr[2][3] = 1;
}


int Engine::getKolumny() { return kolumny; }
int Engine::getWiersze() { return wiersze; }

int Engine::Analize_neighbor(int row, int column)
{
	int counter = 0;
	if (row == 0)
	{

		if (Arr[row][column - 1] == 1) counter++;
		if (Arr[row][column + 1] == 1) counter++;
		if (Arr[row + 1][column + 1] == 1) counter++;
		if (Arr[row + 1][column - 1] == 1) counter++;
		if (Arr[row + 1][column] == 1) counter++;
	}

	else if (row == wiersze - 1)
	{
		if (Arr[row - 1][column] == 1) counter++;
		if (Arr[row - 1][column - 1] == 1) counter++;
		if (Arr[row - 1][column + 1] == 1) counter++;
		if (Arr[row][column - 1] == 1) counter++;
		if (Arr[row][column + 1] == 1) counter++;
	}

	else if (column == 0)
	{
		if (Arr[row - 1][column] == 1) counter++;
		if (Arr[row - 1][column + 1] == 1) counter++;
		if (Arr[row][column + 1] == 1) counter++;
		if (Arr[row + 1][column + 1] == 1) counter++;
		if (Arr[row + 1][column] == 1) counter++;

	}

	else if (column == kolumny - 1)
	{
		if (Arr[row - 1][column] == 1) counter++;
		if (Arr[row - 1][column - 1] == 1) counter++;
		if (Arr[row][column - 1] == 1) counter++;
		if (Arr[row + 1][column - 1] == 1) counter++;
		if (Arr[row + 1][column] == 1) counter++;
	}

	else {
		if (Arr[row - 1][column] == 1) counter++;
		if (Arr[row - 1][column - 1] == 1) counter++;
		if (Arr[row - 1][column + 1] == 1) counter++;
		if (Arr[row][column - 1] == 1) counter++;
		if (Arr[row][column + 1] == 1) counter++;
		if (Arr[row + 1][column + 1] == 1) counter++;
		if (Arr[row + 1][column - 1] == 1) counter++;
		if (Arr[row + 1][column] == 1) counter++;
	}
	return counter;

}



void Engine::Analize()
{
	int temp_cell;

	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
		{
			temp_cell = Analize_neighbor(i, j);
			//cout << temp_cell << endl;

			if ((temp_cell == 2 || temp_cell == 3) && Arr[i][j] == 1)
			{
				temp[i][j] = 1;

			}

			else if (temp_cell == 3 && Arr[i][j] == 0)
			{
				temp[i][j] = 1;
			}

			else {
				temp[i][j] = 0;
			}

		}
	}

	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
		{
			Arr[i][j] = temp[i][j];
		}
	}

}




Engine::~Engine() {

	for (int i = 0; i < wiersze; i++)
		delete[] Arr[i];

	delete[] Arr;

	for (int i = 0; i < wiersze; i++)
		delete[] temp[i];


	delete[] temp;
}

