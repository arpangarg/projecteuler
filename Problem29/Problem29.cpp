#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int distinctTerms[101][601] = {0};
    int tempA, tempB;
    int repTerms = 0;
    for (int a = 2; a < 101; a++)
    {
        for (int b = 2; b < 101; b++)
        {
            for (int i = 1; i < 7; i++)
            {
                if((double)pow(a, 1.0/i) == (int)ceil(pow(a, 1.0/i)))
                {
                    tempA = (int)ceil(pow(a, 1.0/i));
                    tempB = b*i;
                }
            }
            if(distinctTerms[tempA][tempB] == 1)
                repTerms++;
            else
                distinctTerms[tempA][tempB] = 1;
        }
    }

    cout << 99*99 - repTerms <<endl;

    return 0;
}
