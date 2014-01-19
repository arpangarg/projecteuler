#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int numDigits(long long i)
{
    int numDig = 0;
    if (i == 0)
        return 0;
    while (i > 0)
    {
        i /= 10;
        numDig++;
    }
    return numDig;
}

bool isPermut(long long a, long long b)
{
    int numDigA = numDigits(a);
    int numDigB = numDigits(b);

    if (numDigA == numDigB)
    {
        int compA[10] = { 0 };
        for (int i = 0; i < numDigA; i++)
        {
            compA[a % 10]++;
            a /= 10;
        }

        int compB[10] = { 0 };
        for (int i = 0; i < numDigB; i++)
        {
            compB[b % 10]++;
            b /= 10;
        }

        bool isP = true;
        for (int i = 0; i < 10; i++)
        {
            if(compA[i] != compB[i])
                isP = false;
        }
        return isP;
    }
    return false;
}

int main()
{
    vector<long long> cubes;
    for (long long i = 0; i < 15000; i++)
        cubes.push_back(i*i*i);

    while (1)
    {
        vector<int> indices;
        indices.push_back(0);
        int counter = 1;
        for (int k = 1; k < cubes.size(); k++)
        {
            if(isPermut(cubes[0], cubes[k]))
            {
                counter++;
                indices.push_back(k);
            }
        }
        if (counter == 5)
        {
            cout << cubes[0];
            return 0;
        }
        else
        {
            for(int s = indices.size() - 1; s >= 0; s--)
                cubes.erase(cubes.begin() + indices[s]);
        }
    }
    cout << "not found";
    return 0;
}
