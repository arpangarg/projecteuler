#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int checkPan (int i, int j)
{
    int mult = i*j;
    int digs[10] = {0};
    if (mult / 1000 < 0 || mult / 10000 != 0)
    {
        return 0;
    }
    else
    {
        if (i < 10)
        {
            digs[i] = 1;
            digs[j % 10] = 1;
            j /= 10;
            digs[j % 10] = 1;
            j /= 10;
            digs[j % 10] = 1;
            j /= 10;
            digs[j] = 1;
        }
        else
        {
            digs[i % 10] = 1;
            i /= 10;
            digs[i] = 1;
            digs[j % 10] = 1;
            j /= 10;
            digs[j % 10] = 1;
            j /= 10;
            digs[j] = 1;
        }
        digs[mult % 10] = 1;
        mult /= 10;
        digs[mult % 10] = 1;
        mult /= 10;
        digs[mult % 10] = 1;
        mult /= 10;
        digs[mult] = 1;

        for (int k = 1; k < 10; k++)
        {
            if (digs[k] == 0)
                return 0;
        }
        return 1;
    }
}

int main()
{
    vector<int> Pandig;
    int sum = 0;
    for (int i = 1; i < 100; i++)
    {
        if (i < 10)
        {
            for (int j = 1000; j < 10000; j++)
            {
                if (i * j >= 10000)
                    break;
                if (checkPan(i, j) == 1 &&
                    find(Pandig.begin(), Pandig.end(), i*j) == Pandig.end())
                        Pandig.push_back(i*j);
            }
        }
        else
        {
            for (int j = 100; j < 1000; j++)
            {
                if (i * j >= 10000)
                    break;
                if (checkPan(i, j) == 1 &&
                    find(Pandig.begin(), Pandig.end(), i*j) == Pandig.end())
                        Pandig.push_back(i*j);

            }
        }
    }
    for (int m = 0; m < Pandig.size(); m++)
        sum += Pandig[m];
    cout << sum;
    return 0;
}
