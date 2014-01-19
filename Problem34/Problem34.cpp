#include <iostream>
#include <cmath>

using namespace std;

int numDigits(int i)
{
    if (i / 10 == 0)
        return 1;
    else if (i / 100 == 0)
        return 2;
    else if (i / 1000 == 0)
        return 3;
    else if (i / 10000 == 0)
        return 4;
    else if (i / 100000 == 0)
        return 5;
    else if (i / 1000000 == 0)
        return 6;
    else
        return 7;
}

int fact(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n*fact(n - 1);
}

int main()
{
    int numDig, sum, temp1, temp2, totalSum = 0;
    for (int i = 10; i < 5000000; i++)
    {
        sum = 0;
        temp1 = i;
        numDig = numDigits(i);
        while (numDig > 0)
        {
            temp2 = temp1 % 10;
            temp1 /= 10;
            numDig--;
            sum += fact(temp2);
        }
        if (i == sum)
        {
            totalSum += i;
        }
    }

    cout << totalSum;
    return 0;
}
