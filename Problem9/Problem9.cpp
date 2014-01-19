#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b;
    double c;
    
    for (a = 1; a <= 999; a++)
    {
        for (b = 1; b <= 999; b++)
        {
            c = sqrt(a*a + b*b);
            if(a+b+c == 1000)
               cout << a << " " << b << " " << c << endl;
        }
    }
    
    cin.get();
    return 0;
}
