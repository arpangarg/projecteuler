#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

vector<int> triangle;
int tsize;

int level(int i)
{
    return ceil((-1 + sqrt(1 + 8*i))/2);
}

int main()
{
    int temp;

    triangle.push_back(0);
    ifstream inFile;
    inFile.open("data.txt");
    while (!inFile.eof())
    {
        inFile >> temp;
        triangle.push_back(temp);
    }
    inFile.close();

    tsize = triangle.size();
    int left, right;

    for(int i = 99; i > 0; i--)
    {
        for(int k = i*(i+1)/2; k > i*(i+1)/2 - i; k--)
        {
            left = level(k) + k;
            right = level(k) + k + 1;
            if (triangle[left] > triangle[right])
                triangle[k] += triangle[left];
            else
                triangle[k] += triangle[right];
        }
    }
    cout << triangle[1];
    return 0;
}
