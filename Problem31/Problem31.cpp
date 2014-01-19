#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double temp;
    int counter = 0;
    for (int h = 0; h < 2; h++)
    {
        for (int g = 0; g < 3; g++)
        {
            for (int f = 0; f < 5; f++)
            {
                for (int e = 0; e < 11; e++)
                {
                    for (int d = 0; d < 21; d++)
                    {
                        for (int c = 0; c < 41; c++)
                        {
                            for (int b = 0; b < 101; b++)
                            {
                                for (int a = 0; a < 201; a++)
                                {
                                    temp = 0.01*a+0.02*b+0.05*c+0.1*d+0.2*e+0.5*f+g+2.0*h;
                                    if (temp == 2)
                                        counter++;
                                    else if (temp > 2)
                                        break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << counter;
    return 0;
}
