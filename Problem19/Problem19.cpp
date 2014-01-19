#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //month: 0 - 11 (starting Jan), dow: 0 - 6 (starting Mon)
    int day = 1, month = 0, year = 1901, dow = 1;
    int numSundays = 0;

    while (year < 2001)
    {
        day++;
        dow = (dow + 1) % 7;
        if ((month == 3 || month == 5 || month == 8 || month == 10) && day == 31)
        {
            day = 1;
            month++;
        }
        else if (day == 29 && month == 1)
        {
            if (year % 4 == 0) {} // don't need to check for div by 400 condition
            else
            {
                day = 1;
                month++;
            }
        }
        else if (day == 30 && month == 1 && year % 4 == 0)
        {
            day = 1;
            month++;
        }
        else if (month != 11 && day == 32)
        {
            day = 1;
            month = (month + 1) % 12;
        }
        else if (month == 11 && day == 32)
        {
            day = 1;
            month = 0;
            year++;
        }
        else {}

        if (dow == 6 && day == 1)
            numSundays++;
    }
    cout << numSundays;
    return 0;
}
