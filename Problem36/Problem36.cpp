#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int numDigits(int i)
{
    int numDig = 0;
    if (i == 0)
        return 0;
    while (i > 0)
    {
        i /= 10;
        numDig++;
    }
    return numDig;
}

vector<int> decToBin(vector<int> dec)
{
    vector<int> bin;
    int decN = 0;
    for (int k = 0; k < dec.size(); k++)
        decN += dec[k]*ceil(pow(10, k));

    while(decN > 0)
    {
        bin.push_back(decN % 2);
        decN /= 2;
    }
    return bin;
}

int isPalin(vector<int> v)
{
    int a = 0, b = v.size() - 1;
    while(a < b)
    {
        if (v[a] != v[b])
            return 0;
        a++;
        b--;
    }
    return 1;
}

int main()
{
    int numDig;
    vector<int> dec;
    vector<int> bin;
    int temp1, temp2;
    int sum = 0;
    for (int i = 1; i < 1000000; i++)
    {
        numDig = numDigits(i);
        temp1 = i;
        for (int k = 0; k < numDig; k++)
        {
            temp2 = temp1 % 10;
            dec.push_back(temp2);
            temp1 /= 10;
        }
        bin = decToBin(dec);
        if (isPalin(dec) && isPalin(bin))
            sum += i;

        dec.clear();
        bin.clear();
    }

    cout << sum;
    return 0;
}
