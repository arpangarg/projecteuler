#include <iostream>
#include <cmath>

using namespace std;

int getTriangular(int i)
{
    return i*(i+1)/2;
}

int numDivisors(int num)
{
    int numDiv = 0;
    for (int i = 1; i <= (int)sqrt(num); i++)
    {
        if (num % i == 0)
           numDiv += 2;
    }
    return numDiv;
}

int main()
{
    int numDiv = 0;
    int i = 2;
    int triang = getTriangular(i);
    while (numDiv <= 500)
    {
        i++;
        triang = getTriangular(i);
        numDiv = numDivisors(triang);
    }
    cout << numDiv << " " << triang;
    cin.get();
    return 0;
}
