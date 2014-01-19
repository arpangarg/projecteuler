#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int sumSq = 0;
    int Sqsum = pow((double)100*101/2, 2);
    for(int i = 1; i <=100; i++)
            sumSq += i*i;
    cout << Sqsum - sumSq;
    cin.get();
    return 0;
}
