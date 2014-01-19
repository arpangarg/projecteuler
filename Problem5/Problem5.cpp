#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    bool found = false;
    int num = 0;
    while(!found)
    {
        num++;
        found = true;
        for (int i = 1; i <= 20; i++)
        {
            if(num % i != 0)
                   found = false;
        }
    }
    cout << num;
    cin.get();
    return 0;
}
