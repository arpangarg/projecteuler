#include <iostream>
#include <cmath>

//include the TTMath Big Num Library (Author: Tomasz Sowa)
#include "../ttmath/ttmath.h"

using namespace std;

//typedef ttmath::Big<1,2> bigInt;
typedef ttmath::UInt<10> bigInt;

//same method as problem 64 (using Pell's eqn)

int main()
{
	int maxD = 0;
    bigInt maxX = 0;

    int D;
    for(D = 2; D <= 1000; D++)
    {
        int limI = (int)floor(sqrt(D));
        double limD = sqrt(D);
        if (limI == limD)
            continue;

        bigInt lim = limI;
        bigInt d = 1;
        bigInt m = 0;
        bigInt a = lim;

        bigInt currX = 1;
        bigInt X = a;
        bigInt currY = 0;
        bigInt Y = 1;
        bigInt DB = D;

        while(X*X - DB*Y*Y != 1)
        {
            m = d * a - m;
            d = (DB - m * m) / d;
            a = (lim + m) / d;
            bigInt nextX = currX;
            currX = X;
            bigInt nextY = currY;
            currY = Y;
            X = a*currX + nextX;
            Y = a * currY + nextY;
        }

        if (X > maxX)
        {
            maxX = X;
            maxD = D;
        }

    }
    cout << maxD;
	return 0;
}
