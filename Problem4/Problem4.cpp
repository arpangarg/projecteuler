#include <iostream>
#include <cmath>

using namespace std;

int isPalindrome(int n)
{
    int numDec = -1;
    int orig = n;
    int temp = n;
    int reversed = 0;
    while(temp > 0)
    {
        temp /= 10;
        numDec++;
    }
    while (numDec > 0)
    {
        reversed += (n % 10) * pow((double)10, numDec);
        n /= 10;
        numDec--;
    }
    reversed += n;
    if (reversed == orig)
       return 1;
    return 0;
}

int main()
{
    int largest = 0;
    for (int i = 1; i < 1000; i++)
    {
        for (int j = i; j < 1000; j++)
        {
            if(isPalindrome(i*j) && (i*j > largest))
                 largest = i*j;
        }
    }
    cout << largest;
    cin.get();
    return 0;
}
