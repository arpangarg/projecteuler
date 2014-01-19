#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int numb = 0;
    int longestSeq = 0;
    for (int i=3; i <= 1000000; i++)
    {
        long long temp = i;
        int seq = 1;
        while (temp != 1)
        {
            if (temp % 2 == 0)
                temp /= 2;
            else
                temp = 3*temp + 1;
            seq++;
        }
        if (seq > longestSeq)
        {
            longestSeq = seq;
            numb = i;
        }
    }
    cout << longestSeq << " " << numb;
    return 0;
}
