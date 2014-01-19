#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

//global array
int grid[20][20];

int multiplyUp(int i, int j)
{
    return grid[i][j] * grid[i-1][j] * grid[i-2][j] * grid[i-3][j];
}

int multiplyDown(int i, int j)
{
    return grid[i][j] * grid[i+1][j] * grid[i+2][j] * grid[i+3][j];
}

int multiplyLeft(int i, int j)
{
    return grid[i][j] * grid[i][j-1] * grid[i][j-2] * grid[i][j-3];
}

int multiplyRight(int i, int j)
{
    return grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3];
}

int multiplyDiagonally(int i, int j)
{
    return grid[i][j] * grid[i+1][j+1] * grid[i+2][j+2] * grid[i+3][j+3];
}

int multiplyDiagonally2(int i, int j)
{
    return grid[i][j] * grid[i+1][j-1] * grid[i+2][j-2] * grid[i+3][j-3];    
}

int main()
{
    int tempCheck = 0, largest = 0;
    ifstream inFile;
    inFile.open("data.txt");
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            inFile >> grid[i][j];
        }
    }
    inFile.close();
    
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(j > 2)
            {
                 tempCheck = multiplyLeft(i, j);
                 if (tempCheck > largest)
                    largest = tempCheck;
            }
            if(j < 17)
            {
                 tempCheck = multiplyRight(i, j);
                 if (tempCheck > largest)
                    largest = tempCheck;
            }
            if(i > 2)
            {
                 tempCheck = multiplyUp(i, j);
                 if (tempCheck > largest)
                    largest = tempCheck;
            }
            if(i < 17)
            {
                 tempCheck = multiplyDown(i, j);
                 if (tempCheck > largest)
                    largest = tempCheck;
            }
            if(i < 17 && j < 17)
            {
                 tempCheck = multiplyDiagonally(i, j);
                 if (tempCheck > largest)
                    largest = tempCheck;
            }
            if(j > 2 && i < 17)
            {
                 tempCheck = multiplyDiagonally2(i, j);
                 if (tempCheck > largest)
                    largest = tempCheck;
            }
        }
    }
    cout << largest;
    cin.get();
    return 0;
}
