#include <iostream>
#include <cmath>

using namespace std;

int fact[10];

int factorial(int n)
{
    if (n == 0)
        return 1;
    return n*factorial(n-1);
}

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

int detSeqLen(int start, int oldStart)
{
    if (start == 145 || start == oldStart)
        return 1;
    else if(start == 871 || start == 45361 || start == 872 || start == 45362)
        return 2;
    else if(start == 169 || start == 363601 || start == 1454)
        return 3;
    else
    {
        int numDig = numDigits(start);
        int newStart = 0;
        int temp = start;
        for (int k = 0; k < numDig; k++)
        {
            newStart += fact[temp % 10];
            temp /= 10;
        }
        return 1 + detSeqLen(newStart, start);
    }
}

int main()
{
    for (int k = 0; k < 10; k++)
        fact[k] = factorial(k);
    int counter = 0;
    for (int i = 3; i < 1000000; i++)
    {
        if (detSeqLen(i, 0) == 60)
            counter++;
    }
    cout << counter;
    return 0;
}
