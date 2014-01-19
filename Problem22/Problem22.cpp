#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

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

    sort(names.begin(), names.end());
    int sum = 0;
    int tempSum = 0;
    for (int m = 0; m < names.size(); m++)
    {
        for (int k = 0; k < names[m].size(); k++)
        {
            tempSum += names[m][k] - 'A' + 1;
        }
        sum += (m + 1)*tempSum;
        tempSum = 0;
    }
    cout << sum;
    return 0;
}
