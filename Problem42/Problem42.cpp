#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>

using namespace std;

int isTriangular(int t)
{
    double nd = -0.5 + 0.5*sqrt(1+8*t);
    int ni = nd;
    if (ni == nd)
        return 1;
    return 0;
}

int main()
{
    string input;
    ifstream inFile;
    inFile.open("data.txt");
    inFile >> input;
    inFile.close();

    int inSize = input.size();
    int i = 1;
    string temp;
    vector<string> names;
    while (i < inSize)
    {
        while(input[i] != '"')
        {
            temp += input[i];
            i++;
        }
        i += 3;
        names.push_back(temp);
        temp = "";
    }

    int sum = 0;
    int numTr = 0;
    for (int m = 0; m < names.size(); m++)
    {
        for (int k = 0; k < names[m].size(); k++)
        {
            sum += names[m][k] - 'A' + 1;
        }
        if (isTriangular(sum))
            numTr++;
        sum = 0;
    }
    cout << numTr;
    return 0;
}
