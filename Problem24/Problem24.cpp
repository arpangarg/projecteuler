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

void generatePerm()
{
    int temp;
    int counter = 1;
    while (counter < 1000000)
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
        counter++;
    }
}

int main()
{
    generatePerm();
    string perm = "";
    for (int m = 0; m < 10; m++)
        perm += patch::to_string(nums[m]);
    cout << perm;
    return 0;
}
