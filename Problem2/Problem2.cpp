#include <iostream>

using namespace std;

int Fib(int i)
{
    if (i == 1)
       return 1;
    else if (i == 2)
       return 2;
    return Fib(i - 1) + Fib(i-2);
}

int main()
{
    int val = 1;
    int sum = 0;
    int i = 2;
    while (val <= 4000000)
    {
          if(val % 2 == 0)
                 sum += val;
          val = Fib(i);
          i++;
    }
    cout << sum;          
    cin.get();
    return 0;
}
