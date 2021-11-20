#include "GameTXT.h"

GameTXT::GameTXT() : Game()
{
    /*  int row, col, cel_num;
    fstream file_data;
    file_data.open("data.txt");

    if (file_data.good() == false )
    {
        exit(3);
    }


        file_data >> cel_num;

        for (int i = 0; i < cel_num; i++) {
            file_data >> row >> col;

            Arr[row][col] = 1;
        }


        for (int i = 0; i < wiersze; i++)
        {
            for (int j = 0; j < kolumny; j++)
            {
                if (Arr[i][j] != 1)
                {
                    Arr[i][j] = 0;
                }
            }
        }
        file_data.close();*/

    View();

}


GameTXT::GameTXT(int rows, int columns) : Game(rows, columns)
{
    View();
}
GameTXT::~GameTXT()
{

}


void GameTXT::View()
{
    fstream file_output;
    file_output.open("output.txt", fstream::out);

    if (file_output.good() == false)
    {
        exit(3);
    }

    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i < wiersze; i++)
        {
            for (int j = 0; j < kolumny; j++)
            {
                file_output << Arr[i][j] << " ";
            }
            file_output << endl;
        }
        file_output << endl;
        file_output << endl;
        Analize();

    }

}


