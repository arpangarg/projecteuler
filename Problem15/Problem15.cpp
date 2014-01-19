#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int fact(int n)
{
    if (n == 1)
        return n;
    return n*fact(n-1);
}

int main()
{
    long long val1 = 1;
    for (int i = 21; i < 40; i += 2)
    {
        val1 *= i;
    }
    val1 /= fact(10);
    cout << val1 <<endl;
    val1 *= (int)pow(2, 10);
    cout <<val1;
    return 0;
}
