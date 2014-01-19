#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    vector<int> num;
    num.push_back(1);
    int temp, carry = 0;
    int vecSize;

    for (int i = 0; i < 1000; i++)
    {
        carry = 0;
        vecSize = num.size();
        for(int k = 0; k < vecSize; k++)
        {
            temp = 2*num[k] + carry;
            if (temp > 9)
            {
                carry = temp/10;
                temp = temp % 10;
                if (k == vecSize - 1)
                {
                    num.push_back(carry);
                }
            }
            else
            {
                carry = 0;
            }
            num[k] = temp;
        }
    }
    int sum = 0;
    for(int m = num.size() - 1; m >= 0; m--)
        sum += num[m];
    cout << sum;
    return 0;
}
