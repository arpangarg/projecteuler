#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int sum = 0;
    for (int n = 1001; n >= 3; n -= 2)
    {
        sum += 4*n*n - 6*n + 6;
    }
    cout << 1 + sum;
    return 0;
}
