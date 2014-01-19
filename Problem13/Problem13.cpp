#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

int main()
{
    string numbers[100];
    ifstream inFile;
    inFile.open("data.txt");
    for(int k = 0; k < 100; k++)
    {
        inFile >> numbers[k];
    }
    inFile.close();
    int sum = 0;
    for (int j = 49; j > 9; j--)
    {
        for (int i = 0; i < 100; i++)
        {
             sum += (numbers[i][j] - '0');
        }
        sum /= 10;
    }
    long long nums[100];
    for (int m = 0; m < 100; m++)
    {
        numbers[m].resize(10);
        istringstream buffer(numbers[m]);
        buffer >> nums[m];
    }
    long long finSum = sum;
    for (int p = 0; p < 100; p++)
    {
        finSum += nums[p];
    }
    cout << finSum;
    return 0;
}
