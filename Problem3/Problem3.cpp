#include <iostream>
#include <cmath>

using namespace std;

int isPrime(long long n)
{
     if (n == 1 || n == 2)
        return 1;
     int sq = (int)ceil(sqrt(n));
     for (int i = 2; i <= sq; i++)
     {
         if(n % i == 0)
              return 0;
     }
     return 1;
}

int main()
{
    long long orig = 600851475143;
    int num = (int)ceil(sqrt(orig));
    int largest = 1;
    cout << num <<endl;
    for (int i = 1; i <= num; i++)
    {
        if((orig % i == 0) && isPrime(i))
        {
            largest = i;
            cout << largest << endl;
        }
    }
    cout << largest;
    cin.get();
    return 0;
}
