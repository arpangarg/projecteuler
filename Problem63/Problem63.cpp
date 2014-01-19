#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void printV(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i];
    cout << endl;
}

vector<int> multiply(vector<int> toMul, int c)
{
    int temp;
    int carry = 0;
    for(int k = toMul.size() - 1; k >= 0; k--)
    {
        temp = c*toMul[k] + carry;
        if (temp > 9)
        {
            carry = temp/10;
            temp = temp % 10;
            if(k == 0)
            {
                toMul[0] = temp;
                toMul.insert(toMul.begin(), carry);
                return toMul;
            }
        }
        else
        {
            carry = 0;
        }
        toMul[k] = temp;
    }
    return toMul;
}

int main()
{
    int total = 0;
    for(int i = 1; i < 10; i++)
    {
        vector<int> t;
        t.push_back(1);
        for(int n = 1; n < 22; n++)
        {
            t = multiply(t, i);
            if(t.size() == n)
                total++;
        }
    }

    cout << total;
    return 0;
}
