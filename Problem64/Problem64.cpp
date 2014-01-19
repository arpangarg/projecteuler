#include <iostream>
#include <cmath>

using namespace std;

//algorithm determined from:
//http://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Continued_fraction_expansion
int main()
{
    int N = 10000;
    int sum = 0;

    for (int i = 2; i <= N; i++)
    {
        int limI = (int)floor(sqrt(i));
        double limD = sqrt(i);
        if (limI == limD)
            continue;

        int per = 0;
        int d = 1;
        int m = 0;
        int a = limI;

        do
        {
            m = d*a - m;
            d = (i - m * m) / d;
            a = (limI + m) / d;
            per++;
        } while (a != 2*limI);

        if (per % 2 == 1)
            sum++;
    }
    cout << sum;
    return 0;
}
