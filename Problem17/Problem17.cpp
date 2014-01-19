#include <iostream>
#include <cmath>

using namespace std;

int nums[91] = {0};

int numDigits(int n)
{
    if (n / 10 == 0)
        return 1;
    else if (n / 100 == 0)
        return 2;
    else
        return 3;
}

int singleDigit(int n)
{
    return nums[n];
}

int twoDigit(int n)
{
    if (n < 20)
        return nums[n];
    else
        return nums[n - (n%10)] + singleDigit(n%10);
}

int threeDigit(int n)
{
    if (n % 100 == 0)
        return 7 + nums[n/100];
    else
        return 10 + nums[n/100] + twoDigit(n % 100);
}

int main()
{
    nums[1] = 3;
    nums[2] = 3;
    nums[3] = 5;
    nums[4] = 4;
    nums[5] = 4;
    nums[6] = 3;
    nums[7] = 5;
    nums[8] = 5;
    nums[9] = 4;
    nums[10] = 3;
    nums[11] = 6;
    nums[12] = 6;
    nums[13] = 8;
    nums[14] = 8;
    nums[15] = 7;
    nums[16] = 7;
    nums[17] = 9;
    nums[18] = 8;
    nums[19] = 8;
    nums[20] = 6;
    nums[30] = 6;
    nums[40] = 5;
    nums[50] = 5;
    nums[60] = 5;
    nums[70] = 7;
    nums[80] = 6;
    nums[90] = 6;

    int numDig = 0;
    int sum = 0;
    for (int i = 1; i < 1000; i++)
    {
        numDig = numDigits(i);
        if (numDig == 1)
            sum += singleDigit(i);
        else if(numDig == 2)
            sum += twoDigit(i);
        else
            sum += threeDigit(i);
    }

    cout << sum;

    return 0;
}
