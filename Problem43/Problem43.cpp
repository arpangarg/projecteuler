#include <string>
#include <sstream>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

#include <iostream>
#include <cmath>

using namespace std;

int nums[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int div[8] = {1, 2, 3, 5, 7, 11, 13, 17};
long long sum = 0;

void generatePerm()
{
    int temp;
    int counter = 1;
    while (counter < 3628800)
    {
        int i = 9;
        while (nums[i-1] >= nums[i])
            i -= 1;
        int j = 10;
        while (nums[j-1] <= nums[i-1])
            j -= 1;

        temp = nums[i-1];
        nums[i-1] = nums[j-1];
        nums[j-1] = temp;

        i++;
        j = 10;
        while (i < j)
        {
            temp = nums[i-1];
            nums[i-1] = nums[j-1];
            nums[j-1] = temp;
            i++;
            j--;
        }
        if (nums[0] != 0)
        {
            bool divisible = true;
            for (int m = 1; m < 8; m++)
            {
                int num = 100*nums[m] + 10*nums[m+1] + nums[m+2];
                if(num % div[m] != 0)
                {
                    divisible = false;
                    break;
                }
            }
            if (divisible)
            {
                long long n = 0;
                for (int s = 0; s < 10; s++)
                    n = n*10 + nums[s];
                sum += n;
            }
        }
        counter++;
    }
}

int main()
{
    generatePerm();
    cout << sum;
    return 0;
}
